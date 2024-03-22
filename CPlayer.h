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
    std::string getName() const;
    int getMotivation() const;
    int getSuccess() const;
    int getPosition() const;
    int getYear() const;
    void spin();
    void move(int spaces);
    void increaseMotivation(int value);
    void incrementYear();
};


#endif //DEGREES_OF_HELL_CPLAYER_H
