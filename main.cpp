#include "CDegrees.h"

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <fstream> // For file input/output
#include <iostream>

using namespace std;

// Function to read the seed value from "seed.txt"
int readSeedFromFile(const char* filename) {
    ifstream file(filename);
    int seed = 0;
    if (file.is_open()) {
        file >> seed; // Read the seed from the file
        file.close();
    } else {
        // If the file could not be opened, use the current time as a seed
        cout << "Could not open seed file. Using current time as seed." << endl;
        seed = static_cast<int>(time(nullptr));
    }
    return seed;
}


int main()
{
    int seed = readSeedFromFile("E:\\Projects\\Degrees of Hell\\seed.txt");

    srand(seed);
    CDegrees game;

    game.ReadSpaces("degrees.txt");
    game.AddPlayer("Vyvyan");
    game.AddPlayer("Rick");
    game.AddPlayer("Neil");
    game.AddPlayer("Mike");

    game.Run();

    return 0;
}


