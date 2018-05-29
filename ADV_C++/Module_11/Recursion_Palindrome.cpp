/*
Joshua Long
Comcs 165
Palindrome finder
11-24-13
COMPLETE
Module 11 Part 1
*/

#include <iostream>
#include <cstring>

using namespace std;

bool palindromeCheck(char phrase[], int i, int length, bool palin);

int main()
{
    char phrase[50];
    int i = 0, length;
    bool palin = false;

    cout << "This program allows you to see if the phrase you enter is a palindrome" << endl << endl;

    cout << "Enter phrase: ";
    cin.getline(phrase,50);
    length = strlen(phrase);

    palin = palindromeCheck(phrase,i,length,palin);

    if (palin == true)
    {
        cout << endl <<"Congratulations! Your phrase is a palindrome." << endl;
    }
    else
    {
        cout << endl << "Your phrase is not a palindrome." << endl;
    }
}

bool palindromeCheck(char phrase[], int i, int length, bool palin)
{
    while (i < length)
    {
        if (phrase[i] == phrase[length - 1 - i])
        {
            palin = true;
            i++;
            palin = palindromeCheck(phrase,i,length,palin);
        }
        else
        {
            palin = false;
            break;
        }
    }
    return palin;
}
