#include "oddOrEven.h"

bool oddOrEven ( int number ) //<-------no semicolon here
{
	bool answer = false;
	if ( number % 2 == 0 )
		answer = true;
	return answer;
}