#include "vendingMachine.h"

string vendingMachine ( int &money, int choice )
{
	string mmmCandy;
    switch( choice )
	{
		case 1:
			if ( money >= 100 )
			{

				mmmCandy = "Snickers";
				money = money - 100;
			}
			else
				mmmCandy = "Boo...you need to give me more $$";
			
		break;

		case 2:
			 
			if ( money >= 100 )
			{

				mmmCandy = "Peanut Butter Cups";
				money = money - 100;
			}
			else
				mmmCandy = "Boo...you need to give me more $$";
		break;
		case 3:
			if ( money >= 100 )
			{

				mmmCandy = "Skittles";
				money = money - 100;
			}
			else
				mmmCandy = "Boo...you need to give me more $$";
		break;

		default:
			mmmCandy = "Please choose between 1 and 3";
		break;


	}	
	return mmmCandy;	// make sure this is the last thing that you have. Nothing below this will happen. 
}