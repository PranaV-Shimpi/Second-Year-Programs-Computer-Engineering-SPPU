/*
 DSA Asssignment No. 3

Purpose:To find Saddle point in a matrix
*/

#include<iostream>        //header file
using namespace std;

class s                     //class
{
   int i,j,r,c,x,z,v,k,m;  //declerations
   int a[20][20];
   int sm,b;

  public:                    //acess specifier
  void get()           //function to get data
    {
	 cout<<"\nENTER NUMBER OF R AND C"<<endl;   //input no. of rows & columns
	 cin>>r>>c;
	  cout<<"\nENTER ELEMETS"<<endl;



	for(i=0;i<r;i++)
	{

		 for(j=0;j<c;j++)
		 {
		   cin>>a[i][j];         //input elements

		 }
	 }

          cout<<endl;
     }



    void put()    //function to display data
    {

	for(i=0;i<r;i++)
	{

		 for(j=0;j<c;j++)
		 {
		   cout<<a[i][j];    //output the elements
		    cout<<" ";
		 }
	       cout<<"\n";
	 }
              cout<<endl;
    }

  void sp()        //function to calclate saddle point
  {
      x=0;
      m=0;
	for(i=0;i<r;i++)
	{
		sm=a[i][0];
		 for(j=0;j<c;j++)
		 { if(sm>a[i][j])     //finding the smallest in the current row
		      {
			sm=a[i][j];
			   x=j;
		      }


		 }

		   b=a[0][x];
		 for(k=0;k<c;k++)
		 {
		    if(b<a[k][x])
		      {
			   b=a[k][x];   //finding the maximum in the column of that smallest element
			   v=k;
		      }
		 }

	      if(sm==b)
	        {
	          cout<<"saddle point is = "<<b<<" at ( "<<i+1<<","<<x+1<<")"<<endl<<endl;   //compare them
	           m++;
                }

	 }

	     if(m<1)
	      {
	         cout<<"saddle point not exist"<<endl;
	      }

 }

};

int main()      // main function
{
   s o;         //instantization of object
   o.get();     //function call
   o.put();
   o.sp();
return(0);
}

/*

OUTPUT:

student@student-OptiPlex-3010:~/student$ g++ SADD.CPP
student@student-OptiPlex-3010:~/student$ ./a.out

ENTER NUMBER OF R AND C
3
3

ENTER ELEMETS
1
2
3
4
5
6
7
8
9

1 2 3
4 5 6
7 8 9

saddle point is = 7 at ( 3,1)

student@student-OptiPlex-3010:~/student$ g++ SADD.CPP
student@student-OptiPlex-3010:~/student$ ./a.out

ENTER NUMBER OF R AND C
3
3

ENTER ELEMETS
3
2
4
6
2
5
1
1
1

3 2 4
6 2 5
1 1 1

saddle point is = 2 at ( 1,2)

saddle point is = 2 at ( 2,2)

*/


