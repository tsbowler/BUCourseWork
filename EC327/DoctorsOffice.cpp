#include <iostream>
#include "DoctorsOffice.h"

using namespace std;

DoctorsOffice::DoctorsOffice(): Building('D', 0, Point2D(0.0, 0.0) ) {
    this->state = VACCINE_AVAILABLE;
    this->vaccine_capacity = 100;
    this->num_vaccine_remaining = vaccine_capacity;
    this->dollar_cost_per_vaccine = 5;
    cout << "DoctorsOffice default constructed. " << endl;
}


DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost,
        unsigned int vaccine_capacity, Point2D in_loc) : Building('D', in_id, in_loc) {
    this->vaccine_capacity = vaccine_capacity;
    this->num_vaccine_remaining = vaccine_capacity;
    this->dollar_cost_per_vaccine = vaccine_cost;
    this->state = VACCINE_AVAILABLE;
    cout << "DoctorsOffice constructed. " << endl;
}

bool DoctorsOffice::Update() {
    if (num_vaccine_remaining == 0 && state == VACCINE_AVAILABLE) {
        state = NO_VACCINE_AVAILABLE;
        display_code = 'd';
        cout << "DoctorsOffice " << GetId() << " has ran out of vaccine." << endl;
        return true;
    }
    return false;
}

DoctorsOffice::~DoctorsOffice() {
    cout << "DoctorsOffice destructed. " << endl;
}

unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed) {
    unsigned int vaccine = 0;
    if (num_vaccine_remaining >= vaccine_needed) {
        vaccine = vaccine_needed;
        num_vaccine_remaining -= vaccine_needed;
    } else {
        vaccine = num_vaccine_remaining;
        num_vaccine_remaining = 0;
    }
    return vaccine;
}

void DoctorsOffice::ShowStatus() {
    cout << "DoctorsOffice Status: ";
    Building::ShowStatus();
    cout << "\tDollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "\thas " << num_vaccine_remaining << " vaccine(s) remaining" << endl;
}

bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget) {
    return budget >= GetDollarCost(vaccine);
}

double DoctorsOffice::GetDollarCost(unsigned vaccine) {
    return vaccine * dollar_cost_per_vaccine;
}

bool DoctorsOffice::HasVaccine() {
    return num_vaccine_remaining > 0;
}

unsigned int DoctorsOffice::GetNumVaccineRemaining() {
    return num_vaccine_remaining;
}


