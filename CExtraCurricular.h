#ifndef DEGREES_OF_HELL_CEXTRACURRICULAR_H
#define DEGREES_OF_HELL_CEXTRACURRICULAR_H

#include "CSpace.h"

class CExtraCurricular : public CSpace {
public:
    CExtraCurricular(int type, const std::string& name);
    ~CExtraCurricular() override;
    void ApplyEffect(CPlayer& player) override;
};

#endif //DEGREES_OF_HELL_CEXTRACURRICULAR_H
