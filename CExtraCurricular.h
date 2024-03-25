#ifndef DEGREES_OF_HELL_CEXTRACURRICULAR_H
#define DEGREES_OF_HELL_CEXTRACURRICULAR_H

#include "CSpace.h"
#include "CAssessment.h"

class CExtraCurricular : public CSpace
{
private:
    std::vector<CPlayer *> completedPlayers;
    int mNumberOfPlayers = 0;
    const int mMotivationalCost = 100;
public:
    CExtraCurricular(int type, const std::string &name);

    ~CExtraCurricular() override;

    int AddCompletedPlayer(CPlayer &player) override;

    bool IsCompleted(CPlayer &player);

    void PerformAction(CPlayer &player) override;

//    static void ApplyEffect(CPlayer &player, CPlayer &otherPlayer);
};

#endif //DEGREES_OF_HELL_CEXTRACURRICULAR_H
