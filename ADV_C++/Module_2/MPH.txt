/*
Joshua Long
Comcs 165
Miles per hour calculator
9-8-13
Complete
Module 2 Part 2
*/

#include<iomanip>
#include<iostream>

using namespace std;

void calculate(double mile, double hour, double & mph);

int main ()
{
    double mile, hour;
    double mph;

    cout << "This program will calculate the miles per hour based\n on the miles and hour you specify below\n";

    cout << endl << "Number of miles: ";
    cin >> mile;

    cout << "Amount of time passed, in hours: ";
    cin >> hour;

    calculate(mile,hour,mph);

    cout << setprecision(2) << fixed << "\nYou were going " << mph << " miles per hour\n\n";
}

void calculate(double mile, double hour, double & mph)
{
    mph = mile / hour;
}
