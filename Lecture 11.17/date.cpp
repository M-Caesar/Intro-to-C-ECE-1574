#include "date.h"

date::date()
{
	month = "January";
	day = 1;
	year = 2014;

}

date::date(string newMonth, int newDay, int newYear)
{
	if (newMonth== "January" || newMonth == "February")
		month = newMonth;
	else
		month = "January";
	if (day > 0 && newDay < 32)

	day = newDay;
	else
		day = 1;
	if (year > 20)

		year = newYear;
	else
		year = 2014;
}

string date::getMonth() const
{
	return month;
}

int date::getDay() const
{
	return day;
}
int date::getYear() const
{
	return year;
}