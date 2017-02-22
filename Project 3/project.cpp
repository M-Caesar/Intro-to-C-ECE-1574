#include "inventory.h"
// include header to initialize everything in the std library



const int ARRAY_SIZE = 25;
 //this is a global constant to set ArraySize to 25. Makes it easy to dynamically change size

void inventory(istream& in, ostream& out)
// uses the main function preset in the header without;

{
	out << fixed << showpoint << setprecision(2); 
	// universal setting for output to have set number of decimal places. Mine sets it to 2

	Widget myArray[ARRAY_SIZE];//make an array of 25 ints based on the globaal definition above
	int count = 0; //how much stuff is in my array. Starting with 0 as a way to later count up.
	
	string name;
	// setting a string called name to input the name of the text file

	string command;
	// setting a string called command to input the name of the command

	in.ignore(256,':');
	// ignores everything inputted until the : with ability to store 256 chars.

    in >> name;
    // input the name of the text file as that is what it will read first. 

    readfilename( name, myArray, count);
    // calls my function 'readfilename' while giving it the inputs needed. 

	in >> command;
	// after function of reading in inventory is done, it reads the first command from command.txt
	while( !in.fail() )
		// while the input does not fail
	{
        out << "Command: " << command << endl;
        // at the top of the list, we need the command we ran.

		if (command == "list")
			// if the command that we give is list, run the code. 
		{
			while (isspace(in.peek())) //eat whitespace pretty much. If it peeks and sees a space
			in.get(); // it will eat it and move onto next space.

			char c = in.peek();
			// peeks at letter right after it moved. If it is a letter P, it will run the code
			// with the partNumber 
				if (c == 'P')
				{
					string partNumber;
					// initializing a local variable of string partNumber

					in >> partNumber;
					// we then input what the partnumber is. 


					listCalc2(in, myArray, out, count, partNumber);
					// we run the function of listCalc2 below passing in the partNumber as well. 
				}
				else
					// else, it will just run the normal listcalc without partnumber
				{
					
					listCalc(in, myArray, out, count );
					// we run the function

				}
			
		}
		else if (command == "add")
			// if the command given is add, run the code.
		{

			addCalc(in, myArray, out, count);
			// we just run the function code below. 


		}

		else if (command == "buy")
			// if the command given is buy, run the code.
		{
		
			buyCalc(in, myArray, out, count);
			// we just run the function code below. 

		}
		else if (command == "save")
			// if the command given is save, we run the code. 
		{
			
			string output;
			// defining a local variable called output
			
			in >> output;
			// we input the name of the output txt file in the commands.txt

            ofstream out2;
            // we initialize a secondary outputstream for the save to not mix up
            // our primary output stream. 

			out2.open ( output.c_str());
			// we then just open a new document of what the output name was

			saveCalc(in, myArray, out2, count );
			// we run the save calc function which basically stores the data into the doc that is open

            out2.close();
            // we are responsible gentleman, so we close the door to our file after leaving. 

		}

		in >> command;
		// re-prime

	}
	
}



