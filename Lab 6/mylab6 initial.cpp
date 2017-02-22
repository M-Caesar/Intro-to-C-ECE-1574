#include "encrypt.h"
using namespace std;

void encryptDecrypt( istream& in, ostream& out )

{
	string results;
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
			

			results = "";
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
		    	else results = results + input[i];
		    	
	    	}
	    	
	    	out << "encrypted: " << results << endl;
	    	//getline(in, input);
	    	
	    }
		
		else if ( initial == "decrypt")
	    {

	    	getline(in, input2);
	    	cout << "What would you like to decrypt? \n";
	    	
	    	cout << endl;
	    	//getline(in, input2);

		

			results = "";
			for ( int i=0; i<input2.length(); i++ )
			{
		    	if ( input2[i] == 'z' )
		    	{
		       		results = results + "a";
		    	}
		    	else if ( input2[i] == 'y' )
		    	{
		    		results = results + "b";
		    	}
		    	else if ( input2[i] == 'x')
		    	{
		    		results = results + "c";
		    	}
		    	else if ( input2[i] == 'w')
		    	{
		    		results = results + "d";
		    	}
		    	else if ( input2[i] == 'v')
		    	{
		    		results = results + "e";
		    	}
		    	else if ( input2[i] == 'u')
		    	{
		    		results = results + "f";
		    	}
		    	else if ( input2[i] == 't')
		    	{
		    		results = results + "g";
		    	}
		    	else if ( input2[i] == 's')
		    	{
		    		results = results + "h";
		    	}
		    	else if ( input2[i] == 'r')
		    	{
		    		results = results + "i";
		    	}
		    	else if ( input2[i] == 'q')
		    	{
		    		results = results + "j";
		    	}
		    	else if ( input2[i] == 'p')
		    	{
		    		results = results + "k";
		    	}
		    	else if ( input2[i] == 'o')
		    	{
		    		results = results + "l";
		    	}
		    	else if ( input2[i] == 'n')
		    	{
		    		results = results + "m";
		    	}
		    	else results = results + input2[i];
		    	
		    		
		    	
		    }
		    
		    out << "decrypted: " << results << endl;
			
	}

	in >> initial;

	    }


	
}


	
    	




