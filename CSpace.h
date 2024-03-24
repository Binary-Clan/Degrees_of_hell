// CSpace.h
#ifndef DEGREES_OF_HELL_CSPACE_H
#define DEGREES_OF_HELL_CSPACE_H

#include <string>
#include "CPlayer.h"

class CSpace {
private:
    int mType{};
    std::string mName;

public:
    CSpace(int type, const std::string& name);

    CSpace();

    virtual ~CSpace();
    int GetType() const;
    std::string GetName() const;
    virtual void ApplyEffect(CPlayer& player) ;
    virtual void PerformAction(CPlayer& player) {

    }

};

#endif //DEGREES_OF_HELL_CSPACE_H
