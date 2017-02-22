#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

using std::string;

using std::ifstream;
using std::cout;
using std::endl;
using std::isspace;
using namespace std;
using std::cin;

int main()
{
	string filename;
	cout << "What file do you want to read: ";
	cin >> filename;
	cout << endl;
	ifstream in; //declare my input file stream object

	in.open( filename.c_str() ); // don't forget to put it......put this here. 


	string word;
	
	char c;
	in.get(c);

	//in >> word; // read a word from the file
	c = in.peak(); // read 1 character
	while ( !in.fail())
	{
		while( isspace(c) ) //checks if character is whitespace. Checks if c is a space character
			in.get(c);
		if ( c == '/' && in.peek() == '/' )
			in.ignore( 256, '\n') // this will ignore 256 characters or until it finds a \n character
		
		//in >> word;
		getline( in, word );
// read a line at a time. First parameter is input. Second parameter is where the data is stored.
		cout << word << endl; 

		c = in.peek();
	}
	in.close();
}


