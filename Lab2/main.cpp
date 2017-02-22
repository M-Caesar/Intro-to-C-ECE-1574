#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
using std::pow;

int main()
{
	double answer1; //initialize answer1
	double answer2; //initialize answer2
    int principle;
    double rate;
    int number;
    int time;
	
    cout <<  "Please tell me how much money you started with: ";
    cin >>  principle;
    cout <<  endl;
    cout << "Please tell me the rate for the investment: ";
    cin >> rate;
    cout << endl;
    cout << "Please tell me how many times a year your interest is compounded: ";
    cin >>  number;
    cout << endl;
    cout << "Please tell me how many years you want to invest your money: ";
    cin >> time;
	
	double g=(1+((rate)/number));
    answer1=principle*pow(g, number*time);//calculation goes here for compound interest
	answer2=principle*exp(rate*time); //calculation for compound continuously 
	
    cout << "After " << time << " years you're initial investment of " << principle << " compounded every "  
    << number << " times per year at " << rate << " interest rate will be worth " << answer1 << endl << endl;


    cout << "After " << time << " years you're initial investment of " << principle << " compounded continuously at "  
    << rate << " interest rate will be worth " << answer2 << endl << endl;
    return 0;
}
