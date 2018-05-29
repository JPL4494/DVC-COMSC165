/*
Joshua Long
Comcs 165
Array into vector
9-15-13
COMPLETE
Module 3 Part 3
*/

#include <iostream>
#include <vector>

using namespace std;

bool testPIN(vector<int>, vector<int>);

int main ()
{
    int pin1[7] = {2, 4, 1, 8, 7, 9, 0};
    int pin2[7] = {2, 4, 6, 8, 7, 9, 0};
    int pin3[7] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> p1 (pin1,pin1 + sizeof(pin1));
    vector<int> p2 (pin2,pin2 + sizeof(pin2));
    vector<int> p3 (pin3,pin3 + sizeof(pin3));

    if (testPIN(p1, p2))
      cout << "ERROR: pin1 and pin2 report to be the same.\n";
   else
      cout << "SUCCESS: pin1 and pin2 are different.\n";

   if (testPIN(p1, p3))
      cout << "ERROR: pin1 and pin3 report to be the same.\n";
   else
      cout << "SUCCESS: pin1 and pin3 are different.\n";

   if (testPIN(p1, p1))
      cout << "SUCCESS: pin1 and pin1 report to be the same.\n";
   else
      cout << "ERROR: pin1 and pin1 report to be different.\n";
}

bool testPIN(vector<int> test1, vector<int> data1)
{
   for (int i = 0; i < 7; i++)
   {
      if (test1.at(i) != data1.at(i))
         {return false;}
   }
   return true;
}
