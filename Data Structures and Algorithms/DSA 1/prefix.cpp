/*Done By:Bagwan Atira M
 SE(A) Roll no:04
 Date:27/08/18
 strings using stack(expression)*/
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
   	 void push(int a);
   	 int pop();
   	 int isempty();
   	 int isfull();
 };
 
 void stack::push(int element)
 {
 	if(top==MAX)
 	 cout<<"\nstack is full....";
 	else
 	{
 		top++;
 		stk[top]=element;		
 	}
 }//end of push
 int stack::pop()
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
 void evaluate(char prefix[20])
 {
 	stack s;
 	char ch;
 	float val1,op1,op2,ans;
 	int i=0;
 	while(prefix[i]!='\0')
 		i++;
 	i--;
 	while(i>=0)
 	{
 		ch=prefix[i];
 		if(ch>='a'&&ch<='z')
 		{
 			cout<<"\nenter value of\t"<<prefix[i]<<"\t:\t";
 			cin>>val1;
 			s.push(val1);
 		}
 		else
 		{
 			op1=s.pop();
 			op2=s.pop();
 			switch(ch)
 			{
 				case '+':ans=op1+op2;
 					break;
 				case '-':ans=op1-op2;
 					break;
 				case '*':ans=op1*op2;
 					break;
 				case '/':ans=op1/op2;
 					break;
 				case '%':ans=int(op1)%int(op2);
 					break;
 			}
 			s.push(ans);	
 		}
	i--;
 	}//end of while
 	if(!s.isempty())
 	cout<<"\nAfter evaluation:\t"<<s.pop();
 }
 int main()
 {
 	stack s;
 	char prefix[20];
 	cout<<"\nenter a prefix expression:\t";
 	cin>>prefix;
 	evaluate(prefix);
 	cout<<"\n";
 	return 0;
 }
 
 
 
 
 
 
  
 
