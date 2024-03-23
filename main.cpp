#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include "CSpace.h"
#include "CPlayer.h"
#include "CAssessment.h"
#include "CBogus.h"
#include "CBonus.h"

void ReadSpaces(std::vector<CSpace*>& spaces, const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::cout << "File opened" << std::endl;
            int type;
            std::string name;
            while (file >> type) {
                std::getline(file >> std::ws, name); // Read the rest of the line as name
                std::cout << "Reading space: " << name << std::endl;
                std::cout << "Reading type: " << type << std::endl;
                if (type == 1) {
                    int cost, achievement, year;
                    std::string first,second;
                    std::istringstream iss(name);
                    iss >> first >> second >> cost >> achievement >> year;
                    name = first + " " + second;
                    CAssessment* assessment = new CAssessment(type, name, cost, achievement);
                    spaces.push_back(assessment);

                } else if(type == 4) {
                    CBonus* bonus = new CBonus(type, name);
                    spaces.push_back(bonus);
                }else{
                    CSpace* space = new CSpace(type, name);
                    spaces.push_back(space);
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


void PrintSpaces(const std::vector<CSpace*>& spaces) {
    for (const auto& space : spaces) {
        std::cout << "Type: " << space->GetType() << std::endl;
        std::cout << "Name: " << space->GetName() << std::endl;

        // Check if it's an assessment space
        if (const CAssessment* assessment = dynamic_cast<const CAssessment*>(space)) {
            std::cout << "Motivational Cost: " << assessment->GetMotivationCost() << std::endl;
            std::cout << "Achievement: " << assessment->GetAchievement() << std::endl;
        }

        std::cout << std::endl;
    }
}

int main() {

    // Read spaces from file
    std::vector<CSpace*> spaces;
    ReadSpaces(spaces, "degrees.txt");

    // Create players
    CPlayer player1(" Vyvyan");
    CPlayer player2("Rick");

    // Welcome message
    std::cout << "Welcome to Scumbag College" << std::endl;

    // Simulate 20 rounds
    for (int round = 1; round <= 20; ++round) {
        // Display round number
        std::cout << "Round " << round << std::endl;

        // Simulate player turns
        player1.Spin(); // Simulate spinning, adjust this as per your logic
//        player1.Move(1); // Simulate moving, adjust this as per your logic
//        std::cout << player1.GetName() << " spins <number>" << std::endl; // Replace <number> with actual spun number
        std::cout << player1.GetName() << " lands on " << player1.GetPosition() << std::endl;

        player2.Spin(); // Simulate spinning, adjust this as per your logic
//        player2.Move(1); // Simulate moving, adjust this as per your logicr
        std::cout << player2.GetName() << " lands on " << player2.GetPosition() << std::endl;
    }

    PrintSpaces(spaces);

    // Clean up dynamically allocated memory
    for (auto space : spaces) {
        delete space;
    }

    return 0;
}