/*Problem Statement:Department maintains student information .The file contains rollno,name,division and address.
Allow user to add delete information of student.
If record of student does not exist then an appropriate message is displayed.
If it is then system display student details.Use sequential file to maintain data.

*/

//header files

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

class student
{
	char name[20];
	public:
		int roll;
		void getdata()
		{
            		cout<<"\nEnter roll and name : ";
            		cin>>roll>>name;
         	}
         	void putdata()
         	{
             		cout<<"\n"<<roll<<"  "<<name;
         	}

};

class file
{
      fstream fp;
      char ans;
      public:
      	void create()
        {
             fp.open("stu.dat",ios::out);
             student s;
             do
             {
                  s.getdata();
                  fp.write((char*)&s, sizeof(s));
                  cout<<"\n More?";
                  cin>>ans;
             }while(ans=='y');
             fp.close();
        }

        void append()
        {
             fp.open("stu.dat",ios::app);
             student s;
             do
             {
                  s.getdata();
                  fp.write((char*)&s, sizeof(s));
                  cout<<"\nMore?";
                  cin>>ans;
             } while(ans=='y');
             fp.close();
        }

        void display()
        {
             fp.open("stu.dat",ios::in);
             student s;
             while (!fp.eof())
             {

                  fp.read((char*)&s,sizeof(s));
                  if (!fp.eof())s.putdata();
             }
             fp.close();
        }

        void search()
        {
             fp.open("stu.dat",ios::in);
             student s;
             int r,flag=0;
             cout<<"\nEnter roll to be searched : ";
             cin>>r;
             while(fp.read((char*)&s,sizeof(s)))
             {


                  if (s.roll==r)
                  {
                 	 flag=1;
                 	 s.putdata();
                 	 break;
                  }
             }
             if(flag==0)
             	cout<<"\nNot found";
             fp.close();
        }

        void update()
        {
             fp.open("stu.dat",ios::in|ios::out);
             student s;
             int r,flag=0;
             cout<<"\nEnter roll to be updated : ";
             cin>>r;
             while(fp.read((char*)&s,sizeof(s)))
             {


                  if (s.roll==r)
                  {
                  	flag=1;
                  	s.putdata();
                   	cout<<"\nEnter data to update : ";
                  	s.getdata();
                 	fp.seekp(-1*sizeof(s),ios::cur);
                 	fp.write((char*)&s,sizeof(s));
                	break;
                  }
             }
             if(flag==0)
             	cout <<"\nNot found";
             fp.close();
        }
};


int main()
{
	file f;
	int choice;
	do
	{	cout<<"\n------------------------";
   		cout<<"\n\tLIST";
   		cout<<"\n------------------------";
   		cout<<"\n1.Create\n2.Display\n3.Append\n4.Search\n5.Update\n6.Exit";
   		cout<<"\n------------------------";
    		cout<<"\nEnter choice : ";
    		cin>>choice;

    		switch(choice)
    		{
    			case 1: //create
    				f.create();
    				break;

    			case 2://display
    				 f.display();
    				break;

    			case 3://append
    				f.append();
    				break;

    			case 4: //search
    				f.search();
    				break;

    			case 5://update record
    				 f.update();
    				break;

    			case 6: exit(0);


  	 	}
   	}while(choice!=6);
	return 0;
}

/*
OUTPUT :

=======================
    FILE HANDLING
=======================
------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 1

Enter roll and name : 4
rrr

 More?y

Enter roll and name : 7
iii

 More?y

Enter roll and name : 2
aaa

 More?n

------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 2

4  rrr
7  iii
2  aaa
------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 3

Enter roll and name : 8
jjj

More?n

------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 2

4  rrr
7  iii
2  aaa
8  jjj
------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 4

Enter roll to be searched : 7

7  iii
------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 5

Enter roll to be updated : 7

7  iii
Enter data to update :
Enter roll and name : 7
sss

------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 2

4  rrr
7  sss
2  aaa
8  jjj
------------------------
	MENU
------------------------
1.Create
2.Display
3.Append
4.Search
5.Update
6.Exit
------------------------
Enter choice : 6

*/
