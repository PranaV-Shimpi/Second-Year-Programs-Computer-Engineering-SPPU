// Job Scheduling

#include<iostream>
#define MAX 4
using namespace std;
struct job
{
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
		cout<<"\nPriority: "<<priority;
	}
};
class queue
{
	job Q[MAX];
	int front,rear;
  public:
  	queue()   //constructor
  	{front=rear=-1;}
  	void addq(job element);
  	job delq();
  	int isfull();
  	int isempty();
  	job getfront();
  	void display();
};
int queue::isempty()
{
	if(front==rear)
	return 1;
	else
        return 0;
}
int queue::isfull()
{
	if(rear==MAX-1)
	return 1;
	else
 	return 0;
}
void queue::addq(job element)
{
	if(!isfull())
	{
		rear++;
		Q[rear]=element;
	}
	else
	cout<<"\nQueue is Full.\n";
}
job queue::delq()
{
	int i,max,index;
	job j2;

	if(!isempty())
	{
	        max=Q[front+1].priority; index=front+1;
		for(i=front+1;i<=rear;i++)
		{
			if(Q[i].priority>max)
			{max=Q[i].priority; index=i;}
		}

		i=index; j2=Q[index];
		cout << "\n Index " << index << "  " << j2.priority;
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
}
int main()
{
	queue q;
	job j,j1;
	int ch,element;
	do
	{
		cout<<"\n1.Add Job in Queue\n2.Delete Job from Queue\n3.Display \n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:j.getdata();
				q.addq(j);
				break;
			case 2:if(!q.isempty())
				{j1=q.delq();
			       cout<<"\nDeleted Job is: ";
			       j1.dispdata();}
			       else
			         cout << "\n Empty ";
				break;
			case 3:q.display();
				break;
		}
	}while(ch>0);
	cout<<"\n";
	return 0;
}








