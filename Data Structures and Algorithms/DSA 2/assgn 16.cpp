/*
Assignment No: 16

Purpose : Bubble sort And Selection Sort
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class sort
{
	int n;
public:
	float per[100];
	void input();
	void bubble();
	void selection();
};

void sort::input()
{
	cout<<"Enter the no. of students:"<<endl;
	cin>>n;
	cout<<"Enter percentages:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>per[i];
	}
}

void sort::bubble()
{
	float temp;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(per[j]>per[j+1])
			{
				temp=per[j];
				per[j]=per[j+1];
				per[j+1]=temp;
			}
		}
	}
	cout<<"First 5 rankers are:";
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<per[i]<<"\t"<<endl;
	}
}

void sort::selection()
{
	float t;
	int temp;
	for(int i=0;i<n-1;i++)
	{
		temp=i;
		for(int j=i+1;j<n;j++)
		{
			if(per[j]<per[temp])
			{
				temp=j;
			}
		}
		t=per[i];
		per[i]=per[temp];
		per[temp]=t;
	}
	cout<<"First 5 rankers are:"<<endl;
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<per[i]<<"\t"<<endl;
	}
}

int main()
{
	int ch;
	sort s;
	s.input();
	cout<<"1.Bubble Sort\n2.Selection Sort\n3.Exit\nEnter your choice\n";
	do
	{
		cin>>ch;
		switch(ch)
		{
		case 1:
			s.bubble();
			break;

		case 2:
			s.selection();
			break;

		case 3:
			exit(1);
		}
	}while(ch<3);
}



/*
********************************************************output*******************************************************************************
Enter the no. of students:
5
Enter percentages:
34
89
98
55
77
1.Bubble Sort
2.Selection Sort
3.Exit
Enter your choice
1
First 5 rankers are:
98
89
77
55
34

2
First 5 rankers are:
98
89
77
55
34

3

*/
