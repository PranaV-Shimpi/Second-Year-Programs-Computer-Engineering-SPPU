/* Substring finding */

#include<iostream>
using namespace std;
int main()
{
	int i,j,flag;
	char str[50],substr[50];
	cout<<"\nenter a string\n ";
	cin>>str;
	cout<<"\nenter sub string\n";
	cin>>substr;
	i=0;
	j=0;
	flag=0;
	while(str[i]!='\0')
	{
		if(substr[j]==str[i])
		{
			if(substr[j+1]=='\0')
			{flag=1;}

			i++;j++;
		}
		else
		{

			if (substr[j]!=str[i])
			{i++;j=0;}

		}

	}
	if(flag==1)
	cout<<"\nsub string is present\n";
	else if(flag==0)
	cout<<"\nsub string is not present\n";

}
