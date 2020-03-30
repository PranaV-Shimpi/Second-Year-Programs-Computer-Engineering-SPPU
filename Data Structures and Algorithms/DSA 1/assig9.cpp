/*Assignment 9

 STACKS USIING ARRAY*/

 #include<iostream>
 #include<stdlib.h>
 #define MAX 5
 using namespace std;
 class stack
 {
 	int stk[MAX];
 	int top;
    public:
    	stack()
   	 { top=-1; }
   	 void display();
   	 void push(int a);
   	 int pop();
   	 int topp();
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
 void stack::push(int element)
 {
 	if(top==MAX)
 	 cout<<"\nstack i full....";
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
 		int p=stk[top];
 		top--;
 		return p;

 	}
 }//end of pop
 int stack :: topp()
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
	int ch;
	do
	{
		cout<<"\n\n\n1.PUSH\n2.POP\n3.TOP\n4.Display \n 5. Exit\n\n";
		cout<<"\nenter your choice:\t";
		cin>>ch;
		switch(ch)
		{
			case 1:int element;
				cout<<"\nenter element to PUSH:\t";
				cin>>element;
				if (!s.isfull())
				    s.push(element);
				else
				    cout << "\n Full ";
				break;
			case 2: if (!s.isempty())
			        {
			          cout<<"\nPOPed element is:\t"<<s.pop();
				}
				else
				   cout  <<" \n Empty";
				break;
			case 3: if (!s.isempty())
			        {
			           cout<<"\nTOP element is:\t"<<s.topp();
			        }
			        else
			           cout  <<" \n Empty";
				break;

			case 4: s.display(); break;
			case 5: exit(0);
		}//end of switch case
	}while(ch<7);//end of do-while
}





