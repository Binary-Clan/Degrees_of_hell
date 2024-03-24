#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "CSpace.h"
#include "CPlayer.h"
#include "CPlagiarismHearing.h"
#include "CAccusedOfPlagiarism.h"
#include "CAssessment.h"
#include "CExtraCurricular.h"
#include <sstream>
#include <memory> // Include memory header for smart pointers

//void ReadSpaces(std::vector<CSpace*>& spaces, const std::string& filename) {
//    try {
//        std::ifstream file(filename);
//        if (file.is_open()) {
//            std::cout << "File opened" << std::endl;
//            int type;
//            std::string name;
//            while (file >> type) {
//                std::getline(file >> std::ws, name); // Read the rest of the line as name
//                std::cout << "Reading space: " << name << std::endl;
//                std::cout << "Reading type: " << type << std::endl;
//                if (type == 1) {
//                    int cost, achievement, year;
//                    std::string first, second;
//                    std::istringstream iss(name);
//                    iss >> first >> second >> cost >> achievement >> year;
//                    name = first + " " + second;
//                    // Create and store a pointer to CAssessment object
//                    spaces.push_back(new CAssessment(type, name, cost, achievement));
//                } else {
//                    // Create and store a pointer to CSpace object
//                    spaces.push_back(new CSpace(type, name));
//                }
//            }
//            file.close();
//        } else {
//            throw std::runtime_error("Unable to open file: " + filename);
//        }
//    } catch (const std::exception& e) {
//        std::cerr << e.what() << std::endl;
//    }
//}


