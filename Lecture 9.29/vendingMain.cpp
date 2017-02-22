#include "vendingMachine.h"
#include <iostream>

using namespace std;

int main()
{
	string candy;
	int funds;
	int whatILikeToEat;
	cout << "Give me $$";
	cin >> funds;
	cout << endl << "Tell me what you want to eat. 1-3";
	cin >> whatILikeToEat;
	candy = vendingMachine ( funds, whatILikeToEat );
	cout << "You got: "<<candy << endl
	<< "Your funds now are: " << funds << endl;
	return 0;
}

