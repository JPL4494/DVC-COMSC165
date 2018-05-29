/*
Joshua Long
Comcs 165
Searches a list of names
10-20-13
COMPLETE
Module 7 Part 2
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int amount = 10, match = 0, pos;
    int got[match];
    string lookFor;
    string names [amount];

    cout << "This program will take a list of names and" << endl << "phone numbers you enter then search it" << endl << endl;
    cout << "Enter amount of names here: ";
    cin >> amount;

    cin.ignore();

    for (int i = 0; i < amount; i++)
    {
        cout << "Enter name and number " << i+1 << " : ";
        getline(cin,names[i]);
    }

    cout << endl << "Enter item to be searched for: ";
    getline(cin,lookFor);
    cout << endl;

    for(int i = 0; i < amount; i++)
    {
        pos = names[i].find(lookFor);
        cout << pos;
        if (pos >= 0)
        {
            got[match] = i;
            match++;
        }
    }

    cout << "Names found to be matching on the list" << endl;

    for (int i = 0; i < match; i++)
    {
        cout << names[got[i]] << endl;
    }
    if (match == 0)
    {
        cout << "No names or numbers were found to be matching";
    }
}
