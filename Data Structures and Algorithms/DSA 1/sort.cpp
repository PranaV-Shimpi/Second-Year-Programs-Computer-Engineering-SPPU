/* Sort Operations*/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#define max 20
using namespace std;
struct student
{
	char name[20];
	char mobile[20];
};
class array
{
	student s[max];
	int n;
  public:
  	void read();
  	void seqsearch(char nm[20]);
  	void bisearch(char nm[20]);
  	void bubblesort();
  	void selectionsort();
  	void disp();
};
void array::read()
{
	cout<<"\nEnter no of students:\t";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nDetails of student\t"<<i+1<<":\n";
		cout<<"\nName:\t";
		cin>>s[i].name;
		cout<<"\nMobile no.:\t";
		cin>>s[i].mobile;
	}
}
void array::disp()
{
	cout<<"\nLIST:\n";
	cout<<"\nSr.no       NAME        MOBILE NO.\n";
	cout<<"\n.........................................\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<":     "<<s[i].name<<"     "<<s[i].mobile;
	}
}
void array::seqsearch(char nm[20])
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(nm,s[i].name)==0)
		{
			cout<<"\nName found at location  "<<i+1<<"  .\n";
			flag=1;break;
		}
	}
	if(flag==0)
	{
		cout<<"\nYour name not found...\n";
		strcpy(s[n].name,nm);
		cout<<"\nEnter mobile no: ";
		cin>>s[n].mobile;
		n++;
		//return -1;
	}
}
void array::bisearch(char nm[20])
{
	bubblesort();
	int start,end,mid;
	start=0;
	end=n-1;

	while(start<=end)
	{
		mid=(start+end)/2;
		if(strcmp(s[mid].name,nm)==0)
		{
			cout<<"\nElement found at location\t"<<mid+1;
			break;
		}
		else if(strcmp(s[mid].name,nm)<0)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	if(start>end)
	{
		cout<<"\nYour name not found...\n";
		strcpy(s[n].name,nm);
		cout<<"\nEnter mobile no: ";
		cin>>s[n].mobile;
		n++;
		//return -1;
	}

}
void array::bubblesort()
{
	int i,j,swap=0;
	student t;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(strcmp(s[j].name,s[j+1].name)>0)
			{
				t=s[j];
				s[j]=s[j+1];
				s[j+1]=t;
			}
		}
	}
}
void array::selectionsort()
{
	int i,j,pos;
	char min[20];
	student t;
	for(i=0;i<n;i++)
	{
		strcpy(min,s[i].name);
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[j].name,min)<0)
			{
				strcpy(min,s[j].name);
				pos=j;
			}
		}//for j
		if(i!=pos)
		{
			t=s[i];
			s[i]=s[pos];
			s[pos]=t;
		}
	}//for i
}
int main()
{
	array a;
	int ch;
	char nm[20];
	a.read();
	do{
		cout<<"\n1.To see your List\n2. Sequential search name in list\n3.Binary search\n4.For Bubble sort\n5.Selection Sort\n6.EXIT\n";
		cout<<"\nEnter your choice:\t";
		cin>>ch;
		switch(ch)
		{
			case 1:a.disp();
				break;
			case 2:cout<<"\nEnter name to search:\t";
				cin>>nm;
				a.seqsearch(nm);
				break;
			case 3:cout<<"\nEnter name to search:\t";
				cin>>nm;
				a.bisearch(nm);
				break;
			case 4:a.bubblesort();
				a.disp();
				break;
			case 5:a.selectionsort();
				a.disp();
				break;
			case 6:exit(0);
		}

	}while(ch>0);
	cout<<"\n";
	return 0;
}
