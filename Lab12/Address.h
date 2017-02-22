#include <string>
using namespace std;

class Address
{
private:
  string firstName;
  string lastName;
  string address;
public:
  Address();
  Address(string firstName, string lastName, string address);

  void setFirstName( string newFirstName );
  void setLastName( string newLastName );
  void setAddress( string newAddress );
  string getFirstName();
  string getLastName();
  string getAddress();


};