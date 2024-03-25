#include <iostream>
#include "CSkipClasses.h"


void CSkipClasses::PerformAction(CPlayer &player)
{
    std::cout << player.GetName() << " lands on Skip Classes and hangs out with their dodgy mates" << std::endl;
    // No special action for Skip Classes
}

CSkipClasses::CSkipClasses(int type, const std::string &name) : CSpace(type, name)
{

}

CSkipClasses::~CSkipClasses() = default;
