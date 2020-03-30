/*
Assignment No.13

Write C++ program to store names and mobile numbers of your friends in sorted order on
names. a) Search your friend from list using binary search (recursive and non recursive).
Insert friend if not present in phonebook.

Done by: Pranav Shimpi
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class person
{
public:
	char name[20];
	char mob[10];
	person()
	{
		strcpy(name,"");
		strcpy(mob,"");
	}
	~person(){}
};

class list
{
	person p[20];
	int n;
public:
	list()
	{
		n=0;
	}
	~list(){}
	void sort();
	void read();
	void display();
	int seqsearch(char a[]);
	int binsearch(char a[]);
	void addtolist(char a[]);
	int binrecursive(char a[]);
	int recbinsearch(int,int,char a[]);

};

void list::read()
{
	cout<<"Enter no of records to add\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter name and phone number\n";
		cin>>p[i].name>>p[i].mob;
	}
}

void list::display()
{
	cout<<"The list is: \n\n";
	cout<<setw(20)<<"Name\t\t\tPhone\n";
	for(int i=0;i<n;i++)
		cout<<setw(20)<<p[i].name<<"\t"<<p[i].mob<<"\n";
}

void list::sort()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n-i-1; ++j)
			if (strcmp(p[j].name,p[j+1].name)==1)
			{
				person temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
}

int list::seqsearch(char key[])
{
	for (int i = 0; i < n; ++i)
		if (!strcmp(p[i].name,key))
			return 1;
	return 0;
}

int list::binsearch(char key[])
{
	int lb=0,ub=n,flag=0,mid=0;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(strcmp(key,p[mid].name)==-1)
			ub=mid-1;
		else if(strcmp(key,p[mid].name)==1)
			lb=mid+1;
		else
			return 1;	//found
	}
	return 0;			//not found
}

int list::binrecursive(char key[])
{
	return recbinsearch(0,n-1,key);
}

int list::recbinsearch(int lb,int ub,char key[])
{
	int flag=0,mid=0;
 	if(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(!strcmp(key,p[mid].name))
			return 1;
		else if(strcmp(key,p[mid].name)==-1)
			return recbinsearch(lb,mid-1,key);
		else
			return recbinsearch(mid+1,ub,key);
	}
	else
		return 0;

}

void list::addtolist(char na[])
{
	cout<<"Not found\n\n";
	cout<<"Enter the phone number ";
	cin>>p[n].mob;
	strcpy(p[n].name,na);
	n++;
}

int main()
{
	int choice,ans;
	char na[20];
	list l;
	do
	{
		cout<<"Enter\n1.To enter data\n2.Sequential search\n3.Binary search\n4.Recursive binary search\n5.Sort\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 0: break;
			case 1:
				l.read();
				break;
			case 2:
				cout<<"Enter name to search ";
				cin>>na;
				ans=l.seqsearch(na);
				if(ans==1)
					cout<<"\tFound\n";
				else
					l.addtolist(na);
				break;
			case 3:
				cout<<"Enter name to search ";
				cin>>na;
				l.sort();
				ans=l.binsearch(na);
				if(ans==1)
					cout<<"\tFound\n";
				else
				{
					l.addtolist(na);
					l.display();
				}
				break;
			case 4:
				cout<<"Enter name to search ";
				cin>>na;
				l.sort();
				ans=l.binrecursive(na);
				if(ans==1)
					cout<<"\tFound\n";
				else
					l.addtolist(na);
				break;
			case 5:
				l.sort();
				l.display();
				break;
			default:
				cout<<"Invalid choice\n";
		}
	}while(choice!=0);
	return 0;
}
/*
Output:

Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 1
Enter no of records to add
5
Enter name and phone number
qwe
123
Enter name and phone number
asd
345
Enter name and phone number
zcc
456
Enter name and phone number
pol
378
Enter name and phone number
mon
780
Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 2
Enter name to search pol
        Found
Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 3
Enter name to search mon
        Found
Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 4
Enter name to search zcc
        Found
Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 4
Enter name to search sed
Not found

Enter the phone number 907
Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 5
The list is:

Name   Phone
 asd    345
 mon    780
 pol    378
 qwe    123
 sed    907
 zcc    456
Enter
1.To enter data
2.Sequential search
3.Binary search
4.Recursive binary search
5.Sort
0.Exit
Enter choice 0
*/
