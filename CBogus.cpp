#include "CBogus.h"
#include <iostream>

CBogus::CBogus(int type, const std::string& name)
        : CSpace(type, name) {}

void CBogus::PerformAction(CPlayer &player) {
    int spin = player.GetSpin() - 1; // Assuming spin results start from 1

    if (spin < 0 || spin >= boguses.size()) {
        std::cout << "Unexpected spin result. No motivation lost." << std::endl;
        return;
    }

    const BogusInfo& bogus = boguses[spin];
    player.DecreaseMotivation(bogus.loseMotivation); // Assuming a method like this exists in CPlayer
    std::cout << player.GetName() << " lands on Bogus: " << bogus.message << std::endl
              << "Lose motivation of " << bogus.loseMotivation << std::endl;
    std::cout << player.GetName() << " has current motivation: " << player.GetMotivation() << std::endl;
}

const std::vector<CBogus::BogusInfo> CBogus::boguses = {
        {"Fall asleep in a boring lecture.", 20},
        {"Meet with coach about poor attendance.", 50},
        {"Feel really tired after a night out.", 80},
        {"Get kicked out of lab for messing about.", 100},
        {"Get dumped before a big night out.", 150},
        {"Fail an assignment.", 200},
        {"Get caught skipping class.", 50},
        {"Your friend drops out of uni.", 200},
        {"Nobody turns up to teach your class.", 300},
        {"Lecturer changes assignment schedule.", 20}
};
