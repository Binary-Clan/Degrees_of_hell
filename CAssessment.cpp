//
// Created by Sudharaka Fernando on 23/03/2024.
//

#include "CAssessment.h"

CAssessment::CAssessment(int type, const std::string& name, int motiveCost, int achievement)
        : CSpace(type, name), mMotiveCost(motiveCost), mAchievement(achievement) {}

int CAssessment::GetMotivationCost() const {
    return mMotiveCost;
}

int CAssessment::GetAchievement() const {
    return mAchievement;
}
