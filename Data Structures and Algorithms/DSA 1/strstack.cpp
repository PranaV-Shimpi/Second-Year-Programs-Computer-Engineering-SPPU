/*
Assignment :
 STACKS USIING ARRAY*/
 #include <iostream>
 #include "stack.h"
 #include <cstring>

 using namespace std;


int main()
{
	stack <char> s;
	char ch;
	char str[20],str2[20];
	cout << "\n Enter string: ";
	cin >> str;



	int i=0;
	while (str[i] != '\0')
	{
	    s.push(str[i]);
	    i++;
	}
	cout << "\n Pop all : ";
	i=0;
	while (!s.isempty())
	{
	    ch= s.pop();
	    str2[i]=ch;
            i++;
	}
	str2[i]='\0';
	cout << "\n Reverse :"<<str2<< "\n\n";
        if (strcmp(str,str2) == 0)
            cout << "\n Palindrome ";
        else
            cout << "\n NOt palindrome ";

}





