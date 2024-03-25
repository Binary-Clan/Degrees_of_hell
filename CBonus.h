#ifndef DEGREES_OF_HELL_CBONUS_H
#define DEGREES_OF_HELL_CBONUS_H

#include <vector>
#include "CSpace.h"

class CBonus : public CSpace
{
private:
    struct BonusInfo
    {
        std::string message;
        int gainMotivation;
    };
    static const std::vector<BonusInfo> bonuses;
public:
    CBonus(int type, const std::string name);

    virtual ~CBonus()
    {
    };

    void PerformAction(CPlayer &player) override;
};


#endif //DEGREES_OF_HELL_CBONUS_H
