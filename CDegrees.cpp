#include "CDegrees.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include "CAssessment.h"
#include "CExtraCurricular.h"
#include "CBogus.h"
#include "CBonus.h"
#include "CPlagiarismHearing.h"
#include "CAccusedOfPlagiarism.h"

void CDegrees::ReadSpaces(const std::string &filename)
{
    try
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            int type;
            std::string name;
            while (file >> type)
            {
                std::getline(file >> std::ws, name); // Read the rest of the line as name
                switch (type)
                {
                    case 1:
                    {
                        int cost, achievement, year;
                        std::string first, second;
                        std::istringstream iss(name);
                        iss >> first >> second >> cost >> achievement >> year;
                        name = first + " " + second;
                        mSpaces.push_back(std::make_unique<CAssessment>(type, name, cost, achievement));
                        break;
                    }
                    case 3:
                    {  // New case for ExtraCurricular
                        mSpaces.push_back(std::make_unique<CExtraCurricular>(type, name));
                        break;
                    }
                    case 4:
                    {
                        mSpaces.push_back(std::make_unique<CBonus>(type, name));
                        break;
                    }
                    case 5:
                    {
                        mSpaces.push_back(std::make_unique<CBogus>(type, name));
                        break;
                    }
                    case 6:
                    {
                        mSpaces.push_back(std::make_unique<CPlagiarismHearing>(type, name));
                        break;
                    }
                    case 7:
                    {
                        mSpaces.push_back(std::make_unique<CAccusedOfPlagiarism>(type, name));
                        break;
                    }
                    case 8:
                    {
                        mSpaces.push_back(std::make_unique<CPlagiarismHearing>(type, name));
                        break;
                    }
                    default:
                    {
                        mSpaces.push_back(std::make_unique<CSpace>(type, name));
                    }
                }
            }
            file.close();
        } else
        {
            throw std::runtime_error("Unable to open file: " + filename);
        }
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void CDegrees::AddPlayer(const std::string &name)
{
    mPlayers.emplace_back(name);
}

void CDegrees::SimulatePlayerTurn(CPlayer &currentPlayer)
{
    currentPlayer.Spin();
    int position = currentPlayer.GetPosition() - 1; // Adjust for 0-based indexing
    CSpace *currentSpace = mSpaces[position].get();
    std::cout << currentPlayer.GetName() << " lands on " << currentSpace->GetName() << std::endl;
    currentSpace->PerformAction(currentPlayer);
    currentPlayer.CheckAndHandleMotivation();
}

void CDegrees::Run()
{
    std::cout << "Welcome to Scumbag College" << std::endl;
    for (int round = 1; round <= 500; ++round)
    {
        std::cout << "\nRound " << round << std::endl;

        for (auto &player: mPlayers)
        {
            if (!player.IsActive())
            {
                continue;
            }
            SimulatePlayerTurn(player);
        }

        for (const auto &currentPlayer: mPlayers)
        {
            std::cout << currentPlayer.GetName() << "'s motivation is " << currentPlayer.GetMotivation()
                      << " and success is " << currentPlayer.GetSuccess() << std::endl;
        }

        for (const auto &player: mPlayers)
        {
            if (player.HasGraduated())
            {
                std::cout << player.GetName() << " has graduated! Congratulations!" << std::endl;
                GameOver();
                return; // End the game
            }
        }
    }
    GameOver();

}

void CDegrees::GameOver()
{// Implement game over logic and winner determination
    std::cout << "\n\nGame Over" << std::endl;

    // Output final success for each player
    for (const auto &currentPlayer: mPlayers)
    {
        std::cout << currentPlayer.GetName() << " has achieved " << currentPlayer.GetSuccess() << std::endl;
    }

    for (const auto &currentPlayer: mPlayers)
    {
        if (currentPlayer.HasGraduated())
        {
            std::cout << currentPlayer.GetName() << " has graduated and wins with " << currentPlayer.GetSuccess()
                      << " achievements!" << std::endl;
            return;
        }
    }

    int maxSuccess = 0;
    std::string winnerName;
    for (const auto &currentPlayer: mPlayers)
    {
        if (currentPlayer.GetSuccess() > maxSuccess)
        {
            maxSuccess = currentPlayer.GetSuccess();
            winnerName = currentPlayer.GetName();
        }
    }
    if (maxSuccess == 0)
    {
        std::cout << "No one wins. Everyone failed!" << std::endl;
    } else
    {
        std::cout << winnerName << " wins with " << maxSuccess << " achievements!" << std::endl;
    }

    return;
}

