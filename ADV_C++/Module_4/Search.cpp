/*
Joshua Long
Comcs 165
Enter searchNumbers, sort, mean, search
TURN IN DATE
NOT COMPLETE NEED TO FIX SEARCH
Module 4 Part 1
*/

#include <iostream>

using namespace std;

int organize(int changed[], int total);
int searchArray(int changed[], int searchNum, int total);
double findMean(int changed[], double average,int total);

int main ()
{
    int total = 51, searchNum, position = -1;
    double average = 0;
    int arr[total];

    cout << "This program will allow you to enter up to 50 characters and then find a" << endl << "character you enter" << endl;

    do
    {
        cout << "Enter max number of characters [1-50] = ";
        cin >> total;
    } while (total < 1 || total >= 50);

    for (int i = 0; i < total; i++)
    {
        cout << "Enter value " << i+1 << " here: ";
        cin >> arr[i];
    }

    cout << endl << "What number are you searching for?" << endl;
    cin >> searchNum;

    cout << endl << "The size of the array is " << total << endl;

    cout << "The orignal values entered were: ";
    for (int i = 0; i < total; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    organize(arr,total);
    position == searchArray(arr,searchNum,total);
    average = findMean(arr,average,total);

    cout << "That array sorted is: ";
    for (int i = 0; i < total; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The number searched for was " << searchNum << " and ";

    if (position = -1)
    {
        cout << "the number is not in the array you entered";
    }
    if (position > -1)
    {
        cout << "the number's position is at " << position;
    }

    cout << endl << "The average value of the array is " << average;
}

int organize(int changed[], int total)
{
    int temp = 0;
    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (changed[i] > changed[j])
            {
                temp = changed[i];
                changed[i] = changed[j];
                changed[j] = temp;
            }
        }
    }
}

int searchArray(int changed[], int searchNum, int total)
{
    int first = 0;
    int last = total - 1;
    int middle;
    int pos = -1;
    bool found  = false;

    while(!found && first <= last)
    {
        middle = (last + first) / 2;
        if (changed[middle] = searchNum)
        {
            found = true;
            pos = middle;
        }
        else if (changed[middle] > searchNum)
        {
            last = middle - 1;
        }
        else
        {
            last = middle + 1;
        }
        cout << middle;
    }

    return pos;
}

double findMean(int changed[], double average,int total)
{
    for (int i = 0; i < total; i++)
    {
        average = average + changed[i];
    }
    average = average / total;

    return average;
}
