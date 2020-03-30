/*
Assignment No.11

Queues are frequently used in computer programming, and a typical example is the creation
of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating
job queue. Write functions to add job and delete job from queue.

Done by: Pranav Shimpi
*/
#include<iostream>
const int MAX=4;
using namespace std;
class job
{
public:
	char jname[20];
	int priority;
	void getdata()
	{
		cout<<"\nEnter Job name: ";
		cin>>jname;
		cout<<"\nEnter Job priority: ";
		cin>>priority;
	}
	void dispdata()
	{
		cout<<"\nName: "<<jname;
		cout<<"\nPriority: "<<priority<<"\n";
	}
};
class queue
{
	job Q[MAX];
	int front,rear;
public:
	queue()
	{
		front=rear=-1;
	}
	void enque(job element);
	job deque();
	int isfull();
	int isempty();
	job getfront();
	void display();
};
int queue::isempty()
{
	if(front==rear)
		return 1;
	return 0;
}
int queue::isfull()
{
	if(rear==MAX-1)
		return 1;
	return 0;
}
void queue::enque(job element)
{
	if(!isfull())
	{
		rear++;
		Q[rear]=element;
	}
	else
	cout<<"\nQueue full.\n";
}
job queue::deque()
{
	int i,max,index;
	job j2;

	if(!isempty())
	{
		max=Q[front+1].priority;
		index=front+1;
		for(i=front+1;i<=rear;i++)
		{
			if(Q[i].priority>max)
			{max=Q[i].priority; index=i;}
		}

		i=index; j2=Q[index];
		while(i<rear) // shifting
		{
			Q[i]=Q[i+1];
			i++;
		}
		rear--;
		return j2;
	}
	else
		cout<<"\nQueue is empty\n";
}

void queue::display()
{
	cout<<"\n";
	for(int i=front+1;i<=rear;i++)
		Q[i].dispdata();
	cout<<"\n";
}
int main()
{
	queue q;
	job j,j1;
	int ch,element;
	do
	{
		cout<<"\n1.Add Job in Queue\n2.Delete Job from Queue\n3.Display\n0.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0: break;
			case 1:j.getdata();
				q.enque(j);
				break;
			case 2:
				if(!q.isempty())
				{
					j1=q.deque();
					cout<<"\nDeleted Job is:\n";
					j1.dispdata();
				}
				else
					cout << "\n Empty\n";
				break;
			case 3:
				q.display();
				break;
			default:
				cout<<"Invalid input\n";
		}
	}while(ch!=0);
	return 0;
}

/*
Output:

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 1

Enter Job name: qwe

Enter Job priority: 4

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 1

Enter Job name: asd

Enter Job priority: 3

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 1

Enter Job name: wer

Enter Job priority: 2

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 3


Name: qwe
Priority: 4
Name: asd
Priority: 3
Name: wer
Priority: 2

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 1

Enter Job name: ret

Enter Job priority: 5

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 3


Name: qwe
Priority: 4
Name: asd
Priority: 3
Name: wer
Priority: 2
Name: ret
Priority: 5

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 2

Deleted Job is:

Name: ret
Priority: 5

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 3


Name: qwe
Priority: 4
Name: asd
Priority: 3
Name: wer
Priority: 2

1.Add Job in Queue
2.Delete Job from Queue
3.Display
0.Exit
Enter your choice: 0

*/
