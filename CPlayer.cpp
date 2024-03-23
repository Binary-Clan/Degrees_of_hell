// CPlayer.cpp

#include "CPlayer.h"
#include <iostream>
#include "random.cpp"

CPlayer::CPlayer(const std::string& name) : mName(name), mMotivation(1000), mSuccess(0), mPosition(0), mYear(1) {}

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
    // Simulating spinning, you can implement your own logic here
    // Generate a random number between 1 and 10
    int randomNumber = Random();
    // Output the spun number
    Move(randomNumber);
    std::cout << mName << " spins " << randomNumber << std::endl;
    // Move the player based on the spun number, adjust this logic as per your requirement

}

void CPlayer::Move(int spaces) {
    mPosition += spaces;
    if(mPosition > 36) {
        mPosition -= 36;
        IncrementYear();
        IncreaseMotivation(250);
        std::cout << mName << " attends Welcome Week and starts year " << mYear << " more motivated!" << std::endl;
    }
}

void CPlayer::IncreaseMotivation(int value) {
    mMotivation += value;
}

void CPlayer::IncrementYear() {
    mYear++;
}

void CPlayer::IncreaseSuccess(int value) {
    mSuccess += value;
}
