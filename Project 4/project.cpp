#include "runner.h"
// include header to initialize everything in the std library that we have in runner.h


void runRace( istream &in, ostream &out )
// Calls my main function
{
	out << fixed << showpoint << setprecision(2); 
	// universal setting for output to have set number of decimal places. Mine sets it to 2


	Widget *myArray;
	int size = 10;
	int count = 0;
	//Defining a pointer myArray of Widget (struct) data like type. 
	//Initializing an initial size of 10 to be plugged in and a count of 0 for later

	myArray = new Widget [size];
	// Defining myArray to be a 'new' Widget of size 10

	string name;

	string command;

	in.ignore(256,':');

    in >> name;

    readfilename( name, myArray, count, size);

    // The following code defings a string name and command, ignores until the ':'
    // to get to the file name, and calls my function 'readfilename' 

	in >> command; 
	// inputs the command

	while ( !in.fail() )
		// While the input has not failed meaning something is still available to be inputted
	{

		if (command == "find-name")
		{ 
			namefunction(in, myArray, out, count, size, command );

		}
		else if (command == "find-place")
		{
			placefunction(in, myArray, out, count, command );

		}
		
		else if (command == "find-bib")
		{
			bibfunction(in, myArray, out, count, command );

		}
		// All the lines of code above 
		// reads in the command and calls my functions
		
		in >> command;
		// Re-prime of the command. 
		
	}

}

