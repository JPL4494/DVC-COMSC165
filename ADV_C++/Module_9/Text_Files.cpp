/*
Joshua Long
Comcs 165
Encrypts and decrypts a .txt file
11-3-13
COMPLETE
Module 9 Part 1
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int total = 99999;

void code (fstream & source, fstream & coded);
void decode (fstream & coded, fstream & translated);

int main()
{
    fstream source, coded, translated;

    source.open("source.txt", ios::in);
    coded.open("coded.txt", ios::out|ios::in);
    translated.open("converted.txt", ios::out);
    if (source.fail())
    {
        cout << "ERROR 1";
        exit(-1);
    }
    if (!coded)
    {
        cout << "ERROR 2";
        exit(-1);
    }
    if (!translated)
    {
        cout << "ERROR 3";
        exit(-1);
    }

    cout << "Encoded message:" << endl;
    code(source,coded);
    source.close();
    coded.close();

    coded.open("coded.txt", ios::out|ios::in);
    translated.open("converted.txt", ios::out);
    cout << endl << endl << "Decoded message:" << endl;
    decode(coded,translated);

    cout << endl << endl << endl;

    coded.close();
    translated.close();
}

void code (fstream & source, fstream & coded)
{
    char change[total];

    source.get(change,total);
    for (int i = 0; i < strlen(change); i++)
    {
        change[i] += 4 + i;
        coded << change[i];
        cout << change[i];
    }
}

void decode (fstream & coded, fstream & translated)
{
    char change[total];

    coded.get(change,total);
    for (int i = 0; i < strlen(change); i++)
    {
        change[i] -= 4 + i;
        translated << change[i];
        cout << change[i];
    }
}

