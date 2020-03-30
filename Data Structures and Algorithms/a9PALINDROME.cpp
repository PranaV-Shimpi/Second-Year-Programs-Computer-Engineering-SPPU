/*
Assignment No.9

Write C++ program with functions-
1. To check whether given string is palindrome or not that uses a stack to determine whether
a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the Characters to lowercase, and
then call above Palindrome checking function to check for a palindrome
3. to print string in reverse order using stack

Done by: Pranav Shimpi
*/

#include <cstring>
#include "stack.h"

int main()
{
	stack <char> s;
	char str1[20],str2[20],str3[20],ch;
	int choice,i=0,j=0;
	cout << "\nEnter string: ";

	cin.getline(str1,20);
	while (str1[i] !='\0')
			s.push(str1[i++]);
	i=0;
	while(!s.isempty())
	{
		str3[i++]=s.pop();
		if(str3[i-1]!=' ')
		str2[j++]=str3[i-1];
	}
	str2[j]='\0';
	str3[i]='\0';

	do
	{
    	cout<<"Enter\n1.Reverse string without spaces\n2.Check palindrome or not\n0.Exit\nEnter choice ";
    	cin>>choice;
    	switch(choice)
    	{
    	    case 0: break;
    		case 1:
    			cout <<"Reversed string without spaces is : "<< str2<<"\n";
    		break;
    		case 2:
    			if (!strcmp(str1,str3))
    				cout << "Palindrome\n";
    			else
    				cout << "Not Palindrome\n";
    		break;
    		default:
    			cout<<"Invalid choice\n";
    	}
	}while(choice!=0);
	return 0;
}

/*
Output:

Enter string: abc cba
Enter
1.Reverse string without spaces
2.Check palindrome or not
0.Exit
Enter choice 1
Reversed string without spaces is : abccba
Enter
1.Reverse string without spaces
2.Check palindrome or not
0.Exit
Enter choice 2
Palindrome
Enter
1.Reverse string without spaces
2.Check palindrome or not
0.Exit
Enter choice 0

F:\SEA-28-dsa>
*/
