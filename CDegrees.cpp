#include "CDegrees.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include "CAssessment.h"
#include "CExtraCurricular.h"
#include "CBogus.h"
#include "CBonus.h"
#include "CPlagiarismHearing.h"
#include "CAccusedOfPlagiarism.h"

void CDegrees::ReadSpaces(const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (file.is_open()) {
            int type;
            std::string name;
            while (file >> type) {
                std::getline(file >> std::ws, name); // Read the rest of the line as name
                switch (type) {
                    case 1: {
                        int cost, achievement, year;
                        std::string first, second;
                        std::istringstream iss(name);
                        iss >> first >> second >> cost >> achievement >> year;
                        name = first + " " + second;
                        mSpaces.push_back(std::make_unique<CAssessment>(type, name, cost, achievement));
                        break;
                    }
                    case 3: {  // New case for ExtraCurricular
                        mSpaces.push_back(std::make_unique<CExtraCurricular>(type, name));
                        break;
                    }
                    case 4: {
                        mSpaces.push_back(std::make_unique<CBonus>(type, name));
                        break;
                    }
                    case 5: {
                        mSpaces.push_back(std::make_unique<CBogus>(type, name));
                        break;
                    }
                    case 6: {
                        mSpaces.push_back(std::make_unique<CPlagiarismHearing>(type, name));
                        break;
                    }
                    case 7: {
                        mSpaces.push_back(std::make_unique<CAccusedOfPlagiarism>(type, name));
                        break;
                    }
                    case 8: {
                        mSpaces.push_back(std::make_unique<CPlagiarismHearing>(type, name));
                        break;
                    }
                    default: {
                        mSpaces.push_back(std::make_unique<CSpace>(type, name));
                    }
                }
            }
            file.close();
        } else {
            throw std::runtime_error("Unable to open file: " + filename);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void CDegrees::AddPlayer(const std::string& name) {
    mPlayers.emplace_back(name);
}

void CDegrees::SimulatePlayerTurn(CPlayer& currentPlayer) {
    currentPlayer.Spin();
    int position = currentPlayer.GetPosition() - 1; // Adjust for 0-based indexing
    CSpace* currentSpace = mSpaces[position].get();
    std::cout << currentPlayer.GetName() << " lands on " << currentSpace->GetName() << std::endl;

    if (CAssessment* assessment = dynamic_cast<CAssessment*>(currentSpace)) {
        // Handle assessment space
        if (assessment->getCompletedPlayers().empty()) {
            if (currentPlayer.GetMotivation() >= assessment->GetMotivationalCost())
            {
                currentPlayer.IncreaseMotivation( -(assessment->GetMotivationalCost()));
                currentPlayer.IncreaseSuccess(assessment->GetAchievement());
                assessment->SetCompleted(true);
                assessment->AddCompletedPlayer(&currentPlayer);
                currentPlayer.AddCompletedAssessment(currentPlayer.GetYear(), assessment);
                std::cout << currentPlayer.GetName() << " completes " << currentSpace->GetName()
                          << "for " << assessment->GetMotivationalCost()
                          << " and achieves " << assessment->GetAchievement() << std::endl;
            }
            else
            {
                std::cout << "Cannot do assessment due to low motivation" << std::endl;
            }
        }
        else
        {
            if (std::find(assessment->getCompletedPlayers().begin(), assessment->getCompletedPlayers().end(), &currentPlayer) != assessment->getCompletedPlayers().end()) // check if that the current person has not completed the assessment
            {
                std::cout << currentSpace->GetName() << " has already been completed" << std::endl;
            }
            else
            {
                int totalHelpCost = assessment->GetMotivationalCost() ; // Shared cost
                int totalHelpAchievement = assessment->GetAchievement(); // Shared achievement
                int helpersCount = 1; // Including the current player

                // Loop through all players who have completed this assessment to join in helping
                // assumption -> the completed players' motivation does not deduct when helping
                for (CPlayer* helper : assessment->getCompletedPlayers()) {
                    helpersCount++;
                }

                // Distribute the achievement equally, rounded to the nearest whole number
                int sharedAchievement = std::round(static_cast<float>(totalHelpAchievement) / helpersCount);
                int sharedCost = std::round(static_cast<float>(totalHelpCost) / helpersCount);

                currentPlayer.IncreaseSuccess(sharedAchievement);

                // Assuming that the motivation needed is divides by the helpersCount
                currentPlayer.IncreaseMotivation(-sharedCost); // Deduct the shared cost from the current player

                for (CPlayer* helper : assessment->getCompletedPlayers()) {
                    helper->IncreaseSuccess(sharedAchievement); // Award each helper their share of the success
                    std::cout << helper->GetName() << " helps and achieves " << sharedAchievement << std::endl;
                }

                assessment->AddCompletedPlayer(&currentPlayer); // Mark assessment as completed for current player
                currentPlayer.AddCompletedAssessment(currentPlayer.GetYear(), assessment);
            }
        }
    }
    else {
        currentSpace->PerformAction(currentPlayer);
    }
    currentPlayer.CheckAndHandleMotivation();
}

void CDegrees::Run() {
    std::cout << "Welcome to Scumbag College" << std::endl;
    // Simulate 20 rounds
    for (int round = 1; round <= 20; ++round) {
        // Display round number
        std::cout << "\nRound " << round << std::endl;

        // Iterate over each player's turn
        for (auto& player : mPlayers) {
            if (!player.IsActive()) {
                continue; // Skip the turn for players who have quit
            }
            SimulatePlayerTurn(player);

            // Check conditions and handle player state after their turn
        }

        // Output each player's motivation and success
        for (const auto& currentPlayer : mPlayers) {
            std::cout << currentPlayer.GetName() << "'s motivation is " << currentPlayer.GetMotivation()
                      << " and success is " << currentPlayer.GetSuccess() << std::endl;
        }

        for (const auto& player : mPlayers) {
            if (player.HasGraduated()) {
                std::cout << player.GetName() << " has graduated! Congratulations!" << std::endl;
                return; // End the game
            }
        }
    }
    // Implement game over logic and winner determination
    std::cout << "\n\nGame Over" << std::endl;

    // Output final success for each player
    for (const auto& currentPlayer : mPlayers) {
        std::cout << currentPlayer.GetName() << " has achieved " << currentPlayer.GetSuccess() << std::endl;
    }

    // Determine and output the winner
    int maxSuccess = 0;
    std::string winnerName;
    for (const auto& currentPlayer : mPlayers) {
        if (currentPlayer.GetSuccess() > maxSuccess) {
            maxSuccess = currentPlayer.GetSuccess();
            winnerName = currentPlayer.GetName();
        }
    }
    if (maxSuccess == 0) {
        std::cout << "No one wins. Everyone failed!" << std::endl;
    } else {
        std::cout << winnerName << " wins with " << maxSuccess << " achievements!" << std::endl;
    }

    return;
}

