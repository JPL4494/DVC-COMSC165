/*
Joshua Long
Comcs 165
Inputed number swap
9-8-13
Complete
Module 2 Part 1
*/


#include<iostream>

using namespace std;

void change(int & num1, int & num2);

int main()
{
    int num1, num2;

    cout << "This program will take two numbers you give and swap them and then give it back.\n\n";

    cout << "Number 1: ";
    cin >> num1;

    cout << "Number 2: ";
    cin  >> num2;

    cout << endl << "The two numbers you entered were "<< num1 << " and " << num2 << endl << endl;

    change(num1,num2);

    cout << "After swapping, your first number is " << num1 << " which is the value of number 2" << endl << endl;
    cout << "Your second number is " << num2 << " which is the value of number 1" << endl;

}

void change(int & num1, int & num2)
{
    int temp;

    temp = num1;
    num1 = num2;
    num2 = temp;
}
