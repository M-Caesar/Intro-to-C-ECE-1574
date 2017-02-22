#include "calculate.h"
using namespace std;
void calculate( istream& in, ostream& out )

{
string oper;
int degrees;
double radians; 
double answer;
double answer2;
double answer3;

in >> oper;
in >> degrees;

while ( !in.fail() )
{
	if ( oper == "sin" || oper == "Sin" )
	{
	radians = ( degrees * M_PI / 180.0 );
	answer = sin ( radians );
	out << "Operation \t" << "Angle \t" << "Answer \t" << endl;
	
	out << oper << "\t" << "\t" << degrees << "\t" << answer << "\t" << endl;
	}
	else if ( oper == "cos" || oper == "Cos" )
	{
	radians = ( degrees * M_PI / 180.0 );
	answer = cos ( radians ) ;
	out << "Operation \t" << "Angle \t" << "Answer \t" << endl;
	
	out << oper << "\t" << "\t" << degrees << "\t" << answer << "\t" << endl;
	}
	else if ( oper == "tan" || oper == "Tan" )
	{
	radians = ( degrees * M_PI / 180.0 );
	answer = tan ( radians );
	out << "Operation \t" << "Angle \t" << "Answer \t" << endl;
	
	out << oper << "\t" << "\t" << degrees << "\t" << answer << "\t" << endl;
	}
	in >> oper;
	in >> degrees;
}

//out << "Operation \n" << answer << endl  << answer << endl << answer 

}