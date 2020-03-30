/*Assignment No 1
*/

#include <iostream>
using namespace std;
#include<stdlib.h>
int main()
{
	int n,x,n1=0,i,iMarks[100],iChoice,iMax_marks,iMin_marks,iAb,icnt[20],iMost_s_m,imaxcnt,index;
	float fTotal=0;
	float fAvg;

	cout<<"\nenter no of students\n";
	cin>>n;
	cout<<"\nenter marks of students\n";
	for(i=0;i<n;i++)
	{
		cin>>iMarks[i];
	}
		do{
				cout<<"\n\n\n1.TO see sum\n2.To see average\n3.No of absent students\n4.Maximum score\n5.Minimum score\n6.Marks most of students got\n7.Exit\n";
				cin>>iChoice;

	switch(iChoice)
	{
		case 1:n1=0;
				for(i=0;i<=10;i++)
				{
					if(iMarks[i]>0)
					{
						fTotal=fTotal+iMarks[i];
						n1++;
					}
				}
				cout<<"\nsum is\t"<<fTotal;
				break;
		case 2:
				fAvg=fTotal/n1;
				cout<<"\nAverage is\t"<<fAvg;
				break;
		case 3: iAb=n-n1;
				cout<<"\nthe no of absent students is\t"<<iAb;
				break;
		case 4:iMax_marks=iMarks[0];
				for(i=1;i<n;i++)
				{
					if(iMax_marks<iMarks[i])
						iMax_marks=iMarks[i];
				}
				cout<<"\nMaximum marks is\t"<<iMax_marks;
				break;
		case 5:iMin_marks=iMarks[0];
				for(i=1;i<n;i++)
				{
					if((iMin_marks>iMarks[i]) && (iMarks[i]>0))
						iMin_marks=iMarks[i];
				}
				cout<<"\nMinimum marks is\t"<<iMin_marks;
				break;
		case 6:for(i=0;i<=10;i++)
			{
				icnt[i]=0;
			}
			for(i=0;i<n;i++)
				{
					if(iMarks[i]>0)
					{
						x=iMarks[i];
						icnt[x]++;
					}
				}
				imaxcnt=icnt[0],index=0;
				for(i=0;i<=10;i++)
				{
				  if(imaxcnt<icnt[i])
				  {
				    imaxcnt=icnt[i];
				    index=i;
				  }

				}

				cout<<"\n most of the students got\t"<<index<<"\t marks\n";
				break;

		case 7:exit(0);

	}
		}while(iChoice>0);

}
/*output
enter no of students
5

enter marks of students
25
-1
-1
18
15



1.TO see sum
2.To see average
3.No of absent students
4.Maximum score
5.Minimum score
6.Exit
1

sum is	58


1.TO see sum
2.To see average
3.No of absent students
4.Maximum score
5.Minimum score
6.Exit
2

Average is	19.3333


1.TO see sum
2.To see average
3.No of absent students
4.Maximum score
5.Minimum score
6.Exit
3

the no of absent students is	2


1.TO see sum
2.To see average
3.No of absent students
4.Maximum score
5.Minimum score
6.Exit
4

Maximum marks is	25


1.TO see sum
2.To see average
3.No of absent students
4.Maximum score
5.Minimum score
6.Exit
5

Minimum marks is	15


1.TO see sum
2.To see average
3.No of absent students
4.Maximum score
5.Minimum score
6.Exit
6
*/
