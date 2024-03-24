#include <iostream>
#include "CExtraCurricular.h"
#include "CAssessment.h"


//void CExtraCurricular::ApplyEffect(CPlayer& player) {
//    // Implement extra-curricular activity effect
//    std::cout<< player.GetName() << " lands on Extra-Curricular and joins a club" << std::endl;
//}

CExtraCurricular::CExtraCurricular(int type, const std::string &name) : CAssessment(type, name) {

}

CExtraCurricular::~CExtraCurricular() = default;

//void CExtraCurricular::ApplyEffect(CPlayer& player, CPlayer& otherPlayer) {
//    std::cout << player.GetName() << " lands on Extra-Curricular and joins a club" << std::endl;
//    // Implement the logic for completing extra-curricular activities
//    // The motivational cost of completing any extra-curricular activity is 100
//    const int kMotivationalCost = 100;
//
//    if (!player.IsActivityCompleted()) {
//        if (player.GetMotivation() >= kMotivationalCost) {
//            // Player completes the extra-curricular activity
//            player.IncreaseMotivation(-kMotivationalCost);
//            player.SetActivityCompleted(true);
//            std::cout << player.GetName() << " completes the Extra-Curricular activity" << std::endl;
//        } else {
//            // Player asks for help from the other player
//            std::cout << player.GetName() << " asks for help with the Extra-Curricular activity" << std::endl;
//            int helpCost = kMotivationalCost / 2;
//            int helpAchievement = 50; // Assuming half the achievement value
//            if (otherPlayer.GetMotivation() >= helpCost) {
//                player.IncreaseMotivation(helpCost); // Other player motivates the player
//                otherPlayer.IncreaseMotivation(-helpCost);
//                player.IncreaseSuccess(helpAchievement);
//                otherPlayer.IncreaseSuccess(helpAchievement);
//                std::cout << otherPlayer.GetName() << " motivates " << player.GetName() << " by joining their activity" << std::endl;
//            } else {
//                std::cout << otherPlayer.GetName() << " cannot help due to low motivation" << std::endl;
//            }
//        }
//    } else {
//        std::cout << player.GetName() << "'s Extra-Curricular activity has already been completed" << std::endl;
//    }
//}

void CExtraCurricular::ApplyEffect(CPlayer &player) {
}
