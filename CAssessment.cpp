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

void CAssessment::ApplyEffect(CPlayer &player) {

}

CAssessment::CAssessment(int i, const std::string basicString) {

}

