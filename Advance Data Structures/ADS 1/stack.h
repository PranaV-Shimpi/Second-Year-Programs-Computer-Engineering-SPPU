//stack.h

#include <iostream>
using namespace std;
#define max 30
template <class T>
class stack
{
	T a[max];
	int top;
public:
	stack(){top=-1;}
	~stack(){}
	void push(T);
	T pop();
	T gettop();
	void display();
	int isempty();
	int isfull();
};

template <class T>
int stack<T>:: isempty()
{
	if (top == -1)
		return 1;
	return 0;
}
template <class T>
int stack<T>:: isfull()
{
	if (top == max-1) return 1;
	return 0;
}
template <class T>
void stack<T>:: push(T c)
{

	if(!isfull())
		a[++top]=c;
	else
		cout << "\n Full";
}

template <class T>
T stack<T>::gettop()
{
	if(isempty())
		cout<<"Stack is empty\n";
	return a[top];
}

template <class T>
T stack<T>::pop()
{
	if(isempty())
		cout<<"Stack is empty\n";
	return a[top--];

}
template <class T>
void stack<T>::display()
{
	if(isempty())
		cout<<"Stack is empty\n";//usiong templates
	else
	{
		for(int i=0;i<=top;i++)
			cout<<a[i]->data<<" ";
	}
}