void readfilename(string name, Widget myArray[], int &count)
	//void readfilename(string name, Widget myArray[], int &count)
	{
		count =0;
		// in case count was changed, count is re-initialized to 0 for safe practice

	    ifstream in;
	    // opening up the input stream

		in.open( name.c_str() );
		// opens up the file called name with apendings c_str() for webcat to use

		// The following first use an ignore function to ignore everything up to either
		// an : or an $ so we can input just what we need. Then it gets the information

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

		// Get quantity and put it in a widget storage
		in.ignore(256, ':');
		in >> storage.quantity;


		
		
		while(!in.fail())
		{
			// I know that widget storage is full of the good stuff
			//  and I want to store it all into an array. 
			
			myArray[count] = storage;
			count++;
			// at array location 'count' which is a number to define location, all of storage will be put there.
			// add 1 to count with each iteration of the loop
			
			// The following first use an ignore function to ignore everything up to either
			// an : or an $ so we can input just what we need. Then it gets the information

			// Get name and put it in a widget storage
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

			// Get quantity and put it in a widget storage
			in.ignore(256, ':');
			in >> storage.quantity;
			
		}
		
	}


	void listCalc(istream& in, Widget myArray[], ostream& out, int &count )
	// function for the first listcalculation the program needs
	{
		
			for(int i=0; i< count; i++)
			// local int i is 0. As i is less than whatever count is. Run through this, then add 1 with each iteration
			{
				out << "Widget: " << myArray[i].name << endl;
				out << "Description: " << myArray[i].desc << endl;
				out << "Part #: " << myArray[i].part << endl;
				out << "Cost: $" << myArray[i].cost << endl;
				out << "Quantity: " << myArray[i].quantity << endl;

				// the following outputs the entire description in order of the data that was stored. 
			}
		
			
	}


	void saveCalc(istream& in, Widget myArray[], ostream& out, int &count  )
	// function for the save function that the program needs. 
	{
		for(int i=0; i< count; i++)
		// local int i is 0. As i is less than whatever count is. Run through this, then add 1 with each iteration
			{
				out << "Widget: " << myArray[i].name << endl;
				out << "Description: " << myArray[i].desc << endl;
				out << "Part #: " << myArray[i].part << endl;
				out << "Cost: $" << myArray[i].cost << endl;
				out << "Quantity: " << myArray[i].quantity << endl;

			// the following outputs the entire description in order of the data that was stored. 

			}

	}


	void listCalc2(istream& in,Widget myArray[], ostream& out, int &count, string partNumber )
	// function two of the listcal requirements. 
	{
		bool list = false;
		// initializes a boolean of list that is initially false. 

		for ( int i=0; i< count && myArray[i].part == partNumber; i++)
		// for i=0, i less than whatever count is, while at the same time being
		// equal to whatever part at myArray is equalling the partnumber inputted. Run this code
		// then add 1 every time it gets an iteration. 
		{
			out << "Widget: " << myArray[i].name << endl;
			out << "Description: " << myArray[i].desc << endl;
			out << "Part #: " << myArray[i].part << endl;
			out << "Cost: $" << myArray[i].cost << endl;
			out << "Quantity: " << myArray[i].quantity << endl;
			// the following outputs the entire description in order of the data that was stored. 


			list = true;
			// since the code worked as it ran the for loop. Make list = true. 

		}

		if (!list)
		// the code ends up here if list is still false as it didn't run for loop.
		{
			out << "Sorry, we don't have " << partNumber << " in stock.\n";
			// outputs pre-set speech program needs with partNumber output. 
		}
		

	}

	void addCalc(istream& in,Widget myArray[], ostream& out, int &count)
	// function for additional calculations 
	{
		// The following first use an ignore function to ignore everything up to either
		// an : or an $ so we can input just what we need. Then it gets the information

		// initializing the widget storage as a local variable. 
		Widget storage;

		// Get name and put it in a widget storage
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

		// get quantity and put it in a widget storage. 
		in.ignore(256, ':');
		in >> storage.quantity;

			bool added = false;
			// initialize a boolean call added that is at first false. 

			for ( int i=0; i< count; i++)
				// start at 0, as it is less than count, run code. Then add 1 each time
			{
				if (myArray[i].part == storage.part)
					// if the two part numbers match , run the code
				{

				myArray[i].quantity = myArray[i].quantity + storage.quantity;
				added = true;

				// since the two numbers matched. We just add up the quantities of both of them. 

				// we then set boolean added to true so it doesn't run the false code. 
				}

			}

			if (!added )
				// since bool was false for added, we run this code. 
			{

				if (count < ARRAY_SIZE)
				// remembering that count is pass by reference
				// it is understood that count is keeping accurate tabs on how large our array size is
				// so granting there is more space left, we can run the code below
				{
					myArray[count]=storage;
					count++;
					// at array location 'count' which is a number to define location, all of storage will be put there.
					// add 1 to count with each iteration of the loop
				}

			}
			

	}

	void buyCalc(istream& in,Widget myArray[], ostream& out, int &count)
	// function for buying calculations. 
	{
		// initializing the widget storage as a local variable. 
		Widget storage;

		// initializing a quantity integer for storing quantity.
		int buyQuant = 0;
		
		// Get part and put it in a widget storage
		in.ignore(256, ':');
		in >> storage.part;

		in >> buyQuant;
		// as the quantity immediately follows the part#. We just input buyQuant now

		// initializing int e for storing a number for later use in calculting numbers
		int e;

			bool bought = false;
			// making a boolean of bought and setting it to false at first. 

			for ( int i=0; i< count; i++)
			// i=0, as i is less than count, run code. Then add 1 with each iteration
			{
				if (myArray[i].part == storage.part)
					// as long as the two part numbers match, run below.
				{
					e = myArray[i].quantity; 
					// setting e to be the initial quantity value before it is changed. 

					if (myArray[i].quantity - buyQuant <= 0)
					// for use when the number being bought is over the amount that we have.
					{
						out << "Purchased:\n" << "Part #: " << storage.part << "\n" << "Cost: $" << myArray[i].cost * myArray[i].quantity << endl;
						// have to output purchase first so quantity doesn't change. 
						//Cost calculation is done in output itself multiplying the cost and the quant original together. 

						// just need calculation of multiplying the cost by the current quantity
						// as even if they ordered a larger purchase, they can only purchase the maximum
						//in stock.

						myArray[i].quantity = 0;
						
						// seeing as how the stock is now gone. The quantity of the array of that part
						// needs to be updated and set to 0.

					}
					else
					// else here means that the amount bought is smaller than what we have in inventory
					{
						myArray[i].quantity = myArray[i].quantity - buyQuant;
						
						// we are going to update the quantity first this time as we have more stock than requested
						// this is just simple matter of taking the quantity already, and subtracting buyQuant from it

						out << "Purchased:\n" << "Part #: " << storage.part << "\n" << "Cost: $" << myArray[i].cost*buyQuant << endl;
						// cost calculation is done in output itself multiplying cost by buyquant
					}
				
				bought = true;
				// remembering that we had a boolean. We need to know make the boolean true. 
			
				break;
				// stops the code from repeating itself endlessley after an output.

				}

			}

			if (!bought )
				// if the part number wasn't something we have/had anymore. It is false, so run this code
			{

				out << "Sorry, we don't have " << storage.part << " in stock.\n";
				// just output that we have don't have it in stock anymore

			}



	}

	
