/*
Joshua Long
Comcs 165
Store inventroy data input
11-3-13
NOT COMPLETE WON'T ALLOW MORE THAN 1 ITEM INPUT
Module 9 Part 2
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct inventory
{
    string item;
    int quantity;
    double wholeSale;
    double retailCost;
};

void addRecord(fstream & store, inventory onHand[], int inStore);
void displayItem(fstream & store, inventory onHand[], int inStore);
void changeItem(fstream & store, inventory onHand[], int inStore);
void displayAll(fstream & store, inventory onHand[], int inStore);
void makeReport(fstream & store, inventory onHand[], int inStore);

int main()
{
    int inStore = 0, pick = 1;
    inventory onHand[inStore];
    fstream store;

    store.open("storeInventory.txt", ios::out|ios::binary);
    if (store.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(-1);
    }

    while (pick != -1)
    {
        system("CLS");
        cout << "Choose option" << endl;
        cout << "1-Add new item, 2-Display item, 3-Change item" << endl << "4-Display all, 5-Prepare report, -1=Exit" << endl;
        cin >> pick;

        switch (pick)
        {
            case 1: addRecord(store,onHand,inStore);
            inStore++;
            break;

            case 2: displayItem(store,onHand,inStore);
            break;

            case 3: changeItem(store,onHand,inStore);
            break;

            case 4: displayAll(store,onHand,inStore);
            break;

            case 5: makeReport(store,onHand,inStore);
            break;
        }
    }
    if (pick != -1)
    {
        cin.ignore();
        cin.ignore();
        cin.ignore();
        cin.ignore();
    }

    store.close();
}

void addRecord(fstream & store, inventory onHand[], int inStore)
{
    cout << "Enter new item name, quantity on hand, wholesale cost, and retail cost \nseperate them by hitting enter (xxx (enter) yyy)";
    cout << endl;
    cin.ignore();
    cout << "Item name: ";
    getline(cin,onHand[inStore].item);
    cout << "Item quantity: ";
    cin >> onHand[inStore].quantity;
    cout << "Item whole sale cost: ";
    cin >> onHand[inStore].wholeSale;
    cout << "Item retail cost: ";
    cin >> onHand[inStore].retailCost;
    store << onHand[inStore].item << " ";
    store << onHand[inStore].quantity << " ";
    store << onHand[inStore].wholeSale << " ";
    store << onHand[inStore].retailCost << endl;
}

void displayItem(fstream & store, inventory onHand[], int inStore)
{
    string lookFor;
    int pos = 0, match = 0;
    int got [match];

    cout << "Enter an item to look for and it will display its information" << endl;
    cin.ignore();
    getline(cin,lookFor);

    for (int i = 0; i < inStore; i++)
    {
        store >> onHand[i].item;
        store >> onHand[i].quantity;
        store >> onHand[i].wholeSale;
        store >> onHand[i].retailCost;
        pos = onHand[i].item.find(lookFor);
        if (pos >= 0)
        {
            got[match] = i;
            match++;
        }

        cout << "Items found matching with given name: " << endl;
        for (int i = 0; i < match; i++)
        {
            cout << onHand[got[i]].item << " " << onHand[got[i]].quantity << " " << onHand[got[i]].wholeSale << " " << onHand[got[i]].retailCost;
        }

    }

    if (match == 0)
    {
        cout << "No items found to be matching";
    }

    cout << endl << "Hit enter to continue";
    cin.ignore();
}

void changeItem(fstream & store, inventory onHand[], int inStore)
{
    string lookFor;
    int pos = 0, match = 0;
    int got [match];

    cout << "Enter an item to look for and it will display its information" << endl;
    cin.ignore();
    getline(cin,lookFor);

    for (int i = 0; i < inStore; i++)
    {
        store >> onHand[i].item;
        store >> onHand[i].quantity;
        store >> onHand[i].wholeSale;
        store >> onHand[i].retailCost;
        pos = onHand[i].item.find(lookFor);
        if (pos >= 0)
        {
            got[match] = i;
            match++;
        }

        if (match != 0)
        {
            cout << "Enter new information (ALL INFORMATION)";
            cout << endl << "Name: ";
            cin.ignore();
            getline(cin,onHand[i].item);
            cout << "Quantity: ";
            cin >> onHand[i].quantity;
            cout << "Wholesale price: ";
            cin >> onHand[i].wholeSale;
            cout << "Retail cost: ";
            cin >> onHand[i].retailCost;

            store << onHand[i].item << " ";
            store << onHand[i].quantity << " ";
            store << onHand[i].wholeSale << " ";
            store << onHand[i].retailCost << endl;
        }

    }

    if (match == 0)
    {
        cout << "No items found to be matching";
    }
    cin.ignore();

    cout << endl << "Hit enter to continue";
    cin.ignore();
}

void displayAll(fstream & store, inventory onHand[], int inStore)
{
    for (int i = 0; i < inStore; i++)
    {
        store >> onHand[i].item;
        store >> onHand[i].quantity;
        store >> onHand[i].wholeSale;
        store >> onHand[i].retailCost;

        cout << onHand[i].item << " " << onHand[i].quantity << " " << onHand[i].wholeSale << " " << onHand[i].retailCost << endl;
    }
    cin.ignore();
    cout<< "Hit enter to continue";
    cin.ignore();
}

void makeReport(fstream & store, inventory onHand[], int inStore)
{
    int totalWhole = 0, totalRetail = 0, totalQuantity = 0;
    cout << "Creating report...";

    for (int i = 0; i < inStore; i++)
    {
        store >> onHand[i].item;
        store >> onHand[i].quantity;
        store >> onHand[i].wholeSale;
        store >> onHand[i].retailCost;

        totalWhole = totalWhole + onHand[i].wholeSale;
        totalRetail = totalRetail + onHand[i].retailCost;
        totalQuantity = totalQuantity + onHand[i].quantity;
    }

    fstream report;
    report.open("report.txt", ios::out);
    report << "Total quantity of items in store: " << totalQuantity << endl;
    report << "Total whole sale of items in store: $" << totalWhole << endl;
    report << "Total retail cost of items in store: $" << totalRetail << endl;

    report.close();

    cin.ignore();
    cout << "Done. Hit enter to continue";
    cin.ignore();
}
