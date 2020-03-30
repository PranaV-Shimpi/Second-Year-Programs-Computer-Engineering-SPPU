/*
Assignment 4

Program to execute all string operations:
Copy,concatenate,check substring,equality,reverse,length

 */
#include<iostream>
#include <cstring>
using namespace std;
void copy(char c[],char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		c[i]=a[i];
		i++;
	}
	c[i]='\0';
	cout<<"Copied string is: "<<c<<"\n";
}

void concat(char a[],char b[])
{
    	int i,j,flag;
	for(i=0;a[i]!='\0';i++);
		flag=i;
	for(j=0;b[j]!='\0';j++)
	{
		a[i]=b[j];
		i++;
	}
	a[i]='\0';
	cout<<"The concatenated string is: "<<a<<"\n";
	a[flag]='\0';//to reset a to original value
}

void substr(char a[],char b[])
{
	int flag=0,i=0,j=0;
	while(a[i]!='\0')
	{
		if (a[i]==b[j])
		{
			i++;j++;
		}
		else
		{
			i++;j=0;
		}
		if (b[j]=='\0')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"Substring is present\n";
	else
		cout<<"Substring is not present\n";
}

void equal(char a[],char b[])
{
	int l1,l2,flag;
	for(l1=0;a[l1]!='\0';l1++);
	for(l2=0;b[l2]!='\0';l2++);
	if(l1==l2)
	{
		flag=0;
		for(int i=0;a[i]!='\0';i++)
			if(a[i]!=b[i])
				flag=1;
		if(flag==1)
			cout<<"Strings not equal\n";
		else
			cout<<"Strings are equal\n";
	}
	else
		cout<<"Strings not equal\n";

}

void reverse(char a[])
{
	char c[10];
	int l1,i;
	for(l1=0;a[l1]!='\0';l1++);
		for(i=l1-1;i>=0;i--)
			c[l1-1-i]=a[i];
	cout<<"Reversed string is: "<<c<<"\n";
}

void len(char a[],char b[])
{
    	int l1,l2;
   	for(l1=0;a[l1]!='\0';l1++);
	for(l2=0;b[l2]!='\0';l2++);
	cout<<"Length of 1st string is: "<<l1<<"\n";
	cout<<"Length of 2nd string is: "<<l2<<"\n";
}

void palindrome(char a[])
{
	int flag=1,i,j,len;
	for(len=0;a[len]!='\0';len++);

	for(i=0,j=len-1;i<len/2;++i,--j)
	{
		if(a[j]!=a[i]);
		flag=0;
	}
	if(flag=1)
	cout<<"String is Palindrome\n";
	else
	cout<<"String is not Palindrome\n";
}

int main()
{
	char a[10],b[10],c[10];
	int l1,l2,ch;
	cout<<"Enter 2 strings:\n";
	cin.getline(a,50);
	cin.getline(b,50);
	do
	{
		cout<<"\nEnter\n1.Copy\n2.Concatenate\n3.Check substring\n4.Equality\n5.Reverse\n6.Length\n7.Palindrome\n0.Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
			copy(c,a);
			break;
			case 2:
			concat(a,b);
			break;
			case 3:
			for(l1=0;a[l1]!='\0';l1++);
			for(l2=0;b[l2]!='\0';l2++);
			if(l1>l2)		//to make 1st string bigger
				substr(a,b);
			else
				substr(b,a);
			break;
			case 4:
			equal(a,b);
			break;
			case 5:
			reverse(a);
			break;
			case 6:
			len(a,b);
			break;
			case 7:
			palindrome(a);
			break;
			default:
			cout<<"Wrong input\n";
			break;
		}
	} while (ch!=0);
	return 0;
}


/*
Output:

nikhil@kkw-HP-Pro-3330-MT:~/Documents$ ./a.out
Enter 2 strings:
stringopr
ing

Enter
1.Copy
2.Concatenate
3.Check substring
4.Equality
5.Reverse
6.Length
0.Exit
Enter choice: 1
Copied string is: stringopr

Enter
1.Copy
2.Concatenate
3.Check substring
4.Equality
5.Reverse
6.Length
0.Exit
Enter choice: 2
The concatenated string is: stringopring

Enter
1.Copy
2.Concatenate
3.Check substring
4.Equality
5.Reverse
6.Length
0.Exit
Enter choice: 3
String 2 is present in string 1

Enter
1.Copy
2.Concatenate
3.Check substring
4.Equality
5.Reverse
6.Length
0.Exit
Enter choice: 4
Strings not equal

Enter
1.Copy
2.Concatenate
3.Check substring
4.Equality
5.Reverse
6.Length
0.Exit
Enter choice: 5
Reversed string is: rpognirts

Enter
1.Copy
2.Concatenate
3.Check substring
4.Equality
5.Reverse
6.Length
0.Exit
Enter choice: 6
Length of 1st string is: 9
Length of 2nd string is: 3

*/
