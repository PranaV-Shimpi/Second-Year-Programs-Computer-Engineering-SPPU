/*
 DSA Asssignment No. 4

purpose: perform different mathematical operations on matrix
*/

#include<iostream>        //header file
using namespace std;

class s                     //class
{
   int i,k,j,sum,r,c;  //declerations
   int a[20][20];

  public:                    //acess specifier
  void get()           //function to get data
    {
	 cout<<"\nENTER NUMBER OF R AND C"<<endl;
	 cin>>r>>c;
	 cout<<"\nENTER ELEMETS"<<endl;
	    for(i=0;i<r;i++)
	     {

		 for(j=0;j<c;j++)
		 {
		   cin>>a[i][j];

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
		   cout<<a[i][j];
		    cout<<" ";
		 }
	       cout<<"\n";
	 }
              cout<<endl;
    }

    void ut()                 //upper triangle
    {
       int x=0;
       for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   if(j>i)
                     {
                        if(a[i][j]==0)
                        {
				 x++;
                        }
                     }

		 }
	 }
      if((x==3)||(x==6))
      {
         cout<<"matrix is upper triangular\n ";

      }
      else
      {
       cout<<"matrix is not upper triangular\n ";

      }
    }

      void tr()                                        //transpose
       {   cout<<"transpose of matrix is \n";
            for(i=0;i<r;i++)
	    {

		 for(j=0;j<c;j++)
		 {
		   cout<<a[j][i];
		    cout<<" ";
		 }
	       cout<<"\n";
	     }
              cout<<endl;


        }

    void sd()
     {  sum=0;

	for(i=0;i<r;i++)
	{

		 for(j=0;j<c;j++)
		 {
		      if(i==j)
                        {
                           sum=sum+a[i][j];
                        }

		 }
	 }

            cout<<"sum of digonal elements  :"<<sum<<"\n\n";
       }

};
  class op
  {
    int i,k,j,sum,r,c;        //declerations
     int a[20][20],b[20][20];
   int d[10][10];

    public:
   void mul()
   {
	cout<<"\n matrix a*b: \n";
	for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   d[i][j]=0;
                   for(k=0;k<c;k++)
                   {
                     d[i][j]=d[i][j]+a[i][k]*b[k][j];
                   }
		 }
	 }

        for(i=0;i<r;i++)
          {
               for(j=0;j<c;j++)
		 {
		   cout<<d[i][j];
		    cout<<" ";
		 }
	       cout<<"\n";
	   }
              cout<<endl;
    }

    void getdata()                    //accept the data of 2 matrix
    {
       cout<<"\nENTER NUMBER OF R AND C"<<endl;
	 cin>>r>>c;
	  cout<<"\nENTER ELEMETS OF FIRST MATRIX"<<endl;
	for(i=0;i<r;i++)
	 {
		 for(j=0;j<c;j++)
		 {
		   cin>>a[i][j];
		 }
         }
       cout<<"\nENTER ELEMETS OF SECOND MATRIX"<<endl;
        for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   cin>>b[i][j];
		 }
	}
          cout<<endl;
    }

   void add()                                    //addition
    {
       cout<<"\n matrix a+b: \n";
      int d[10][10];
	for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   d[i][j]=0;
                   for(k=0;k<c;k++)
                    {
                       d[i][j]=a[i][j]+b[i][j];
                    }
		  }
	 }

        for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   cout<<d[i][j];
		    cout<<"  ";
		  }
	       cout<<"\n";
	 }
              cout<<endl;
      }

  void sub()                                 //subtraction
  {
     cout<<"\n matrix a-b: \n";
      int d[10][10];
	for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   d[i][j]=0;

                   for(k=0;k<c;k++)
                   {
                     d[i][j]=a[i][j]-b[i][j];
                    }
		 }
	}

       for(i=0;i<r;i++)
	{
		 for(j=0;j<c;j++)
		 {
		   cout<<d[i][j];
		    cout<<"  ";
		 }
	       cout<<"\n";
	 }
              cout<<endl;
    }

};

int main()      // main function
{  char ch;
   s o;         //instantization of object
   op p;
   o.get();     //function call
   o.put();
   o.ut();
   o.tr();
   o.sd();
   cout<<"enter\n + for addition \n - for subsraction \n * for multiply";
   cin>>ch;
   p.getdata();

 switch(ch)               //perform different operations
 {
   case '+':  p.add();
              break;

   case '-':  p.sub();
              break;

   case '*':  p.mul();
              break;

 }
return(0);
}

/*
student@student-OptiPlex-3010:~/Desktop/final$ g++ dsa4.cpp
student@student-OptiPlex-3010:~/Desktop/final$ ./a.out

ENTER NUMBER OF R AND C
3
3

ENTER ELEMETS
1
0
0
1
2
0
1
2
3

1 0 0
1 2 0
1 2 3

matrix is upper triangular
 transpose of matrix is
1 1 1
0 2 2
0 0 3

sum of digonal elements  :6

enter
 + for addition
 - for subsraction
 * for multiply*

ENTER NUMBER OF R AND C
3
3

ENTER ELEMETS OF FIRST MATRIX
4
2
3
1
5
6
4
2
1

ENTER ELEMETS OF SECOND MATRIX
2
4
1
3
2
5
4
1
2


 matrix a*b:
26 23 20
41 20 38
18 21 16


*/
