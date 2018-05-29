/*
Joshua Long
Comcs 165
People's favorite drinks running tally
8-26-13
Complete
Module 1 Part 1
*/

#include<iostream>

using namespace std;

int main()
{
    int w, s, c, fj;
    int choice, number;

    cout << "This program will create a running tally of people's favorite drinks\n";
    cout << "Just type in the number from the four choices below, to exit enter -1\n";

    choice = 1;
    w = 0;
    s = 0;
    c = 0;
    fj = 0;
    number = 1;

    cout << endl << endl << "Person " << number << "\n1-Water\n2-Soda\n3-Coffee\n4-Fruit Juice\n";
    cin >> choice;

    while (choice != -1)
    {
        number = number + 1;

        if (choice == 1)
        {
            w = w + 1;
        }

        if (choice == 2)
        {
            s = s + 1;
        }

        if (choice == 3)
        {
            c = c + 1;
        }

        if (choice == 4)
        {
            fj = fj + 1;
        }

        cout << endl << endl << "Person " << number << "\n1-Water\n2-Soda\n3-Coffee\n4-Fruit Juice\n";
        cin >> choice;
    }

    number = number - 1;

    cout << "\n\nThe total number of people surveyed is " << number  << ". \nHere are the results:\n";
    cout << "****************************************\n";
    cout << "Water: " << w << endl;
    cout << "Soda: " << s << endl;
    cout << "Coffee: " << c << endl;
    cout << "Fruit Juice: " << fj << endl;
}
