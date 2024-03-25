#include <iostream>
#include "CBonus.h"

CBonus::CBonus(int type, const std::string name)
    : CSpace(type, name){}

void CBonus::PerformAction(CPlayer &player)  {
    int spin = player.GetSpin()-1;

    const BonusInfo& bonus = bonuses[spin];

    player.IncreaseMotivation(bonus.gainMotivation);
    std::cout << player.GetName() << " lands on Bonus: " << bonus.message << std::endl
              << "Gain motivation of " << bonus.gainMotivation << std::endl;
    std::cout << player.GetName() << " has current motivation: " << player.GetMotivation() << std::endl;
}

const std::vector<CBonus::BonusInfo> CBonus::bonuses = {
        {"Receive some useful feedback.", 20},
        {"Win a hackathon.", 50},
        {"Get a free coffee with full loyalty card.", 80},
        {"Impress your lecturer in class.", 100},
        {"Motivational talk from course leader.", 5},
        {"Secure an industry placement.", 150},
        {"Attend an inspiring C++ lecture.", 200},
        {"Get your best ever assignment mark.", 300},
        {"Make a new romantic friend.", 150},
        {"Get elected School President.", 10}
};