#ifndef DEGREES_OF_HELL_CPLAGIARISMHEARING_H
#define DEGREES_OF_HELL_CPLAGIARISMHEARING_H

#include "CSpace.h"

class CPlagiarismHearing : public CSpace {
public:
    CPlagiarismHearing(int type, const std::string& name);
    ~CPlagiarismHearing() override;
    void ApplyEffect(CPlayer& player) override;
};

#endif // DEGREES_OF_HELL_CPLAGIARISMHEARING_H
