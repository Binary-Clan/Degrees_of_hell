#include <iostream>
#include <algorithm>
#include "CExtraCurricular.h"
#include "CSpace.h"



CExtraCurricular::CExtraCurricular(int type, const std::string &name) : CSpace(type, name) {

}

void CExtraCurricular::PerformAction(CPlayer &player) {
    if(mNumberOfPlayers == -10){
        std::cout<< this->GetName()<< " is already completed by this player "<< player.GetName()<< std::endl;
    } else if(mNumberOfPlayers > 0){
        const int dividedCost = mMotivationalCost/ mNumberOfPlayers;
        player.DecreaseMotivation(dividedCost);
        for (int i = 0; i < mNumberOfPlayers; i++) {
            completedPlayers[i]->IncreaseMotivation(dividedCost);
        }
        std::cout << player.GetName() << " motivates ";
        for (CPlayer* completedPlayer : completedPlayers) {
            std::cout << completedPlayer->GetName() ;
        }
        std::cout << " by joining their activity" << std::endl;

    } else{
        std::cout << player.GetName() << " is participating in " << GetName() << std::endl;
        if (player.GetMotivation() >= mMotivationalCost) {
            player.DecreaseMotivation(mMotivationalCost);
        }
    }
}


CExtraCurricular::~CExtraCurricular() = default;

int CExtraCurricular::AddCompletedPlayer(CPlayer &player) {
    if(IsCompleted(player)){
        mNumberOfPlayers = -10;
    } else{
        completedPlayers.push_back(&player);
        mNumberOfPlayers =  completedPlayers.size()-1;
    }
    return mNumberOfPlayers;
}

bool CExtraCurricular::IsCompleted(CPlayer &player) {
    //before checking if player is in the list, check if player is already in the completed mPlayers vector
    auto it = std::find(completedPlayers.begin(), completedPlayers.end(), &player);
    // If player is found, return true; otherwise, return false
    return it != completedPlayers.end();
}


