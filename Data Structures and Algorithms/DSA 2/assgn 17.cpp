/*
Assignment No: 17

Problem Statement :
write c++ progrm to store 12th percentage in array.
write function for sorting of floating point number
in ascending order using bucket sort and display top five score.
*/


#include <iostream>
using namespace std;
class sort
{
	int i,j,k,d,g;
	float a[15],b[15],c[15];

public:

void bsort();
void get();
void display();

sort()  //constructor
{

d=0;
g=0;

  for(i=0;i<15;i++)
  {
          a[i]=0.0;
          b[i]=0.0;
          c[i]=0.0;

  }
}
};

void sort::get()  //input function
{
float x;
cout<<"Enter elements in an array of 15"<<"\n";
	for(i=0;i<15;)
	{
		cin>>x;
		if(x>-100&&x<100)  //aceepet the numbers which are in our range
		{
		a[i]=x;
		i++;
		}
		else
		{
			cout<<"enter again, number not in our range"<<endl;
		}
	}

cout<<endl;
}

void sort::bsort()  //sorting according to the bucket
{

        for(i=0,j=0,k=0;i<15;i++)
	{
		if((a[i]>-10)&&(a[i]<10))   //bucket for single digits
		{
			b[j]=a[i];
			j++;
                        d++;
		}

		else if((a[i]>=10)&&(a[i]<100)||(a[i]<=-10)&&(a[i]>-100))  //bucket for double digits
		{
			c[k]=a[i];
			k++;
                        g++;
		}
		else
		{
			continue;
		}


	}
cout<<endl<<"number in first bucket: "<<d<<endl<<"number in second bucket:"<<g<<endl<<endl; //display the number of digits in each bucket

	for(i=0;i<d;i++)
	{
		for(j=0;j<d;j++)
		{
			if(b[i]<b[j])
			{
				float temp;
				temp=b[i];    //sorting the bucket one
				b[i]=b[j];
				b[j]=temp;
			}
		}

	}

for(i=0;i<g;i++)
{	for(j=0;j<g;j++)
	{
		if(c[i]<c[j])
		{
			float temp1;
			temp1=c[i];
			c[i]=c[j];     //sorting the bucket two
			c[j]=temp1;
		}
	}
}


}
void sort::display()  // display function
{

cout<<"Sorted elements of first bucket  are "<<"\n";
for(i=0;i<d;i++)
{

	cout<<b[i]<<"\t";   // display first bucket only
}

cout<<"\n";
cout<<endl;
cout<<"Sorted elements of second bucket  are "<<"\n";

for(i=0;i<g;i++)
{
	cout<<c[i]<<"\t";   // display second bucket only
}
cout<<endl<<endl;
cout<<"all sorted elements are"<<endl;

// display combine bucket

for(i=0;i<g;i++)
{

	if(c[i]>-100&&c[i]<-10)
	cout<<c[i]<<"\t";
}
for(i=0;i<d;i++)
{
	cout<<b[i]<<"\t";

}
for(i=0;i<g;i++)
{

	if(c[i]>9&&c[i]<100)
	cout<<c[i]<<"\t";
}

}


int main()
{
sort s; //object
s.get();
s.bsort();   //function call
s.display();
return 0;
}

/*
output:

-3010:~/Desktop/Ashish$ g++ 16U202_assgn17.cpp
student@student-OptiPlex-3010:~/Desktop/Ashish$ ./a.out
Enter elements in an array of 15
2.2
-2
20
1.2
-5.6
-5.6
30.1
30.1
3000
enter again, number not in our range
-500
enter again, number not in our range
10
-55.5
45.2
666
enter again, number not in our range
0
2.5
-45
62


number in first bucket: 7
number in second bucket:8

Sorted elements of first bucket  are
-5.6	-5.6	-2	0	1.2	2.2	2.5

Sorted elements of second bucket  are
-55.5	-45	10	20	30.1	30.1	45.2	62

all sorted elements are
-55.5	-45	-5.6	-5.6	-2	0	1.2	2.2	2.5	10	20	30.1	30.1	45.2	62	student@student-OptiPlex-3010:~/Desktop/Ashish$

*/

