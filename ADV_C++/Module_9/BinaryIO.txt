/*
Joshua Long
Comcs 165
Store inventroy data input
11-6-13 Turned in then fixed it so that it now works
COMPLETE
Module 9 Part 2
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int total = 50;

struct inventory
{
    char item[total];
    int quantity;
    double wholeSale;
    double retailCost;
};

void addRecord(inventory onHand, int pass);
void displayItem(inventory onHand);
void changeItem(inventory onHand);
void displayAll(inventory onHand);
void makeReport(inventory onHand);

int main()
{
    int pick = 1;
    inventory onHand;
    int pass = 0;

    while (pick != -1)
    {
        system("CLS");
        cout << "Choose option" << endl;
        cout << "1-Add new item, 2-Display item, 3-Change item" << endl << "4-Display all, 5-Prepare report, -1=Exit" << endl;
        cin >> pick;

        switch (pick)
        {
            case 1: addRecord(onHand,pass);
            pass++;
            break;

            case 2: displayItem(onHand);
            break;

            case 3: changeItem(onHand);
            break;

            case 4: displayAll(onHand);
            break;

            case 5: makeReport(onHand);
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
}

void addRecord(inventory onHand, int pass)
{
    fstream store;
    if (pass == 0)
    {
        store.open("storeInventory.dat", ios::out|ios::binary);
    }
    else
    {
        store.open("storeInventory.dat", ios::out|ios::app|ios::binary);
    }
    if (store.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(EXIT_FAILURE);
    }

    cout << "Enter new item name, quantity on hand, wholesale cost, and retail cost \nseperate them by hitting enter (xxx (enter) yyy)";
    cout << endl;
    cin.ignore();
    cout << "Item name: ";
    cin.getline(onHand.item,total);
    cout << "Item quantity: ";
    cin >> onHand.quantity;
    cout << "Item whole sale cost: ";
    cin >> onHand.wholeSale;
    cout << "Item retail cost: ";
    cin >> onHand.retailCost;

    store.write((char*) &onHand, sizeof(onHand));
    store.close();
}
void displayItem(inventory onHand)
{
    fstream store("storeInventory.dat", ios::in|ios::binary);
    char lookFor[total];

    if (store.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(EXIT_FAILURE);
    }

    cout << "Enter an item to look for and it will display its information" << endl;
    cin.ignore();
    cin.getline(lookFor,total);

    store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    while (!store.eof())
    {
        if(strstr(lookFor,onHand.item))
        {
            cout << "Item found to be matching:" << endl;
            cout << onHand.item << " " << onHand.quantity << " " << onHand.wholeSale << " " << onHand.retailCost << endl;
        }
        store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    }

    cout << "Hit enter to continue";
    cin.ignore();
    store.close();
}

void changeItem(inventory onHand)
{
    fstream store("storeInventory.dat", ios::in|ios::out|ios::binary);
    char lookFor[total];
    int found = 0;

    if (store.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(EXIT_FAILURE);
    }

    cout << "Enter an item to look for and it will display its information" << endl;
    cin.ignore();
    cin.getline(lookFor,total);

    store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    while (!store.eof() || found == 0)
    {
        if(strstr(lookFor,onHand.item))
        {
            cout << "Item found to be matching:" << endl;
            cout << onHand.item << " " << onHand.quantity << " " << onHand.wholeSale << " " << onHand.retailCost << endl;
            cout << "Enter new item information";
            cout << endl;

            cout << "Item name: ";
            cin.getline(onHand.item,total);
            cout << "Item quantity: ";
            cin >> onHand.quantity;
            cout << "Item whole sale cost: ";
            cin >> onHand.wholeSale;
            cout << "Item retail cost: ";
            cin >> onHand.retailCost;

            long pos = store.tellp();
            store.seekp(pos-sizeof(onHand));

            store.write((char*) &onHand, sizeof(onHand));
            found++;
        }
        store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    }

    if (found == 0)
    {
        cout << "No items found to be matching" << endl;
        cout << "Done. Hit enter to continue";
        cin.ignore();
    }
    else
    {
        cin.ignore();
        cout << "Done. Hit enter to continue";
        cin.ignore();
    }
    store.close();
}

void displayAll(inventory onHand)
{
    fstream store("storeInventory.dat", ios::in|ios::binary);
    if (store.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(EXIT_FAILURE);
    }
    cout << "Inventory List" << endl;

    store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    while (!store.eof())
    {
        cout << onHand.item << " " << onHand.quantity << " " << onHand.wholeSale << " " << onHand.retailCost << endl;
        store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    }

    cin.ignore();
    cout << "Hit enter to continue";
    cin.ignore();
    store.close();
}

void makeReport(inventory onHand)
{
    int totalWhole = 0, totalRetail = 0, totalQuantity = 0;
    fstream store("storeInventory.dat", ios::in|ios::binary);

    if (store.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(EXIT_FAILURE);
    }
    cout << "Creating report...";

    store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    while (!store.eof())
    {
        totalWhole = totalWhole + onHand.wholeSale;
        totalRetail = totalRetail + onHand.retailCost;
        totalQuantity = totalQuantity + onHand.quantity;
        store.read(reinterpret_cast<char*>(&onHand), sizeof(onHand));
    }

    fstream report ("report.dat", ios::out);
    if (report.fail())
    {
        cout << "ERROR-No file to store information on!";
        exit(EXIT_FAILURE);
    }
    report << "Total quantity of items in store: " << totalQuantity << endl << endl;
    report << "Total whole sale of items in store: $" << totalWhole << endl << endl;
    report << "Total retail cost of items in store: $" << totalRetail << endl << endl;
    report << "Total whole sale value of items in store: $" << (totalWhole * totalQuantity) << endl << endl;
    report << "Total retail cost value of items in store: $" << (totalRetail * totalQuantity) << endl << endl;

    cout << endl << "Total quantity of items in store: " << totalQuantity << endl << endl;
    cout << "Total whole sale of items in store: $" << totalWhole << endl << endl;
    cout << "Total retail cost of items in store: $" << totalRetail << endl << endl;
    cout << "Total whole sale value of items in store: $" << (totalWhole * totalQuantity) << endl << endl;
    cout << "Total retail cost value of items in store: $" << (totalRetail * totalQuantity) << endl << endl;

    report.close();

    cin.ignore();
    cout << "Done. Hit enter to continue";
    cin.ignore();
    store.close();
}
