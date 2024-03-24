#include "CPlayer.h"
#include <iostream>
#include "random.cpp" // Ensure this is your custom random number generator implementation.
#include "CAssessment.h"

CPlayer::CPlayer(const std::string& name) : mName(name), mMotivation(1000), mSuccess(0), mPosition(0), mYear(1), mIsActive(
        true) {}

std::string CPlayer::GetName() const {
    return mName;
}

int CPlayer::GetMotivation() const {
    return mMotivation;
}

int CPlayer::GetSuccess() const {
    return mSuccess;
}

int CPlayer::GetPosition() const {
    return mPosition;
}

int CPlayer::GetYear() const {
    return mYear;
}

void CPlayer::Spin() {
    int randomNumber = Random(); // Assumes Random() is defined and returns an int
    Move(randomNumber);
    std::cout << mName << " spins " << randomNumber << std::endl;
}

void CPlayer::Move(int spaces) {
    mPosition += spaces;
    if (mPosition > 36) { // Assuming 36 mSpaces in the game, adjust accordingly
        mPosition -= 36;
        if (CanAdvanceToNextYear()) {
            IncrementYear();
            IncreaseMotivation(250); // Reward for starting a new academic year
            std::cout << mName << " attends Welcome Week and starts year " << mYear << " more motivated!" << std::endl;
        } else {
            std::cout << mName << " has not completed enough assessments to advance to the next year." << std::endl;
        }
    }
}

void CPlayer::IncreaseMotivation(int value) {
    mMotivation += value;
}

void CPlayer::DecreaseMotivation(int value) {
    mMotivation-= value;
}

void CPlayer::IncrementYear() {
    mYear++;
}

int CPlayer::GetSpin() {
    return Random();
}

void CPlayer::IncreaseSuccess(int value) {
    mSuccess += value;
}

void CPlayer::SetPosition(int position) {
    mPosition = position;
}

bool CPlayer::IsActivityCompleted() {
    // This method might need adjustments based on your game logic.
    return false;
}

void CPlayer::AddCompletedAssessment(int year, CAssessment* assessment) {
    completedAssessments.emplace_back(year, assessment);
}

bool CPlayer::CanAdvanceToNextYear() const {
    int count = std::count_if(completedAssessments.begin(), completedAssessments.end(),
                              [this](const std::pair<int, CAssessment*>& p) { return p.first == this->mYear; });
    return count >= 3; // Assuming 3 assessments are needed to advance
}

bool CPlayer::HasGraduated() const {
    // Assuming graduation requires completing at least 3 assessments in year 3
    int countYear3 = std::count_if(completedAssessments.begin(), completedAssessments.end(),
                                   [](const std::pair<int, CAssessment*>& p) { return p.first == 3; });
    return countYear3 >= 3;
}

void CPlayer::CheckAndHandleMotivation() {
    if (HasNegativeMotivation()) {
        // Sort completed assessments by motivational cost, lowest first
        std::sort(completedAssessments.begin(), completedAssessments.end(),
                  [](const auto& a, const auto& b) { return a.second->GetMotivationalCost() < b.second->GetMotivationalCost(); });

        for (auto& assessment : completedAssessments) {
            if (HasNegativeMotivation()) {
                DeferAssessment(assessment.second);
            } else {
                break;
            }
        }

        if (HasNegativeMotivation()) {
            std::cout << GetName() << " is unable to reach positive motivation and quits the course." << std::endl;
            QuitGame();
        }
    }

    // Attempt to complete any deferred assessments if possible
    CompleteDeferredAssessment();
}

void CPlayer::DecreaseSuccess(int value) {
    mSuccess -= value;
}

void CPlayer::RemoveCompletedAssessment(CAssessment* assessment) {
    auto it = std::remove_if(completedAssessments.begin(), completedAssessments.end(),
                             [assessment](const std::pair<int, CAssessment*>& p) {
                                 return p.second == assessment;
                             });

    // If the assessment was found and removed, `it` won't be `end()`. Erase actually removes the element(s).
    if (it != completedAssessments.end()) {
        completedAssessments.erase(it, completedAssessments.end());
        std::cout << "Assessment " << assessment->GetName() << " removed from completed assessments." << std::endl;
    } else {
        std::cout << "Assessment " << assessment->GetName() << " not found in completed assessments." << std::endl;
    }
}


void CPlayer::DeferAssessment(CAssessment* assessment) {
    IncreaseMotivation(assessment->GetMotivationalCost()); // Regain motivation
    DecreaseSuccess(assessment->GetAchievement()); // Lose success
    deferredAssessments.push_back(assessment); // Add to deferred assessments
    RemoveCompletedAssessment(assessment);
    std::cout << GetName() << " defers " << assessment->GetName() << " for motivation." << std::endl;
}


void CPlayer::CompleteDeferredAssessment() {
    auto it = deferredAssessments.begin();
    while (it != deferredAssessments.end()) {
        CAssessment* assessment = *it;
        if (mMotivation > assessment->GetMotivationalCost()) {
            IncreaseMotivation(-assessment->GetMotivationalCost());
            IncreaseSuccess(assessment->GetAchievement());
            AddCompletedAssessment(mYear, assessment);
            std::cout << GetName() << " completes deferred " << assessment->GetName() << std::endl;
            it = deferredAssessments.erase(it); // Successfully complete the deferred assessment
        } else {
            ++it;
        }
    }
}


void CPlayer::QuitGame() {
    mIsActive = false;
    std::cout << mName << " has quit the game due to insufficient motivation." << std::endl;
}
