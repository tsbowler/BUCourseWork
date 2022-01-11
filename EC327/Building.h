#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"

class Building : public GameObject {
public:
    Building();
    Building(char code, int id, Point2D in_loc);
    ~Building();
    void AddOneStudent();
    void RemoveOneStudent();
    void ShowStatus();
    bool ShouldBeVisible();
private:
    unsigned int student_count;
};
#endif
