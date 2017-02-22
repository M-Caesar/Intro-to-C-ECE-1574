#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;


#ifndef __Adressbook__Addressbook__
#define __Adressbook__Addressbook__


const int SIZE = 20;

class not_found
{

};

class Addressbook
{
private:
	Address theBook[Size];
	int count;
public:
  Addressbook();
  void addAddress(Address a);

  Address findAddress(string lastName) const throw (not_found);

  Address removeAddress(string lastName) throw (not_found);

  void displayAddress(ostream & out) const;

  /*
  Address(string firstName, string lastName, string address);

  void setFirstName( string newFirstName );
  void setLastName( string newLastName );
  void setAddress( string newAddress );
  string getFirstName();
  string getLastName();
  string getAddress();
  */

};




#endif /* defined(__Fall14Project5__Student__) */
