//
// Created by Sudharaka Fernando on 22/03/2024.
//

#include "CPlayer.h"
#include <iostream>
#include "random.cpp"

CPlayer::CPlayer(const std::string& name) : mName(name), mMotivation(1000), mSuccess(0), mPosition(0), mYear(1) {}

std::string CPlayer::getName() const {
    return mName;
}

int CPlayer::getMotivation() const {
    return mMotivation;
}

int CPlayer::getSuccess() const {
    return mSuccess;
}

int CPlayer::getPosition() const {
    return mPosition;
}

int CPlayer::getYear() const {
    return mYear;
}

void CPlayer::spin() {
    // Simulating spinning, you can implement your own logic here
    // Generate a random number between 1 and 10
    int randomNumber = Random();
    // Output the spun number
    move(randomNumber);
    std::cout << mName << " spins " << randomNumber << std::endl;
    // Move the player based on the spun number, adjust this logic as per your requirement

}

void CPlayer::move(int spaces) {
    mPosition += spaces;
    if(mPosition>36) {
        mPosition = mPosition - 36;
        incrementYear();
        increaseMotivation(250);
        std::cout <<this->mName<<" attends Welcome Week and starts year "<< this->mYear<< " more motivated!" << std::endl;
    }

}

void CPlayer::increaseMotivation(int value) {
    mMotivation += value;
}

void CPlayer::incrementYear() {
    mYear++;
}

