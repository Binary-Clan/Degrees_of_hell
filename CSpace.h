//
// Created by Sudharaka Fernando on 22/03/2024.
//

#ifndef DEGREES_OF_HELL_CSPACE_H
#define DEGREES_OF_HELL_CSPACE_H

#include <string>

class CSpace {
private:
    int mType;
    std::string mName;

public:
    CSpace(int type, const std::string& name);
    int getType() const;
    std::string getName() const;
};

#endif //DEGREES_OF_HELL_CSPACE_H
