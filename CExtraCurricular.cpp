#include <iostream>
#include "CExtraCurricular.h"


void CExtraCurricular::ApplyEffect(CPlayer& player) {
    // Implement extra-curricular activity effect
    std::cout<< player.GetName() << " lands on Extra-Curricular and joins a club" << std::endl;
}

CExtraCurricular::CExtraCurricular(int type, const std::string &name) : CSpace(type, name) {

}

CExtraCurricular::~CExtraCurricular() = default;
