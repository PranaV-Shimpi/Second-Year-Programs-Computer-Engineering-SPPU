    /*a7
    FLIGHT  adjacency list
    */

#include <iostream>
#include <string.h>
using namespace std;
class llist
{
	public:
	string city;
	int time;
	float fuel;
	llist *next;
	llist()
	{
		next=NULL;
	}
};
class headlist
{
	public:
	string city;
	llist *to;
	headlist *down;
	headlist()
	{
		to=NULL;
		down=NULL;
	}
};
class flight
{
	public:
	headlist *head;
	flight()
	{
		head=NULL;
	}
	void create();
	void createroute();
	void display();
};
void flight::create()
{
	headlist *curr,*temp;
	char ch;
	do
	{
		temp=head;
		curr=new headlist;
		cout<<"\nEnter city name:";
		cin>>curr->city;
		if(head==NULL)
		{
			head=curr;
		}
		else
		{
			while(temp->down!=NULL)
			temp=temp->down;
			temp->down=curr;
		}
		cout<<"\nDo you want to enter more ?(y/n) ";
		cin>>ch;
	}while(ch=='y');
}
void flight::createroute()
{
	headlist *temp;
	llist *curr,*temp2;
	char ch;
	string c;
	display();
	temp=head;
	cout<<"Enter starting location:";
	cin>>c;
	while(temp!=NULL)
	{
		if(temp->city==c)
		{
			do
			{
				curr=new llist;
				cout<<temp->city<<"->";
				cin>>curr->city;
				if(temp->to==NULL)
				{
					temp->to=curr;
					temp2=curr;
				}
				else
				{
					temp2=temp->to;
					while(temp2->next!=NULL)
						temp2=temp2->next;
					temp2->next=curr;
				}
				cout<<"\ndo you want to enter more ?(y/n) ";
				cin>>ch;
			}while(ch=='y'||ch == Y);
			return;
		}
		else
			temp=temp->down;
	}
}
void flight::display()
{
	headlist *temp;
	llist *temp2;
	char x;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->city;
		temp2=temp->to;
		while(temp2!=NULL)
		{
			cout<<"->"<<temp2->city;
			temp2=temp2->next;
		}
		temp=temp->down;
		cout<<endl;
	}
}
int main()
{
	int ch;
	flight a;
	do
	{
		cout<<"\n1.Add city\n2.Add route\n3.Display\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:break;
			case 1:
				a.create();
				break;
			case 2:
				a.createroute();
				break;
			case 3:
				a.display();
				break;
			default:
				cout<<"Choice mmust be between 0 and 3 only\n\n";
		}
	}while(ch!=0);


}
