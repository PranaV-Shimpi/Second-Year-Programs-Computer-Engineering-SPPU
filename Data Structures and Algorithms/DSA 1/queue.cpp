// Queue Operations

#include<iostream>
#define MAX 2
using namespace std;
class queue
{
	int Q[MAX];
	int front,rear;
  public:
  	queue()   //constructor
  	{front=rear=-1;}
  	void addq(int element);
  	int delq();
  	int isfull();
  	int isempty();
  	int getfront();
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
void queue::addq(int element)
{
	if(!isfull())
	{
		rear++;
		Q[rear]=element;
	}
	else
	cout<<"\nQueue is Full.\n";
}
int queue::delq()
{
	if(!isempty())
	{
		front++;
		return Q[front];
	}
	else
	cout<<"\nQueue is empty\n";
}

void queue::display()
{
	cout<<"\n";
	for(int i=front+1;i<=rear;i++)
	cout<<Q[i]<<"\t";
}
int main()
{
	queue q;
	int ch,element;
	do
	{
		cout<<"\n1.Add element in Queue\n2.Delete elements from Queue\n3.Display \n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\nEnter element to Add: ";
				cin>>element;
				q.addq(element);
				break;
			case 2:if (!q.isempty())
			       cout<<"\nDeleted element is: "<<q.delq();
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








