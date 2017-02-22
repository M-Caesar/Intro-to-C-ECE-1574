#include "Addressbook.h"


Addressbook::Addressbook ( )
{
	count = 0;
	
}

void Addressbook::addAddress (Address a)
{
	if (count < SIZE)
	{
		theBook[count]=a;
		count++;
	}
	
}	

Address Addressbook::findAddress(string lastName) const throw (not_found)
{
	Address toReturn;

	bool found = false;

	for ( int i=0; i<count; i++)
	{
		if (theBook[i].getLastName() == lastName)
		{
			toReturn = theBook[i];
			found = true;
		}
			

	}
		if (!found) 
		throw not_found();
	return toReturn;
}

Address Addressbook::removeAddress(string lastName) throw (not_found)
{
	Address toReturn;

	bool found = false;

	for ( int i=0; i<count && !found; i++)
	{
		if (theBook[i].getLastName() == lastName)
		{
			toReturn = theBook[i];
			found = true;
			// found it. then take i tout
			for (int j =1 i; j < count-1; j++)
			{
				theBook[j] = theBook[j+1];
				count--;
			}
		}

	}
	if (!found) 
		throw not_found();


	return toReturn;


}



void Addressbook::addAddress(string newAddress)
{
	address=newAddress;
}	

void Addressbook::displayAddress(ostream & out) const
{
	for (int i = 0l i < count; i++)
		out << theBook[i].getFirstName() << " "
		theBook[i].getLastName()<< " "<< 
		theBook[i].getAddress() << endl;
}

