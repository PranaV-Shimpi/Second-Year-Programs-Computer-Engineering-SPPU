/*Assignment : 14
Pizza parlor accepting maximum M orders.Order are served in First come first serve basis.Order once placed cant be cancelled.
 write a c++ program to simulate the system using circular queue using array.
Done by : Pranav Shimpi
*/


#include<iostream>
#define max 50
using namespace std;
struct order
{
	int order_no;
	char name[20];
	char type[20];
	int qty;
	float cost;
	public:
		void getdata()
		{
			cout<<"\nenter order no: ";
			cin>>order_no;
			cout<<"\nenter customer's name: ";
			cin>>name;
			cout<<"\n1. PANEER---------200/-";
			cout<<"\n2. ONION----------100/-";
			cout<<"\n3. CHEESE---------150/-";
			cout<<"\nENTER TYPE NUMBER OF PIZZA: ";
			cin>>type;
		}
		void putdata()
		{
			cout<<"\nOR_NO.: "<<order_no;
			cout<<"\nNAME: "<<name;
			cout<<"\nTYPE: "<<type;
			cout<<"\n------------------------------------------------";
		}

};
class que
{
	order q[max];
	int front,rear;
	public:
	que()
	{
		front=rear=0;
	}
	void display();
	void add(order ele);
	order del();
	int isfull();
	int isempty();
};
int que::isempty()
{
	if(front==rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int que::isfull()
{
	if(rear==max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void que::display()
{
	for(int i=front+1; i<=rear; i++)
	{
		q[i].putdata();
	}
}
void que::add(order ele)
{
	if(!isfull())
	{
		rear=(rear+1)%max;
		if(front==rear)
		{
			cout<<"\nqueue full";
		}
		else
		{
			q[rear]=ele;
		}
	}

}
order que::del()
{
	if(front==rear)
	{
		cout<<"\nqueue empty";
	}
	else
	{
		front=(front+1)%max;
		return (q[front]);
	}
}
int main()
{
	order ele,o;
	int ch;
	que Q;
	do
	{
		cout<<"\n***MENU***";
		cout<<"\n1. ADD ORDER";
		cout<<"\n2. DELIVER ORDER";
		cout<<"\n3. DISPLAY PENDING ORDERS";
		cout<<"\nENTER YOUR CHOICE: ";
		cin>>ch;
		switch(ch)
		{
			case 1://add
				ele.getdata();
				Q.add(ele);
				break;
			case 2://delete
				if(!Q.isempty())
				{
					cout<<"\ndelivered order is: ";
					o=Q.del();
					o.putdata();
				}
				else
				{
					cout<<"\n no order is to be delivered";
				}
				break;
			case 3://display
				cout<<"\nPENDING ORDERS"<<endl;
				Q.display();
				break;
		}
	}while(ch<4);
}
