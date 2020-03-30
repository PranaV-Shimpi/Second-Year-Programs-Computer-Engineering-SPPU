/*
Assignment :
 removing spaces
*/
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
	char str1[30],str2[30],str3[30],ch;
	int i=0,j=0,k=0;
	cout<<"\nenter string :\t";
	cin.getline(str1,30);
	while(str1[i]!='\0')
	{
		if(str1[i]!=32)
		{
			str3[k]=str1[i];
			s.push(str1[i]);
			k++;
		}
		i++;
	}
	str3[k]='\0';
	i=0;
	while(!s.isempty())
	{
		ch=s.pop();
		str2[i]=ch;
		i++;
	}
	str2[i]='\0';
	cout<<"reverse :\t"<<str2;
	if(strcmp(str2,str3)==0)
		cout<<"\nPALINDROME...";
	else
		cout<<"\nNOT PALINDROME...";
	cout<<"\n";
	return 0;
}
