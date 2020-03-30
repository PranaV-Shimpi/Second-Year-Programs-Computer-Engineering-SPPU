/*  Assignment 7
    Hospital management Using Link List
    Done by : Pranav Shimpi*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
  public:
	char name[20];
	int st,et;
	node *next;
};
class appointment
{
	node *head,*tail;
   public:
   	appointment()
   	{
   		head=tail=NULL;
   	}
   	void create();
	void display();
	void bookapp();
	void cancelapp();
	void freeslots();
};
void appointment::create()
{
	node *curr,*prev;
	char ans;
	do
	{
		curr=new node;
		cout<<"\nenter name:\t";
		cin>>curr->name;
		cout<<"\nenter start time:\t";
		cin>>curr->st;
		cout<<"\nenter end time:\t";
		cin>>curr->et;
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
		cout<<"\nwant add more?(y/n):\t";
		cin>>ans;
	}while(ans=='y');
	if(ans=='n')
	{
		tail=curr;
		tail->next=NULL;
	}
}
void appointment::display()
{
	node *curr;
	curr=head;
	cout<<"\nNAME\t\t\tSTART TIME\t\tEND TIME";
	cout<<"\n...............................................";
	while(curr != NULL)
	{
		cout<<"\n"<<curr->name<<"\t\t\t"<<curr->st<<"\t\t"<<curr->et;
		curr=curr->next;
	}
}
void appointment::bookapp()
{
	node *curr;
	curr=new node;
	cout<<"\nenter name:\t";
	cin>>curr->name;
	cout<<"\nenter start time:\t";
	cin>>curr->st;
	cout<<"\nenter start time:\t";
	cin>>curr->et;
	curr->next=NULL;
	tail->next=curr;
	tail=curr;
}
void appointment::cancelapp()
{
	node *curr,*prev,*after;
	int flag=0;
	char nmc[20];
	cout<<"\nenter name:\t";
	cin>>nmc;
	curr=head;
	if(strcmp(nmc,head->name)==0)
	{
		prev=head;
		head=head->next;
		delete(prev);
	}
	else
	{
		while(curr!=NULL)
		{
			if(strcmp(nmc,curr->name)==0)
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
void appointment::freeslots()
{
	int cnt[20],i;
	for(i=0;i<20;i++)
		cnt[i]=0;
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		cnt[curr->st]++;
		curr=curr->next;
	}
	cout<<"\nFREE SLOT:";
	for(i=10;i+1<=18;i++)
	{
			if(cnt[i]==0)
			cout<<"\n"<<i<<"to"<<i+1;
	}

}
int main()
{
	int ch;
	appointment a;
	a.create();
	a.display();
	do
	{
		cout<<"\n\n\n1.to book appointment\n2.to cancel appointment\n3.to see free slots\n4.exit\n";
		cout<<"\nenter your choice:\t";
		cin>>ch;
		switch(ch)
		{
			case 1:a.bookapp();
				a.display();
				break;
			case 2:a.cancelapp();
				a.display();
				break;
			case 3:a.freeslots();
				a.display();
				break;
			case 4:exit(0);
			default:cout<<"\nplease enter proper choice\n";
		}
	}while(ch>0);
	cout<<"\n";
	return 0;
}











