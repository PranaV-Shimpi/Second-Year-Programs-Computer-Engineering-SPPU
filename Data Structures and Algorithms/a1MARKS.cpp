/*
Assignment 1

Program to accept marks for n students.
Compute:
1.The avg score
2.Highest and lowset score
3.Marks scored by most of the students
4.List of students absent for the test


 */
#include<iostream>
using namespace std;

int main()
{
	int max,min,i,j,f,temp,max_mks,ch;
	int DSA_mks[20],n,total=0,count=0;
	cout<<"Enter the no. of students ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter marks for student"<<i+1<<"(-1 if absent) ";
		cin>>DSA_mks[i];
	}
	do
	{
		cout<<"Enter:\n1.The avg score\n2.Highest and lowest score\n3.Marks scored by most of the students\n4.List of students absent for the test\n0.Exit\n";
		cout<<"Enter your choice ";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
			count=0;
			total=0;
			for (i = 0; i < n; ++i)
				if(DSA_mks[i]!=-1)
				{
					total+=DSA_mks[i];
					count++;
				}
			cout<<"The average is "<<total/float(count)<<"\n";
			break;
			case 2:
			max=0,min=1000000;
			for(i = 0; i < n; ++i)
			{
				if(DSA_mks[i]>max )
					max=DSA_mks[i];
				if(min>DSA_mks[i] && DSA_mks[i]!=-1)
					min=DSA_mks[i];
			}
			cout<<"The max marks are: "<<max<<" and the min marks are: "<<min<<"\n";
			break;
			case 3:
			f=0,max_mks=0;
			for (i = 0; i < n; ++i)
			{
				count=0;
				temp=DSA_mks[i];
				for (j = 0; j < n; ++j)
					if(DSA_mks[j]==temp && DSA_mks[j]!=-1)
						count++;
				if(f<count)
				{
					f=count;
					max_mks=temp;
				}
			}
			cout<<"Roll No.\tMarks\n";
			for (i = 0; i < n; ++i)
				if(DSA_mks[i]==max_mks)
					cout<<i+1<<"\t\t"<<max_mks<<"\n";
			break;
			case 4:
			temp=0;
			for (i = 0; i < n; ++i)
				if(DSA_mks[i]==-1)
				{
				    cout<<"Roll No."<<i+1<<" is absent\n";
				    temp=1;
				}
			if(temp==0)
			    cout<<"No one is absent\n";
			break;
			default:
			cout<<"Invalid choice\n";
		}
	}while(ch!=0);
    return 0;
}

/*
Output:

nikhil@kkw-HP-Pro-3330-MT:~/Documents$ ./a.out
Enter the no. of students 4
Enter name for student 1 rgf
Enter marks for student1(-1 if absent) -1
Enter name for student 2 tgf
Enter marks for student2(-1 if absent) 67
Enter name for student 3 ytgh
Enter marks for student3(-1 if absent) 89
Enter name for student 4 ghf
Enter marks for student4(-1 if absent) 67
Enter:
1.The avg score
2.Highest and lowest score
3.Marks scored by most of the students
4.List of students absent for the test
0.Exit
1
The average is 74.3333
Enter:
1.The avg score
2.Highest and lowest score
3.Marks scored by most of the students
4.List of students absent for the test
0.Exit
2
The max marks are: 89 and the min marks are: 67
Enter:
1.The avg score
2.Highest and lowest score
3.Marks scored by most of the students
4.List of students absent for the test
0.Exit
3
Roll No.	Marks
2			67
4			67
Enter:
1.The avg score
2.Highest and lowest score
3.Marks scored by most of the students
4.List of students absent for the test
0.Exit
4
The list of absent students is:
Roll No.1 is absent
Enter:
1.The avg score
2.Highest and lowest score
3.Marks scored by most of the students
4.List of students absent for the test
0.Exit

*/
