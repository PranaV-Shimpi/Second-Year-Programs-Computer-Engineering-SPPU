#include<iostream>
using namespace std;
#define MAX 50
template<class T>
class stack
{
	T stk[MAX];
	int top;
	public:
		stack()
		{
			top=-1;
		}
		void push(T);
		T pop();
		int isempty();
		int isfull();
		T Top();
};
template<class T>
void stack<T> :: push(T num)
{
	if(!isfull())
	{
		top++;
		stk[top]=num;
	}
	else
		cout<<"\nstack overflow";
}
template<class T>
T stack<T> :: pop()
{
	T no;
	if(!isempty())
	{
		no=stk[top];
		top--;
		return no;
	}
	else
		cout<<"\nstack underflow";
}
template<class T>
int stack<T> :: isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
template<class T>
int stack<T> :: isfull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}
template<class T>
T stack<T> :: Top()
{
	return stk[top];
}
