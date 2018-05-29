/*
Joshua Long
Comcs 165
Pig Latin
TURN IN DATE
NOT COMPLETE
Module 7 Part 1
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence;
    string ending("ay");
    char temp;
    int length, place = 0;

    cout << "This program will convert your sentence into Pig Latin";
    cout << endl << endl << "Enter sentence here (in lowercase): ";
    getline(cin,sentence);

    length = sentence.length();

    for (int i = 0; i < length; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            for (int j = place; j < i - 1; j++)
            {
                temp = sentence[j];
                sentence[j] = sentence[j+1];
                sentence[j+1] = temp;

                place = j;
            }
            i += 2;
            length += 2;
            sentence.insert(place, "ay");
        }

        if (i == length - 1)
        {
            for (int j = place; j < i - 1; j++)
            {
                temp = sentence[j];
                sentence[j] = sentence[j+1];
                sentence[j+1] = temp;

                place = j;
            }
            //i += 2;
            //length += 2;
            //sentence.insert(place, "ay");
        }
    }

    sentence += ending;

    cout << sentence;
}
