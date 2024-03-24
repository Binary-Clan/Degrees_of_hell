#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <memory> // Include memory header for smart pointers
#include <sstream>
#include "CSpace.h"
#include "CPlayer.h"
#include "CPlagiarismHearing.h"
#include "CAccusedOfPlagiarism.h"
#include "CAssessment.h"
#include "CExtraCurricular.h"
#include "CBogus.h"
#include "CBonus.h"

// Typedef for vector of smart pointers to CSpace objects
using SpaceVector = std::vector<std::unique_ptr<CSpace>>;
using PlayerList = std::vector<CPlayer>;

void ReadSpaces(SpaceVector& spaces, const std::string& filename) {
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
                        spaces.push_back(std::make_unique<CAssessment>(type, name, cost, achievement));
                        break;
                    }
                    case 3: {  // New case for ExtraCurricular
                        spaces.push_back(std::make_unique<CExtraCurricular>(type, name));
                        break;
                    }
                    case 4: {
                        spaces.push_back(std::make_unique<CBonus>(type, name));
                        break;
                    }
                    case 5: {
                        spaces.push_back(std::make_unique<CBogus>(type, name));
                        break;
                    }
                    case 6: {
                        spaces.push_back(std::make_unique<CPlagiarismHearing>(type, name));
                        break;
                    }
                    case 7: {
                        spaces.push_back(std::make_unique<CAccusedOfPlagiarism>(type, name));
                        break;
                    }
                    case 8: {
                        spaces.push_back(std::make_unique<CPlagiarismHearing>(type, name));
                        break;
                    }
                    default: {
                        spaces.push_back(std::make_unique<CSpace>(type, name));
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

// Function to simulate a player's turn
void SimulatePlayerTurn(CPlayer& currentPlayer, SpaceVector& spaces) {
    currentPlayer.Spin();
    int position = currentPlayer.GetPosition() - 1; // Adjust for 0-based indexing
    CSpace* currentSpace = spaces[position].get();
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
                currentPlayer.AddCompletedAssessment(assessment);
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
            if (assessment->getCompletedPlayers().at(0) == &currentPlayer)
            {
                std::cout << currentSpace->GetName() << " has already been completed" << std::endl;
            }
            else
            {
                CPlayer *otherPlayer = assessment->getCompletedPlayers().at(0);
                int helpCost = assessment->GetMotivationalCost() / 2;
                int helpAchievement = assessment->GetAchievement() / 2;
                if (otherPlayer->GetMotivation() >= helpCost)
                {
                    currentPlayer.IncreaseMotivation(-helpCost);
                    otherPlayer->IncreaseMotivation(-helpCost);
                    currentPlayer.IncreaseSuccess(helpAchievement);
                    otherPlayer->IncreaseSuccess(helpAchievement);
                    assessment->AddCompletedPlayer(&currentPlayer);
                    currentPlayer.AddCompletedAssessment(assessment);
                    assessment->SetCompleted(true);
                    std::cout << otherPlayer->GetName() << " helps and achieves " << helpAchievement << std::endl;

                }
            }
        }
    }
    else {
        currentSpace->PerformAction(player);
    }
}


int main() {
    // Read spaces from file
    SpaceVector spaces;
    ReadSpaces(spaces, "degrees.txt");

    // Create players
    PlayerList players;
    players.emplace_back("Vyvyan");
    players.emplace_back("Rick");
//    players.emplace_back("Neil");
//    players.emplace_back("Mike");


    // Welcome message
    std::cout << "Welcome to Scumbag College" << std::endl;

    // Simulate 20 rounds
    for (int round = 1; round <= 20; ++round) {
        // Display round number
        std::cout << "\nRound " << round << std::endl;

        // Iterate over each player's turn
        for (auto& currentPlayer : players) {
            SimulatePlayerTurn(currentPlayer, spaces);
        }

        // Output each player's motivation and success
        for (const auto& currentPlayer : players) {
            std::cout << currentPlayer.GetName() << "'s motivation is " << currentPlayer.GetMotivation()
                      << " and success is " << currentPlayer.GetSuccess() << std::endl;
        }
    }

    // Game Over
    std::cout << "\n\nGame Over" << std::endl;

    // Output final success for each player
    for (const auto& currentPlayer : players) {
        std::cout << currentPlayer.GetName() << " has achieved " << currentPlayer.GetSuccess() << std::endl;
    }

    // Determine and output the winner
    int maxSuccess = 0;
    std::string winnerName;
    for (const auto& currentPlayer : players) {
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

    return 0;
}


