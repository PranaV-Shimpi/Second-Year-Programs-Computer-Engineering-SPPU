/*Assignment 8:
    Linked list
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
  public:
	int data;
	node *prev,*next;
	node()
	{
		prev=next=NULL;//constructor
	}
};
class dll
{
  public:
	node *head,*tail;
	void create();
	void display();
	void traverseback();
	void complement();
	dll add(dll l1);
	void twoscomplement();
	dll()
	{
		head=tail=NULL;//constructor
	}
};
void dll::create()
{
	node *curr,*temp;
	char ans;
	int x,flag=0;
	do
	{
		do
		{
			cout<<"\nenter bit:\t";
			cin>>x;
			if(x!=0 && x!=1)
				{
					cout<<"\ninvalid input,enter again...\n";
					flag=1;
				}
			else
				flag=0;
		}while(flag==1);
		curr=new node;
		curr->data=x;
		if(head==NULL)
		{
			head=curr;
			temp=curr;
		}
		else
		{
			temp->next=curr;
			curr->prev=temp;
			temp=curr;
		}
		cout<<"\nadd more(y/n):\t";
		cin>>ans;
	}while(ans=='y');
	if(ans=='n')
	{
		tail=curr;
	}
}
void dll::display()
{
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<"\t";
		curr=curr->next;
	}
}
void dll::traverseback()
{
	node *curr;
	curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	while(curr!=NULL)
	{
		cout<<curr->data<<"\t";
		curr=curr->prev;
	}
}
void dll::complement()
{
	node *t1;
	t1=head;
	while(t1!=NULL)
	{
		if(t1->data==1)
			t1->data=0;
		else
			t1->data=1;
		t1=t1->next;
	}
}
dll dll::add(dll l1)
{
	dll temp;
	node *t1,*t2,*t3,*prev,*prv;
	t1=head;
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
	t2=l1.head;
	while(t2->next!=NULL)
	{
		t2=t2->next;
	}
	int c=0;
	while(t1!=NULL)
	{
		int x;
		x=(t1->data+t2->data+c)%2;
		c=(t1->data+t2->data+c)/2;
		t3=new node;
		t3->data=x;
		if(temp.tail==NULL)
		{
			temp.tail=t3;
			prv=t3;
			t1=t1->prev;
			t2=t2->prev;
		}
		else
		{
			t3->next=prv;
			prv=t3;
			prv->prev=t3;
			t1=t1->prev;
			t2=t2->prev;

		}


	}
	if(c==1)
	{
		t3=new node;
		t3->data=1;
		t3->next=prv;
		prv->prev=t3;
	}
	temp.head=t3;
	return temp;
}
void dll::twoscomplement()
{
	node *curr;
	int c=1;
	curr=tail;
	do
	{
		c=(curr->data+c)/2;
		curr->data=(curr->data+c)%2;
		curr=curr->prev;
	}while(c==1 && curr!=NULL);

}
int main()
{
	dll l,l1,l2,l3,l4;
	int ch;
	l.create();
	l.display();
	do
	{
		cout<<"\n\n\nMENU:\n1.traverse back\n2.for complement\n3.to add two binary no.\n4.for 2's complement\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nafter traverse back:\n";
				l.traverseback();
				break;
			case 2:cout<<"\ncomplement is:\n";
				l.complement();
				l.display();
				break;
			case 3:cout<<"\nfor second binary no:\n";
				l1.create();
				l1.display();
				l2=l.add(l1);
				cout<<"\nafter addition:\n";
				l2.display();
				break;
			case 4:l.complement();
				l.twoscomplement();
				cout<<"\n2's complement is:\n";
				l.display();
				break;
			case 5:exit(0);
		}

	}while(ch>0);
	cout<<"\n";
	return 0;
}
























