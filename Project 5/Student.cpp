#include "Student.h"
// 'include' the Student.h file into this cpp so I can use anything in there
// including all the standard libraries



Student::Student(string last, string first)
// using my class Student and a function
{
	this->last=last;
	// the last name 'here' will be the same as the last name 'there'
	this->first=first;
	// the first name 'here' will be the exact same as the first name 'there'

	hwCount = 0;
	// initializes hwcount to 0
	projectCount = 0;
	// initializes projectcount to 0
	attendance = 0;
	// initializes attendance to 0
	midterm = 0;
	//initializes midterm to 0
	finalExam = 0; 
	// initializes final exam to 0

}


void Student::addHWGrade (double newGrade)
// a function that also gets data from class Student so one can add the grade that it passes in
{
	if (hwCount < HW_SIZE)
		// if statement makes sure that there is space in the array to add the grade
	{
		hwGrades[hwCount] = newGrade;
		// the new grade will be stored in the array at location hwCount of hwGrade
		hwCount++;
		// makes hwCout larger each time so it re-iterates until all the space is gone
	}


}
void Student::addProjectGrade (double newGrade)
// a function that gets data from class Student that will get newGrade passed in
{
	if (projectCount < PROJ_SIZE)
	// if statement makes sure that there is space in the array to add the grade

	{
		projectGrades[projectCount] = newGrade;
		// the new grade will be stored in location projectCount of array projectGrades
		projectCount++;
		// increases the count so it loops
	}

}
 
void Student::setAttendance (double attendance)
// another function using the student class that gets an attendance value
{
	this->attendance = attendance;
	// this makes the functional passing in value for attendance the same one as 'our' attendance

}
 
void Student::setMidtermGrade (double midterm)
// a function using student class that passes in a midterm grade
{
	this->midterm = midterm;
	// this makes the functional passing in value for midterm grade the same one as 'our' midterm grade

}
 
void Student::setFinalExam (double finalExam)
// a function using student class that passes in the final exam grade
{
	this->finalExam = finalExam;
	// this makes the functional passing in value for final the same one as 'our' final

}
 
double Student::getAverage () const
// a function that isn't 'void' in return of constant value. It also has access to the student class. 
{

//--attendance calculation--------------------------------------------------------

	double ATd = 0;
	// initializes ATd that holds the grade for the attendance
		

	ATd = attendance / 10.0;
	// calculation of Attendance divided by 10 is thus ATd

	double AttendanceFinal =0;
	// initializes a double to get the final grade which is based on weight

	AttendanceFinal =ATd * .05;

	// final attendce being the calculated attendance average multiplied by the weight

// -- HW calculation--------------------------------------------------------
	double totalHW = 0;
	// initializes a variable to store the totalHW grade 

	for (int i = 0; i < hwCount; i++)
	{
		totalHW = totalHW + hwGrades[i];
		// Adds up all the HW grades
	}
	// the loop adds up the total home work grade by using a for loop on the array

	double totalHWt = 0;
	// initializes a variable to store the value denomnator that is an x00 number.

	totalHWt=(hwCount)*100;
	// totalHWt will calculate the X00 number such as 500 or 400 that the total will divide by. 
	//Since count starts at 0, there needs to be a +1 before being multiplied by 100

	double HWfinal = 0;
	// initializes a variable to store the final score before the weight

	HWfinal=totalHW/totalHWt;

	// the HW average itself is thus the total homework of the student divided by the x00 number 

	double Hwpercent=0;
	// initializes a variable to store the final grade amount that will be added later

	Hwpercent=HWfinal *.15;

	// the final percent is the HW average multiplied by the weight

// Project Calculation--------------------------------------------------------
	double totalproj =0;
	// initializes a variable to store the total project grade
	
	for (int i = 0; i < projectCount; i++)
	{
		totalproj = totalproj + projectGrades[i];
		// adds up all the project grades
	}
	// the loop adds up the total project work grade by using a for loop on the array

	double totalprojt= 0;
	// initializes a variable to store the project grade in x00 format

	totalprojt= (projectCount)*100;

	// totalprojt will calculate the X00 number such as 500 or 400 that the total will divide by. 
	//Since count starts at 0, there needs to be a +1 before being multiplied by 100
	double Projfinal=0;
	// initializes a variable to store the final grade before weight

	Projfinal=totalproj/totalprojt;
	// the project average itself is thus the total project grade of the student divided by the x00 number 


	double projpercent=0;
	// initializes a variable to store the final final grade that includes weight

	projpercent=Projfinal *.4;

	// the final percent is the project average multiplied by the weight


// - Midterm calculation-----------------------------------------------------------------

	double midtermpercent=0;
	// initializes a variable to store the midterm grade post weight

	midtermpercent=(midterm / 100) *.2;

	// the mid term calculation is just the one grade itself divided by 100 and then multiplied by the weight

// - Final test calculation--------------------------------------------------------

	double finalpercent=0;
	// initializes a variable to store the final grade post weight

	finalpercent=(finalExam / 100) *.2;

	// the final exam calculation is just the one grade itself divided by 100 and then multiplied by the weight


// Final average calc--------------------------------------------------------------------

	double totalfinalfinal = 0;
	// initializes a variable to store the final percentages together to add it all up

	totalfinalfinal=(finalpercent + midtermpercent + projpercent + Hwpercent + AttendanceFinal)*100;

	// this here adds up all the percent weights of the class and multiplies it by 100

	return totalfinalfinal;
	// function will return the value whenever it is called. 

}
 
string Student::getLastName () const
// function that is a string that will return something
{
	return last;

	// the last name is just the last name, so any time it is called, it will just return last.

}
 
string Student::getFirstName () const
// function that is a string that will return something
{
	return first;

	// the first name is just the first name unmodified, so it'll just return this. 

}
 
void Student::displayGrades (ostream &out) const
// function that will take in the output stream 'out' to display grades
{

	out << "Name: " << last << ", " <<first << endl;
	// outputs the name

	out << "Attendance: " << attendance << endl;
	// outputs the attendance

	out << "Midterm: " << midterm << endl;
	// outputs the midterm grade

	out << "Final: " << finalExam << endl;
	// outputs the final

	// The above are just ordinary outputs

	out<< "HWs: ";
	for (int i = 0; i < hwCount; i++)
		// runs through HW count
	{
		out << hwGrades[i];

		if (i < hwCount-1)
		{
			out << ", ";
		}
		// adss the comma to the grade count
		 
	}
	out << "\n";
	// new line char

	out << "Projects: ";
	for (int i = 0; i < projectCount; i++)
	{
		out << projectGrades[i];
		// outputs the project grade
		if (i < projectCount-1)
		{
			out << ", ";
		}
		// adds the comma to the project count
		
	}

	// the above with the for loops use it so that the grades will be outputed one by one until
	// the array is exhausted. This is determined using the count we kept track of.
	// There is an dditional if loop that will output the comma necessary. 
	// this loop is needed or else an extra comma will be outputed in the ostream

	out << "\n";
	// new line

	out << "Average: " << getAverage() <<"0";
	// the Average output will call the getAverage function and have it return a value
	// the additional "0" adds the extra decimal value onto it for presentation as setprecision
	// didn't work too well here. 



	
}