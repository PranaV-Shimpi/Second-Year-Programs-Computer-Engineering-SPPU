/*
Assignment 6:

Write a program to implement funstioon template selection
and bubble sort.

Done by: Pranav Shimpi
*/
#include <iostream>
using namespace std;

template<class T>
class sort
{
	T a[20];
	int n;
public:
	sort(){}
	~sort(){}
	void selection();
	void bubble();
	void display();
	void read();
};

template<class T>
void sort<T>::selection()
{
	int i,j,min;
	for (i = 0; i < n-1; i++)
	{
		min=i;
		for (j = i+1; j < n; j++)
			if (a[j]<a[min])
				min=j;
		T temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

template<class T>
void sort<T>::bubble()
{
	int i,j;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-1-i; j++)
			if (a[j]>a[j+1])
			{
				T temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}


template<class T>
void sort<T>::display()
{
	cout<<"\nThe sorted array is:\n";
	for (int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

template<class T>
void sort<T>::read()
{
	cout<<"Enter the number of elements in array ";
	cin>>n;
	cout<<"Enter the array\n";
	for (int i = 0; i < n; i++)
		cin>>a[i];
}

int main()
{
	int x,ch;
	do
	{
		cout<<"Enter 1 for selection sort, 2 for bubble sort ";
		cin>>x;
		cout<<"\nEnter\n1.Integer array\n2.Float array\n3.Character array\n4.String array\n0.Exit\nEnter your choice ";
		cin>>ch;
		switch(ch)
		{
			case 0:break;
			case 1:
			{
				sort<int> c;
				c.read();
				(x==1) ? c.selection():c.bubble();
				c.display();
			}
				break;
			case 2:
			{
				sort<float> c;
				c.read();
				(x==1) ? c.selection():c.bubble();
				c.display();
			}
				break;
			case 3:
			{
				sort<char> c;
				c.read();
				(x==1) ? c.selection():c.bubble();
				c.display();
			}
			break;
			case 4:
			{
				sort<string> c;
				c.read();
				(x==1) ? c.selection():c.bubble();
				c.display();
			}
			break;
			default:
			cout<<"Invalid input\n";
		}
	}while(ch!=0);
	return 0;
}

/*
Output:


The sorted array is:

Enter 1 for selection sort, 2 for bubble sort 1

Enter
1.Integer array
2.Float array
3.Character array
4.String array
0.Exit
Enter your choice 1
Enter the number of elements in array 5
Enter the array
54
3
67
2
89

The sorted array is:
2 3 54 67 89
Enter 1 for selection sort, 2 for bubble sort 1

Enter
1.Integer array
2.Float array
3.Character array
4.String array
0.Exit
Enter your choice 2
Enter the number of elements in array 5
Enter the array
45.6
3.7
23.4
2.8
12.7

The sorted array is:
2.8 3.7 12.7 23.4 45.6
Enter 1 for selection sort, 2 for bubble sort 1

Enter
1.Integer array
2.Float array
3.Character array
4.String array
0.Exit
Enter your choice 3
Enter the number of elements in array 5
Enter the array
w
a
s
d
b

The sorted array is:
a b d s w
Enter 1 for selection sort, 2 for bubble sort 2

Enter
1.Integer array
2.Float array
3.Character array
4.String array
0.Exit
Enter your choice 4
Enter the number of elements in array 4
Enter the array
wqer
asd
fgh
nmk

The sorted array is:
asd fgh nmk wqer
Enter 1 for selection sort, 2 for bubble sort 2

Enter
1.Integer array
2.Float array
3.Character array
4.String array
0.Exit
Enter your choice 0

*/
