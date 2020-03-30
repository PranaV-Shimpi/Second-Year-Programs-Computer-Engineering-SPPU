/*
Assignment 1:

Write a program to create a student database containing the
following information: Name, Roll number, Class,
division, Date of Birth, Blood group, Contact address,
telephone number, driving license no. etc.

Done By: Pranav Shimpi

*/
#include<iostream>
#include<cstring>
using namespace std;
class student
{
	int roll;
	char name[20];
	char cls[5];
	char div;
	char addr[20];
	unsigned long int mob;
	int license;

	public:
		static int count;
		void getdata();
		friend void display(student&);
		student()//constructor
		{
			roll=0;
			strcpy(name,"NULL");
			strcpy(addr,"NULL");
			mob=0;
			license=0;
			count++;
		}

		~student()	{}//destructor

		student(student &s)//copy constructor
		{
			this->roll=s.roll;
			strcpy(name,s.name);
			strcpy(cls,s.cls);
			div=s.div;
			strcpy(addr,s.addr);
			mob=s.mob;
			license=s.license;
		}
};

int student::count=0;

void student::getdata()
{
	cout<<"Enter the name\n";
	cin>>name;
	cout<<"Enter the class\n";
	cin>>cls;
	cout<<"Enter the division\n";
	cin>>div;
	cout<<"Enter the roll no.\n";
	cin>>roll;
	cout<<"Enter the address\n";
	cin>>addr;
	cout<<"Enter the mobile no.\n";
	cin>>mob;
	cout<<"Enter the license no.\n";
	cin>>license;
}

void display(student &s)
{
	cout<<"Name: "<<s.name<<"\n";
	cout<<"Class:  "<<s.cls<<"\n";
	cout<<"Div:      "<<s.div<<"\n";
	cout<<"Roll No: "<<s.roll<<"\n";
	cout<<"Address: "<<s.addr<<"\n";
	cout<<"Mobile: "<<s.mob<<"\n";
	cout<<"License No: "<<s.license<<"\n";
}


int main()
{
	int n,i;

	student s1;
	s1.getdata();
	student s2(s1);
	display(s1);
	cout<<"Copied Object Details:\n";
	display(s2);

	cout<<"Enter no. of students: ";
	cin>>n;
	student *s[n];
	for(i=0;i<n;i++)
		s[i]=new student;//diff betn student() and student
	for(i=0;i<n;i++)
		s[i]->getdata();
	for(i=0;i<n;i++)
		display(*s[i]);
	for(i=0;i<n;i++)
		delete s[i];
	cout<<"\nCount= "<<student::count<<"\n";
	return 0;
}

/*
Output:

nikhilkhairnar@res-HP-280-G2-MT-Legacy:~$ g++ assign1.cpp
nikhilkhairnar@res-HP-280-G2-MT-Legacy:~$ ./a.out
Enter the name
nikhil
Enter the class
se
Enter the division
a
Enter the roll no.
31
Enter the address
nasik
Enter the mobile no.
3456789
Enter the license no.
456
Name: nikhil
Class: se
Div:   a
Roll No: 31
Address: nasik
Mobile: 3456789
License No: 456
Copied Object Details:
Name: nikhil
Class: se
Div:   a
Roll No: 31
Address: nasik
Mobile: 3456789
License No: 456
Enter no. of students: 1
Enter the name
rahul
Enter the class
se
Enter the division
b
Enter the roll no.
45
Enter the address
nasik
Enter the mobile no.
436986545
Enter the license no.
547
Name: rahul
Class: se
Div:   b
Roll No: 45
Address: nasik
Mobile: 436986545
License No: 547

Count= 2
*/

