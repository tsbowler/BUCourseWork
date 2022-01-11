//File for checkpoint 1 in PA3
//EC327 Fall 2021

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"

using namespace std;


/*
Start by writing the Point2D and Vector2D classes and a couple of their functions. Add the additional functions one at a time and test each one. Write a TestCheckpoint1.cpp file with a main function to test them. There, create multiple Point2D and Vector2D objects in order to test their constructors and overloaded operators (<<, +, -, *, /). Getting the overloaded output operator to work soon will make testing the remaining functions more fun. Create GameObject and instantiate a few cases in your main function and run the ShowStatus() function. Convince yourself that the objects have been created correctly and that their member variables have the right values.
*/

int main()
{
	cout << "Checkpoint 1" << endl;
	
	Point2D pnt1,
		pnt2(3.5,5.8),
		pnt3(1.2,1.8);


	Vector2D vec1,
		vec2(8.8,2.0);

	cout << pnt1 << ", " << pnt2 << ", " << vec1 << ", " << vec2 << ", " << pnt3 << endl;

	vec2 = pnt2-pnt3;
	vec1 = vec2/2.2;

	cout << pnt1 << ", " << pnt2 << ", " << vec1 << ", " << vec2 << ", " << endl;
	
	pnt1 = pnt2+vec2;
	vec1 = vec2*5.7;
	double dist = GetDistanceBetween(pnt1,pnt2);

	cout << pnt1 << ", " << pnt2 << ", " << vec1 << ", " << vec2 << ", " << dist << endl;

	GameObject obj1('A');
	GameObject obj2(pnt1, 3, 'B');
	GameObject obj3(pnt2, -1, 'Z');

	obj1.ShowStatus();
	obj2.ShowStatus();
	obj3.ShowStatus();

	return 0;
}
