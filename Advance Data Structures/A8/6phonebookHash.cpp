/*
 * 6phonebookHash.cpp
 *
 *
 */
#include<iostream>
using namespace std;
#define SIZE 10
class Record
{
public:
    string name;
    string phone;
    string flag;

    Record()
    {
        name = "";
        phone = "";
        flag = "EMPTY";
    }
};

class PhoneBook
{
public:
    int capacity = 0;
    void insertRecord(Record table[]);
    int getHashCode(string name);
    void displayRecord(Record table[]);
    void searchRecord(Record table[]);
};

int PhoneBook::getHashCode(string name)
{
    int sum = 0;
    for(int i =0; i<name.length(); i++)
        sum = sum + name[i];

    return sum % SIZE;
}

void PhoneBook::insertRecord(Record table[])
{
    if(capacity == SIZE)
    {
        cout<<"\nPhonebook is full, cannot insert!";
        return;
    }
    Record r;
again:
    cin.ignore();
    cout<<"\nEnter the name: ";
    getline(cin, r.name);
    cout<<"\nEnter phone no. : ";
    getline(cin, r.phone);
    int code = getHashCode(r.name);

    while(table[code].flag == "OCCUPIED")
    {
        if(table[code].name == r.name)
        {
            cout<<"\n"<<r.name<< " already exists! Enter another record.";
            goto again;
        }
        code++;
        code = code % SIZE;
    }

    table[code] = r;
    table[code].flag = "OCCUPIED";
    capacity++;

}

void PhoneBook::displayRecord(Record table[])
{
    cout<<"\nNAME: " << "\t\t" << "PHONE";
    for(int i=0 ; i<SIZE ; i++)
    {
        if(table[i].flag == "OCCUPIED")
            cout<<"\n"<<table[i].name<<"\t\t"<<table[i].phone;
    }
}
void PhoneBook::searchRecord(Record table[])
{
    Record key;
    cout<<"\nEnter the name to search: ";
    cin>>key.name;
    for(int i=0 ; i<SIZE ; i++)
    {
        if(key.name == table[i].name)
        {
                cout<<"\n\nRecord  found!"<<"\n"<<table[i].name<<"\t\t"<<table[i].phone;
                return ;
        }
    }
    cout<<"\nRecord not found!";

}

int main()
{
    int choice;
    PhoneBook p1;
    Record table[SIZE];
MENU:
    cout<<"\n\nMENU: ";
    cout<<"\n1. Insert record";
    cout<<"\n2. Search record";
    cout<<"\n3. Display records";
    cout<<"\nEnter your choice: ";
    cin>> choice;
    switch(choice)
    {
    case 1:
        p1.insertRecord(table);
        break;
    case 2:
        p1.searchRecord(table);
        break;
    case 3:
        p1.displayRecord(table);
        break;
    case 4:
        return 0;
    default:
        cout<<"\nInvalid choice! Try again!";
    }
    goto MENU;
    return 0;
}
