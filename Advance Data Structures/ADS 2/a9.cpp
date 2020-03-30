#include<iostream>
#include<string.h>

#define MAX 10
using namespace std;
class hash
{
	public:
	long int num;
	char name[20];
	
	
	
	
};

class hashing
{
	public:
	hash h1[MAX];
	
	hashing()
	{
		for(int i=0;i<MAX;i++)
		{
			h1[i].num=-1;
			strcpy(h1[i].name,"-1");
		}
	}
	void create();
	void insert();
	void display();
	void search();
};

void hashing::create()
{
	long int key,ans;
	cout<<"Enter a phone number:";
	cin>>key;
	
	ans=key%10;
	for(int i=0;i<MAX;i++)
	{
		if(i==ans)
		{
			h1[i].num=key;
			cout<<"Enter a name: ";
			cin>>h1[i].name;
		}
	}	
}

void hashing::insert()
{
	int m=0;
	long int key1,ans1;
	int flag=0;
	cout<<"Enter a phone number ";
	cin>>key1;
	ans1=key1%MAX;
	if(h1[ans1].num==-1)
	{
		h1[ans1].num=key1;
		cout<<"Enter a name: ";
		cin>>h1[ans1].name;
		flag=2;
		cout<<"done";
	}
	else
	{
		while(ans1<=MAX)
		{
			if(h1[ans1].num==-1)
			{
				h1[ans1].num=key1;
				cout<<"Enter a name: ";
				cin>>h1[ans1].name;
				flag=1;
				break;
			
			}
			else
			{
				ans1++;
			}
		}
	}
	if(flag==0)
	{
	 ans1=0;
		while(ans1<key1%MAX)
		{
			if(h1[ans1].num==-1)
			{
				h1[ans1].num=key1;
				flag=1;
				cout<<"Enter a name: ";
				cin>>h1[ans1].name;
			}
			else
			{
				ans1++;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\n Hash table is full:  ";
	}
	
	
}

void hashing::display()
{
	for(int i=0;i<MAX;i++)
	{
		cout<<"\n["<<i<<"] = "<<h1[i].num<<" << "<<h1[i].name<<"\n";	
	}
}

void hashing::search()
{
	unsigned long int b;
	int c,i=1,flag2=0;
	cout<<"Enter a no. to be search ";
	cin>>b;
	c=b%MAX;
	while(c<MAX)
	{
	if(h1[c].num==b)
	{
		cout<<"\n Number found: "<<h1[c].name;
		flag2=1;
		break;
	}
	while(i<MAX)
	{
		c=(b+i)%MAX;
		if(h1[c].num==b)
		{
			cout<<"\n Number found: "<<h1[c].name;
			flag2=1;
			break;
		}
	
	}
	}
	if(flag2==0)
	{
	cout<<"Number not found: ";
	}
	
	
}


int main()
{
	int choice;
	hashing h2;
	cout<<"\n ";
	do
	{	
		cout<<"\n";		
		cout<<"\n\t*MEnu*";
		cout<<"\nSelect the option: ";
		cout<<"\n1.Create";
		cout<<"\n2.Insert";
		cout<<"\n3.Display";
		cout<<"\n4.SEarch";
		cout<<"\n5.Exit";		
		cout<<"\nEnter ur choice : ";
		cin>>choice;
		cout<<"\n";
		switch(choice)
		{
			case 1:
				h2.create();
				break;
				
			case 2:
				h2.insert();
				break;
				
			case 3:
				h2.display();
				break;
				
			case 4:
				h2.search();
				break;	
			case 5:
				cout<<"Thank u...";
				break;
			default:
				cout<<"wrong input...";
		}
	}while(choice!=5);
	return 0;
}
