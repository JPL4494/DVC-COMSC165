/*
Joshua Long
Comcs 165
Palindrome finder
TURN IN DATE
COMPLETE
Module 6 Part 1
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char word[50];
    int length;
    bool yes = false;

    cout << "Enter the word, sentence or number that you would like to " << endl << "see if it is a palindrome up to 50 characters" << endl;
    cout << endl << "Enter word: ";
    cin.getline(word,50);

    length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (word[i] == word[length - 1 - i])
            {
                yes = true;
            }
            else
            {
                yes = false;
                break;
            }
    }

    if (yes)
    {
        cout << endl << "Congrulations, your input is a palindrome!";
    }

    if (!yes)
    {
        cout << endl << "Your input is not a palindrome, try again";
    }
}
