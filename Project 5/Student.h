#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>
// Above is all the #includes that I use. These call for pre-designated libraries in the C++ default lib
// and will allow me to use more code functions and variables. 
using namespace std;
// gives me access to all the 'named' variables that C++ has

#ifndef __Student__
// if student isn't defined, then define it. 
#define __Student__
// define the student so that my student.cpp knows what the student is what it calls it


const int HW_SIZE = 20;
// sets a global constant integer for 20. Later this will be the size of the HW array
const int PROJ_SIZE = 5;
// sets a global constant integer for 5. This later will be the size of the Proj array

class Student
// defines a class called Student
{
private:
	// Student will have private variables defined here that can't be easilly modified

	string last;
	string first;
	// strings for the first and last name

	double hwGrades[HW_SIZE];

	// makes an array for the hw grades
	int hwCount;
	// count for the hw grades
	double projectGrades[PROJ_SIZE];
	// makes an array for the project grades
	int projectCount;
	// count for the project

	double attendance;
	// a number initialization for attendance
	double midterm;
	// number for midterm
	double finalExam;
	// number for final
	
	// the above are just one numerber that will be held as those scores/attendance are just one value. 

	// All the above are private local variables that Student has access to and will be initialized 
	// with a value later

public:
	// thsee will be public functions that 'can' be modified. 

	Student(string last="", string first="");
	// initializing last and first to be what it 'is' later on

	void addHWGrade (double newGrade);

	// this function will allow me to add all the HW grades together when I call it later

 	void addProjectGrade (double newGrade);

 	// this function will allow me to add all the project grades together when I call it later
 
	void setAttendance (double attendance);

	// this function will allow me to return the attendance number to be exactly that, the number it reads in. 
 
	void setMidtermGrade (double midterm);

	// this function will allow me to return the midterm grade that is exactly the grade that will be used.
 
	void setFinalExam (double finalExam);

	// this function will allow me to return exactly the single number final exam grade. 
 
	double getAverage () const;

	// a function will compute the average for everything
 
	string getLastName () const;

	// a function that will return exactly the last name
 
	string getFirstName () const;

	// a function that will return exactly the first name
 
	void displayGrades (ostream &out) const;

	// the output for being able to display to the terminal and webcat giving it output streaming 'out'

};

#endif /* defined(__Fall14Project5__Student__) */
// end definition for the student