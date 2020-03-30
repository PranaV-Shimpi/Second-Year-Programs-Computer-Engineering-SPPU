/*
ASSIGNMENT NO: 13

PROBLEM STATEMENT:->
QUEUES ARE FREQUENTLY USED IN COMPUTER PROGRAMMING, AND A TYPICAL EXAMPLE
IS THECREATION ODF A JOB QUEUE BY AN OPERATING SYSTEM. IF THE PROGRAMMING
DOES NOT USE PRIORITIES, THEN THE JOBS ARE PROCESSED IN THE ORDER THEY
ENTER THE SYSTEM. WRITE C++ PROGRAM FOR SIMULATING JOB QUEUE. WRITE
FUNCTIONS TO ADD JOB AND DELETE JOB FROM QUEUE
====================================================================================================================*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class qnode
{
	int jobnumber;
	qnode *next;
	friend class queue;
};

class queue
{
	qnode *front, *rear;
public:
	void enque(int val);
	int deque();
	int isempty();
	void display();

	queue()
	{
		front=rear=NULL;
	}

};



int queue::isempty()
{
	if(front==NULL && rear==NULL)
		return 1;
	else
		return 0;
}

void queue::enque(int val)
{
	qnode *t;
	t=new qnode;
	t->jobnumber=val;
	t->next=NULL;
	if(isempty())
	{
		front=t;
		rear=t;
	}
	else
	{
		rear->next=t;
		rear=t;
	}
}


int queue::deque()
{
	qnode *t;
	int val;
	if(isempty())
		cout<<"\nQueue is empty\n";
	else
	{
		t=front;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		val=t->jobnumber;
		delete t;
	}
	return val;
}

void queue::display()
{
	qnode *t;

	if(isempty())
		cout<<"\nQueue is empty\n";
	else
	{
		cout<<"\nQueue jobnumbers: ";
		for(t=front;t!=NULL;t=t->next)
		{
			cout<<"\t"<<t->jobnumber;
		}
	}
}






int main()
{
	int ch,n;
	queue obj;
	while(1)
	{
		cout<<"\n1.Add job \n2.Delete job \n3.Display job \n4.exit";
		cout<<"\nEnter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter jobnumbers";
			cin>>n;
			obj.enque(n);
			break;
		case 2:
			obj.deque();
			break;
		case 3:
			obj.display();
			break;
		case 4:
			exit(0);
		default:
			cout<<"\nYou enter wrong choice";
		}


	}

	return 0;
}


/*===============================================================================================OUTPUT=============================================================================================

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice3

Queue is empty

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice2

Queue is empty

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice1

Enter jobnumbers1

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice1

Enter jobnumbers2

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice2

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice2

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice3

Queue is empty

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice1

Enter jobnumbers25

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice1

Enter jobnumbers25

1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice3

Queue jobnumbers: 	25	25
1.Add job
2.Delete job
3.Display job
4.exit
Enter your choice4

 */
