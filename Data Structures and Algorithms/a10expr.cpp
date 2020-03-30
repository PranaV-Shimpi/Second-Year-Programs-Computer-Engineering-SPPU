/*
Assignment 10

Implement C++ program for expression conversion-
a) infix to prefix, b)prefix to postfix,
c) prefix to infix, d) postfix to infix and e) postfix to prefix.

Done by: Pranav Shimpi
*/

#include <iostream>
#include "stack.h"
#include <string>
using namespace std;

int icp(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':	return 1;
		case '*':
		case '/':
		case '%':	return 2;
		case '^':	return 3;
		case '(':	return 4;
		case ')':	return 4;//what priority ?
	}
}

int isp(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':	return 1;
		case '*':
		case '/':
		case '%':	return 2;
		case '^':	return 3;
		case '(':	return 0;
		case ')':	return 0;
	}
}

string intopost(string infix)
{
	stack <char> s;
	string res;
	char ch;
	for(int i=0;i<infix.length();i++)
	{
		ch=infix[i];				//take current char and increment
		if(isalpha(ch))				//operand
			res+=ch;
		else if(ch==')')
		{
			while(s.gettop()!='(')
				res+=s.pop();
			s.pop();				//to pop '(' but not display
		}
		else						//operator
		{	if(!s.isempty())
				while(isp(s.gettop()) >= icp(ch))	//in stack priority >= incoming priority
					res+=s.pop();
			s.push(ch);
		}
	}
	while(!s.isempty())				//pop remaining
		res+=s.pop();
	return res;
}
string posttoin(string post)
{
	stack <string> s;
	string res;
	char ch;
	for(int i=0;i<post.length();i++)
	{
		ch=post[i];					//take current char and increment
		string temp="";
		temp=temp+ch;
		if(isalpha(ch))		//operand
			s.push(temp);
		else if(ch==')')
		{
			while(s.gettop()!="(")
				res+=s.pop();
			s.pop();				//to pop '(' but not display
		}
		else						//operator
		{	if(!s.isempty())
			{
				string op2=s.pop();
				string op1=s.pop();
				string ans="("+op1+temp+op2+")";
				s.push(ans);
			}
		}
	}
	res+=s.pop();
	return res;

}
string intopre(string infix)
{
 	stack <char> s;
 	string ans;
 	char ch;
 	char pre[20],rev[20];
 	int j=0,k=0;

 	for(int i=infix.length()-1;i>=0;i--)
 	{
 		ch=infix[i];
 		if(ch>='a'&&ch<='z')
 		{
 			pre[j]=ch;
 			j++;
 		}
 		else if(ch=='(')
 		{
 			while(s.gettop()!=')')
 			{
 				pre[j]=s.pop();
 				j++;
 			}
 			s.pop();
 		}
 		else
 		{
 			if(!s.isempty())
 				while(isp(s.gettop())>icp(ch))
 				{
 					pre[j]=s.pop();
 					j++;
 				}
 			s.push(ch);
 		}
 	}
	while(!s.isempty())
	{
		pre[j]=s.pop();
		j++;
	}
 	pre[j]='\0';
 	j--;
 	while(j>=0)
 	{
 		rev[k]=pre[j];
 		k++;j--;
 	}
 	rev[k]='\0';
 	ans=rev;
 	return ans;
}

string pretoin(string pre)
{
	stack <string> s;
	char ch;
	for(int i=pre.length()-1;i>=0;i--)
	{
		ch=pre[i];					//take current char and increment
		string temp="";
		temp=temp+ch;
		if(isalpha(ch))		//operand
			s.push(temp);
		else if(ch==')')
		{
			while(s.gettop()!="(")
				cout<<s.pop();
			s.pop();				//to pop '(' but not display
		}
		else						//operator
		{	if(!s.isempty())
			{
				string op2=s.pop();
				string op1=s.pop();
				string ans="("+op2+temp+op1+")";
				s.push(ans);
			}
		}
	}
	return s.pop();
}

