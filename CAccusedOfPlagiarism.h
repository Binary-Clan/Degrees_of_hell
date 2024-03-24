#ifndef DEGREES_OF_HELL_CACCUSEDOFPLAGIARISM_H
#define DEGREES_OF_HELL_CACCUSEDOFPLAGIARISM_H

#include "CSpace.h"

class CAccusedOfPlagiarism : public CSpace {
public:
    CAccusedOfPlagiarism(int type, const std::string& name);
    ~CAccusedOfPlagiarism() override;
    void PerformAction(CPlayer& player) override;
};

#endif // DEGREES_OF_HELL_CACCUSEDOFPLAGIARISM_H
