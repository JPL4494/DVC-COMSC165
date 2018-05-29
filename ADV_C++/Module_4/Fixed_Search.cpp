/*
Joshua Long
Comcs 165
Enter searchNumbers, sort, mean, search
TURN IN DATE
COMPLETE
Module 4 Part 1
*/

#include <iostream>

using namespace std;

int organizeArray(int arr[], int total);
int binarySearch(int arr[], int total, int searchNum);
double findAverage(int arr[], int total);

int main ()
{
    int total = 51;
    int searchNum;
    double average;
    int arr[total];
    int position;

    cout << "This program will allow you to enter up to 50 characters and then find a" << endl << "character you enter" << endl;

    do {
        cout << "Enter total number of characters [1-50]: ";
        cin >> total;
    }while (total <= 1 || total > 50);

    for (int i = 0; i < total; i++)
    {
        cout << "Enter " << i+1 << " character: ";
        cin >> arr[i];
    }

    cout << endl << "Enter the character you are searching for: ";
    cin >> searchNum;

    cout << "The total numbers of characters entered was " << total;
    cout << endl << "The original characters entered were ";
    for (int i = 0; i < total; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    organizeArray(arr,total);
    cout << "The sorted characters entered were ";
    for (int i = 0; i < total; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    position = binarySearch(arr,total,searchNum);
    cout << "The number searched for was " << searchNum << " and ";
    if (position > -1)
    {
        cout << "the position in the sorted array is " << position+1;
    }
    else
    {
        cout << "the value was not in the array";
    }
    cout << endl;

    average = findAverage(arr,total);
    cout << "The average value of the array is " << average;
    cout << endl;
}

int organizeArray(int arr[], int total)
{
    int temp;
    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int total, int searchNum)
{
    int first = 0;
    int last = total - 1;
    int middle;

    while (first <= last)
    {
        middle = first + (last - first) / 2;
        if (arr[middle] == searchNum)
        {
            return middle;
        }
        else if (arr[middle] < searchNum)
        {
            last = middle - 1;
        }

        else
        {
            first = middle + 1;
        }
    }
return -1;
}

double findAverage(int arr[], int total)
{
    double ave = 0;
    for (int i = 0; i < total; i++)
    {
        ave = ave + arr[i];
    }

    ave = ave / total;

    return ave;
}
