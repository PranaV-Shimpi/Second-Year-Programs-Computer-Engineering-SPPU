/*
 * 10fileHandling.cpp

 */

#include<iostream>
#include<fstream>

using namespace std;

class student
{
	int roll;
	int div;
	char name[30];
	char address[50];
	int size;
public:
	student()
	{
		roll = 0;
		div = 0;
		size = 0;
	}

	void create();
	void addRecord();
	void deleteRecord();
	void searchRecord();
	void modifyRecord();
	void displayAll();
};

void student::create()
{
	ofstream file;
	file.open("db.dat", ios::out|ios::binary);
	if(!file)
	{
		cout<<"\nFailed to create database!";
		return ;
	}
	student obj1;
	cout<<"\nEnter the number of students: ";
	cin>>obj1.size;
	cout<<"\nEnter the records: ";
	for(int i=0 ; i<obj1.size ; i++)
	{
		cout<<"\nEnter the data for student " << i+1 << " :";
		cout<<"\nRoll number: ";
		cin>>obj1.roll;
		cout<<"Division: ";
		cin>>obj1.div;
		cin.ignore();
		cout<<"Name: ";
		cin.getline(obj1.name, 30);
		cout<<"Address: ";
		cin.getline(obj1.address, 50);
		file.write((char *)&obj1, sizeof(obj1));
	}
	cout<<"\n\nDatabase successfully created!";
	file.close();

}
void student::addRecord()
{
	ofstream file;
	file.open("db.dat", ios::app|ios::out|ios::binary);
	if(!file)
	{
		cout<<"\nFailed to create database!";
		return ;
	}
	student obj1;
	cout<<"\nEnter the details: ";
	cout<<"\nRoll number: ";
	cin>>obj1.roll;
	cout<<"Division: ";
	cin>>obj1.div;
	cin.ignore();
	cout<<"Name: ";
	cin.getline(obj1.name, 30);
	cout<<"Address: ";
	cin.getline(obj1.address, 50);
	file.write((char *)&obj1, sizeof(obj1));
	size++;
}
void student::displayAll()
{
	ifstream file;
	file.open("db.dat", ios::binary|ios::in);
	if(!file)
	{
		cout<<"\nFailed to open database!";
		return ;
	}
	student obj;
	cout<<"\nDATABASE: \n";
	while(1)
	{
		file.read((char*)&obj, sizeof(obj));
		if(file.eof())
			break;

		cout<<"\n\nRoll number: ";
		cout<<obj.roll;
		cout<<"\nDivision: ";
		cout<<obj.div;
		cout<<"\nName: ";
		cout<<obj.name;
		cout<<"\nAddress: ";
		cout<<obj.address;

	}
	file.close();

}

void student::searchRecord()
{
	ifstream file;
	int key, flag=0;
	file.open("db.dat", ios::binary|ios::in);
	if(!file)
	{
		cout<<"\nFailed to open database!";
		return ;
	}
	student obj;
	cout<<"\nEnter the roll no. to search: ";
	cin>>key;
	while(1)
	{
		file.read((char*)&obj, sizeof(obj));
		if(file.eof())
			break;
		if(obj.roll==key)
		{
			flag=1;
			cout<<"\n\nRecord found!";
			cout<<"\nRoll number: ";
			cout<<obj.roll;
			cout<<"\nDivision: ";
			cout<<obj.div;
			cout<<"\nName: ";
			cout<<obj.name;
			cout<<"\nAddress: ";
			cout<<obj.address;
		}
	}
	if(flag==0)
		cout<<"\nRecord not found!";
	file.close();
}

void student::modifyRecord()
{
	fstream file;
	int key, flag=0, pos=0;
	file.open("db.dat", ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<"\nFailed to open database!";
		return ;
	}
	student obj, newObj;
	cout<<"\nEnter the roll no. to modify: ";
	cin>>key;
	while(1)
	{
		file.read((char*)&obj, sizeof(obj));
		if(file.eof())
			break;
		if(obj.roll==key)
		{
			flag=1;
			cout<<"\n\nRecord found! Current record: ";
			cout<<"\nRoll number: ";
			cout<<obj.roll;
			cout<<"\nDivision: ";
			cout<<obj.div;
			cout<<"\nName: ";
			cout<<obj.name;
			cout<<"\nAddress: ";
			cout<<obj.address;

			cout<<"\nEnter the new record: ";
			cout<<"\nRoll number: ";
			cin>>newObj.roll;
			cout<<"Division: ";
			cin>>newObj.div;
			cin.ignore();
			cout<<"Name: ";
			cin.getline(newObj.name, 30);
			cout<<"Address: ";
			cin.getline(newObj.address, 50);
			pos = file.tellg();
			file.seekp(pos - sizeof(obj));
			file.write((char *)&newObj, sizeof(newObj));
			return;
		}
	}
	if(flag==0)
		cout<<"\nRecord not found!";
	file.close();
}

void student::deleteRecord()
{
	ifstream file;
	ofstream tempFile;
	int key, flag=0;
	file.open("db.dat", ios::binary|ios::in);
	tempFile.open("tempdb.dat", ios::binary|ios::out);
	if(!file)
	{
		cout<<"\nFailed to open database!";
		return ;
	}
	student obj;
	cout<<"\nEnter the roll no. to delete: ";
	cin>>key;
	while(1)
	{
		file.read((char*)&obj, sizeof(obj));
		if(file.eof())
			break;
		if(obj.roll==key)
		{
			flag=1;
			cout<<"\n\nRecord found!";
			cout<<"\nRoll number: ";
			cout<<obj.roll;
			cout<<"\nDivision: ";
			cout<<obj.div;
			cout<<"\nName: ";
			cout<<obj.name;
			cout<<"\nAddress: ";
			cout<<obj.address;
			continue;
		}
		else
			tempFile.write((char*)&obj, sizeof(obj));
	}

	if(flag==0)
		cout<<"\nRecord not found!";

	else
	{
		remove("db.dat");
		rename("tempdb.dat", "db.dat");
	}
	cout<<"\nDeleted record successfully";
	file.close();
	tempFile.close();
}
int main()
{
MENU:
	int choice;
	student db1;
	cout<<"\n\n\nSTUDENT DATABASE MANAGEMENT";
	cout<<"\n1. Create database";
	cout<<"\n2. Add record";
	cout<<"\n3. Search record";
	cout<<"\n4. Modify record";
	cout<<"\n5. Delete record";
	cout<<"\n6. Display database";
	cout<<"\n7. EXIT";
	cout<<"\n\nEnter your choice: ";
	cin>> choice;
	switch(choice)
	{
	case 1:
		db1.create();
		break;
	case 2:
		db1.addRecord();
		break;
	case 3:
		db1.searchRecord();
		break;
	case 4:
		db1.modifyRecord();
		break;
	case 5:
		db1.deleteRecord();
		break;
	case 6:
		db1.displayAll();
		break;
	case 7:
		return 0;
	default:
		cout<<"\nInvalid choice! Try again!";
	}
	goto MENU;


}






