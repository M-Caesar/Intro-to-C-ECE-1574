#include "encrypt.h"
using namespace std;

void encryptDecrypt( istream& in, ostream& out )
{
	string a;
	string input;
	string input2;
	string initial;
	cout << "Do you want to Encrypt or decrypt? ";

	in >> initial;

	while(!in.fail())
	{

		if ( initial == "encrypt" )
		{

			getline(in, input);
			cout << "What would you like to Encrypt? \n";
			//getline(in, input);
			cout << endl;
			
			a = encrypt(input);	   
	    	
	    	out << "encrypted: " << a << endl;
	    	//getline(in, input);
	    	
	    }
		else if ( initial == "decrypt")
	    {

	    	getline(in, input);
	    	cout << "What would you like to decrypt? \n";
	    	
	    	cout << endl;
	    	//getline(in, input2);

			a = decrypt(input);
			
		    
		    out << "decrypted: " << a << endl;
		}
		in >> initial;
	}

	
}

	string encrypt(string input)
	{
		string results = "";
		for ( int i=0; i<input.length(); i++ )
			{
		    	if ( input[i] == 'a' )
		    	{
		       		 results = results + "z";
		    	}
		    	else if ( input[i] == 'b' )
		    	{
		    		results = results + "y";
		    	}
		    	else if ( input[i] == 'c')
		    	{
		    		results = results + "x";
		    	}
		    	else if ( input[i] == 'd')
		    	{
		    		results = results + "w";
		    	}
		    	else if ( input[i] == 'e')
		    	{
		    		results = results + "v";
		    	}
		    	else if ( input[i] == 'f')
		    	{
		    		results = results + "u";
		    	}
		    	else if ( input[i] == 'g')
		    	{
		    		results = results + "t";
		    	}
		    	else if ( input[i] == 'h')
		    	{
		    		results = results + "s";
		    	}
		    	else if ( input[i] == 'i')
		    	{
		    		results = results + "r";
		    	}
		    	else if ( input[i] == 'j')
		    	{
		    		results = results + "q";
		    	}
		    	else if ( input[i] == 'k')
		    	{
		    		results = results + "p";
		    	}
		    	else if ( input[i] == 'l')
		    	{
		    		results = results + "o";
		    	}
		    	else if ( input[i] == 'm')
		    	{
		    		results = results + "n";
		    	}
		    	else if ( input[i] == 'z' )
		    	{
		       		results = results + "a";
		    	}
		    	else if ( input[i] == 'y' )
		    	{
		    		results = results + "b";
		    	}
		    	else if ( input[i] == 'x')
		    	{
		    		results = results + "c";
		    	}
		    	else if ( input[i] == 'w')
		    	{
		    		results = results + "d";
		    	}
		    	else if ( input[i] == 'v')
		    	{
		    		results = results + "e";
		    	}
		    	else if ( input[i] == 'u')
		    	{
		    		results = results + "f";
		    	}
		    	else if ( input[i] == 't')
		    	{
		    		results = results + "g";
		    	}
		    	else if ( input[i] == 's')
		    	{
		    		results = results + "h";
		    	}
		    	else if ( input[i] == 'r')
		    	{
		    		results = results + "i";
		    	}
		    	else if ( input[i] == 'q')
		    	{
		    		results = results + "j";
		    	}
		    	else if ( input[i] == 'p')
		    	{
		    		results = results + "k";
		    	}
		    	else if ( input[i] == 'o')
		    	{
		    		results = results + "l";
		    	}
		    	else if ( input[i] == 'n')
		    	{
		    		results = results + "m";
		    	}
		    	else results = results + input[i];
		    }

		    	return results;	    	
	}


	string decrypt(string input)
	{
		string results = "";
		for ( int i=0; i<input.length(); i++ )
			{
		    	if ( input[i] == 'z' )
		    	{
		       		results = results + "a";
		    	}
		    	else if ( input[i] == 'y' )
		    	{
		    		results = results + "b";
		    	}
		    	else if ( input[i] == 'x')
		    	{
		    		results = results + "c";
		    	}
		    	else if ( input[i] == 'w')
		    	{
		    		results = results + "d";
		    	}
		    	else if ( input[i] == 'v')
		    	{
		    		results = results + "e";
		    	}
		    	else if ( input[i] == 'u')
		    	{
		    		results = results + "f";
		    	}
		    	else if ( input[i] == 't')
		    	{
		    		results = results + "g";
		    	}
		    	else if ( input[i] == 's')
		    	{
		    		results = results + "h";
		    	}
		    	else if ( input[i] == 'r')
		    	{
		    		results = results + "i";
		    	}
		    	else if ( input[i] == 'q')
		    	{
		    		results = results + "j";
		    	}
		    	else if ( input[i] == 'p')
		    	{
		    		results = results + "k";
		    	}
		    	else if ( input[i] == 'o')
		    	{
		    		results = results + "l";
		    	}
		    	else if ( input[i] == 'n')
		    	{
		    		results = results + "m";
		    	}
		    	else if ( input[i] == 'a' )
		    	{
		       		 results = results + "z";
		    	}
		    	else if ( input[i] == 'b' )
		    	{
		    		results = results + "y";
		    	}
		    	else if ( input[i] == 'c')
		    	{
		    		results = results + "x";
		    	}
		    	else if ( input[i] == 'd')
		    	{
		    		results = results + "w";
		    	}
		    	else if ( input[i] == 'e')
		    	{
		    		results = results + "v";
		    	}
		    	else if ( input[i] == 'f')
		    	{
		    		results = results + "u";
		    	}
		    	else if ( input[i] == 'g')
		    	{
		    		results = results + "t";
		    	}
		    	else if ( input[i] == 'h')
		    	{
		    		results = results + "s";
		    	}
		    	else if ( input[i] == 'i')
		    	{
		    		results = results + "r";
		    	}
		    	else if ( input[i] == 'j')
		    	{
		    		results = results + "q";
		    	}
		    	else if ( input[i] == 'k')
		    	{
		    		results = results + "p";
		    	}
		    	else if ( input[i] == 'l')
		    	{
		    		results = results + "o";
		    	}
		    	else if ( input[i] == 'm')
		    	{
		    		results = results + "n";
		    	}
		    	else results = results + input[i];
		    }

		    	return results;
	}


	
    	




