/*Problem Statement:Read the marks obtained by students of second year in online exam of particular subject
.Find out maximum and minimum marks obtained in that subject
.Use heap data structure.Analyze the algorithm.

*/

//header files

#include<iostream>
#include<cstdlib>
#include<cstring>
#include <fstream>
#define SIZE 20
#define MAX 20
using namespace std;

class student
{
	float fMarks;
	char cName[SIZE];
	public:
		student()
		{
			fMarks=0;
			strcpy(cName,"");
		}
		int get_student(char nm[SIZE],float m);
		int put_student();
		float ret_marks();
		char* ret_name();
		int put_marks(float x);
		int put_name(char cStr[SIZE]);
};

int student :: put_student()
{
	cout<<"\n";
	cout<<"\t"<<cName<<"\t"<<fMarks;
	return 1;
}

int student :: get_student(char nm[SIZE],float m)
{
	strcpy(cName,nm);
	fMarks=m;
	return 1;
}

float student :: ret_marks()
{
	return fMarks;
}

char* student :: ret_name()
{
	return cName;
}

int student :: put_marks(float x)
{
	fMarks=x;
	return 1;
}

int student :: put_name(char cStr[SIZE])
{
	strcpy(cName,cStr);
	return 1;
}
class Heap
{
	student Array[MAX];
	int n;
	public:
		Heap()
		{
			n=0;
		}
		int display_root();
		int create_heap();
		int read_array();
		int insert(student x);
		int delete_heap();
		int reheap_up(int i);
		int display();
		int heapify();
		int heapify(int x);			//overloaded heapify for minheap
		int reheap_down(int i,int x);
		int reheap_down(int i,int x,int y);	//overloaded reheap_down for minheap
};

int Heap :: display_root()
{
	Array[0].put_student();
}

int Heap :: reheap_down(int i,int x,int y)		//reheap down function for minheap
{
	int j;
	while(2*i+1<x)
	{
		j=2*i+1;
		if(j+1<x && Array[j].ret_marks()>Array[j+1].ret_marks())
			j=j+1;
		if(Array[i].ret_marks()<Array[j].ret_marks())
			break;
		swap(Array[i],Array[j]);
		i=j;
	}
	return 1;
}

int Heap :: heapify(int x)				//heapify for minheap(function overloading)
{
	int i=(n-1)/2;
	while(i>=0)
	{
		reheap_down(i,n,1);
		i--;
	}
	return 1;
}


int Heap :: create_heap()
{
	int x;
there:	cout<<"\nEnter the number of elements to be entered : ";
	try
	{
		cin>>n;
		if(n>MAX)
			throw n;
	}
	catch(int y)
	{
		cout<<"\nLimit of numbers is "<<MAX;
		goto there;
	}

	ifstream f1("input.txt");
	char nm[SIZE];
	float m;

	for(int i=0;i<n;i++)
	{
		//f1>>nm;
		//f1>>m;
		cout<<"\nEnter Name : ";
		cin>>nm;
		cout<<"\nEnter Marks : ";
		cin>>m;
		Array[i].get_student(nm,m);
		reheap_up(i);
		//Array[i].put_student();
	}
	return 1;
}

int swap(student &a,student &b)
{
	student temp=a;
	a=b;
	b=temp;
	return 1;
}

int Heap :: reheap_up(int i)
{
	while(i>=0 && Array[i].ret_marks()>Array[(i-1)/2].ret_marks())
	{
		swap(Array[i],Array[(i-1)/2]);
		i=(i-1)/2;
	}
	return 1;
}

int Heap :: reheap_down(int i,int x)
{
	int j;
	while(2*i+1<x)
	{
		j=2*i+1;
		if(j+1<x && Array[j].ret_marks()<Array[j+1].ret_marks())
			j=j+1;
		if(Array[i].ret_marks()>Array[j].ret_marks())
			break;
		swap(Array[i],Array[j]);
		i=j;
	}
	return 1;
}

int Heap :: delete_heap()
{
	swap(Array[0],Array[n-1]);
	n=n-1;
	reheap_down(0,n);
	return 1;
}