void ReadSpaces(std::vector<CSpace*>& spaces, const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (file.is_open()) {
//            std::cout << "File opened" << std::endl;
            int type;
            std::string name;
            while (file >> type) {
                std::getline(file >> std::ws, name); // Read the rest of the line as name
//                std::cout << "Reading space: " << name << std::endl;
//                std::cout << "Reading type: " << type << std::endl;
                switch (type) {
                    case 1:{
                        int cost, achievement, year;
                        std::string first,second;
                        std::istringstream iss(name);
                        iss >> first >> second >> cost >> achievement >> year;
                        name = first + " " + second;
                        CSpace* assessment = new CAssessment(type, name, cost, achievement);
                        spaces.push_back(assessment);
                        break;
                    }

                    case 3: {  // New case for ExtraCurricular
                        CSpace* extraCurricular = new CExtraCurricular(type, name);
                        spaces.push_back(extraCurricular);
                        break;
                    }

                    case 6:{
                        CSpace* plagiarismHearing = new CPlagiarismHearing(type, name);
                        spaces.push_back(plagiarismHearing);
                        break;
                    }

                    case 7:{
                        CSpace* accusedOfPlagiarism = new CAccusedOfPlagiarism(type, name);
                        spaces.push_back(accusedOfPlagiarism);
                        break;
                    }

                    case 8:{
                        CSpace* plagiarismHearing = new CPlagiarismHearing(type, name);
                        spaces.push_back(plagiarismHearing);
                        break;
                    }

                    default:{
                        CSpace* space = new CSpace(type, name);
                        spaces.push_back(space);
                    }

                }
//                if (type == 1) {
//                    int cost, achievement, year;
//                    std::string first,second;
//                    std::istringstream iss(name);
//                    iss >> first >> second >> cost >> achievement >> year;
//                    name = first + " " + second;
//                    CSpace* assessment = new CAssessment(type, name, cost, achievement);
//                    spaces.push_back(assessment);
//                } else {
//                    CSpace* space = new CSpace(type, name);
//                    spaces.push_back(space);
//                }
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
void SimulatePlayerTurn(CPlayer& player, std::vector<CSpace *> spaces, CPlayer& otherPlayer) {
    player.Spin();
    int position = player.GetPosition() - 1; // Adjust for 0-based indexing
    CSpace* currentSpace = spaces[position];
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
    }else if(auto* extraCurricular = dynamic_cast<CExtraCurricular*>(currentSpace)) {
        if (!extraCurricular->IsCompleted()) {
            if (player.GetMotivation() >= extraCurricular->GetMotivationalCost()) {
                player.IncreaseMotivation(-100);
//                player.IncreaseSuccess(assessment->GetAchievement());
                extraCurricular->SetCompleted(true);

//                std::cout << player.GetName() << " completes " << currentSpace->GetName()
//                          << " for " << assessment->GetMotivationalCost()
//                          << " and achieves " << assessment->GetAchievement() << std::endl;
            } else {
                // Ask for help
//                std::cout << player.GetName() << " asks for help with " << currentSpace->GetName() << std::endl;
                const int kExtraCurricularCost = 100;
                int helpCost = kExtraCurricularCost / 2;
//                int helpAchievement = assessment->GetAchievement() / 2;
                if (otherPlayer.GetMotivation() >= helpCost) {
                    player.IncreaseMotivation(-helpCost);
                    otherPlayer.IncreaseMotivation(-helpCost+kExtraCurricularCost);
//                    player.IncreaseSuccess(helpAchievement);
//                    otherPlayer.IncreaseSuccess(helpAchievement);
                    std::cout<< player.GetName() << "motivates" << otherPlayer.GetName() << "by joining their activity" << std::endl;
//                    std::cout << otherPlayer.GetName() << " helps and achieves " << helpAchievement << std::endl;
                } else {
                    std::cout << otherPlayer.GetName() << " cannot help due to low motivation" << std::endl;
                }
            }
        } else {
            std::cout << currentSpace->GetName() << " has already been completed" << std::endl;
        }
    }
    else {
        // Apply effect of the space using polymorphism
        currentSpace->ApplyEffect(player);
//        std::cout << "Nothing happens" << std::endl;
    }
}


int main() {
    // Read spaces from file
    std::vector<CSpace *> spaces;
    ReadSpaces(spaces, "degrees.txt");

    // Create players
    CPlayer player1("Vyvyan");
    CPlayer player2("Rick");

    // Welcome message
    std::cout << "Welcome to Scumbag College" << std::endl;

    // Simulate 20 rounds
    for (int round = 1; round <= 20; ++round) {
        // Display round number
        std::cout << "\nRound " << round << std::endl;

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

    // Simulate 20 rounds
//    for (int round = 1; round <= 20; ++round) {
//        // Display round number
//        std::cout << "\nRound " << round << std::endl;
//
//        // Player 1 turn
//        player1.Spin();
//        CSpace* currentSpace1 = spaces[player1.GetPosition()-1];
//        std::cout << player1.GetName() << " lands on " << currentSpace1->GetName() << std::endl;
//        if (CAssessment* assessment = dynamic_cast<CAssessment*>(currentSpace1)) {
//            if (!assessment->IsCompleted()) {
//                if (player1.GetMotivation() >= assessment->GetMotivationalCost()) {
//                    player1.IncreaseMotivation(-assessment->GetMotivationalCost());
//                    player1.IncreaseSuccess(assessment->GetAchievement());
//                    assessment->SetCompleted(true);
//                    std::cout << player1.GetName() << " completes " << currentSpace1->GetName()
//                              << " for " << assessment->GetMotivationalCost()
//                              << " and achieves " << assessment->GetAchievement() << std::endl;
//                } else {
//                    // Ask for help
//                    std::cout << player1.GetName() << " asks for help with " << currentSpace1->GetName() << std::endl;
//                    int helpCost = assessment->GetMotivationalCost() / 2;
//                    int helpAchievement = assessment->GetAchievement() / 2;
//                    if (player2.GetMotivation() >= helpCost) {
//                        player1.IncreaseMotivation(-helpCost);
//                        player2.IncreaseMotivation(-helpCost);
//                        player1.IncreaseSuccess(helpAchievement);
//                        player2.IncreaseSuccess(helpAchievement);
//                        std::cout << player2.GetName() << " helps and achieves " << helpAchievement << std::endl;
//                    } else {
//                        std::cout << player2.GetName() << " cannot help due to low motivation" << std::endl;
//                    }
//                }
//            } else {
//                std::cout << currentSpace1->GetName() << " has already been completed" << std::endl;
//            }
//        } else {
//            std::cout << "Nothing happens" << std::endl;
//        }
//
//        // Output player's motivation and success
//        std::cout << player1.GetName() << "'s motivation is " << player1.GetMotivation()
//                  << " and success is " << player1.GetSuccess() << std::endl;
//
//        // Player 2 turn
//        // Simulate player 2 turn similarly
//        player2.Spin();
//        CSpace* currentSpace2 = spaces[player2.GetPosition()-1];
//        std::cout << player2.GetName() << " lands on " << currentSpace2->GetName() << std::endl;
//        if (CAssessment* assessment = dynamic_cast<CAssessment*>(currentSpace2)) {
//            if (!assessment->IsCompleted()) {
//                if (player2.GetMotivation() >= assessment->GetMotivationalCost()) {
//                    player2.IncreaseMotivation(-assessment->GetMotivationalCost());
//                    player2.IncreaseSuccess(assessment->GetAchievement());
//                    assessment->SetCompleted(true);
//                    std::cout << player2.GetName() << " completes " << currentSpace2->GetName()
//                              << " for " << assessment->GetMotivationalCost()
//                              << " and achieves " << assessment->GetAchievement() << std::endl;
//                } //after this line occur error
//                else {
//                    // Ask for help
//                    std::cout << player2.GetName() << " asks for help with " << currentSpace2->GetName() << std::endl;
//                    int helpCost = assessment->GetMotivationalCost() / 2;
//                    int helpAchievement = assessment->GetAchievement() / 2;
//                    if (player1.GetMotivation() >= helpCost) {
//                        player2.IncreaseMotivation(-helpCost);
//                        player1.IncreaseMotivation(-helpCost);
//                        player2.IncreaseSuccess(helpAchievement);
//                        player1.IncreaseSuccess(helpAchievement);
//                        std::cout << player1.GetName() << " helps and achieves " << helpAchievement << std::endl;
//                    } else {
//                        std::cout << player1.GetName() << " cannot help due to low motivation" << std::endl;
//                    }
//                }
//            } else {
//                std::cout << currentSpace2->GetName() << " has already been completed" << std::endl;
//            }
//        } else {
//            std::cout << "Nothing happens" << std::endl;
//        }
//
//    }

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

    // Clean up dynamically allocated memory
    for (auto space : spaces) {
        delete space;
    }

    return 0;
}
