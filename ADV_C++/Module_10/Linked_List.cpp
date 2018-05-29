/*
Joshua Long
Comcs 165
Make an ordered and searchable list of numbers
11-17-13
COMPLETE
Module 10
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int num;
    Node * next;
};

void addNumber(Node * &);
void searchNumber(Node * &);
void deleteNumber(Node * &);
void displayAll(Node *);

int main()
{
    int pick = 1, pass = 0;

    Node * head = NULL;

    cout << "This program allows you to enter many numbers," << endl << "organizes it, and lets you change it" << endl;

    while (pick != 5)
    {
        if (pass > 0)
        {
            system("CLS");
        }
        cout << "1- Add number  2- Search  3- Delete number  4- Display all  5- Exit" << endl;
        cin >> pick;
        system("CLS");
        switch (pick)
        {
            case 1: addNumber(head);
            break;

            case 2: searchNumber(head);
            break;

            case 3: deleteNumber(head);
            break;

            case 4: displayAll(head);
            break;

            case 5: break;

            default: cout << "ERROR: WRONG NUMBER\n";
        }
        pass++;
    }
    cout << "Goodbye" << endl;
}

void addNumber(Node * & head)
{
    int number;

    struct Node * cur;
    struct Node * prev;

    Node * newNode = new Node;

    goback:
    cout << "Enter a number: ";
    cin >> number;

    newNode -> num = number;
    newNode -> next = NULL;

    if (head == NULL)
	{
        head = newNode;
        return;
    }

    for (prev = NULL, cur = head; cur != NULL; prev = cur, cur = cur -> next)
    {
        if (newNode -> num == cur -> num)
        {
            cout << "Number already exists, enter new number" << endl;
            goto goback;
        }
    }

    for (prev = NULL, cur = head; cur != NULL; prev = cur, cur = cur -> next)
    {
        if (newNode -> num < cur -> num)
            break;
    }

    if (prev == NULL)
    {
        newNode -> next = head;
        head = newNode;
    }
    else
	{
		newNode -> next = prev -> next;
		prev -> next = newNode;
    }
}

void searchNumber(Node * & head)
{
    int number;

    Node * prev = NULL;
    Node * curr = NULL;

    cout <<"Enter a number to look for: ";
    cin >> number;

    if (head == NULL)
    {
        cout << "List is empty! Add numbers first";
        return;
    }

    for(prev = NULL, curr = head; curr != NULL; prev = curr, curr = curr -> next)
    {
        if (curr -> num == number)
            break;
    }

    if (curr == NULL)
    {
        cout << "Number not found" << endl;
    }
    else
    {
        cout << "Number found! " << number;
    }
    cin.ignore();
    cout << endl << "Press enter to continue";
    cin.ignore();
}

void deleteNumber(Node *& head)
{
    Node * prev = NULL;
    Node * curr = NULL;
    int number;

    cout <<"Enter a number to delete: ";
    cin >> number;

    if (head == NULL)
    {
        cout << "List is empty! Add numbers first";
        return;
    }

    if(head -> num == number)
    {
        curr = head->next;
        head = curr;
        return;
    }

    for(prev = NULL, curr = head; curr != NULL; prev = curr, curr = curr -> next)
    {
        if (curr -> num == number)
            break;
    }

    if (curr == NULL)
    {
        cout << "Number not found" << endl;
    }

    else
    {
        prev -> next = curr -> next;
        delete curr;
        curr = NULL;
        cout << "Number deleted....";
    }

    cin.ignore();
    cout << endl << "Press enter to continue";
    cin.ignore();
}

void displayAll(Node * head)
{
    cout << "All numbers: " << endl;

    for (Node * curr = head; curr != NULL; curr = curr -> next)
    {
        cout << curr -> num << " " ;
    }
    cin.ignore();
    cout << endl << "Press enter to continue";
    cin.ignore();
}

