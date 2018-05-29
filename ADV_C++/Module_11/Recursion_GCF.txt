/*
Joshua Long
Comcs 165
Greatest common factor finder
11-24-13
COMPLETE
Module 11 Part 2
*/

#include <iostream>

using namespace std;

int GCFfinder(int x, int y, int factor);

int main()
{
    int num1, num2, GCF, factor = 1;

    cout << "This program allows you to see the GCF of two numbers you enter, -1 to exit" << endl << endl;
    cout << "Enter number 1: ";
    cin >> num1;

    while (num1 != -1)
    {
        cout << "Enter number 2: ";
        cin >> num2;
        if (num1 > num2)
        {
            int temp;
            temp = num1;
            num1 = num2;
            num2 = temp;
        }

        GCF = GCFfinder(num1,num2,factor);

        cout << endl << "The greatest common factor of " << num1 << " and " << num2 << " is " << GCF << endl << endl;

        cout << "This program allows you to see the GCF of two numbers you enter, -1 to exit" << endl << endl;
        cout << "Enter number 1: ";
        cin >> num1;
    }

    cout << endl << "Goodbye." << endl << endl;
}

int GCFfinder(int x, int y, int factor)
{
    while(factor != 0)
    {
        if ((y % x) != 0)
        {
            factor = (y % x);
            y = x;
            x = factor;

            if ((y % x) ==! 0)
            {
                GCFfinder(x,y,factor);
            }
        }
        else if ((y % x) == 0)
        {
            factor = x;
            break;
        }
    }
    return factor;
}
