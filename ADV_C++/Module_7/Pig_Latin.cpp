/*
Joshua Long
Comcs 165
Pig Latin
10-20-13
COMPLETE
Module 7 Part 1
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence;
    char temp;
    int length, place = 0;
    int j = place, i;

    cout << "This program will convert your sentence into Pig Latin";
    cout << endl << endl << "Enter sentence here: " << endl;
    getline(cin,sentence);

    cout << endl;

    length = sentence.length();

    for (i = 0; i < length; i++)
    {
        if (i == 0 && sentence[1] == ' ')
        {
            sentence.insert(1, "ay ");
            i += 3;
            length += 3;

            place += 4;
        }

        else if (sentence[i] == ' ' && sentence[i-2] == ' ')
        {
            sentence.insert(i, "ay ");
            i += 3;
            length += 3;

            place += 3;
        }

        else if (sentence[i] == ' ')
        {
            for (j = place; j < i-1; j++)
            {
                temp = sentence[j];
                sentence[j] = sentence[j + 1];
                sentence[j + 1] = temp;
                place = i;
            }
            sentence.insert(place, "ay");

            i += 2;
            length += 2;

            place += 3;
        }

    }

    if (length > 2)
    {
        for (j = place; j < i-1; j++)
            {
                temp = sentence[j];
                sentence[j] = sentence[j + 1];
                sentence[j + 1] = temp;
                place = i;
            }
        sentence.insert(place, "ay");
    }

    if (length == 1)
    {
        sentence.insert(1, "ay");
    }

    if (sentence[2] == 'y' && sentence[3] == ' ')
    {
        sentence.erase(3,3);
    }

    cout << sentence << endl << endl;
}
