#include <string>

using namespace std;

// enum is an enumerated type
enum Months {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec }

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

	// setters or the mutators
	void setMonth (string month);
	void setDay(int day);
	void setYear(int year);

};
// has no return type
