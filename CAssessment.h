// CAssessment.h

#ifndef DEGREES_OF_HELL_CASSESSMENT_H
#define DEGREES_OF_HELL_CASSESSMENT_H

#include "CSpace.h"

class CAssessment : public CSpace {
private:
    int mMotivationalCost;
    int mAchievement;
    bool mCompleted;

public:
    CAssessment(int type, const std::string& name, int cost, int achievement);
    int GetMotivationalCost() const;
    int GetAchievement() const;
    bool IsCompleted() const;
    void SetCompleted(bool completed);
};

#endif //DEGREES_OF_HELL_CASSESSMENT_H
