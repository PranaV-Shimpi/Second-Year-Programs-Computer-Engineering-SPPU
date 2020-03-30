/*
 DSA Asssignment No. 5

Purpose: To do various opertion like lenght of string, reversing string,comparing string,copying string,concatenation of string,checking  substring .
*/

#include <iostream> //header file
using namespace std;

class str	// Declaration of class
{
	int i,j,a,b,f,k;		//Private declerations
	char str3[10],substr1[10],str1[10],str2[10],rev1[20],rev2[20];

	public:			//public function
	void getdata();
	void calc();
	void putdata();
};

void str::getdata()			//Function to take input of string (lenght restriction to 10)
{
	/*cout<<"Enter The string1 lenght"<<endl;
	cin>>i;
	cout<<"Enter The string2 lenght"<<endl;
	cin>>j;
	*/
	cout<<endl<<"Enter The string1"<<endl;
	cin.getline(str1,10);
	cout<<endl<<"Enter The string2"<<endl;
	cin.getline(str2,10);cout<<endl;
}

void str::calc()		//Function to calculate lenght of string ,reversing string,comparing string,copying string,

{
   {
	//lenght of string
	cout<<"to check the lenght of string1"<<endl;
	for(i=0; str1[i]!='\0';++i);
	a=i;

        cout << "Length of string1: " << i<<endl<<endl;
	cout<<"to check the lenght of string2"<<endl;
	for(i=0; str2[i]!='\0';++i);
		b=i;

    cout << "Length of string2: " << i<<endl<<endl;
   }

   {		//reverse of string
		int p=-1;
		int q=0;
		while(str1[++p]!='\0');
		while(p>=0)
		rev1[q++]=str1[--p];
		rev1[q]='\0';
		cout<<"reverse of string1 is:"<<rev1<<endl<<endl; //reverse of string 1
		int w=-1;
		int e=0;
		while(str2[++w]!='\0');
		while(w>=0)
		rev2[e++]=str2[--w];
		rev2[e]='\0';
		cout<<"reverse of string2 is:"<<rev2<<endl<<endl;  //reverse of string 2
    }

    {
	f=0;	// comparing string
	if (a==b)
	{

		for(i=0;i<a;i++)
			{
			if (str2[i] != str1[i] )
				{
				f=1;

				i=a;
				}
			}
	}

	if(f==1)
			{
			cout<<"strings are  same"<<endl<<endl;
			}
	else
	cout<<"string are not same"<<endl<<endl;
    }

    {  // to copy
	for(i=0;i<a;i++)
	str3[i]=str1[i];
	cout<<"after copying in other string:";  //copying in other string
	for(i=0;i<a;i++)
	cout<<str3[i];
	cout<<endl;
    }

    {	//to concat
	for(i=0; str1[i]!='\0'; ++i);
	    for(j=0; str2[j]!='\0'; ++j, ++i)   //concatenation
	    {
		str1[i]=str2[j];
	    }
	    str1[i]='\0';
	    cout << "After concatenation: " << str1<<endl<<endl;
    }

    {   //to check substring

	cout<<"Enter The substring"<<endl;
	cin.getline(substr1,10);

	for(j=0;j<a;j++)
			{
			if (substr1[j] != str1[j] )    //substring checking
				{
				k=1;

				j=a;
				}
			}
	if(k==1)
			{
			cout<<"The entered string is not a substring"<<endl<<endl;
			}
	else
	cout<<"the entered string is substring "<<endl<<endl;

    }
}

int main()		//main function
{
	str c;
	c.getdata();
	c.calc();
}

/*

OUTPUT
student@student-OptiPlex-3010:~/student/dsa/final$ g++ dsa5.cpp
student@student-OptiPlex-3010:~/student/dsa/final$ ./a.out

Enter The string1
chetan

Enter The string2
ghate

to check the lenght of string1
Length of string1: 6

to check the lenght of string2
Length of string2: 5

reverse of string1 is:natehc

reverse of string2 is:etahg

string are not same

after copying in other string:chetan
After concatenation: chetanghate

Enter The substring
chetan
the entered string is substring


*/
