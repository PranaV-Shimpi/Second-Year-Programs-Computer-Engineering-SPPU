/*Binary Sort*/

#include<iostream>
using namespace std;
int main()
{
	int i,j,key,a[20],n;
	int start,end,mid,flag;
	cout<<"\nenter no of elements\n";
	cin>>n;
	cout<<"\nenter elements in ascending order\n";
	for(i=0;i<n;i++)
		cin>>a[i];

	cout<<"\nenter element to search:\t";
	cin>>key;
	start=0;
	end=n-1;
	while(start<=end)
	{
		mid=(start+end)/2;

		if(a[mid]==key)
		{
			cout<<"\nelement found at location\t"<<mid+1;
			break;
		}
		else if(a[mid]<key)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}

	if(start>end)
	cout<<"\nelement not found\n";
		cout<<"\n";
}
