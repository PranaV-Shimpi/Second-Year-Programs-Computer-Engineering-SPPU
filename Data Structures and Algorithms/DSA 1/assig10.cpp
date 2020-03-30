/* Assignment 10
 strings using stack*/
 #include<iostream>
 #include<string.h>
 #define MAX 5
 using namespace std;
  class stack
 {
 	char stk[MAX];
 	int top;
    public:
    	stack()
   	 { top=-1; }
   	 void display();
   	 void push(char a);
   	 char pop();
   	 char topp();
   	 int isempty();
   	 int isfull();
 };
 void stack::display()
 {
 	int i;
 	for(i=0;i<=top;i++)
 	{
 		cout<<"\n"<<stk[i];
 	}
 }
 void stack::push(char element)
 {
 	if(top==MAX)
 	 cout<<"\nstack is full....";
 	else
 	{
 		top++;
 		stk[top]=element;
 	}
 }//end of push
 char stack::pop()
 {
 	if(top==-1)
 		cout<<"\nstack is empty....";
 	else
 	{
 		char p=stk[top];
 		top--;
 		return p;

 	}
 }//end of pop
 char stack :: topp()
 {
 	if(top==-1)
 	   cout<<"\nstack is empty....";
 	return (stk[top]);
 }//end of top
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
int main()
{
	stack s;
	char ch,str1[20],str2[20];
	cout<<"\nenter string:\t";
	cin>>str1;
	int i=0;
	while(str1[i]!='\0')
	{
		s.push(str1[i]);
		i++;
	}
	i=0;
	while(!s.isempty())
	{
		ch=s.pop();
		str2[i]=ch;
		i++;
	}
	str2[i]='\0';
	cout<<"\nReverse string:\t"<<str2;

	if(strcmp(str1,str2)==0)
		cout<<"\nPALIDROME...";
	else
		cout<<"\nnot PALINDROME";
	cout<<"\n";
}





