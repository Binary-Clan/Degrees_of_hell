// CAssessment.cpp

#include <iostream>
#include <cmath>
#include "CAssessment.h"

CAssessment::CAssessment(int type, const std::string& name, int cost, int achievement)
        : CSpace(type, name), mMotivationalCost(cost), mAchievement(achievement), mCompleted(false) {}

int CAssessment::GetMotivationalCost() const {
    return mMotivationalCost;
}

int CAssessment::GetAchievement() const {
    return mAchievement;
}

bool CAssessment::IsCompleted() const {
    return mCompleted;
}

void CAssessment::SetCompleted(bool completed) {
    mCompleted = completed;
}

void CAssessment::PerformAction(CPlayer &player) {
    if (GetCompletedPlayers().empty()) {
        if (player.GetMotivation() >= GetMotivationalCost())
        {
            player.IncreaseMotivation( -(GetMotivationalCost()));
            player.IncreaseSuccess(GetAchievement());
            SetCompleted(true);
            AddCompletedPlayer(&player);
            player.AddCompletedAssessment(player.GetYear(), this);
            std::cout << player.GetName() << " completes " << GetName()
                      << "for " << GetMotivationalCost()
                      << " and achieves " << GetAchievement() << std::endl;
        }
        else
        {
            std::cout << "Cannot do assessment due to low motivation" << std::endl;
        }
    }
    else
    {
        if (std::find(GetCompletedPlayers().begin(), GetCompletedPlayers().end(), &player) != GetCompletedPlayers().end()) // check if that the current person has not completed the assessment
        {
            std::cout << GetName() << " has already been completed" << std::endl;
        }
        else
        {
            int totalHelpCost = GetMotivationalCost() ; // Shared cost
            int totalHelpAchievement = GetAchievement(); // Shared achievement
            int helpersCount = 1; // Including the current player

            // Loop through all players who have completed this assessment to join in helping
            // assumption -> the completed players' motivation does not deduct when helping
            for (CPlayer* helper : GetCompletedPlayers()) {
                helpersCount++;
            }

            // Distribute the achievement equally, rounded to the nearest whole number
            int sharedAchievement = std::round(static_cast<float>(totalHelpAchievement) / helpersCount);
            int sharedCost = std::round(static_cast<float>(totalHelpCost) / helpersCount);

            player.IncreaseSuccess(sharedAchievement);

            // Assuming that the motivation needed is divides by the helpersCount
            player.IncreaseMotivation(-sharedCost); // Deduct the shared cost from the current player

            for (CPlayer* helper : GetCompletedPlayers()) {
                helper->IncreaseSuccess(sharedAchievement); // Award each helper their share of the success
                std::cout << helper->GetName() << " helps and achieves " << sharedAchievement << std::endl;
            }

            AddCompletedPlayer(&player); // Mark assessment as completed for current player
            player.AddCompletedAssessment(player.GetYear(), this);
        }
    }
}


CAssessment::CAssessment(int i, const std::string basicString) {

}

const std::vector<CPlayer *> &CAssessment::GetCompletedPlayers() const {
    return completedPlayers;
}

void CAssessment::setCompletedPlayers(const std::vector<CPlayer *> &completedPlayers) {
    CAssessment::completedPlayers = completedPlayers;
}

void CAssessment::AddCompletedPlayer(CPlayer* player){
    completedPlayers.push_back(player);
}

void CAssessment::RemoveCompletedPlayer(CPlayer* player) {
    auto it = std::find(completedPlayers.begin(), completedPlayers.end(), player);
    if (it != completedPlayers.end()) {
        completedPlayers.erase(it);
    }
}
