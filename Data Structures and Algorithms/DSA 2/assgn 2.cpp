
// DSA Asssignment No. 2


#include<iostream>//header files
using namespace std;
int main()
{
int a[3][3];
int i,j;
int sum1=0,sum2=0,count=0;

cout<<"enter the elements of matrix"<<endl;
//accept the data
for(i=0;i<3;i++)
   {
     cout<<endl;
     for(j=0;j<3;j++)
      {
        cin>>a[i][j];
      }
   }
cout<<endl;
//display the data
for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
      {
        cout<<a[i][j]<<"\t";
      }
         cout<<endl;
   }
cout<<endl;


    // for sum1
  for(i=0;i<3;i++)
    {

     for(j=0;j<3;j++)
      {
        sum1=sum1+a[i][j];
       }
	break;
     }

    //for row
    for(i=0;i<3;i++)
    {
     sum2=0;
     for(j=0;j<3;j++)
      {
        sum2=sum2+a[i][j];
      }
	if(sum1==sum2)
          count++;
        else
	goto label;

     }

  //for  column
   for(j=0;j<3;j++)
    {
     sum2=0;
     for(i=0;i<3;i++)
      {
       sum2=sum2+a[i][j];
	}
	if(sum1==sum2)
          count++;
  else
	goto label;

     }

 //for main diagonal elements
     sum2=0;
     for(i=0;i<3;i++)
      {
        for (j=0;j<3;j++)
          {
            if(i==j)
             sum2=sum2+a[i][j];
            }
         }
          if(sum1==sum2)
       count++;
         else
            goto label;
  //for secondary diagonal elements
        sum2=0;
     for(i=0;i<3;i++)
      {
        for (j=0;j<3;j++)
          {
            if(i+j==2)
             sum2=sum2+a[i][j];
            }
         }
          if(sum1==sum2)
            count++;
                    else
            goto label;

     if (count==8)
   cout<<"it is a magic matrix"<<endl;


  else
  {
   label:cout<<"it is not a magic matrix"<<endl;
  }


}




/*
   OUTPUT:

  student@student-OptiPlex-3010:~/Desktop/ch/final$ g++ dsa2.cpp
student@student-OptiPlex-3010:~/Desktop/ch/final$ ./a.out
enter the elements of matrix

1
2
3

4
5
6

7
8
9

1	2	3
4	5	6
7	8	9

it is not a magic matrix
student@student-OptiPlex-3010:~/Desktop/ch/final$ g++ dsa2.cpp
student@student-OptiPlex-3010:~/Desktop/ch/final$ ./a.out
enter the elements of matrix

1
1
1

1
1
1

1
1
1

1	1	1
1	1	1
1	1	1

it is a magic matrix




*/




