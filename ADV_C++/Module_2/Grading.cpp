/*
Joshua Long
Comcs 165
Overall grade calculator
9-8-13
Complete
Module 2 Part 3
*/


#include<iostream>

using namespace std;

int main()
{
    int number, grade, i;
    char overall;

    cout << "This program will tell you your overall grade based on the number of grades you enter\n";

    cout << "Enter number of grades: ";
    cin >> number;

    grade = 0;

    for (i = 1; i <= number; i++)
    {
        int temp;

        cout << "Enter grade " << i << ": ";
        cin >> temp;

        grade = grade + temp;
    }

    i = i - 1;

    grade = grade / i;

    if (grade >= 90)
    {
        overall = 'A';
    }

    else if (grade < 90 && grade >= 80)
    {
        overall = 'B';
    }

    else if (grade < 80 && grade >= 70)
    {
        overall = 'C';
    }

    else if (grade < 70 && grade >= 60)
    {
        overall = 'D';
    }

    else if (grade < 60)
    {
        overall = 'F';
    }

    cout << "Your overall grade is a " << overall << endl;
}
