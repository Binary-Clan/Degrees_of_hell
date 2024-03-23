// CSpace.h
#ifndef DEGREES_OF_HELL_CSPACE_H
#define DEGREES_OF_HELL_CSPACE_H

#include <string>

class CSpace {
private:
    int mType;
    std::string mName;

public:
    CSpace(int type, const std::string& name);
    virtual ~CSpace();
    int GetType() const;
    std::string GetName() const;
};

#endif //DEGREES_OF_HELL_CSPACE_H
