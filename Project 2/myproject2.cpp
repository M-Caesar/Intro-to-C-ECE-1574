#include "resist.h"
using namespace std;

// include header, and using namespace std to initialize everything in the std library

void computeResistance( istream& in, ostream& out )
// uses the main function preset in the header without;


{

	double results = 0; // the result for series. These need to all be kept seperate as the while loop uses the same values
						// thus they won't interfer with each other as this is a global variable. 
	double resultp = 0; // the result for parallel
	double finals = 0; // the final value for series
	double finalp = 0; // the final value for parallel
	string path; // initializing a string for the path used to keep track of series and parallel
	char c; // initializing a character name that will be used to store the 'letters' and for decision later on. 

	while (isspace(in.peek())) //eat whitespace pretty much. If it peeks and sees a space
			in.get(); // then it will eat it and move to the next line. 

	c = in.peek(); //look at the next character and assign it to c
	

	while( !in.fail()) // while the input has not failed
	{
		if (isalpha(c) && (c == 'p' || c == 'P')) // and if the character is a 'letter' and it is p or P
		{
		finalp = parallel(in, path); // look at my function parallel at in and path, and assign it to final
		path = path + " in parallel "; // adds the word "in parallel" to my path below for output
		resultp = resultp + finalp; // results are added up again for total addition and stored in a result
		}

		else 
		{

		finals = series(in, path);
		path = path + " in series ";
		results = results + finals;
		// look at my function series at in and path, and assign it to final
		// adds the word "in series" to my path below for output
 		// results are added up again for total addition and stored in a result
		
		}

		while (isspace(in.peek())) 
			in.get();
		//eat whitespace pretty much. If it peeks and sees a space
		// then it will eat it and move to the next line. 

		if (!in.fail())
			path = path + " with ";

		// as long as the input doesn't fail, add the word "with" to the path
		
		c = in.peek();
		// Reprime
		//look at the next character and assign it to c 

		
	}
out <<"Equivalent Resistance: \n" // outputs an out for Webcat to read and see 
	<< "Total Equivalent Resistance " << (results + resultp ) << " Ohms"  // just out statements that have the total resistance and a final addition
	<< "\nResistor Path: Resistors " << path << endl; // outputs the path and all that goes with it. 

	

}
	double series(istream& in, string &path)
	// calls my series function with an input stream called in, and a string called path that changes. 
	{
		char c = in.peek();
		if (isalpha(c))
			in.get();
		while (isspace(in.peek()))
			in.get();
		c = in.peek();
		double result =0;
		double final=0;

		// char c is assigned to in.peek which looks at next character
		// as long as c is a character. Eat it up and move to the next line
		// as long as any whitespace is remaining. Eat it.
		// Reprime the c=in.peek to read the next word 
		// initializing of local variables then happens 
		while (!in.fail() && !isalpha(c)) // while input hasn't failed and c isn't a letter
		{
			char buffer[50]; 
			//sets size for character buffer to be 50 charcters

			in >> result;
			// inputs from my input stream


			final = final + result;
			// the code for the math on adding series and assinging it to final

			sprintf(buffer, "%f", result);
			// sprintf puts a buffer, in a float format with the result to allow it to read and assign values to the path 

			path = path + " " + string(buffer);
			// the path is then given a space to seperate the numbers so they don't stick. It then uses a function of string at buffer. 
			while (isspace(in.peek()))
				in.get();
            c= in.peek();

            // eats whitespace and then repriming
		}
		return final;
		// returns a value to when the function was called
	}


	

	double parallel(istream& in, string &path)
	// calls my parallel function with an input stream called in, and a string called path that changes. 

	{
		char c = in.peek();
		if (isalpha(c))
			in.get();
		while (isspace(in.peek()))
			in.get();
		c = in.peek();
		double result=0;
		double final=0;
		// char c is assigned to in.peek which looks at next character
		// as long as c is a character. Eat it up and move to the next line
		// as long as any whitespace is remaining. Eat it.
		// Reprime the c=in.peek to read the next word 
		// initializing of local variables then happens 
		while (!in.fail() && !isalpha(c)) // while input hasn't failed and c isn't a letter
		{
			char buffer[50];
			//sets size for character buffer to be 50 charcters

			in >> result;
			// inputs from my input stream


			final = final + 1.0/result;
			// the code for the math on adding series and assinging it to final

			sprintf(buffer, "%f", result);
			// sprintf puts a buffer, in a float format with the result to allow it to read and assign values to the path 

			path = path + " " + string(buffer);
			// the path is then given a space to seperate the numbers so they don't stick. It then uses a function of string at buffer. 

			while (isspace(in.peek()))
				in.get();
			c = in.peek();
            // eats whitespace and then repriming
		}
		return 1/final;
		// returns a value to when the function was called
	}
	
	
