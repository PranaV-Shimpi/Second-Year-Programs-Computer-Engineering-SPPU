/*Assignment:
 strings using stack(expression)*/

 #include<iostream>
 #include<string.h>
 #define MAX 50
 using namespace std;
 class stack
 {
 	char stk[MAX];
 	int top;
    public:
    	stack()
   	 { top=-1; }
   	 void push(char a);
   	 char pop();
   	 int isempty();
   	 int isfull();
   	 char gettop();
 };

 void stack::push(char element)
 {
 	if(top==MAX)
 	 cout<<"\nstack is full...";
 	else
 	{
 		top++;
 		stk[top]=element;
 	}
 }//end of push
 char stack::pop()
 {
 	if(top==-1)
 		cout<<"\nstack is empty.";
 	else
 	{
 		char p=stk[top];
 		top--;
 		return p;

 	}
 }//end of pop

 int stack::isempty()
 {
 	if(top==-1)
 		return 1;
 	else
 		return 0;
 }//end of isempty
 int stack::isfull()
 {
 	if(top==MAX)
 		return 1;
 	else
 		return 0;
 }//end of isfull
 char stack::gettop()
 {
 	if(!isempty())
 	return stk[top];
 }
 int icp(char ch)
 {
 	switch(ch)
 	{
 		case '+':
 		case '-':return 1;
 			 break;
 		case '*':
 		case '/':return 2;
 			break;
 		case '^':return 3;
 			break;
 		case '(':return 4;
 			break;
 	}
 }
  int isp(char ch)
 {
 	switch(ch)
 	{
 		case '+':
 		case '-':return 1;
 			 break;
 		case '*':
 		case '/':return 2;
 			break;
 		case '^':return 3;
 			break;
 		case '(':return 0;
 			break;
 	}
 }
 void intopost()
 {
 	stack s;
 	char infix[20],ch,x,post[20];
 	int i=0,j=0;
 	cout<<"\nenter a infix expression:\t";
 	cin>>infix;
 	while(infix[i]!='\0')
 	{
 		ch=infix[i];
 		if(ch>='a'&&ch<='z')
 		{
 			post[j]=ch;
 			j++;
 		}
 		else if(ch==')')
 		{
 			while(s.gettop()!='(')
 			{
 				post[j]=s.pop();
 				j++;
 			}
 			s.pop();
 		}
 		else
 		{
 				while(isp(s.gettop())>=icp(ch))
 				{
 					x=s.pop();
 					post[j]=x;
 					j++;
 				}
 			s.push(ch);
 		}
 		i++;
 	}//end of while
 while(!s.isempty())
 {
 	x=s.pop();
 	post[j]=x;
 	j++;
 }
 	post[j]='\0';
 	cout<<"\npostfix expression:\t"<<post;
 }
 int main()
 {
 	intopost();
 	cout<<"\n";
 }










