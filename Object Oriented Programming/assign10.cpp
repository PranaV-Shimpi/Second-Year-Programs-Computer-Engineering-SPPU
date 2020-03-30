/*
Assignment 10:

Write a program that initializes the random-access file
hardware.dat to 100 empty records, lets you input the data
concerning each tool, enables you to list all your tools,
lets you delete a record for a tool that you no longer have
and lets you update any information in the file.
The tool identification number should be the record number.

Done by: Pranav Shimpi
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define max 10
class item
{
public:
	int no;
	char name[20];
	int qty;
	float cost;
	item()
	{
		no=0;
		strcpy(name,"");
		qty=0;
		cost=0;
	}
	~item(){}
	void read();
	void display();
};

void item::read()
{
	cout<<"Enter the number ";
	cin>>no;
	cout<<"Enter your name ";
	cin>>name;
	cout<<"Enter the quantity ";
	cin>>qty;
	cout<<"Enter the cost ";
	cin>>cost;
}

void item::display()
{
	cout<<"\nNumber: "<<no;
	cout<<"\nName: "<<name;
	cout<<"\nQuantity: "<<qty;
	cout<<"\nCost: "<<cost;
}

int main()
{
	fstream file;
	item obj;
	int choice;

	do
	{
		cout<<"\n\n****************MENU****************\n";
		cout<<"1.Create new file\n2.Add record\n3.Display\n4.Modify\n5.Delete\n0.Exit\nEnter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 0:break;
			case 1:
			{
				file.open("hardware.dat",ios::out|ios::ate);//no ios::in as file doesn't exist
				for (int i = 0; i < 100; i++)
					file.write((char*)&obj,sizeof(obj));
				file.close();
				cout<<"File successfully created\n";
			}
			break;
			case 2:
			{
				file.open("hardware.dat",ios::in|ios::out|ios::ate);
				obj.read();
				int wloc=(obj.no-1)*sizeof(obj);
				if(file.eof())
					file.clear();
				file.seekp(wloc);
				file.write((char*)&obj,sizeof(obj));
				file.close();
			}
			break;
			case 3:
			{
				file.open("hardware.dat",ios::in|ios::out|ios::ate);
				file.seekg(0,ios::beg);
				while(file.read((char*)&obj,sizeof(obj)))
					if(obj.no!=0)
						obj.display();
				file.close();
			}
			break;
			case 4:
			{

				file.open("hardware.dat",ios::in|ios::out|ios::ate);
				cout<<"Enter item no. to modify ";
				int n;
				cin>>n;
				int loc=(n-1)*sizeof(obj);
				if(file.eof())
					file.clear();
				file.seekp(loc);
				cout<<"Enter new data\n";
				obj.read();
				file.write((char*)&obj,sizeof(obj));
				file.close();
			}
			break;
			case 5:
			{
				file.open("hardware.dat",ios::in|ios::out|ios::ate);
				cout<<"Enter item no. you want to delete ";
				int d;
				cin>>d;
				int dloc=(d-1)*sizeof(obj);
				if(file.eof())
					file.clear();
				file.seekp(dloc);
				obj.no=0;
				strcpy(obj.name,"");
				obj.qty=0;
				obj.cost=0;
				file.write((char*)&obj,sizeof(obj));
				file.close();
			}
			break;
			default:
			cout<<"Invalid choice\n";
		}
	}while(choice!=0);
	return 0;
}

/*
Output:

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 1
File successfully created

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 2
Enter the number 14
Enter your name we
Enter the quantity 2
Enter the cost 56

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 2
Enter the number 56
Enter your name asd
Enter the quantity 5
Enter the cost 89

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 2
Enter the number 78
Enter your name ceed
Enter the quantity 4
Enter the cost 77

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 3

Number: 14
Name: we
Quantity: 2
Cost: 56
Number: 56
Name: asd
Quantity: 5
Cost: 89
Number: 78
Name: ceed
Quantity: 4
Cost: 77

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 4
Enter item no. to modify 56
Enter new data
Enter the number 56
Enter your name rfv
Enter the quantity 8
Enter the cost 99

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 5
Enter item no. you want to delete 14

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice 3

Number: 56
Name: rfv
Quantity: 8
Cost: 99
Number: 78
Name: ceed
Quantity: 4
Cost: 77

****************MENU****************
1.Create new file
2.Add record
3.Display
4.Modify
5.Delete
0.Exit
Enter your choice
*/
