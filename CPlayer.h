// CPlayer.h

#ifndef DEGREES_OF_HELL_CPLAYER_H
#define DEGREES_OF_HELL_CPLAYER_H

#include <string>
#include <vector>
#include <algorithm>
//#include "CSpace.h"

class CSpace;
class CAssessment;
class CPlayer {
private:
    std::string mName;
    int mMotivation;
    int mSuccess;
public:
    const std::vector<CAssessment *> &GetCompletedAssessments() const;

    void SetCompletedAssessments(const std::vector<CAssessment *> &completedAssessments);

private:
    int mPosition;
    int mYear;
    CSpace* currentSpace;
    std::vector<CAssessment*> completedAssessments;


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
    void SetActivityCompleted(bool b);
    void SetCurrentSpace(CSpace *currentSpace);
    CSpace *GetCurrentSpace() const;
    void AddCompletedAssessment(CAssessment* assessment) {
        completedAssessments.push_back(assessment);
    }

    void RemoveCompletedAssessment(CAssessment* assessment) {
        // Find the assessment in the vector
        auto it = std::find(completedAssessments.begin(), completedAssessments.end(), assessment);
        if (it != completedAssessments.end()) {
            // Erase the assessment from the vector
            completedAssessments.erase(it);
        }
    }

};

#endif //DEGREES_OF_HELL_CPLAYER_H
