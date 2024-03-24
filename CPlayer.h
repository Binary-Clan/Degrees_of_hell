// CPlayer.h

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
    void SetPosition(int position);
    int GetPosition() const;
    int GetYear() const;
    void Spin();
    void Move(int spaces);
    void IncreaseMotivation(int value);
    void DecreaseMotivation(int value);
    void IncrementYear();
    void IncreaseSuccess(int value); // Added method
    bool IsActivityCompleted();
    int GetSpin();
};


    void SetActivityCompleted(bool b);
};

#endif //DEGREES_OF_HELL_CPLAYER_H
