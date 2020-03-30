/* Assignment :
 strings using stack(expression)*/
 #include<iostream>
 #include<string.h>
 #include "stack.h"
 void evaluate(char postfix[20])
 {
 	stack <float> s;
 	char ch;
 	float val1,op1,op2,ans;
 	int i=0;
 	while(postfix[i]!='\0')
 	{
 		ch=postfix[i];
 		if(ch>='a'&&ch<='z')
 		{
 			cout<<"\nenter value of\t"<<postfix[i]<<"\t:\t";
 			cin>>val1;
 			s.push(val1);
 		}
 		else
 		{
 			op2=s.pop();
 			op1=s.pop();
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
	i++;
 	}//end of while
 	cout<<"\nAfter evaluation:\t"<<s.pop();
 }
 int main()
 {
 	char postfix[20];
 	cout<<"\nenter a postfix expression:\t";
 	cin>>postfix;
 	evaluate(postfix);
 	cout<<"\n";
 	return 0;
 }








