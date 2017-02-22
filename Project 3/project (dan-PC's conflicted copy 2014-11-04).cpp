#include "inventory.h"

const int ARRAY_SIZE = 25; //this is a global constant

void inventory(istream& in, ostream& out)
{
	Widget myArray[ARRAY_SIZE];//make an array of 25 ints
	int count = 0; //how much stuff is in my array
	string name;

	string command;

	//string WidgetName;
	in.ignore(256,':');
    in >> name;
    readfilename( name, myArray, count);


	in >> command;
	while( !in.fail() )
	{
        out << "Command: " << command << endl;
		if (command == "list")
		{
			char c = in.peek();
				if (c == ' ')
				{
					string partNumber;

					in >> partNumber;
					listCalc2(in, myArray, out, count, partNumber);
				}
				else
				{
					
					listCalc(in, myArray, out, count );

				}
			
		}
		else if (command == "add")
		{

			addCalc(in, myArray, out, count );


		}

		else if (command == "buy")
		{
			/*
			string partbuy;
			int buynum

			in.ignore(256, ':');
			in >> partbuy;
			in >> buynum;

			out << "Purchased\n" << "Part #: " << partbuy << "\n" << "Cost: " << buynum

			// where do you get the cost?
			*/



		}
		else if (command == "save")
		{
			
			string output;
			
			in >> output;
            ofstream out2;
			out2.open ( output.c_str());
			saveCalc(in, myArray, out2, count );
            out2.close();


		}

		in >> command;

	}
	/*

	char c;
	c = in.peek();

	

	while(!in.fail())
	{

		//out << name <<;




	}

	for ( int i=0; i<count; i++)
	{
		if (myArray[i].part == partnumber)
		{
			//you found the widget
			//do something
		}
	}

	*/

}



void readfilename(string name, Widget myArray[], int &count)
	//void readfilename(string name, Widget myArray[], int &count)
	{
		count =0;

	    ifstream in;
		in.open( name.c_str() );

		// Get name and put it in a widget storage
		Widget storage;
		in.ignore(256, ':');
		in >> storage.name;

		// Get description using getline to get full line and put it in a widget storage
		in.ignore(256, ':');
		getline(in, storage.desc);

		// Get part and put it in a widget storage
		in.ignore(256, ':');
		in >> storage.part;

		// Get cost and put it in a widget storage
		in.ignore(256, '$');
		in >> storage.cost;

		in.ignore(256, ':');
		in >> storage.quantity;

		// read the rest of the widget info
		
		while(!in.fail())
		{
			// know that storage is full of gooooy goodness. 
			// want to stuff it into an array

			if ( count < 25)
			{
				myArray[count] = storage;
				count++;
			}
			
			

			//cout << "The Amount is: " << storage.name << endl;
			
			in.ignore(256, ':');
			in >> storage.name;

			// Get description using getline to get full line and put it in a widget storage
			in.ignore(256, ':');
			getline(in, storage.desc);

			// Get part and put it in a widget storage
			in.ignore(256, ':');
			in >> storage.part;

			// Get cost and put it in a widget storage
			in.ignore(256, '$');
			in >> storage.cost;

			in.ignore(256, ':');
			in >> storage.quantity;
			

		}


		
	}


	void listCalc(istream& in, Widget myArray[], ostream& out, int &count )
	{
		
			for(int i=0; i< count; i++)
			{
				//out << "Widget: " << myArray[i].name << endl;
				//out << "Description: " << myArray[i].desc << endl;
				out << "Part #: " << myArray[i].part << endl;
				//out << "Cost: " << myArray[i].cost << endl;
				//out << "Quantity: " << myArray[i].quantity << endl;
			}
		
			
	}


	void saveCalc(istream& in, Widget myArray[], ostream& out, int &count  )
	{
		for(int i=0; i< count; i++)
			{
				out << "Widget: " << myArray[i].name << endl;
				out << "Description: " << myArray[i].desc << endl;
				out << "Part #: " << myArray[i].part << endl;
				out << "Cost: " << myArray[i].cost << endl;
				out << "Quantity: " << myArray[i].quantity << endl;
			}

	}


	void listCalc2(istream& in,Widget myArray[], ostream& out, int &count, string partNumber ) // this is wrong, need to just list part number
	{

		for ( int i=0; i< count && myArray[i].part == partNumber; i++)
		{
			out << "Widget: " << myArray[i].name << endl;
			out << "Description: " << myArray[i].desc << endl;
			out << "Part #: " << myArray[i].part << endl;
			out << "Cost: " << myArray[i].cost << endl;
			out << "Quantity: " << myArray[i].quantity << endl;

		}


	}

	void addCalc(istream& in,Widget myArray[], ostream& out, int &count, Widget storage )
	{

		// Get name and put it in a widget storage
		Widget storage;
		in.ignore(256, ':');
		in >> storage.name;

		// Get description using getline to get full line and put it in a widget storage
		in.ignore(256, ':');
		getline(in, storage.desc);

		// Get part and put it in a widget storage
		in.ignore(256, ':');
		in >> storage.part;

		// Get cost and put it in a widget storage
		in.ignore(256, '$');
		in >> storage.cost;

		in.ignore(256, ':');
		in >> storage.quantity;

			bool added = false;
			for ( int i=0; i< count; i++)
			{
				if (myArray[i].part == storage.part)
				{

				myArray[i].quantity = myArray[i].quantity + storage.quantity;
				added = true;
				}




			}
			if (!added )
			{

				if (count < ARRAY_SIZE)
				{
					myArray[count]=storage;
					count++;
				}

			}
			


	}

	void buyCalc(istream& in,Widget myArray[], ostream& out, int &count, Widget storage)
	{
		//loop through array
		//if part number is same as the one in array, then try to purchase it. 

	}


	
