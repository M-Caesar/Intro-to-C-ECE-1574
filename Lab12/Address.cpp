#include "Address.h"

Address::Address()
{
	firstName = "";
	lastName = "";
	address = "";
}

Address::Address ( string firstName, string lastName, string address)
{
	this->firstName=firstName;
	this->lastName=lastName;
	this->address=address;
	
}

string Address::getAddress	()
{
	return address;
}	

string Address::getFirstName()
{
	return firstName;
}

string Address::getLastName()
{
	return lastName;
}



void Address::setAddress(string newAddress)
{
	address=newAddress;
}	

void Address::setFirstName(string newFirstName)
{
	firstName=newFirstName;

}

void Address::setLastName(string newLastName)
{
	lastName=newLastName;

}