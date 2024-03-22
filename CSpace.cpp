//
// Created by Sudharaka Fernando on 22/03/2024.
//
#include "CSpace.h"
#include <iostream>

CSpace::CSpace(int type, const std::string& name) : mType(type), mName(name) {}

int CSpace::getType() const {
    return mType;
}

std::string CSpace::getName() const {
    std::cout << "Getting name for space: " << mName << std::endl;
    return mName;
}