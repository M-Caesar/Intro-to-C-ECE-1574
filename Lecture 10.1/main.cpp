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

	in >> word; // read a word from the file
	while ( !in.fail())
	{
		if ( isspace(c) ) // if ( c == '/' && in.peek() == '/' )
			cout << "whoo hoo, space!" << endl; // in.ignore( 256, '\n')
		
		in >> word;
		cout << word << endl; 

		in.get(c) ;
	}
	in.close();
}


