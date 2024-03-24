// CAssessment.cpp

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

}

CAssessment::CAssessment(int i, const std::string basicString) {

}

const std::vector<CPlayer *> &CAssessment::getCompletedPlayers() const {
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