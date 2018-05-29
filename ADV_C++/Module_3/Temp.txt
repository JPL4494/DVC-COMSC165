/*
Joshua Long
Comcs 165
Temperature sorter and average temperature finder
9-15-13
Complete
Module 3 Part 1
*/

#include<iostream>
#include<iomanip>

using namespace std;

double input(double T, int s, double a[], double b[]);
double organize(double T, double temp, double b[]);
double average(double T, double a[], double average);

int main()
{
    int T = 10;
    double a[T], b[T], temp, av = 0;
    int s = 11;

    cout << "This program will take the temperatures you enter, but only up to 10 days" << endl;
    cout << "It will then sort them from lowest to highest and give the average temperature" << endl;

    T = input(T,s,a,b);
    organize(T,temp,b);

    cout << endl << endl;

    cout << "The original tmeperatures entered were ";
    for (s = 0; s < T; s++)
    {
        cout << a[s] << " ";
    }

    cout << endl;

    cout << "The sorted temperatures are ";
    for (s = 0; s < T; s++)
    {
        cout << b[s] << " ";
    }

    cout << endl;

    av = average(T,a,av);

    cout << setprecision(2) << fixed << "The average temperature was " << av << endl << endl;


}

double input(double T, int s, double a[], double b[])
{
    do
        {cout << endl << "Enter number of days, <1-10>: ";
        cin >> s;} while (s < 0 || s > 10);

        T = s;

        for (int j = 0; j < s; j++)
        {
            cout << "Enter temperature: ";
            cin >> a[j];
            b[j] = a[j];
        }
        return T;
}

double organize(double T, double temp, double b[])
{
    for (int j = 0; j < T; j++)
    {
        for (int s = j + 1; s < T; s++)
        {
            if (b[j] > b[s])
            {
                temp = b[j];
                b[j] = b[s];
                b[s] = temp;
            }
        }
    }
}

double average(double T, double a[], double av)
{
    for (int s = 0; s < T; s++)
    {
        av = av + a[s];
    }
    av = av / T;
    return av;
}
