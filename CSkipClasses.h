#ifndef DEGREES_OF_HELL_CSKIPCLASSES_H
#define DEGREES_OF_HELL_CSKIPCLASSES_H

#include "CSpace.h"

class CSkipClasses : public CSpace {
public:
    CSkipClasses(int type, const std::string& name);
    ~CSkipClasses() override;
    void PerformAction(CPlayer& player) override;
};

#endif //DEGREES_OF_HELL_CSKIPCLASSES_H
