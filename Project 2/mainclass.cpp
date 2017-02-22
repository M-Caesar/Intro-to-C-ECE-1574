#include <iostream>
#include <cctype>

using namespace std;

int main()

{

	char c;

	c = cin.peek(); //look at the next character

	while( !cin.fail())
	{
		if (isalpha(c) && c == 'p' || c == 'P')// will look at c, will return true if it is an alphabetic letter.
												// Then check if lower or uppercase p. Character is a letter so single quote
												// string is always double quote as as many characters
		{
			// go call some function when this happens. 
			// passing in the information. 

			//below won't work

			cin.get();


		}
		else
		{
			// go call soething else

			cin.get();
		}

		while ( isspace(cin.peek())) // eat white space 
			cin.get();




		c = cin.peek();
	}
}