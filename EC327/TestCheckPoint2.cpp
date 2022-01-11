//File for checkpoint 2 in PA3
//EC327 Fall 2021

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"

using namespace std;

/*
Write the Building, ClassRoom and DoctorsOffice classes. To test these classes, also write a TestCheckpoint2.cpp. Instantiate multiple objects of these classes in the main function and test out their functions (e.g. Update(), DistributeVaccine(), AddOneStudent(), etc.) in order to ensure their proper behavior. For example, call each object’s ShowStatus() method after calling their Update() method.
*/

int main()
{
	cout << "Checkpoint 2" << endl;

	Point2D pnt1,
		pnt2(3.5,5.8),
		pnt3(1.2,1.8);

	Building b1,
		b2('T', 3, pnt2);

	b1.ShowStatus();
	b2.ShowStatus();

	b2.AddOneStudent();
	b2.AddOneStudent();
	
	b2.ShowStatus();
	
	b2.RemoveOneStudent();
	
	b2.ShowStatus();
//docoff test
	DoctorsOffice d1,
			d2(7, 1.5, 20, pnt3);

	
	d1.ShowStatus();
	d2.AddOneStudent();
	d2.ShowStatus();

	d1.DistributeVaccine(52);
	d2.DistributeVaccine(52);
	d1.Update();
	d2.Update();
	d2.Update();

	bool aff1 = d2.CanAffordVaccine(10, 10);
	bool aff2 = d2.CanAffordVaccine(10, 20);
	bool has1 = d1.HasVaccine();
	bool has2 = d2.HasVaccine();

	cout << aff1 << " " << aff2 << " " << has1 << " " << has2 << endl; //0 1 1 0
	d2.ShowStatus();
//class test
	ClassRoom c1,
		c2(56, 21, 31, 3, 11, pnt3);

	
	c1.ShowStatus();
	c2.AddOneStudent();
	c2.ShowStatus();

	bool abl1 = c1.IsAbleToLearn(3, 32.5, 100);
	bool abl2 = c2.IsAbleToLearn(3, 500, 60);
	bool abl3 = c2.IsAbleToLearn(3, 2, 69);
	bool abl4 = c2.IsAbleToLearn(60, 100, 100);

	cout << abl1 << " " << abl2 << " " << abl3 << " " << abl4 << endl; //1 0 0 0

	unsigned cred1 = c1.TrainStudents(9);
	unsigned cred2 = c2.TrainStudents(60);

	c1.Update();
	c2.Update();
	c1.Update();
	c2.Update();

	c1.ShowStatus();
	c2.AddOneStudent();
	c2.ShowStatus();
	
	return 0;
}