int Heap :: insert(student x)
{
	n=n+1;
	if(n<=MAX)
	{

		Array[n-1]=x;
		reheap_up(n-1);
	}
	else
		cout<<"\nArray capacity full!";

	return 1;
}

int Heap :: heapify()
{
	int i=(n-1)/2;
	while(i>=0)
	{
		reheap_down(i,n);
		i--;
	}
	return 1;
}

int Heap :: read_array()
{
	cout<<"\nEnter the number of elements to be entered : ";
	cin>>n;
	cout<<"\nEnter the Records : ";
	for(int i=0;i<n;i++)
	{
		//Array[i].get_student();
	}
	//cout<<"\nRecords read successfully!";
	return 1;
}

int Heap :: display()
{
	if(n==0||n<0)
		cout<<"Heap not present!!!";

	else
	{
		cout<<"\n";
		cout<<"\n------------------------";
		cout<<"\n\tNAME\tMARKS";
		cout<<"\n------------------------";
		for(int i=0;i<n;i++)
		{
			Array[i].put_student();
		}
		cout<<"\n------------------------";
	}
	return 1;
}

int main()
{
	Heap h;
	student s;
	int iCh,x,iFlag=0;
	char nm[SIZE];
	float m;
	cout<<"\n   HEAP AND HEAP SORT";
	do
	{
	here:	cout<<"\n------------------------";
		cout<<"\n\tMENU";
		cout<<"\n------------------------";
		cout<<"\n1.Enter Marks\n2.Insert New Marks\n3.Delete \n4.Display\n5.Max Marks\n6.Min Marks\n7.Exit";
		cout<<"\n------------------------";
		cout<<"\nEnter your choice : ";
		cin>>iCh;
		cout<<"\n\n";
		switch(iCh)
		{
			case 1:	h.create_heap();
				iFlag=1;
				break;

			case 2:	cout<<"\nEnter the record to be inserted : ";
				cout<<"\nEnter Name : ";
				cin>>nm;
				cout<<"\nEnter Marks : ";
				cin>>m;
				s.get_student(nm,m);
				h.insert(s);
				h.heapify();
				break;

			case 3:	if(iFlag==0)
					cout<<"\nNo Heap present.";
				else
					h.delete_heap();
				break;

			case 4:	if(iFlag==0)
					cout<<"\nNo Heap present.";
				else
					h.display();
				break;

			case 5:	if(iFlag==0)
					cout<<"\nNo Heap present.";
				else
				{
					h.heapify();
					h.display_root();
				}
				break;

			case 6:	if(iFlag==0)
					cout<<"\nNo Heap present.";
				else
				{
					h.heapify(1);
					h.display_root();
				}
				break;

			case 7:	exit(0);

			default : goto here;
		}
	}while(iCh!=8);

	return 0;
}

/*
OUTPUT :

   HEAP AND HEAP SORT
------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 1



Enter the number of elements to be entered : 10

Enter Name : a

Enter Marks : 45

Enter Name : b

Enter Marks : 88

Enter Name : c

Enter Marks : 77

Enter Name : d

Enter Marks : 15

Enter Name : e

Enter Marks : 97

Enter Name : f

Enter Marks : 2

Enter Name : g

Enter Marks : 6

Enter Name : h

Enter Marks : 55

Enter Name : h

Enter Marks : 67

Enter Name : i

Enter Marks : 83

------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 4




------------------------
	NAME	MARKS
------------------------
	e	97
	b	88
	c	77
	h	67
	i	83
	f	2
	g	6
	d	15
	h	55
	a	45
------------------------
------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 5



	e	97
------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 6



	f	2
------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 3



------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 4




------------------------
	NAME	MARKS
------------------------
	i	83
	d	15
	g	6
	h	55
	a	45
	c	77
	e	97
	h	67
	b	88
------------------------
------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 2



Enter the record to be inserted :
Enter Name : x

Enter Marks : 2

------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 4




------------------------
	NAME	MARKS
------------------------
	e	97
	b	88
	i	83
	h	67
	a	45
	c	77
	g	6
	d	15
	h	55
	x	2
------------------------
------------------------
	MENU
------------------------
1.Enter Marks
2.Insert New Marks
3.Delete
4.Display
5.Max Marks
6.Min Marks
7.Exit
------------------------
Enter your choice : 7

*/
