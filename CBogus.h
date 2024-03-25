#ifndef DEGREES_OF_HELL_CBOGUS_H
#define DEGREES_OF_HELL_CBOGUS_H

#include "CSpace.h"
#include "CPlayer.h"
#include <vector>
#include <string>

class CBogus : public CSpace {
private:
    struct BogusInfo {
        std::string message;
        int loseMotivation;
    };
    static const std::vector<BogusInfo> boguses;

public:
    CBogus(int type, const std::string& name);
    virtual ~CBogus() {}
    virtual void PerformAction(CPlayer& player) override;
};

#endif //DEGREES_OF_HELL_CBOGUS_H
