// CPlayer.h

#ifndef DEGREES_OF_HELL_CPLAYER_H
#define DEGREES_OF_HELL_CPLAYER_H

#include <string>
#include <vector>
#include <algorithm>
#include <utility>

class CSpace;
class CAssessment;
class CPlayer {
private:
    std::string mName;
    int mMotivation;
    int mSuccess;
    int mPosition;
    int mYear;
    bool mIsActive;
    CSpace* currentSpace;
    std::vector<std::pair<int, CAssessment*>> completedAssessments;
    std::vector<CAssessment*> deferredAssessments;

public:
    const std::vector<CAssessment *> &GetCompletedAssessments() const;

    void SetCompletedAssessments(const std::vector<CAssessment *> &completedAssessments);

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
    void DecreaseSuccess(int value);
    bool IsActivityCompleted();
    int GetSpin();
    void SetActivityCompleted(bool b);
    void SetCurrentSpace(CSpace *currentSpace);
    CSpace *GetCurrentSpace() const;
    void AddCompletedAssessment(int year, CAssessment* assessment);
    void RemoveCompletedAssessment(CAssessment* assessment);
    bool CanAdvanceToNextYear() const ;
    bool HasGraduated() const ;
    void CheckAndHandleMotivation();
    void DeferAssessment(CAssessment* assessment);
    void CompleteDeferredAssessment();
    bool HasNegativeMotivation() const { return mMotivation < 0; }
    void QuitGame(); // Method to handle quitting
    bool IsActive() const { return mIsActive; }
};

#endif //DEGREES_OF_HELL_CPLAYER_H