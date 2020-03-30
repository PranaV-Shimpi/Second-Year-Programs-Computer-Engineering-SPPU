/*Assignment 1
Purpose:To find average, highest marks, frequency using class and functions
*/


#include<iostream>                                                      //heade file

using namespace std;
class student                                                            //class
{    public:
     int a[50],r[50],c,friq[50],n,i,o[50],sum,j,m,z,x;                  //declarations
     int max,min;
     float avg;
     char name[5][50],b;
     public:

        void get()                                                     // function to take data
        {   avg=0;
            sum=0;
         cout<<"ENTER NUMBER OF STUDENTS IN THIS CLASS\n";
         cin>>n;
         for(i=0;i<n;i++)                              //accepting the data
         {
               cout<<"\nENTER NAME OF STUDENT\n";
               cin>>name[i];
               cout<<"\nENTER ROLL NUMBER OF STUDENT\n";
               cin>>r[i];
               cout<<"\nPRESS P IF STUDENT IS PRESENT AD A IF ABSENT AT EXAM\n"; //attendence
               cin>>b;

               if(b=='p')
               { cout<<"\nENTER MARKS OF STUDENT\n";
                 cin>>a[i];
                  sum=sum+a[i];
               }
               else
                 {   a[i]=0;
                     cout<<"NOT APPLICABLE\n\n";
                     o[i]=a[i];

                 }

         }

       avg=sum/n;      //average
         }

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
      void calc()                   //function to calculate min and max
	{
            max=a[0];
            min=a[0];
           for(i=0;i<n;i++)
	     {
      	        if(a[i]>max)
      	   	{
      	           max=a[i];  //max

      	     	}
		if(a[i]!=0)
                {
        	  if(a[i]<min)
      	  	  {
      	 	         min=a[i];  //min

      	     	  }
                }
             }
        }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     void fri()                                //function to calculate friquency
       {  c=1;
           for(i=0;i<n;i++)
            {
               for(j=i+1;j<n+1;j++)
                 {
                       if(a[i]==a[j])
			{
                         a[j]=100;
                      c++;			//frequency
			}
                 }
                friq[i]=c;
		c=1;
            }


         cout<<"frequency is\n";

         for(i=0;i<n;i++)
           {
               if((a[i]!=100)&&(a[i]!=0))
               cout<<a[i]<<" "<<"occurs  "<<friq[i]<<endl;
           }

          }


////////////////////////////////////////////////////////////////////////////////////////////////////////
      void put()                                 // function to display
       {
             cout<<"Name\t"<<"ROLLNO.\t"<<"MARKS\n";      //list of all students
             for(i=0;i<n;i++)
         {
             if(a[i]==o[i])
             {
              cout<<"\n"<<name[i]<<"\t"<<r[i]<<"\t"<<"ABSENT";
             }
             else
              cout<<"\n"<<name[i]<<"\t"<<r[i]<<"\t"<<a[i];

         }
       }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void putd()                             // function to display min and max
            {   for(i=0;i<n;i++)
                 {

                if(a[i]==max)
                {
                 cout<<"\nMAXIMUM MARKS ARE  ";    //minimum marks
                 cout<<max;
                 cout<<"  BY STUDENT\t"<<name[i];
	        }
             }
            for(i=0;i<n;i++)
            {

               if(a[i]==min)
                {
                  cout<<"\nMINIMUM MARKS ARE  ";   //maximum marks
                  cout<<min;
                  cout<<"  BY STUDENT\t";
                  cout<<name[i];
				}
		}
          cout<<"\naverage is "<<avg<<"\n";  // display of average value

           }


};

/////////////////////////////////////////////////////////////////////////////////////////////////
int main()                                // main function
{
   student s;                            //instantization of object
   s.get();                               // function call
   s.calc();                              // function call
   s.put();                               // function call
   s.putd();
   s.fri();
   return(0);                      //return
}



/*

OUTPUT:


chetanghate@chetanghate-Inspiron-660s:~/Desktop/dsa$ g++ dsa1.cpp
chetanghate@chetanghate-Inspiron-660s:~/Desktop/dsa$ ./a.out
ENTER NUMBER OF STUDENTS IN THIS CLASS
5

ENTER NAME OF STUDENT
sam

ENTER ROLL NUMBER OF STUDENT
1

PRESS P IF STUDENT IS PRESENT AD A IF ABSENT AT EXAM
p

ENTER MARKS OF STUDENT
70

ENTER NAME OF STUDENT
dom

ENTER ROLL NUMBER OF STUDENT
2

PRESS P IF STUDENT IS PRESENT AD A IF ABSENT AT EXAM
p

ENTER MARKS OF STUDENT
80

ENTER NAME OF STUDENT
fog

ENTER ROLL NUMBER OF STUDENT
3

PRESS P IF STUDENT IS PRESENT AD A IF ABSENT AT EXAM
p

ENTER MARKS OF STUDENT
70

ENTER NAME OF STUDENT
gof

ENTER ROLL NUMBER OF STUDENT
4

PRESS P IF STUDENT IS PRESENT AD A IF ABSENT AT EXAM
a
NOT APPLICABLE


ENTER NAME OF STUDENT
tom

ENTER ROLL NUMBER OF STUDENT
5

PRESS P IF STUDENT IS PRESENT AD A IF ABSENT AT EXAM
p

ENTER MARKS OF STUDENT
80
Name	ROLLNO.	MARKS

sam	1	70
dom	2	80
fog	3	70
gof	4	ABSENT
tom	5	80
MAXIMUM MARKS ARE  80  BY STUDENT	dom
MAXIMUM MARKS ARE  80  BY STUDENT	tom
MINIMUM MARKS ARE  70  BY STUDENT	sam
MINIMUM MARKS ARE  70  BY STUDENT	fog
average is 60
frequency is
70 occurs  2
80 occurs  2

*/



