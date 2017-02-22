#include <string>

using namespace std;

class date
{
private: // access modifiers -- defaulted to private until you say public
	string month;
	int year;
	int day;

public: // access modifiers
	date(); // constructor, is to initialize the private fields to some valid state. Iniitialization
	date(string newMonth, int newDay, int newYear); // paramtterized constructor
	
	//getters
	string getMonth() const;
	int getDay() const;
	int getYear() const;

};
// has no return type
