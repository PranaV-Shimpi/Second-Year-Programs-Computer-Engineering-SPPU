/* Assignment no. 5

Linked List */

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
	public:
	char prn[20];
	char name[20];
	node *next;
};
class linkedlist
{
	node *head,*tail;
	public:
		linkedlist()
		{
			head=tail=NULL;
		}
		void create();
		void display();
		void insertatbegin();
		void insertatend();
		void search();
		void del();
		void count();
		void insertafter();
		void insertbefore();
		void concat(linkedlist l1);
		void reverse();
};
void linkedlist::create()
{
	node *curr,*prev;
	char ans;
	do
	{
		curr=new node;
		cout<<"\nenter prn:\t";
		cin>>curr->prn;
		cout<<"\nenter name:\n";
		cin>>curr->name;
		curr->next=NULL;

		if(head==NULL)
		{
			head=curr;
			prev=curr;
		}
		else
		{
			prev->next=curr;
			prev=curr;
		}
		cout<<"\nAdd more(y/n):\t";
		cin>>ans;
	}while(ans=='y');
	if(ans=='n')
	{
		tail=curr;
		tail->next=NULL;
	}
}

void linkedlist::display()
{
	node *curr;
	curr=head;
	cout<<"\nPRN\t\t\tNAME";
	cout<<"\n................................";
	while(curr != NULL)
	{
		cout<<"\n"<<curr->prn<<"\t\t"<<curr->name<<"\n";
		curr=curr->next;
	}
}
void linkedlist::insertatbegin()
{
	node *curr;
	curr=new node;
	cout<<"\nenter prn:\t";
	cin>>curr->prn;
	cout<<"\nenter name:\n";
	cin>>curr->name;
	curr->next=NULL;
	curr->next=head;
	head=curr;
}
void linkedlist::insertatend()
{
	node *curr;
	curr=new node;
	cout<<"\nenter prn:\t";
	cin>>curr->prn;
	cout<<"\nenter name:\n";
	cin>>curr->name;
	curr->next=NULL;
	tail->next=curr;
	tail=curr;
}

void linkedlist::search()
{
	int flag;
	node*curr;
	char nm[20];
	cout<<"\nenter name to search\n";
	cin>>nm;
	curr=head;
	flag=0;
	while(curr != NULL)
	{

		if(strcmp(nm,curr->name)==0)
		{
			cout<<"\nfound";
			flag=1;
			break;
		}
		curr=curr->next;

	}
	if(flag==0)
	cout<<"\nnot found";
	cout<<"\n";
}

void linkedlist::del()
{
	int flag=0;
	char nm[20];
	node *curr,*prev,*after;
	cout<<"\nenter name to delete:\n";
	cin>>nm;
	curr=head;
	if(strcmp(nm,head->name)==0)
	{
		prev=head;
		head=head->next;
		delete(prev);
	}
	else
	{
		while(curr!=NULL)
		{
			if(strcmp(nm,curr->name)==0)
			{
				cout<<"\nfound\n";
				flag=1;
				after=curr->next;
				prev->next=after;
				delete(curr);
				cout<<"\nDELETED";
				break;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
	}
	if(flag==0)
	cout<<"\nnot found";

}

void linkedlist::count()
{
	node *curr;
	curr=head;
	int cnt=0;
	while(curr!=NULL)
	{
		cnt++;
		curr=curr->next;
	}
	cout<<"\nthere are\t"<<cnt<<"\tnodes.";
}

void linkedlist::insertafter()
{
	node *curr,*temp,*prev;
	char nma[20];
	cout<<"\nenter name after which to insert:\t";
	cin>>nma;
	curr=head;
	int flag=0;
	while(curr!=NULL)
	{
		if(strcmp(nma,curr->name)==0)
		{
			flag=1;
			break;
		}
		else
		{
			curr=curr->next;
		}
	}
	if(flag==1)
	{
		temp=new node;
		cout<<"\nenter prn:\t";
		cin>>temp->prn;
		cout<<"\nenter name:\t";
		cin>>temp->name;
		temp->next=NULL;
		prev=curr;
		curr=curr->next;
		prev->next=temp;
		temp->next=curr;
	}
	else
		cout<<"\nname not found.\n";

}
void linkedlist::insertbefore()
{
	node *curr,*prev,*temp;
	char nmb[20];
	int flag=0;
	cout<<"\nenter name before which you want to insert:\t";
	cin>>nmb;
	curr=head;
	while(curr!=NULL)
	{
		if(strcmp(nmb,curr->name)==0)
		{
			cout<<"\nFOUND...";
			flag=1;
			break;
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
	if(flag==1)
	{
		temp=new node;
		cout<<"\nenter prn:\t";
		cin>>temp->prn;
		cout<<"\nenter name:\t";
		cin>>temp->name;
		temp->next=NULL;
		prev->next=temp;
		temp->next=curr;
	}
	else
		cout<<"\n NOT FOUND..\n";
}

void linkedlist::concat(linkedlist l1)
{
	node *curr;
	curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=l1.head;
}
void reverse()
{
	node *curr;
}
int main()
{
	int ch;
	linkedlist l,l1;;
	l.create();
	l.display();
	do
	{
		cout<<"\n1.insert at beginning\n2.insert at end\n3.to search name\n4.to delete\n5.to count node\n6.to insert after any node\n7.to insert before any node\n8.to concatenate\n9.to reverse list\n10.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1: l.insertatbegin();
				l.display();
				break;
			case 2:l.insertatend();
				l.display();
				break;
			case 3:l.search();
				break;
			case 4:l.del();
				l.display();
				break;
			case 5:l.count();
				break;
			case 6:l.insertafter();
				l.display();
				break;
			case 7:l.insertbefore();
				l.display();
				break;
			case 8:cout<<"\nenter new list:\n";
				l1.create();
				cout<<"\nnew list is:\n";
				l1.display();
				cout<<"\nafter concatenation:\n";
				l.concat(l1);
				l.display();
				break;
			case 9:
			case 10:exit(0);
		}
	}while(ch>0);
	cout<<"\n";
	return 0;
}
















