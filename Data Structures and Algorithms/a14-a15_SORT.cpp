/*
Assignment No.14 and 15

Write C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
	a) Selection Sort
	b) Bubble sort and display top five scores.
Write C++ program to store second year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
	a) Insertion sort
	b) Shell Sort and display top five scores

Done by: Pranav Shimpi
*/

#include <iostream>
using namespace std;

class list
{
	float a[20];
	int n;
public:
	list()
	{
		n=0;
	}
	list(const list &l)
	{
	    for(int i=0;i<n;i++)
	        a[i]=l.a[i];
        n=l.n;
	}

	~list(){}
	void read();
	void display();
	void bubble();
	void bubblerev();
	void selection();
	void insertion();
	void shell();
};

void list::read()
{
	cout<<"Enter no of records to add\n";
	cin>>n;
	cout<<"Enter marks\n";

	for(int i=0;i<n;i++)
		cin>>a[i];
}

void list::display()
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

void list::bubble()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (a[j]>a[j+1])
			{
				float temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		cout<<"Pass "<<i+1<<": ";
		display();
	}
}

void list::bubblerev()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i; ++j)
		{
			if (a[j]<a[j+1])
			{
				float temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"Top 5: ";
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

void list::selection()
{
	int min=0;
	for (int i = 0; i < n; ++i)
	{
		min=i;
		for (int j = i+1; j < n; ++j)
		{
			if(a[min]>a[j])
				min=j;
		}
		if (min!=i)
		{
			float temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
		cout<<"Pass "<<i+1<<": ";
		display();
	}
}

void list::insertion()
{
	float element;
	for (int i = 1; i < n; ++i)
	{
		element=a[i];
		int j=i-1;
		while(a[j]>element && j>=0)  //use temp araay
		{
			a[j+1]=a[j];		//shifting to right
			j--;
		}
		a[j+1]=element;
		cout<<"Pass "<<i<<": ";
		display();
	}
}

void list::shell()
{
	int gap,i,j,temp;
	for (int gap = n/2; gap > 0; gap/=2)
	{
		for (int i = gap; i < n; ++i)
			for (int j = i-gap; j>=0 && a[j]>a[j+gap]; j-=gap)
			{
				float temp=a[j];
				a[j]=a[j+gap];
				a[j+gap]=temp;
			}
		cout<<"Pass: ";
		display();
	}
}

//display passes-- call display in loop
int main()
{
	int choice;
	list temp,l;
	temp.read();

	do
	{
	    l=temp;
		cout<<"Enter\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Shell sort\n5.Display top 5\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
		    case 0: break;
			case 1:
			l.bubble();
			break;
			case 2:
			l.selection();			//send a copy of array to function
			break;
			case 3:					//use templates
			l.insertion();
			break;
			case 4:
			l.shell();
			break;
			case 5:
			l.bubblerev();
			break;
			default:
			cout<<"Invalid choice\n";
		}
	}while(choice!=0);
	return 0;
}

/*
Output:

Enter no of records to add
10
Enter marks
78
45
56
89
82
95
68
76
91
84
Enter
1.Bubble sort
2.Selection sort
3.Insertion sort
4.Shell sort
5.Display top 5
0.Exit
Enter choice 1
Pass 1: 45 56 78 82 89 68 76 91 84 95
Pass 2: 45 56 78 82 68 76 89 84 91 95
Pass 3: 45 56 78 68 76 82 84 89 91 95
Pass 4: 45 56 68 76 78 82 84 89 91 95
Pass 5: 45 56 68 76 78 82 84 89 91 95
Pass 6: 45 56 68 76 78 82 84 89 91 95
Pass 7: 45 56 68 76 78 82 84 89 91 95
Pass 8: 45 56 68 76 78 82 84 89 91 95
Pass 9: 45 56 68 76 78 82 84 89 91 95
Pass 10: 45 56 68 76 78 82 84 89 91 95
Enter
1.Bubble sort
2.Selection sort
3.Insertion sort
4.Shell sort
5.Display top 5
0.Exit
Enter choice 2
Pass 1: 45 78 56 89 82 95 68 76 91 84
Pass 2: 45 56 78 89 82 95 68 76 91 84
Pass 3: 45 56 68 89 82 95 78 76 91 84
Pass 4: 45 56 68 76 82 95 78 89 91 84
Pass 5: 45 56 68 76 78 95 82 89 91 84
Pass 6: 45 56 68 76 78 82 95 89 91 84
Pass 7: 45 56 68 76 78 82 84 89 91 95
Pass 8: 45 56 68 76 78 82 84 89 91 95
Pass 9: 45 56 68 76 78 82 84 89 91 95
Pass 10: 45 56 68 76 78 82 84 89 91 95
Enter
1.Bubble sort
2.Selection sort
3.Insertion sort
4.Shell sort
5.Display top 5
0.Exit
Enter choice 3
Pass 1: 45 78 56 89 82 95 68 76 91 84
Pass 2: 45 56 78 89 82 95 68 76 91 84
Pass 3: 45 56 78 89 82 95 68 76 91 84
Pass 4: 45 56 78 82 89 95 68 76 91 84
Pass 5: 45 56 78 82 89 95 68 76 91 84
Pass 6: 45 56 68 78 82 89 95 76 91 84
Pass 7: 45 56 68 76 78 82 89 95 91 84
Pass 8: 45 56 68 76 78 82 89 91 95 84
Pass 9: 45 56 68 76 78 82 84 89 91 95
Enter
1.Bubble sort
2.Selection sort
3.Insertion sort
4.Shell sort
5.Display top 5
0.Exit
Enter choice 4
Pass: 78 45 56 89 82 95 68 76 91 84
Pass: 56 45 68 76 78 84 82 89 91 95
Pass: 45 56 68 76 78 82 84 89 91 95
Enter
1.Bubble sort
2.Selection sort
3.Insertion sort
4.Shell sort
5.Display top 5
0.Exit
Enter choice 5
Top 5: 95 91 89 84 82
Enter
1.Bubble sort
2.Selection sort
3.Insertion sort
4.Shell sort
5.Display top 5
0.Exit
Enter choice 0
*/
