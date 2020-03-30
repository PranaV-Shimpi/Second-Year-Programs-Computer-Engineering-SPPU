/* Stack using Linked List
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};
class stack
{
	node *top;
   public:
   	stack()
   	{top=NULL;}
   	void push(int);
   	int pop();
   	int gettop();
   	int isempty();
};
void stack::push (int element)
{
	node *curr;
	curr=new node;
	curr->data=element;
	curr->next=NULL;
	if(top==NULL)
	{
		top=curr;
	}
	else
	{
		curr->next=top;
		top=curr;
	}
}
int stack::pop()
{
	node *curr;
	if(top==NULL)
	cout<<"\nstack is empty..";
	else
	{
		curr=top;
		int x=curr->data;
		top=top->next;
		delete (curr);
		return x;
	}
}
int stack::isempty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
int stack::gettop()
{
	int x=top->data;
	return x;
}
int main()
{
	stack s;
	int x,ch;
	do{
		cout<<"\n1.push\n2.pop\n3.gettop\n4.exit\n";
		cout<<"\nenter your choice:\t";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\nenter element to push:\t";
				cin>>x;
				s.push(x);
				break;
			case 2:cout<<"\npoped element is:\t"<<s.pop();
				break;
			case 3:cout<<"\nelement on top is:\t"<<s.gettop();
				break;
			case 4:exit(0);
		}
	}while(ch>0);
}










