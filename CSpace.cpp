// CSpace.cpp
#include "CSpace.h"

CSpace::CSpace(int type, const std::string& name) : mType(type), mName(name) {}

CSpace::~CSpace() = default;

int CSpace::GetType() const {
    return mType;
}

std::string CSpace::GetName() const {
    return mName;
}

void CSpace::ApplyEffect(CPlayer &player) {

}

CSpace::CSpace() = default;
