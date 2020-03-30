/*
Assignment 8

Write C++ program for storing binary number using doubly linked lists.
Write functions:
	a)to compute 1‘s and 2‘s complement
	b) add two binary numbers

Done by: Pranav Shimpi
 */
#include <iostream>
using namespace std;

class node
{
public:
	node *prev;
	int data;
	node *next;
	node(int d)
	{
		data=d;
		prev=NULL;
		next=NULL;
	}
	~node(){}
};
class DLL
{
	node *head,*tail;
public:
	DLL()
	{
		head=tail=NULL;
	}
	~DLL(){}
	void create();
	void display();
	DLL complement();
	DLL add(DLL);
	DLL sub(DLL);
	DLL twocomp();
};

void DLL::create()
{
	char ans;
	int d,n;
	node *curr,*temp;
	cout<<"Enter number of bits ";
	cin>>n;
	cout<<"Enter data\n";
	for (int i = 1; i <=n; i++)
	{
		while(true)//for input validation
		{
			cin>>d;
			if (d!=0 && d!=1)
				cout<<"Invalid input. Enter again:\n";
			else
				break;
		}
		curr=new node(d);
		if (head==NULL)
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
	}
	tail=curr;
}

void DLL::display()
{
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data;
		curr=curr->next;
	}
	cout<<"\n";
}

DLL DLL::complement()
{

	node* curr,*curr1,*trackprev;
	curr=head;
	DLL temp;

	while(curr!=NULL)
	{
		if (curr->data==0)
			curr1=new node(1);
		else
			curr1=new node(0);

		if (temp.head==NULL)
		{
			temp.head=curr1;
			trackprev=curr1;
		}
		else
		{
			curr1->prev=trackprev;
			trackprev->next=curr1;
			trackprev=curr1;
		}
		curr=curr->next;
	}
	temp.tail=curr1;
	return temp;
}

DLL DLL::add(DLL d)
{
	DLL total;
	int carry=0,n;
	node *temp1,*temp2,*temp3,*trackprev;
	temp1=tail;
	temp2=d.tail;
	while(temp1!=NULL && temp2!=NULL)
	{
		n=temp1->data+temp2->data+carry;
		temp3=new node(n%2);
		carry=n/2;
		if(total.tail!=NULL)
		{
			temp3->next=trackprev;
			trackprev->prev=temp3;
		}
		else
			total.tail=temp3;
		trackprev=temp3;
		total.head=temp3;
		temp1=temp1->prev;
		temp2=temp2->prev;
	}

	while(temp1!=NULL)//if first list is longer
	{
		n=temp1->data+carry;
		temp3=new node(n%2);
		carry=n/2;

		temp3->next=trackprev;
		trackprev->prev=temp3;
		trackprev=temp3;
		total.head=temp3;
		temp1=temp1->prev;
	}
	while(temp2!=NULL)//if second list is longer
	{
		n=temp2->data+carry;
		temp3=new node(n%2);
		carry=n/2;

		temp3->next=trackprev;
		trackprev->prev=temp3;
		trackprev=temp3;
		total.head=temp3;
		temp2=temp2->prev;
	}
	if (carry!=0)
	{
		temp3=new node(1);
		temp3->next=trackprev;
		total.head=temp3;
	}
	return total;
}

DLL DLL::twocomp()
{
	node *curr;
	DLL temp;
	temp.head=head;
	temp.tail=tail;
	temp=temp.complement();
	DLL one;
	node *p=new node(1);
	one.head=p;
	one.tail=p;
	temp=temp.add(one);
	return temp;
}

DLL DLL::sub(DLL d)
{
	/*count digits
	ignore carry
	check decimal values
	if sub is -ve take complement of result
*/}
	//use this for making io fast
	std::ios::sync_with_stdio(false);


int main()
{
	DLL a,b,c;
	int ch;
	cout<<"Enter binary number\n";
	a.create();
	cout<<"Enter second binary number:\n";
	b.create();
	do
	{
		cout<<"Enter\n1.1's complement\n2.2's complement\n3.Addition\n0.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
			cout<<"\n1's complement of first number= ";
			c=a.complement();
			c.display();
			break;
			case 2:
			cout<<"\n2's complement of first number= ";
			c=a.twocomp();
			c.display();
			break;
			case 3:
			c=a.add(b);
			cout<<"\nSum of both numbers= ";
			c.display();
			break;
			default:
			cout<<"Invalid input\n";
		}
	}while(ch!=0);
	return 0;
}

/*
Output:

Enter binary number
Enter data
1
Add more elements ?(y/n) y
Enter data
0
Add more elements ?(y/n) y
Enter data
1
Add more elements ?(y/n) y
Enter data
1
Add more elements ?(y/n) n
Enter second binary number:
Enter data
1
Add more elements ?(y/n) y
Enter data
0
Add more elements ?(y/n) y
Enter data
0
Add more elements ?(y/n) y
Enter data
0
Add more elements ?(y/n) n
Enter
1.1's complement
2.2's complement
3.Addition
0.Exit
1

1's complement of first number= 0100
Enter
1.1's complement
2.2's complement
3.Addition
0.Exit
2

2's complement of first number= 0101
Enter
1.1's complement
2.2's complement
3.Addition
0.Exit
3

Sum of both numbers= 10011
Enter
1.1's complement
2.2's complement
3.Addition
0.Exit
0
*/
