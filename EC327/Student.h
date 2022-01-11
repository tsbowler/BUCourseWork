#ifndef STUDENT_H
#define STUDENT_H
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include <string>

enum StudentStates {
    STOPPED            = 0,
    MOVING             = 1,
    INFECTED           = 2,
    AT_DOCTORS         = 3,
    IN_CLASS           = 4,
    MOVING_TO_DOCTOR   = 5,
    MOVING_TO_CLASS    = 6,
    STUDYING_IN_CLASS    = 7,
    RECOVERING_ANTIBODIES = 8
};

class Student : public GameObject {
public:
    Student();
    Student(char in_code);
    Student(string name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    ~Student();
    void StartMoving(Point2D dest);
    void StartMovingToDoctor(DoctorsOffice* office);
    void StartMovingToClass(ClassRoom* classr);
    void StartLearning(unsigned int num_assignments);
    void StartRecoveringAntibodies(
            unsigned int num_vaccines);
    void Stop();
    void ShowStatus();
    bool Update();
    string GetName();
    bool IsInfected();
    bool ShouldBeVisible();

protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);
private:
    double speed;
    Vector2D delta;
    Point2D destination;
//protected:
    double dollars;
    unsigned int credits;
    bool is_in_class;
    bool is_at_doctor;
    unsigned int antibodies;
    unsigned int assignments_to_buy;
    unsigned int vaccines_to_buy;
    DoctorsOffice* current_office;
    ClassRoom* current_class;
    string name;
};
static double GetRandomAmountOfDollars();
#endif
