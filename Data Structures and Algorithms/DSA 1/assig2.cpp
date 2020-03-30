/*Assignment no. 02
 */
#include <iostream>
#include<stdlib.h>
using namespace std;
int stlen(char str1[20]);
void stcnt(char [50],char [50]);
void stutl( char str1[50]);
void stfind(char str1[50]);
void stcmp(char str1[50],char str2[50]);
void strev(char str1[50]);
int main()
{
	int i,j,choice,exist,equal=1,l1,l2;
	char str1[50],str2[50],str3[50],ch,rev1[50],rev2[50];



	cout<<"\nenter first a string\n";
	cin>>str1;
	cout<<"\n enter second string\n";
	cin>>str2;
	do{
	cout<<"\n1.to see length of string\n2.to concatenate the strings\n3.for uppr to lower case\n4.to find perticular char \n5.to compare the strings\n6.to reverse strings\n7.exit\n";
	cin>>choice;
		switch(choice)
		{
			case 1:
				l1=stlen(str1);cout<<"\nlength of first string is\t"<<l1<<"\n";
                                l2=stlen(str2);cout<<"\nlength of seecond string is\t"<<l2<<"\n";
				break;
			case 2:
			        stcnt(str1,str2);
                                cout<<"\nconcatenated string is\n"<<str1;
		                cout<<"\n";
				break;
			case 3:stutl(str1);
				cout<<"\nfor first string\n"<<str1;
				stutl(str2);
                               cout<<"\nfor second string\n"<<str2;

				break;
			case 4:

				cout<<"\nfor string 1:\n";
				stfind(str1);
				cout<<"\nfor string 2:\n";
				stfind(str2);
			       break;
			case 5:stcmp(str1,str2);
				break;

			case 6:cout<<"\nfor string 1:\n";
				strev(str1);
				cout<<"\nfor string 2:\n";
				strev(str2);
				break;

			case 7:exit(0);
			default:cout<<"\nenter valid choice\n";
		}
	}while(choice!=0);
}// end of main


int stlen(char str1[20])
{
 int i=0;
 while(str1[i]!= '\0')
 {
	i++;
 }
 return i;

}





void stcnt(char str1[50],char str2[50])
{
                int i,j;
		for(i=0;str1[i]!='\0';i++);

		for(j=0;str2[j]!='\0';j++)
		{
			str1[i]=str2[j];
			i++;
		}
		str1[i]='\0';

}

void stutl(char str1[50])
{
		int i,j;
		cout<<"\nlower to upper case:\n";
                for(i=0;str1[i]!='\0';i++)
                {
		 	if(str1[i]>='a'&&str1[i]<='z')
			{
				str1[i]=str1[i]-32;
			}
			else if(str1[i]>='A'&&str1[i]<='Z')
			{
				str1[i]=str1[i]+32;
			}
		}


}

void stfind(char str1[50])
{
   char ch;
   cout<<"\nenter a char to search\n";
   cin>>ch;
   int i,exist=0;

   for(i=0;str1[i]!='\0';i++)
   {
	if(str1[i]==ch)
	{exist=1;}
   }
   if(exist==1)
   cout<<"\n"<<ch<<"\tis present in string \n";
   else
   cout<<"\n"<<ch<<"\tis not present in string \n";

}

void stcmp(char str1[50],char str2[50])
{
	int equal,i=0;
	while(str1[i]!='\0')
	{
		if(str1[i]!=str2[i])
		equal=0;
		i++;
	}
	if(equal==1)
	cout<<"\nthe two strings are equal\n";
	else if(equal==0)
	cout<<"\nthe two strings are not equal\n";
}

void strev(char str1[50])
{
	int i,j;
	char rev1[50];
	for(i=0;str1[i]!='\0';i++);

	i=i-1;
	j=0;
	while(i>=0)
	{
		rev1[j]=str1[i];
		j++;
		i--;
	}
	cout<<"\nreverse of  string is:\n"<<rev1;



}



