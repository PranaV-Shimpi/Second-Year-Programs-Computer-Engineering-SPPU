/*
Assignment 8:

Use a class object to store each set of data, access the file created
and implement the following tasks:
 I. Determine the telephone number of specified person
 II.Determine the name if telephone number is known
III.Update the telephone number, whenever there is a change.

Done by: Pranav Shimpi
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 50
class tel
{
	public:
	char name[MAX];
	long no;

			void read()
			{
				cout<<"\n Enter the name:-\t";
				cin>>name;
				cout<<"\n Enter the telephone number:-\t";
				cin>>no;
			}
			void display()
			{
				cout<<"\n Name:-\t"<<name;
				cout<<"\n Telephone no:-\t"<<no;
			}
			long returnno()
			{
				return no;
			}
};
void writedata()
{
	fstream file;
	int i,n;
	tel a[MAX];
	file.open("telephone.txt",ios::binary | ios::out);
	cout<<"\n Enter the no. of users ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		a[i].read();
		file.write((char*)&a[i],sizeof(a[i]));
	}
	file.close();
}
void disp()
{
	fstream file;
	int i,n;
	tel a[MAX];
	file.open("telephone.txt",ios::binary | ios::in);
	while(file.read((char*)&a[i],sizeof(a[i])))
	{
		a[i].display();
	}
	file.close();
}
void search(long no1)
{
	fstream file;
	int i,n,flag=0;
	tel a[MAX];
	file.open("telephone.txt",ios::out | ios::in);
	while(file.read((char*)&a[i],sizeof(a[i])))
	{
		if(a[i].returnno()==no1)
		{
			cout<<"\n Number is found";
			a[i].display();
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\n  Number is not found";
	file.close();
}
void searchname(char nm[MAX])
{
	fstream file;
	int i,n,flag=0;
	tel a[MAX];
	file.open("telephone.txt",ios::out | ios::in);
	while(file.read((char*)&a[i],sizeof(a[i])))
	{
		if(strcmp(a[i].name,nm)==0)
		{
			cout<<"\nName found";
			a[i].display();
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\nName not found";
	file.close();
}
void modify(long no2)
{
	fstream file;
	int i,n,flag=0;
	tel b[MAX];
	file.open("telephone.txt",ios::out | ios::in);
	while(file.read((char*)&b[i],sizeof(b[i])))
	{
		if(b[i].returnno()==no2)
		{
			cout<<"\n Enter the new detail";
			b[i].read();
			long pos=-1*sizeof(b[i]);
			file.seekp(pos,ios::cur);
			file.write((char*)&b[i],sizeof(b[i]));
			b[i].display();
		}
	}
	file.close();
}
void delete_no(long no3)
{
	int i,n;
	tel c;
	fstream file;
	file.open("telephone.txt",ios::in);
	fstream outfile;
	outfile.open("temp.txt",ios::out);
	while(file.read((char *)&c,sizeof(c)))
	{
		if(c.returnno()!=no3)
		{
			outfile.write((char*)&c,sizeof(c));
			c.display();
		}
	}
	file.close();
	outfile.close();
	remove("telephone.txt");
	rename("temp.txt","telephone.txt");
}
int main()
{
	int ch,i,no1,no2,no3;
	tel a;
	char nm[MAX];
	writedata();
	disp();
	do
	{
		cout<<"\nMenu\n 1.Search name\n 2.Search number\n 3.Modify data\n 4.Delete data";
		cout<<"\n Enter the choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				  cout<<"\n Enter the name to search:-\t";
				  cin>>nm;
				  searchname(nm);
				  break;
			case 2:
				  cout<<"\n Enter the number to search:-\t";
				  cin>>no1;
				  search(no1);
				  break;
			case 3:
				  cout<<"\n Enter the number to be modified:-\t";
				  cin>>no2;
				  modify(no2);
				  break;
			case 4:
				  cout<<"\n Enter the number to be delete:-\t";
				  cin>>no3;
				  delete_no(no3);
				  break;
	   }
	}while(ch>0);
cout<<"\n";
return 0;
}

/*
Output:


 Enter the no. of users 3

 Enter the name:-       qwe

 Enter the telephone number:-   123

 Enter the name:-       asd

 Enter the telephone number:-   456

 Enter the name:-       zxc

 Enter the telephone number:-   789

 Name:- qwe
 Telephone no:- 123
 Name:- asd
 Telephone no:- 456
 Name:- zxc
 Telephone no:- 789
Menu
 1.Search name
 2.Search number
 3.Modify data
 4.Delete data
 Enter the choice 4

 Enter the number to be delete:-        465

 Name:- qwe
 Telephone no:- 123
 Name:- asd
 Telephone no:- 456
 Name:- zxc
 Telephone no:- 789
Menu
 1.Search name
 2.Search number
 3.Modify data
 4.Delete data
 Enter the choice 4

 Enter the number to be delete:-        456

 Name:- qwe
 Telephone no:- 123
 Name:- zxc
 Telephone no:- 789
Menu
 1.Search name
 2.Search number
 3.Modify data
 4.Delete data
 Enter the choice 1

 Enter the name to search:-     qwe

Name found
 Name:- qwe
 Telephone no:- 123
Menu
 1.Search name
 2.Search number
 3.Modify data
 4.Delete data
 Enter the choice 2

 Enter the number to search:-   789

 Number is found
 Name:- zxc
 Telephone no:- 789
Menu
 1.Search name
 2.Search number
 3.Modify data
 4.Delete data
 Enter the choice 3

 Enter the number to be modified:-      123

 Enter the new detail
 Enter the name:-       tgb

 Enter the telephone number:-   741

 Name:- tgb
 Telephone no:- 741
Menu
 1.Search name
 2.Search number
 3.Modify data
 4.Delete data
 Enter the choice
*/
