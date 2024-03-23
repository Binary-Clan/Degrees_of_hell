//
// Created by Sudharaka Fernando on 23/03/2024.
//

#ifndef DEGREES_OF_HELL_CASSESSMENT_H
#define DEGREES_OF_HELL_CASSESSMENT_H

#include "CSpace.h"

class CAssessment : public CSpace {
private:
    int mMotiveCost;
    int mAchievement;

public:
    CAssessment(int type, const std::string& name, int motiveCost, int achievement);

    int GetMotivationCost() const;
    int GetAchievement() const;
};


#endif //DEGREES_OF_HELL_CASSESSMENT_H
