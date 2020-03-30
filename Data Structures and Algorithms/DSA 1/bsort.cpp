/*Bubble Sort*/

#include<iostream>
#define MAX 20
using namespace std;
template <class T>
class array
{
 public:
	T arr[MAX];
	int n;

  	void bubblesort();
  	void selectionsort();
  	void display();
};
template <class T>
void array<T>::bubblesort()
{
	T temp;
	int i,j,swap;
	for(i=0;i<n-1;i++)
	{
		swap=0;
		for(j=0;j<(n-i)-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap=1;
			}
		}
		if(swap==0)
			break;
	}
	cout<<"\nAfter Bubble sort:\n";
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
	cout<<"\n";
}
int main()
{
	array<int> a;
	int ch,n,i;
	cout<<"\nenter no of elements\n";
	cin>>a.n;
	cout<<"\nenter elements:\n";
	for(i=0;i<n;i++)
	cin>>a.arr[i];

	do
	{
		cout<<"\n\n*****MENU*****";
		cout<<"\n1.Bubble Sort\n2.Selection Sort\n";
		cout<<"\nEnter your choice:\t";
		cin>>ch;
		switch(ch)
		{
			case 1:a.bubblesort();
				a.display();
				break;
			case 2:a.selectionsort();
				a.display();
				break;
		}
	}while(ch>0);
}









