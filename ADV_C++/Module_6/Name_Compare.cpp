/*
Joshua Long
Comcs 165
Name Compare
TURN IN DATE
COMPLETE
Module 6 Part 2
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char name1[25], name2[25];
    int length1, length2;
    bool yes;

    cout << "This program compares two names that you give and sees if they are the same" << endl;
    cout << "Enter the names in the fashion 'Last, First' up to 25 characters";

    cout << endl << "Enter name 1: ";
    cin.getline(name1, 25);

    cout << endl << "Enter name 2: ";
    cin.getline(name2, 25);

    length1 = strlen(name1);
    length2 = strlen(name2);

    if (length1 == length2)
    {
        for (int i = 0; i < length1; i++)
        {
        if (name1[i] == name2[i])
            {
                yes = true;
            }
            else
            {
                yes = false;
                break;
            }
        }
        if (yes)
        {
            cout << endl << "The names are as follow:";
            cout << endl << name1;
            cout << endl << name2;
            cout << endl << "The names are the same" << endl;
        }
        else
        {
            length1 = length1 + 9;
        }
    }

    if (length1 != length2)
    {

        if (strcmp(name1,name2) > 0)
        {
             cout << endl << "The names are as follow:";
             cout << endl << name2;
             cout << endl << name1;
             cout << endl;
        }

        else
        {
             cout << endl << "The names are as follow:";
             cout << endl << name1;
             cout << endl << name2;
             cout << endl;
        }

    }
}
