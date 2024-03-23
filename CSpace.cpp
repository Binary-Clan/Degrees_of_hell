// CSpace.cpp
#include "CSpace.h"

CSpace::CSpace(int type, const std::string& name) : mType(type), mName(name) {}

CSpace::~CSpace() {}

int CSpace::GetType() const {
    return mType;
}

std::string CSpace::GetName() const {
    return mName;
}
