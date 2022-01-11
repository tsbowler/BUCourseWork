#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Building.h"

enum ClassRoomStates {
    NOT_PASSED = 0,
    PASSED = 1
};

class ClassRoom: public Building {
public:
    ClassRoom();
    ~ClassRoom();
    ClassRoom(unsigned int max_assign,
               unsigned int antibody_cost, double dollar_cost,
               unsigned int crd_per_assignment, int in_id,
               Point2D point2d);
    bool Update();
    void ShowStatus();
    double GetDollarCost(unsigned int unit_qty);
    unsigned int GetAntibodyCost(unsigned int unit_qty);
    unsigned int TrainStudents(unsigned int assignment_units);
    // NOTE: this function is not required in the assignment`
    // returns the max number of assignments given 3 factors
    // budget: how many dollars a student has in their possession
    // antibodies: how many antibodies a student has remaining
    // num_credits_remaining: how many credits a student has left to get//CHECK!!
    unsigned int GetMaxAllowableAssignments(double budget, unsigned int antibodies);
    bool IsAbleToLearn(unsigned int unit_qty,
                 double budget, unsigned int antibodies);
    // NOTE: this function is not required in the assignment
    bool HasEnoughAssignments(unsigned int assignment_units);
    unsigned int GetNumAssignmentsRemaining();
    bool passed();


private:
    unsigned int max_number_of_assignments;
    unsigned int num_assignments_remaining;
    unsigned int antibody_cost_per_assignment;
    double dollar_cost_per_assignment;
    unsigned int credits_per_assignment;
};

#endif // CLASSROOM
