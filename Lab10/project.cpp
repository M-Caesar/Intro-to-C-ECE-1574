#include "lab10.h"

void readData( istream& in, ostream& out )
{
	Widget myArray[10];//make an array of 25 ints based on the globaal definition above
	int count = 0; //how much stuff is in my array. Starting with 0 as a way to later count up.

	string file;
	// setting a string called name to input the name of the text file

	string command;
	// setting a string called command to input the name of the command

	in.ignore(256,':');
	// ignores everything inputted until the : with ability to store 256 chars.

    in >> file;
    // input the name of the text file as that is what it will read first. 

    readfilename( file, myArray, count);

    in >> command;
	while( !in.fail() )
	{
       // cout << "\t Command given is: " << command << endl;

		if (command == "find-name")
			// if the command that we give is list, run the code. 
		{

			while (isspace(in.peek())) //eat whitespace pretty much. If it peeks and sees a space
			in.get(); // it will eat it and move onto next space.

			string name;
					
			in >> name;

			listCalc2(in, myArray, out, count, name);
			
			
		}
		else if (command == "find-number")
			// if the command given is add, run the code.
		{
			double number;

			in >> number;

			listCalc(in, myArray, out, count, number);


		}
		in >> command;

	}



}

void readfilename(string file, Widget myArray[], int &count)
	{
		//count =0;

	    ifstream in;

	    //cout << "file check " << file << endl;

		in.open( file.c_str() );


		Widget storage;

		//in.ignore(256, ':');
		in >> storage.name;
		//cout << "Name check " << storage.name << endl; 

		
		in >> storage.number;
		//cout << "Number check " << storage.number << endl; 

		
		while(!in.fail())
		{

			//cout << "hi\n";
			// I know that widget is full of good
			if ( count < 10 )
			{
			myArray[count] = storage;
			count++;
			}
			in >> storage.name;
			//cout << "Name check " << storage.name << endl; 

			
			in >> storage.number;
			//cout << "Number check " << storage.number << endl; 

			//cout << myArray[count].name << endl;
			//cout << myArray[count].number << endl;
			
			
		}

		
	}

void listCalc2(istream& in,Widget myArray[], ostream& out, int &count, string name )
	{
		bool list1 = false;
		string finalname;

		for ( int i=0; i< count && myArray[i].name == name; i++)
	
		{

			out << "Found: " << myArray[i].name << " "<< myArray[i].number << endl;

			

			myArray[i].name = finalname;
			
			list1 = true;

		}

		if (!list1)
		{
			out << "Not found: " << name << "\n";
		}
		

	}

void listCalc(istream& in,Widget myArray[], ostream& out, int &count, double number )
	{
		bool list = false;

		//double finalnumber;
		//count = 0;

		//out << "found number check function " << number << endl;

		//int d =0 ;

		for ( int i=0; i< 10; i++)
	
		{
			if (myArray[i].number == number)
			{
				out << "Found: " << myArray[i].name << " "<< myArray[i].number << endl;

			
			list = true;

			break;
			}

			

		}

		if (!list)
		{
			out << "Not found: " << number << "\n";
		}
		

	}