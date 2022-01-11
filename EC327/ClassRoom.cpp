#include <iostream>
#include "Building.h"
#include "ClassRoom.h"
using namespace std;

ClassRoom::ClassRoom(): Building('C', 0, Point2D(0.0, 0.0)) {
    state = NOT_PASSED;
    max_number_of_assignments = 10;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = 1;
    dollar_cost_per_assignment = 1.0;
    credits_per_assignment = 2;
    cout << "ClassRoom default constructed. " << endl;
}

ClassRoom::ClassRoom(unsigned int max_assign,
                       unsigned int antibody_cost, double dollar_cost,
                       unsigned int crd_per_training, int in_id,
                       Point2D point2d): Building('C', in_id, point2d) {
    state = NOT_PASSED;
    max_number_of_assignments = max_assign;
    num_assignments_remaining = max_assign;
    antibody_cost_per_assignment = antibody_cost;
    dollar_cost_per_assignment = dollar_cost;
    credits_per_assignment = crd_per_training;
    cout << "ClassRoom constructed. " << endl;
}

bool ClassRoom::Update() {
    if (state == NOT_PASSED && num_assignments_remaining == 0) {
        state = PASSED; // current_classroom closes when finish all assignments
        display_code = 'c';
        cout << display_code << GetId() << " has been passed" << endl;
        return true;
    }
    return false;
}

void ClassRoom::ShowStatus() {
    cout << "ClassRoom Status: ";
    Building::ShowStatus();
    cout << "\tMax number of assignments: " << max_number_of_assignments << endl;
    cout << "\tAntibody cost per assignment: " << antibody_cost_per_assignment << endl;
    cout << "\tDollar cost per assignment: " << dollar_cost_per_assignment << endl;
    cout << "\tCredits per assignment: " << credits_per_assignment << endl;
    cout << "\t" << num_assignments_remaining << " assignment(s) are remaining for this ClassRoom" << endl;
}

ClassRoom::~ClassRoom() {
    cout << "ClassRoom destructed. " << endl;
}

double ClassRoom::GetDollarCost(unsigned int unit_qty) {
    return unit_qty * dollar_cost_per_assignment;
}

unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty) {
    return unit_qty * antibody_cost_per_assignment;
}

unsigned int ClassRoom::GetMaxAllowableAssignments(double budget, unsigned int antibodies) {
    // TODO: check for division by zero
    unsigned int cost_by_antibodies = antibodies / antibody_cost_per_assignment;
    unsigned int cost_by_budget = (int)(budget / dollar_cost_per_assignment);
    unsigned int allowable_assignments = min(cost_by_budget, cost_by_antibodies);
    return allowable_assignments;
}


unsigned int ClassRoom::TrainStudents(unsigned int assignment_units) {
    unsigned int credits = 0;
    if (num_assignments_remaining >= assignment_units) {
        credits = assignment_units * credits_per_assignment;
        num_assignments_remaining -= assignment_units;
    } else {
        credits = num_assignments_remaining * credits_per_assignment;
        num_assignments_remaining = 0;
    }
    return credits;
}

bool ClassRoom::HasEnoughAssignments (unsigned int assignment_units) {
    return num_assignments_remaining >= assignment_units;
}

bool ClassRoom::IsAbleToLearn(unsigned int unit_qty,
        double budget, unsigned int antibodies) {
    return GetMaxAllowableAssignments(budget, antibodies) >= unit_qty;
}

bool ClassRoom::passed() {
    return num_assignments_remaining == 0;
}

unsigned int ClassRoom::GetNumAssignmentsRemaining() {
    return num_assignments_remaining;
}




