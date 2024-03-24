#ifndef DEGREES_OF_HELL_CEXTRACURRICULAR_H
#define DEGREES_OF_HELL_CEXTRACURRICULAR_H

#include "CSpace.h"
#include "CAssessment.h"

class CExtraCurricular : public  CAssessment{
public:
    CExtraCurricular(int type, const std::string& name);
    ~CExtraCurricular() override;
    void PerformAction(CPlayer& player) override;

//    static void ApplyEffect(CPlayer &player, CPlayer &otherPlayer);
};

#endif //DEGREES_OF_HELL_CEXTRACURRICULAR_H
