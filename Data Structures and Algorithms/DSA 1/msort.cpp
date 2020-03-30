// Merge Sort

#include<iostream>
using namespace std;
int main()
{
	int i,j,k,m,n,a[20],b[20],c[20];
	cout<<"\nenter no of elements in first array:\t";
	cin>>m;
	cout<<"\nenter elements of first array in ascending order\n";
	for(i=0;i<m;i++)
	cin>>a[i];
	cout<<"\nenter no of elements in second array:\t";
	cin>>n;
	cout<<"\nenter elements of second array in ascending order\n";
	for(j=0;j<n;j++)
	cin>>b[j];
	i=0;
	j=0;
	k=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;k++;
		}
		else if(a[i]>b[j])
		{
			c[k]=b[j];
			j++;k++;
		}
		else
		{
			c[k]=a[i];
			k++;i++;
			c[k]=b[j];
			k++;j++;
		}
	}

	while(i<m)
	{
		c[k]=a[i];
		i++;k++;
	}
	while(j<n)
	{
		c[k]=b[j];
		j++;k++;
	}
	//k=k-1;
	cout<<"\nAfter merging :\n";
	for(i=0;i<k;i++)
	cout<<c[i]<<"\n";

}
