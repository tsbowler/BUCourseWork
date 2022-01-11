#include "Model.h"
#include "GameObject.h"
#include "Student.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "View.h"
#include <cstdlib>
#include <iostream>
#include <string>

Model::Model() {
    time = 0;
    //Student 1
    student_ptrs[0] = new Student("Homer", 1, 'S', 2.0, Point2D(5, 1));
    object_ptrs[0] = student_ptrs[0];
    //Student 2
    student_ptrs[1] = new Student("Marge", 2, 'S', 1.0, Point2D(10, 1));
    object_ptrs[1] = student_ptrs[1];
    //DoctorsOffice 1
    office_ptrs[0] = new DoctorsOffice(1, 1, 100, Point2D(1, 20));
    object_ptrs[2] = office_ptrs[0];
    //DoctorsOffice 2
    office_ptrs[1] = new DoctorsOffice(2, 2, 200,  Point2D(10, 20));
    object_ptrs[3] = office_ptrs[1];
    //ClassRoom
    class_ptrs[0] = new ClassRoom(10, 1.0,
                                 2.0, 3, 1, Point2D(0, 0));
    object_ptrs[4] = class_ptrs[0];
    class_ptrs[1] = new ClassRoom(20, 5,
                                 7.5, 8, 2, Point2D(5, 5));
    object_ptrs[5] = class_ptrs[1];
/*
    virus_ptrs[0] = new Virus("Virus1", 4, 1, 16, false, 1, Point2D(10, 12));
    object_ptrs[6] = virus_ptrs[0];

    virus_ptrs[1] = new Virus("Virus2", 6, 3, 8, false, 2, Point2D(15, 5));
    object_ptrs[7] = virus_ptrs[1];
*/
    num_objects = 6;//8
    num_students = 2;
    num_offices = 2;
    num_classes = 2;
    //num_virus = 2;

    cout << "Model default constructed. " << endl;
}

Model::~Model() {
    for (int i = 0; i < num_objects; i++) {
        delete object_ptrs[i];
    }
    cout << "Model destructed. " << endl;
}

Student *Model::GetStudentPtr(int id) {
    for (int i = 0; i < num_students; i++) {
        if (id == student_ptrs[i]->GetId()) {
            return student_ptrs[i];
        }
    }
    return 0;
}

DoctorsOffice *Model::GetDoctorsOfficePtr(int id) {
    for (int i = 0; i < num_offices; i++) {
        if (id == office_ptrs[i]->GetId()) {
            return office_ptrs[i];
        }
    }
    return 0;
}

ClassRoom *Model::GetClassRoomPtr(int id) {
    for (int i = 0; i < num_classes; i++) {
        if (id == class_ptrs[i]->GetId()) {
            return class_ptrs[i];
        }
    }
    return 0;
}

bool Model::Update() {
    time++;
    int classes_passed = 0;
    int students_infected = 0;
    //Calculating number of classes passed
    if (classes_passed != num_classes) {
        for (int i = 0; i < num_classes; i++) {
            if (class_ptrs[i]->GetState() == PASSED)
                classes_passed++;
        }
    }
    // Calculating number of students that are infrected
    if (students_infected != num_students) {
        for (int i = 0; i < num_students; i++) {
            if (student_ptrs[i]->IsInfected())
                students_infected++;
        }
    }
    bool event = false;
    // continue to update all
    if (classes_passed == num_classes) {
        cout << "GAME OVER: You win! All assigments done!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (students_infected == num_students) {
        cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
        exit(EXIT_SUCCESS);
    }
    // update if winning condition is not met
    for (int i = 0; i < num_objects; i++) {
        bool temp = object_ptrs[i]->Update();
        if (temp) {
            event = temp;
        }
    }
    return event;
}

void Model::Display(View &view) {
    view.Clear();
    for (int i = 0; i < num_objects; i++) {
        if (object_ptrs[i]->ShouldBeVisible()) {
            view.Plot(object_ptrs[i]);
        }
    }
    view.Draw();
}

void Model::ShowStatus() {
    cout << "Time: " << time << endl;
    for (int i = 0; i < num_objects; i++) {
        object_ptrs[i]->ShowStatus();
    }
}
