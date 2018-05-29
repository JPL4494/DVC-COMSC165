/*
Joshua Long
Comcs 165
Total amount of sick days taken
8-26-13
Complete
Module 1 Part 2
*/


#include<iostream>

using namespace std;

int main()
{
    int teller, days;

    cout << "This program will tell you how many sick days were" << endl << "taken by tellers in the past three years\n";

    cout << endl << "Number of tellers at the bank: ";
    cin >> teller;

    days = 0;

    for (int num = 1; num <= teller; num++)
         {
             for (int i = 1; i <= 3; i++)
                  {
                      int temp = 0;
                      cout << "Teller " << num << " was sick how many days in year " << i << "?: ";
                      cin >> temp;

                      days = days + temp;
                  }
         }



    cout << "\n\nThe total number of sick days the " << teller  << " tellers \ntook were " << days << " days during the last three years.\n\n";

}
