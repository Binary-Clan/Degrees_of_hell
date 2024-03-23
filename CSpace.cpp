//
// Created by Sudharaka Fernando on 22/03/2024.
//
#include "CSpace.h"
#include <iostream>

CSpace::CSpace(int type, const std::string& name) : mType(type), mName(name) {}

CSpace::~CSpace() {}

int CSpace::GetType() const {
    return mType;
}

std::string CSpace::GetName() const {
//    std::cout << "Getting name for space: " << mName << std::endl;
    return mName;
}