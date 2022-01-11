#include "GameCommand.h"
#include <iostream>

void DoMoveCommand(Model& model, int student_id, Point2D p1) {
    if (model.GetStudentPtr(student_id) != 0) {
        cout << "Moving " << model.GetStudentPtr(student_id)->GetName()
             << " to " << p1 << endl;
        model.GetStudentPtr(student_id)->StartMoving(p1);
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoMoveToDoctorCommand(Model& model, int student_id, int office_id) {
    if (model.GetStudentPtr(student_id) != 0 && model.GetDoctorsOfficePtr(office_id) != 0) {
        cout << "Moving " << model.GetStudentPtr(student_id)->GetName()
             << " to doctors office " << office_id << endl;
        model.GetStudentPtr(student_id)->StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoMoveToClassCommand(Model& model, int student_id, int class_id) {
    if (model.GetStudentPtr(student_id) != 0 && model.GetClassRoomPtr(class_id) != 0) {
        cout << "Moving " << model.GetStudentPtr(student_id)->GetName()
             << " to class " << class_id << endl;
        model.GetStudentPtr(student_id)->StartMovingToClass(model.GetClassRoomPtr(class_id));
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoStopCommand(Model& model, int student_id) {
    if (model.GetStudentPtr(student_id) != 0) {
        cout << "Stopping " << model.GetStudentPtr(student_id)->GetName() << endl;
        model.GetStudentPtr(student_id)->Stop();
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoLearningCommand(Model& model, int student_id, unsigned int assignments) {
    if (model.GetStudentPtr(student_id) != 0) {
        cout << "Teaching " << model.GetStudentPtr(student_id)->GetName() << endl;
        model.GetStudentPtr(student_id)->StartLearning(assignments);
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs) {
    if (model.GetStudentPtr(student_id) != 0) {
        cout << "Recovering " << model.GetStudentPtr(student_id)->GetName() << "'s antibodies" << endl;
        model.GetStudentPtr(student_id)->StartRecoveringAntibodies(vaccine_needs);
    } else
        cout << "ERROR: Please enter a valid command!" << endl;
}

void DoGoCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event." << endl;
    int count = 0;
    bool event = false;
    while (count < 5 && !event) {
        event = model.Update();
        count++;
    }
    model.ShowStatus();
    model.Display(view);
}



