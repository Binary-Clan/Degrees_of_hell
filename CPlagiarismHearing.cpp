#include <iostream>
#include "CPlagiarismHearing.h"

CPlagiarismHearing::CPlagiarismHearing(int type, const std::string& name) : CSpace(type, name) {}

CPlagiarismHearing::~CPlagiarismHearing() = default;

void CPlagiarismHearing::PerformAction(CPlayer& player) {
    std::cout << player.GetName() << " lands on Plagiarism Hearing and supports their friend" << std::endl;
}
