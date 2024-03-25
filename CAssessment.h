// CAssessment.h

#ifndef DEGREES_OF_HELL_CASSESSMENT_H
#define DEGREES_OF_HELL_CASSESSMENT_H

#include "CSpace.h"

class CAssessment : public CSpace
{
private:
    int mMotivationalCost;
    int mAchievement;
    bool mCompleted;
    std::vector<CPlayer *> completedPlayers;

protected:
    CAssessment(int i, const std::string basicString);

public:
    CAssessment(int type, const std::string &name, int cost, int achievement);

    int GetMotivationalCost() const;

    int GetAchievement() const;

    bool IsCompleted() const;

    void SetCompleted(bool completed);

    const std::vector<CPlayer *> &GetCompletedPlayers() const;

    void setCompletedPlayers(const std::vector<CPlayer *> &completedPlayers);

    void PerformAction(CPlayer &player) override;

    void AddCompletedPlayer(CPlayer *player);

    void RemoveCompletedPlayer(CPlayer *player);
};

#endif //DEGREES_OF_HELL_CASSESSMENT_H