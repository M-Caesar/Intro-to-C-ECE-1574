#include "compute.h"

using namespace std;
void compute ( istream& in, ostream& out )

{
string oper;
string symbol;
int number1;
int number2;
double answer;

cout << "What is the operation?\n";
in >> oper;

cout << endl << "What is the first number? \n";

in >> number1;

cout << endl << "What is the second number? \n";

in >> number2;
out << "Operand1 \t" << "Operation \t" << "Operand2 \t" << "Answer \t" << endl;

while ( !in.fail() )
{
	if ( oper == "add" || oper == "Add")
	{
		answer = number1 + number2;
        
        symbol = "+";

	}
	else if ( oper == "subtract" || oper == "Subtract")
	{
		answer = number1 - number2;
		symbol = "-";

	}
	else if ( oper == "multiply" || oper == "Multiply")
	{
		answer = number1 * number2;
		symbol = "*";
	}
	else if ( oper == "divide" || oper == "Divide")
	{
		answer = (number1 / number2);
		symbol = "/";
	}
	else if ( oper == "remainder" || oper == "Remainder")
	{
		answer = number1 % number2;
		symbol = "%";
	}

	
	out << number1 << "\t" << "\t" << "\t" << symbol << "\t" << "\t" << "\t" << number2 << "\t" << "\t" << "\t"  << answer << endl;

	in >> oper;
	in >> number1;
	in >> number2;

	
}



}