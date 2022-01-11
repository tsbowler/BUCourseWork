#include "Building.h"

Building::Building() : GameObject('B') {
    student_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(char code, int id, Point2D loc) : GameObject(loc, id, code) {
    student_count = 0;
    cout << "Building constructed" << endl;
}

Building::~Building() {
    cout << "Building destructed" << endl;
}

void Building::AddOneStudent() {
    student_count += 1;
}

void Building::RemoveOneStudent() {
	student_count -= 1;
}

void Building::ShowStatus() {
    cout << display_code << GetId() << " located at " << location << endl;
    cout << "\t" << student_count << " Students " << (student_count == 1 ? "is" : "are")
         <<  " in this building" << endl;
}

bool Building::ShouldBeVisible() {
    return true;
}