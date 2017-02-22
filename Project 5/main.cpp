#include "Student.h"


int main()
{
	ifstream in("grades.txt");
	Student s;
	string first, last;
	int attendance;
	double midterm, finalExam, grade;

	string header;

	getline( in, header, ':' );
	while( !in.fail() )
	{
		if ( header == "Name" )
		{
			cout << "Reading name: ";
			getline( in, first, '\t' );
			getline( in, last );
			cout << first << "\t" << last << "\n";
			s = Student( last, first );//cheat to set the first and last name	
		}
		else if ( header == "Attendance"  )
		{
			cout << "Reading attendance: ";
			in >> attendance;
			s.setAttendance(attendance);
			cout << attendance << '\n';
			in.ignore( 200, '\n' );
		}
		else if ( header == "Midterm" )
		{
			cout << "Reading midterm: ";
			in >> midterm;
			s.setMidtermGrade(midterm);
			cout << midterm << '\n';
			in.ignore( 200, '\n' );
		}
		else if ( header == "Final" )
		{
			cout << "Reading final: ";
			in >> finalExam;
			s.setFinalExam(finalExam);
			cout << finalExam << '\n';
			in.ignore( 200, '\n' );
		}
		else if ( header == "HWs" )
		{
			cout << "Reading HWs: ";
			while( in.peek() != '\n' )
			{
				in >> grade;
				s.addHWGrade(grade);
				cout << grade << '\t';
			}
			cout << '\n';
			in.ignore( 200, '\n' );
		}
		else if ( header == "Projects" )
		{
			cout << "Reading Projects: ";
			while( in.peek() != '\n' )
			{
				in >> grade;
				s.addProjectGrade(grade);
				cout << grade << '\t';
			}
			cout << '\n';
			in.ignore( 200, '\n' );
		}
		else
		{
			cout << "Boo, I don't know this: '" << header << "'" << endl;
		}
		getline( in, header, ':' );
	}
	cout << endl << "Grades:\n";
	s.displayGrades(cout);
	cout << '\n';

}
