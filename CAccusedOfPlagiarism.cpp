#include <iostream>
#include "CAccusedOfPlagiarism.h"

CAccusedOfPlagiarism::CAccusedOfPlagiarism(int type, const std::string& name) : CSpace(type, name) {}

CAccusedOfPlagiarism::~CAccusedOfPlagiarism() = default;

void CAccusedOfPlagiarism::ApplyEffect(CPlayer& player) {

    // Reduce player's motivation by 50
    player.IncreaseMotivation(-50);
    //piece immediately moves to the Plagiarism Hearing space and their motivation is reduced by 50.
    player.SetPosition(33);

    std::cout << player.GetName() << " lands on Accused of Plagiarism and goes to the hearing" << std::endl;
    std::cout << player.GetName() << " lose motivation" << std::endl;

//    std::cout << player.GetName() << " new position " << player.GetPosition() << std::endl;
}
