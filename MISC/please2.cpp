#include "resist.h"
using namespace std;

void computeResistance( istream& in, ostream& out )


{

	string name;

	double results = 0; // the result for series
	double resultp = 0; // the result for parallel
	double finals = 0; // the final value for series
	double finalp = 0; // the final value for parallel

	string path;

	//string input;
	//double resistor = 0;

	double answer;


	double two = 0;
	double total;

	//cout << "Please tell me if this is Parallel or Serial: \n"; // outputs a cout that won't be read by webcat but for user
	//cin >> name; //this will read the word of parallel or series to identify the true calculation
	
	

	//cout << endl << "Please tell me the resistor value(s): \n"; // outputs a cout that won't be read by webcat but for user
	//cin >> resistor; //prime that inputs a value for resistor

	//in >> initial;
	
	char c;

	while (isspace(in.peek())) //eat whitespace
			in.get();
	c = in.peek(); //look at the next character
	

	while( !in.fail())
	{
		if (isalpha(c) && (c == 'p' || c == 'P'))
		{
		finalp = parallel(in, path);
		path = path + " in parallel ";
		resultp = resultp + finalp;

		//two = 1.0/finalp;
		

		//out << "The answer p is " << two << endl;
		}


			
		else //if ((isalpha(c) && (c == 's' || c == 'S') )|| isdigit(c))
		{

		finals = series(in, path);
		path = path + " in series ";
		results = results + finals;

		
		//out << "The answer s is " << result << endl;
		}

		while (isspace(in.peek())) //eat whitespace
			in.get();

		if (!in.fail())
			path = path + " with ";
		
		c = in.peek();

		
	}
out <<"Equivalent Resistance: \n" // outputs a cout that won't be read by webcat but for user
	<< "Total Equivalent Resistance " << (results + resultp )  // just cout statements that have the 'name' setup.
	<< "\nResistor Path: Resistors " << path << endl;

}
	double series(istream& in, string &path)
	{
		char c = in.peek();
		if (isalpha(c))
			in.get();
		while (isspace(in.peek()))
			in.get();
		c = in.peek();
		double result =0;
		double final=0;
		while (!in.fail() && !isalpha(c))
		{
			char buffer[50];

			in >> result;


			final = final + result;

			sprintf(buffer, "%f", result);

			path = path + " " + string(buffer);
			while (isspace(in.peek()))
				in.get();
            c= in.peek();
		}
		return final;
	}


	

	double parallel(istream& in, string &path)
	{
		char c = in.peek();
		if (isalpha(c))
			in.get();
		while (isspace(in.peek()))
			in.get();
		c = in.peek();
		double result=0;
		double final=0;
		while (!in.fail() && !isalpha(c))
		{
			char buffer[50];

			in >> result;


			final = final + 1.0/result;

			sprintf(buffer, "%f", result);

			path = path + " " + string(buffer);
			while (isspace(in.peek()))
				in.get();

			c = in.peek();
		}
		return 1/final;
	}
	
	



/*
	string series(string input)
	{
		char c = cin.peek(); 

		while (isspace( cin.peek() ) )
		{
			cin.get();

			if ( isalpha(c) )
			{
				cin.get();
			}
			
		}


		double resistor;
		double answer;
        string path;

		
		while (!cin.fail() && !isalpha(c))
		{
			char buffer[50]; //gives space for 50 characters. Long enough
			cin >> resistor;

			answer = answer + resistor;
			
			sprintf(buffer, "%f", answer); // take the double, use the floating point format, and stick it into the buffer. 
			
			path = path + string(buffer);

			while (isspace( cin.peek()))
				cin.get();

		}

		return answer;

	}

	string parallel(string input)
	{
		char c = cin.peek(); 

		
		while (isspace( cin.peek()))
		{
			cin.get();

			if ( isalpha(c))
			{
				cin.get();
			}
			
		}
				


		double resistor;
		double answer;
		string path;
		while (!cin.fail() && !isalpha(c))
		{
			char buffer[50]; //gives space for 50 characters. Long enough
			cin >> resistor;

			answer = answer + 1.0/resistor;
			
			sprintf(buffer, "%f", answer) // take the double, use the floating point format, and stick it into the buffer. 
			
			path = path + string(buffer);

			while (isspace( cin.peek()))
				cin.get();
		}

		return answer;

	}
	


//string Resistance ( char choice, double answer );

*/
	