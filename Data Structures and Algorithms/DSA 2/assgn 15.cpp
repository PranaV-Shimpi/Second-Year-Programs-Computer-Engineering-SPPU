/*
Assignment No: 15

write c++ program to maintain club members of student club.
sort on roll nos in ascending order. write a function ternary
search to search whether particular student is club member or not.
Ternary search is modified binary search that divides array into
three halves insted of two halves.
*/

#include <iostream>
using namespace std;
class student
{
	int rollno;
	string name;
	friend class club;
};
class club
{
	student s[50];
	int n;
public:
	club()
{
		n=0;
}
	void addmembers();
	void printmembers();
	void sort();
	void ternarysearch();
};
void club::addmembers()
{
	cout<<"\n how many members do you want to add";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nenter  rollno of member";
		cin>>s[i].rollno;
		cout<<"\n enter name of member";
		cin>>s[i].name;
	}
}
void club::printmembers()
{
	cout<<"\n the club members are:\nrollno\tname";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<s[i].rollno<<"\t"<<s[i].name;
	}



}
void club::sort()
{
	int i,pass;
	student temp;
	for(pass=1;pass<n;pass++)
	{
		for(i=0;i<n-pass;i++)
		{
			if(s[i].rollno>s[i+1].rollno)
			{
				temp=s[i];
				s[i]=s[i+1];
				s[i+1]=temp;
			}
		}

	}
}
int main()
{
	club o;
	o.addmembers();
	o.printmembers();
	o.sort();
	o.printmembers();

	return 0;
}
/*
====================================OUTPUT=======================================================

 how many members do you want to add4

enter  rollno of member1

 enter name of membermandar

enter  rollno of member4

 enter name of memberrohan

enter  rollno of member3

 enter name of memberkiran

enter  rollno of member2

 enter name of memberajinkya

 the club members are:
rollno	name
1	mandar
4	rohan
3	kiran
2	ajinkya
 the club members are:
rollno	name
1	mandar
2	ajinkya
3	kiran
4	rohan
*/

