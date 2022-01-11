#ifndef DOCTORSOFFICE_H
#define DOCTORSOFFICE_H
#include "Building.h"

enum DoctorsOfficeStates {
    VACCINE_AVAILABLE = 0,
    NO_VACCINE_AVAILABLE = 1
};

class DoctorsOffice: public Building {
public:
    DoctorsOffice();
    DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_capacity, Point2D in_loc);
    ~DoctorsOffice();
    unsigned int DistributeVaccine(unsigned int points_needed=1);
    bool Update();
    void ShowStatus();
    double GetDollarCost(unsigned vaccine);
    bool HasVaccine();
    unsigned int GetNumVaccineRemaining();
    bool CanAffordVaccine(unsigned int vaccine, double budget);
private:
    double dollar_cost_per_vaccine;
    unsigned int vaccine_capacity;
    unsigned int num_vaccine_remaining;
};
#endif
