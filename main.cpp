#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "CSpace.h"
#include "CPlayer.h"

void readSpaces(std::vector<CSpace*>& spaces, const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::cout << "File opened" << std::endl;
            int type;
            std::string name;
            while (file >> type >> name) {
                std::cout << "Reading space: " << name << std::endl;
                std::cout << "Reading type: " << type << std::endl;
                CSpace* space = new CSpace(type, name);
                spaces.push_back(space);
            }
            file.close();
        } else {
            throw std::runtime_error("Unable to open file: " + filename);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {

    // Read spaces from file
    std::vector<CSpace*> spaces;
    readSpaces(spaces, "degrees.txt");

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
        player1.spin(); // Simulate spinning, adjust this as per your logic
//        player1.move(1); // Simulate moving, adjust this as per your logic
//        std::cout << player1.getName() << " spins <number>" << std::endl; // Replace <number> with actual spun number
        std::cout << player1.getName() << " lands on " << player1.getPosition() << std::endl;

        player2.spin(); // Simulate spinning, adjust this as per your logic
//        player2.move(1); // Simulate moving, adjust this as per your logicr
        std::cout << player2.getName() << " lands on " << player2.getPosition() << std::endl;
    }

    // Clean up dynamically allocated memory
    for (auto space : spaces) {
        delete space;
    }

    return 0;
}