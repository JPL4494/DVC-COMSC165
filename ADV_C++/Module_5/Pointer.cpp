/*
Joshua Long
Comcs 165
Number of movies student watch
TURN IN DATE
NOT COMPLETE NNED TO PUT IN POINTERS
Module 5 Part 1
*/

#include <iostream>

using namespace std;

double findAverage(int av[], int numStudent);
int sortArray(int sorted[], int numStudent);
int findMedian(int numMovie[], int numStudent);
int findMode(int numMovie[], int numStudent);

int main ()
{
    int numStudent;
    int average = 0, median = 0, mode = 0;

    cout << "How many students did you interview?" << endl;
    cin >> numStudent;

    int * numMovie = new int[numStudent];
    int * sortNum = new int[numStudent];

    for (int i = 0; i < numStudent; i++)
    {
        do{
            cout << endl << "Number of movies student " << i + 1 << " saw: ";
            cin >> numMovie[i];
            sortNum[i] = numMovie[i];
        }while (numMovie[i] < 0);
    }

    average = findAverage(numMovie,numStudent);
    sortArray(sortNum,numStudent);

    cout << average << endl;

    for(int i = 0; i < numStudent; i++)
    {
        cout << sortNum[i] << " ";
    }
    cout << endl;

    delete [] sortNum;
    delete [] numMovie;

}

double findAverage(int av[], int numStudent)
{
    int temp = 0;

    for (int i = 0; i < numStudent; i++)
    {
        temp = temp + av[i];
    }

    temp = temp / numStudent;

    delete [] av;

    return temp;
}
int sortArray(int sorted[], int numStudent)
{
    int temp;

    for (int i = 0; i < numStudent; i++)
    {
        for (int j = i + 1; j < numStudent; j++)
        {
            if (sorted[j] < sorted[i])
            {
                temp = sorted[j];
                sorted[j] = sorted[i];
                sorted[i] = temp;
            }
        }
    }

    delete [] sorted;
}
int findMedian(int numMovie[], int numStudent)
{
    //
}
int findMode(int numMovie[], int numStudent)
{
    //
}
