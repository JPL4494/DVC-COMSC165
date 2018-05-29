/*
Joshua Long
Comcs 165
Searches a list of names
10-27-13
COMPLETE
Module 8
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct PersonalInfo
{
    string firstName, lastName, month, day, year;
};

int main()
{
    int total = 10, pick = 2, match = 0, pos;
    int got[match];
    string lookFor;
    PersonalInfo soccer[total], temp, sorted[total];

    cout << "This program will take in a list of 10 names you enter" << endl << "and you can sort or search them if you so choose" << endl;

    for (int i = 0; i < total; i++)
    {
        cout << "Enter data in form First Last MM DD YYYY: ";
        getline(cin,soccer[i].firstName,' ');
        getline(cin,soccer[i].lastName, ' ');
        getline(cin,soccer[i].month,' ');
        getline(cin,soccer[i].day, ' ');
        getline(cin,soccer[i].year);
    }
    total++;

    while (pick != 6)
    {
        if (pick == 1)
        {
            total++;
        }
        cout << "1= Data input  2= Display data  3= Sort data  4= Display sorted \n 5= Search last name  6= Exit program" << endl;
        cin >> pick;

        switch (pick)
        {
            case 1: system("CLS");
            cout << "Enter data in form First Last MM DD YYYY: ";
            getline(cin,soccer[total].firstName,' ');
            getline(cin,soccer[total].lastName,' ');
            getline(cin,soccer[total].month,' ');
            getline(cin,soccer[total].day,' ');
            getline(cin,soccer[total].year);
            break;

            case 2: system("CLS");
            cout << "Original list as follows:" << endl;
            for (int i = 0; i < total; i++)
            {
                cout << soccer[i].firstName << " ";
                cout << soccer[i].lastName << " ";
                cout << soccer[i].month << " ";
                cout << soccer[i].day << " ";
                cout << soccer[i].year;
            }
            cout << endl << endl;
            cout << "Press enter to continue";
            cin.ignore();
            cin.ignore();
            break;

            case 3: system("CLS");
            cout << "Sorting data.....";
            for (int i = 0; i < total; i++)
            {
                for (int j = 0; j < total; j++)
                {
                    if (soccer[i].lastName < soccer[j].lastName)
                    {
                        temp = soccer[i];
                        soccer[i] = soccer[j];
                        soccer[j] = temp;
                    }

                    if (soccer[i].lastName == soccer[j].lastName)
                    {
                        if (soccer[i].firstName < soccer[j].firstName)
                        {
                            temp = soccer[i];
                            soccer[i] = soccer[j];
                            soccer[j] = temp;
                        }
                    }
                }
            }
            for (int i = 0; i < total; i++)
            {
                sorted[i] = soccer[i];
            }
            cout << "Done\nPress enter to continue";
            cin.ignore();
            cin.ignore();

            break;

            case 4: system("CLS");
            cout << "Sorted names are as follows:" << endl;
            for (int i = 0; i < total; i++)
            {
                cout << sorted[i].firstName << " ";
                cout << sorted[i].lastName << " ";
                cout << sorted[i].month << " ";
                cout << sorted[i].day << " ";
                cout << sorted[i].year;
            }
            cout << endl << endl << "Press enter to continue";
            cin.ignore();
            cin.ignore();
            break;

            case 5: system("CLS");
            cin.ignore();
            cout << "Enter last name to search for: ";
            getline(cin, lookFor);

            for(int i = 0; i < total; i++)
            {
                pos = soccer[i].lastName.find(lookFor);
                if (pos >= 0)
                {
                   got[match] = i;
                   match++;
                }
            }
            cout << "Names found to be matching on the list" << endl;
            for (int i = 0; i < match; i++)
            {
               cout << soccer[got[i]].firstName << " " << soccer[got[i]].lastName << " " << soccer[got[i]].month << " " << soccer[got[i]].day << " " << soccer[got[i]].year;
            }
            cout << endl << endl << "Press enter to continue";
            cin.ignore();
        }

        system("CLS");
    }

    cout << "Goodbye" << endl << endl;

}