void evaluate(string post)
{
	stack <float> s;
	char ch;
	float val1,op1,op2,ans;
	for(int i=0;i<post.length();i++)
	{
		ch=post[i];
		if(isalpha(ch))
		{
			cout<<"\nenter value of "<<post[i]<<": ";
			cin>>val1;
			s.push(val1);
		}
		else
		{
			op2=s.pop();
			op1=s.pop();
			switch(ch)
			{
				case '+':
					ans=op1+op2;
					break;
				case '-':
					ans=op1-op2;
					break;
				case '*':
					ans=op1*op2;
					break;
				case '/':
					ans=op1/op2;
					break;
				case '%':
					ans=int(op1)%int(op2);
					break;
			}
			s.push(ans);
		}
	}
	cout<<"\nValue of expression= "<<s.pop()<<"\n\n";
}

int main()
{
	int choice;
	string input,ans;
	do
	{
		cout<<"Enter expression ";
		cin>>input;
		cout<<"Enter \n1.Infix to postfix\n2.Postfix to infix\n3.Infix to prefix\n4.Prefix to infix\n5.Postfix evaluation";
		cout<<"\n6.Prefix to postfix\n7.Postfix to prefix\n0.Exit\nEnter choice ";
		cin>>choice;

		switch(choice)
		{
			case 0:break;
			case 1:
				ans=intopost(input);
				cout<<"Postfix expression: "<<ans<<"\n";
				break;
			case 2:
				ans=posttoin(input);
				cout<<"Infix expression: "<<ans<<"\n";
				break;
			case 3:
				ans=intopre(input);
				cout<<"Prefix expression: "<<ans<<"\n";
				break;
			case 4:
				ans=pretoin(input);
				cout<<"Infix expression: "<<ans<<"\n";
				break;
			case 5:
				evaluate(input);
				break;
			case 6:
				ans=intopost(pretoin(input));
				cout<<"Postfix expression: "<<ans<<"\n";
				break;
			case 7:
				ans=intopre(posttoin(input));
				cout<<"Prefix expression: "<<ans<<"\n";
				break;
			default:
				cout<<"Invalid choice\n";
		}
	}while(choice!=0);
	return 0;
}

/*
Output:

Enter
1.Infix to postfix
2.Postfix to infix
3.Infix to prefix
4.Prefix to infix
5.Postfix evaluation
0.Exit
Enter choice 1
Enter expression a+b*(c-d)/e
Postfix expression: abcd-*e/+
Enter
1.Infix to postfix
2.Postfix to infix
3.Infix to prefix
4.Prefix to infix
5.Postfix evaluation
0.Exit
Enter choice 2
Enter expression abcd-*e/+
Infix expression: (a+((b*(c-d))/e))
Enter
1.Infix to postfix
2.Postfix to infix
3.Infix to prefix
4.Prefix to infix
5.Postfix evaluation
0.Exit
Enter choice 3
Enter expression a+b*(c-d)/e
Stack is empty
Prefix expression: +a/*b-cde
Enter
1.Infix to postfix
2.Postfix to infix
3.Infix to prefix
4.Prefix to infix
5.Postfix evaluation
0.Exit
Enter choice 4
Enter expression +a/*b-cde
Infix expression: (a+((b*(c-d))/e))
Enter
1.Infix to postfix
2.Postfix to infix
3.Infix to prefix
4.Prefix to infix
5.Postfix evaluation
0.Exit
Enter choice 5
Enter expression abcd-*e/+

enter value of a: 1
enter value of b: 2
enter value of c: 3
enter value of d: 4
enter value of e: 5

Value of expression= 0.6

Enter
1.Infix to postfix
2.Postfix to infix
3.Infix to prefix
4.Prefix to infix
5.Postfix evaluation
0.Exit
Enter choice 0
*/