void readfilename(string name, Widget *&myArray, int &count, int &size)
// calls my function and passes in such inputs I want
	{
		count = 0;

	    ifstream in;

		in.open( name.c_str() );
		// the code opens up a local inputstream and runs in.open to open the file.

		Widget storage;
		//defining a local Widget called storage

		int hour =0;
		int min = 0;
		int sec = 0;

		// initializing time data so that time can be changed to an int and stored as a single number later

		char c;
		// initializing a character to eat the ':'

		getline(in, storage.last, ',');

		getline(in, storage.first, ',');

		getline(in, storage.bib, ',');

		getline(in, storage.sex, ',');
		// getline, gets the 4 types of struct of string type that I declared until the comma

		in >> hour >> c >> min >> c >> sec;
		in.get();
		storage.clock = hour*3600+min*60+sec;

		in >> hour >> c >> min >> c >> sec;
		storage.chip = hour*3600+min*60+sec;

		// following code inputs the time data in the sequence as follows, and uses c to eat the ':'
		// it is then multiple accordingly to get the data as a single number in seconds

		in.get();
		// eats the space to move up one 

		while(!in.fail())
		{

			if (count == size)
				// sees if my Array is 'full'
			{
				grow(myArray, size);
				// if it is full, it will call my grow function passing in myArray and the size
				
			}
			
			{

				myArray[count] = storage;
				count++;
				// the data in storage above will be pushed into myArray at count. then count will +1 
				// so we can add data to it later
				
				getline(in, storage.last, ',');

				getline(in, storage.first, ',');

				getline(in, storage.bib, ',');

				getline(in, storage.sex, ',');

				in >> hour >> c >> min >> c >> sec;
				in.get();
				storage.clock = hour*3600+min*60+sec;

				in >> hour >> c >> min >> c >> sec;
				storage.chip = hour*3600+min*60+sec;

				in.get();
				// runs through the same code and explanation as above.
				
			}
			
			for (int i= 0; i < count; i++)
				// runs through the entire code to the lengths of 'count'
			{	
					
				for (int j=i; j < count; j++)
					//initializes j and runs through the code until count ends
					if(myArray[i].chip > myArray[j].chip)
						// if my time at i is larger than the one at j then
					{
						Widget temp = myArray[i];
						myArray[i]=myArray[j];
						myArray[j]=temp;

						//swap them
					}
			}
			// The following code seen above is my 'sort' code.
				
		}

		
	}

	void grow( Widget *&myArray, int &size)
	{

	int newSize = size * 2;
	// initializes newSize to be just the size *2
	Widget *temp = new Widget[newSize];
	// makes a widget of pointer temp that is basically the one with the double size. 

		for (int i=0; i<size; i++)
			temp[i]=myArray[i];
		// copies over myArray into temp

		
		size = size * 2; // size = size *2
		delete [] myArray; // gives back x's memory
		myArray = temp;
		// grows myArray by then setting it equal to temp

		temp = NULL; 
		// setting temp to Null as myArray and temp still hold the location so if you delete temp, myArray also loses it
		//so just set it to Null.

	}

	void namefunction(istream& in, Widget *myArray, ostream& out, int &count, int &size, string command)
	{
		string name;

		in >> name;
		// inputs the name

		bool namebool = false;
		// makes a boolean that is initially false

		out << command <<" "<<  name << endl;
		// outputs the command name and then the 'name'
		
		for ( int i=0; i<count ; i++)
			// runs through my entire array
		{

				if (myArray[i].last == name)
					// if the two names match, then run my code
				{
					// ------------------ Clock Time Reformat
					int hour = myArray[i].clock/3600;

					int rem = myArray[i].clock % 3600;

					int minutes = rem/60;

					int seconds = rem % 60;

					// ------------------ Chip Time Reformat

					int hour2 = myArray[i].chip/3600;

					int rem2 = myArray[i].chip % 3600;

					int minutes2 = rem2/60;

					int seconds2 = rem2 % 60;

					// The code above basically takes the single digit number in seconds and re-converts it back to a 'real' time format
					// that the code wants. 
					// int is an hour, so dividing the seconds by 3600 will just give us the integer number we need.
					// the modulus of that same division, but now the remainder. The remainder can be converted to minutes by dividing by 60. And so on
					// can the remainder for that be made into seconds

					
					out << i+1 <<" "<< name << ", "<< myArray[i].first <<" "<< myArray[i].bib <<" "<< myArray[i].sex <<" "<< hour << ":";
					if ( minutes < 10)
						out << "0";
					out << minutes << ":";
					if ( seconds < 10)
						out << "0";
					 out << seconds <<" "<< hour2 << ":";
					if (minutes2 < 10)
					 	out << "0";
					 out << minutes2 << ":";
					if (seconds2 <10 )
					 	out << "0";
					 out << seconds2 << endl;

					 // code above outputs the answer output stream and has if statements to add an extra '0' to the stream of minutes and seconds of
					 // both chip and clock for if the number it gets back is less than 10. This is so it is a 'full' format.
					
					namebool = true;
					// since it found it, set the boolean to true. 
				}
				
		}

		if (!namebool)
			// if it didn't find it
			{
				
				out << "Sorry, no runners with last name " << name << " were found." << endl;
				// just output this

			}
			
	}

	void placefunction(istream& in, Widget *myArray, ostream& out, int &count,string command )
	{
		int place;
		in >> place;
		// inputs the place number

		bool placebool = false;
		// initializes my boolean

		if (place > 0 && place < count)
			// just makes sure the number given is an actual number. This is checked by being a positive number, and being less than the count we have as place
			// is coorelative to count
		{
			// ------------------ Clock Time Reformat
			place = place -1;	
			int hour = myArray[place].clock/3600;

			int rem = myArray[place].clock % 3600;

			int minutes = rem/60;

			int seconds = rem % 60;

			// ------------------ Chip Time Reformat

			int hour2 = myArray[place].chip/3600;

			int rem2 = myArray[place].chip % 3600;

			int minutes2 = rem2/60;

			int seconds2 = rem2 % 60;

					// The code above basically takes the single digit number in seconds and re-converts it back to a 'real' time format
					// that the code wants. 
					// int is an hour, so dividing the seconds by 3600 will just give us the integer number we need.
					// the modulus of that same division, but now the remainder. The remainder can be converted to minutes by dividing by 60. And so on
					// can the remainder for that be made into seconds


			out << command <<" "<<  place + 1 << endl;
			out << place+1 <<" "<< myArray[place].last << ", "<< myArray[place].first <<" "<< myArray[place].bib <<" "<< myArray[place].sex <<" "<< hour << ":"; 
			if ( minutes < 10)
				out << "0";
			out << minutes << ":";
			if ( seconds < 10)
				out << "0";
			 out << seconds <<" "<< hour2 << ":";
			if (minutes2 < 10)
			 	out << "0";
			 out << minutes2 << ":";
			if (seconds2 <10 )
			 	out << "0";
			out << seconds2 << endl;
			 // code above outputs the answer output stream and has if statements to add an extra '0' to the stream of minutes and seconds of
					 // both chip and clock for if the number it gets back is less than 10. This is so it is a 'full' format.
					
			placebool = true;
			// since we found it, set boolean to true
			

		}


		if (!placebool)
			// but if we didn't find it.
		{
			out << command <<" "<<  place << endl;
			out << "Sorry, no runners with place " << place << " were found." << endl;
			// output the command and the Sorry statement
		}

	}
	

	void bibfunction(istream& in, Widget myArray[], ostream& out, int &count,string command )
	{
		string bib;
		in >> bib;
		// inputs the bib as a string, makes it easy to getline. It doesn't matter if it is an int either way

		bool bibbool = false;
		// initializes the boolean to false

		for ( int i=0; i<count ; i++)
			// goes through my entire array
		{
			
			if (myArray[i].bib == bib)
				// if it finds that the bib is equal to each other
			{
					// ------------------ Clock Time Reformat
					int hour = myArray[i].clock/3600;


					int rem = myArray[i].clock % 3600;

					int minutes = rem/60;

					int seconds = rem % 60;

					// ------------------ Chip Time Reformat


					int hour2 = myArray[i].chip/3600;


					int rem2 = myArray[i].chip % 3600;

					int minutes2 = rem2/60;

					int seconds2 = rem2 % 60;

					// The code above basically takes the single digit number in seconds and re-converts it back to a 'real' time format
					// that the code wants. 
					// int is an hour, so dividing the seconds by 3600 will just give us the integer number we need.
					// the modulus of that same division, but now the remainder. The remainder can be converted to minutes by dividing by 60. And so on
					// can the remainder for that be made into seconds

					out << command << " "<< bib << endl;
					out << i+1 <<" "<< myArray[i].last << ", "<< myArray[i].first <<" "<< myArray[i].bib <<" "<< myArray[i].sex <<" "<< hour << ":";
					if ( minutes < 10)
						out << "0";
					out << minutes << ":";
					if ( seconds < 10)
						out << "0";
					 out << seconds <<" "<< hour2 << ":";
					if (minutes2 < 10)
					 	out << "0";
					 out << minutes2 << ":";
					if (seconds2 <10 )
					 	out << "0";
					out << seconds2 << endl;

					 // code above outputs the answer output stream and has if statements to add an extra '0' to the stream of minutes and seconds of
					 // both chip and clock for if the number it gets back is less than 10. This is so it is a 'full' format.
					
					bibbool = true;

					// we found bib so we can set the boolean to true. 

			}
		}		

		if (!bibbool)
			// if we didn't find it
		{
			out << command << " "<< bib << endl;
			out << "Sorry, no runners with bib " << bib << " were found." << endl;
			// we just output the command and the sorry statement. 
		}

	}

