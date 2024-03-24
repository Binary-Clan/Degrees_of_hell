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
void SimulatePlayerTurn(CPlayer& player, SpaceVector& spaces, CPlayer& otherPlayer) {
    player.Spin();
    int position = player.GetPosition() - 1; // Adjust for 0-based indexing
    CSpace* currentSpace = spaces[position].get();
    std::cout << player.GetName() << " lands on " << currentSpace->GetName() << std::endl;
    if (CAssessment* assessment = dynamic_cast<CAssessment*>(currentSpace)) {
        if (!assessment->IsCompleted()) {
            if (player.GetMotivation() >= assessment->GetMotivationalCost()) {
                player.IncreaseMotivation(-assessment->GetMotivationalCost());
                player.IncreaseSuccess(assessment->GetAchievement());
                assessment->SetCompleted(true);
                std::cout << player.GetName() << " completes " << currentSpace->GetName()
                          << " for " << assessment->GetMotivationalCost()
                          << " and achieves " << assessment->GetAchievement() << std::endl;
            } else {
                // Ask for help
                std::cout << player.GetName() << " asks for help with " << currentSpace->GetName() << std::endl;
                int helpCost = assessment->GetMotivationalCost() / 2;
                int helpAchievement = assessment->GetAchievement() / 2;
                if (otherPlayer.GetMotivation() >= helpCost) {
                    player.IncreaseMotivation(-helpCost);
                    otherPlayer.IncreaseMotivation(-helpCost);
                    player.IncreaseSuccess(helpAchievement);
                    otherPlayer.IncreaseSuccess(helpAchievement);
                    std::cout << otherPlayer.GetName() << " helps and achieves " << helpAchievement << std::endl;
                } else {
                    std::cout << otherPlayer.GetName() << " cannot help due to low motivation" << std::endl;
                }
            }
        } else {
            std::cout << currentSpace->GetName() << " has already been completed" << std::endl;
        }
    } else if (auto* extraCurricular = dynamic_cast<CExtraCurricular*>(currentSpace)) {
        if (!extraCurricular->IsCompleted()) {
            if (player.GetMotivation() >= extraCurricular->GetMotivationalCost()) {
                player.IncreaseMotivation(-100);
                extraCurricular->SetCompleted(true);
            } else {
                const int kExtraCurricularCost = 100;
                int helpCost = kExtraCurricularCost / 2;
                if (otherPlayer.GetMotivation() >= helpCost) {
                    player.IncreaseMotivation(-helpCost);
                    otherPlayer.IncreaseMotivation(-helpCost + kExtraCurricularCost);
                    std::cout << player.GetName() << " motivates " << otherPlayer.GetName() << " by joining their activity" << std::endl;
                } else {
                    std::cout << otherPlayer.GetName() << " cannot help due to low motivation" << std::endl;
                }
            }
        } else {
            std::cout << currentSpace->GetName() << " has already been completed" << std::endl;
        }
    } else {
        currentSpace->PerformAction(player);
    }
}

int main() {
    // Read spaces from file
    SpaceVector spaces;
    ReadSpaces(spaces, "degrees.txt");

    // Create players
    CPlayer player1("Vyvyan");
    CPlayer player2("Rick");

    // Welcome message
    std::cout << "Welcome to Scumbag College" << std::endl;

    // Simulate 20 rounds
    for (int round = 1; round <= 20; ++round) {
        // Display round number
        std::cout << "\nRound "
                << round << std::endl;

        // Player 1 turn
        SimulatePlayerTurn(player1, spaces, player2);

        // Output player's motivation and success
        std::cout << player1.GetName() << "'s motivation is " << player1.GetMotivation()
                  << " and success is " << player1.GetSuccess() << std::endl;

        // Player 2 turn
        SimulatePlayerTurn(player2, spaces, player1);

        // Output player's motivation and success
        std::cout << player2.GetName() << "'s motivation is " << player2.GetMotivation()
                  << " and success is " << player2.GetSuccess() << std::endl;
    }

    // Game Over
    std::cout << "\n\nGame Over" << std::endl;
    std::cout << player1.GetName() << " has achieved " << player1.GetSuccess() << std::endl;
    std::cout << player2.GetName() << " has achieved " << player2.GetSuccess() << std::endl;
    if (player1.GetSuccess() > player2.GetSuccess()) {
        std::cout << player1.GetName() << " wins." << std::endl;
    } else if (player1.GetSuccess() < player2.GetSuccess()) {
        std::cout << player2.GetName() << " wins." << std::endl;
    } else {
        std::cout << "It's a tie." << std::endl;
    }

    return 0;
}
