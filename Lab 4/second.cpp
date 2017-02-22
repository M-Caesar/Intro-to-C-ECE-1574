#include "calculate.h"
using namespace std;
void calculate( istream& in, ostream& out )

{
    double answer;
    int degrees;
    double radians;
    string name;

in >> name;
in >> degrees;
radians = ( degrees * M_PI / 180.0 );

	while ( !in.fail() )
	{
		if (name == "Sin" || name == "sin" || name == "Sine" || name == "sine")
		{
		
		answer = sin (radians);


		

		}
		else if (name == "Cos" || name == "cos" || name == "Cosine" || name == "cosine")
        {
		answer = cos (radians);


		}

		in >> name;
		in >> degrees;
		radians = ( degrees * M_PI / 180.0 );

	}




		out << "The answer to the degree " << degrees << " of the trigonometric operator " << name << " is: \n";
}