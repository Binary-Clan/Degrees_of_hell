//
// Created by Sudharaka Fernando on 22/03/2024.
//

#ifndef DEGREES_OF_HELL_CPLAYER_H
#define DEGREES_OF_HELL_CPLAYER_H

#include <string>

class CPlayer {
private:
    std::string mName;
    int mMotivation;
    int mSuccess;
    int mPosition;
    int mYear;

public:
    CPlayer(const std::string& name);
    std::string GetName() const;
    int GetMotivation() const;
    int GetSuccess() const;
    int GetPosition() const;
    int GetYear() const;
    void Spin();
    void Move(int spaces);
    void IncreaseMotivation(int value);
    void DecreaseMotivation(int value);
    void IncrementYear();
    int GetSpin();
};


#endif //DEGREES_OF_HELL_CPLAYER_H
