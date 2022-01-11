//File for checkpoint 1 in PA3
//EC327 Fall 2021

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"

using namespace std;


/*
Iteratively develop the Student class. Start implementing the class by only writing the constructors and  a  partial  form  of  the ShowStatus()  function;  leave  everything  else  out.  To  test  the  correct behavior, write another simple TestCheckpoint3.cpp file. In the main function, create aStudentobject, and call its ShowStatus() function. It should display the correct initial state of the objects, so you can verify if both the constructors and the ShowStatus() function work properly. Only then start  implementing  the StartMoving(), SetupDestination(),  and UpdateLocation() functions, and STOPPEDand MOVINGparts of the update and ShowStatus()functions. Change your trivial main function to call the StartMoving()function on your one Studentobject, showing its status, calling its Update()function, and showing its status again -it should be in a different  location!  Check  that  amount  moved  on  the  step  is  correct.  Put  in  a  few  more  calls  of update and see if the Studentstops like it should. With the help of DoctorsOfficeand ClassRoomobjects, you are able to train your Student and recover its antibodiesafter it becomes tired.
*/

int main()
{
	cout << "Checkpoint 3" << endl;
	
	Point2D pnt1,
		pnt2(3.5,5.8),
		pnt3(1.2,1.8);
	
	Student s1;
	Student s2('A');
	Student s3("Tom", 2, 'T', 1, pnt2);

	s1.ShowStatus();
	s2.ShowStatus();
	s3.ShowStatus();
	
	s3.StartMoving(pnt3);
	s3.ShowStatus();
	s3.Update();
	s3.ShowStatus();
	s3.Update();
	s3.Update();
	s3.Update();
	s3.Update();
	s3.ShowStatus();

	return 0;
}
