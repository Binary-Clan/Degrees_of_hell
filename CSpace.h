//
// Created by Sudharaka Fernando on 22/03/2024.
//

#ifndef DEGREES_OF_HELL_CSPACE_H
#define DEGREES_OF_HELL_CSPACE_H

#include <string>
#include "CPlayer.h"

class CSpace {
private:
    int mType;
    std::string mName;

public:
    CSpace(int type, const std::string& name);
    virtual ~CSpace();
    int GetType() const;
    std::string GetName() const;
    virtual void PerformAction(CPlayer& player) {

    }
};

#endif //DEGREES_OF_HELL_CSPACE_H
