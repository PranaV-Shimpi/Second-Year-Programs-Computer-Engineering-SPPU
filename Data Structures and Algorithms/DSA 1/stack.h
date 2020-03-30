
 #include<iostream>
 #include<stdlib.h>
 #define MAX 50
 using namespace std;
 template <class T>
 class stack
 {
 	T stk[MAX];
 	int top;
    public:
    	stack()
   	 { top=-1; }
   	 void display();
   	 void push(T);
   	 T pop();
   	 T topp();
   	 int isempty();
   	 int isfull();
   	 T gettop();
 };
 template <class T>
 void stack<T>::display()
 {
 	int i;
 	for(i=0;i<=top;i++)
 	{
 		cout<<"\n"<<stk[i];
 	}
 }
  template <class T>
 void stack<T>::push(T element)
 {
 	if(top==MAX-1)
 	 cout<<"\nstack i full....";
 	else
 	{
 		top++;
 		stk[top]=element;
 	}
 }//end of push
template <class T>
T stack<T>::pop()
 {
 	if(top==-1)
 		cout<<"\nstack is empty....";
 	else
 	{
 		T p=stk[top];
 		top--;
 		return p;

 	}
 }//end of pop
 template <class T>
T stack <T> :: topp()
 {
 	if(top==-1)
 	   cout<<"\nstack is empty....";
 	return (stk[top]);
 }//end of top
  template <class T>
 int stack<T>::isempty()
 {
 	if(top==-1)
 		return 1;
 	else
 		return 0;
 }//end of isempty
  template <class T>
 int stack<T>::isfull()
 {
 	if(top==MAX-1)
 		return 1;
 	else
 		return 0;
 }//end of isfull
 template<class T>
 T stack<T>::gettop()
 {
 	if(!isempty())
 	return stk[top];
 }



