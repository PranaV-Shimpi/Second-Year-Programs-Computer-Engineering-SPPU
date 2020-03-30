/*
Assignment 7:

Create User defined exception to check the following conditions
and throw the exception if the criterion does not meet.

1.User has age between 18 and 55
2.User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
3.User stays in Pune/ Mumbai/ Bangalore / Chennai
4.User has 4-wheeler

Accept age, Income, City, Vehicle from the user and
check for the conditions mentioned above.
If any of the condition not met then throw the exception.

Done by: Pranav Shimpi
*/
#include <iostream>
#include <cstring>
using namespace std;

class user
{
	int age;
	long salary;
	char city[10];
	char vehicle;
public:
	user()
	{
		age=0;
		salary=0;
		strcpy(city,"");
		vehicle=' ';
	}
	~user(){}
	void getdata();
	void display();
};

void user::getdata()
{
	while(true)
	{
		try
		{
			cout<<"Enter the age(18-55) ";
			cin>>age;
			if (age<18 || age>55)
				throw age;
			else
				break;
		}
		catch(int)
		{cout<<"Invalid input. Enter again\n\n";}
	}
	while(true)
	{
		try
		{
			cout<<"Enter your salary(between 50k and 1 lakh) ";
			cin>>salary;
			if (salary<50000||salary>100000)
				throw salary;
			else
				break;
		}
		catch(long)
		{cout<<"Invalid input. Enter again\n\n";}
	}
	while(true)
	{
		try
		{
			cout<<"Enter the city where you live(pune,mumbai,chennai,bangalore) ";
			cin>>city;
			if (strcmp(city,"pune")!=0&&strcmp(city,"mumbai")!=0&&strcmp(city,"bangalore")!=0&&strcmp(city,"chennai")!=0)
				throw city;
			else
				break;
		}
		catch(char*)
		{cout<<"Invalid input. Enter again\n\n";}
	}

	while(true)
	{
		try
		{
			cout<<"Do you have a 4-wheeler?(y/n) ";
			cin>>vehicle;
			if (vehicle!='y'&&vehicle!='n')
				throw vehicle;
			else
				break;
		}
		catch(char)
		{cout<<"Invalid input. Enter again\n\n";}
	}
}

void user::display()
{
	cout<<"\tAge= "<<age<<"\n\tSalary= "<<salary<<"\n\tCity= "<<city<<"\n\tHave a 4-wheeler? "<<vehicle<<"\n";
}

int main()
{
	char ch;
	user u;
	cout<<"Enter Data for user\n";
	u.getdata();
	cout<<"Details of user are:\n";
	u.display();
	return 0;
}

/*
Output:

Enter Data for user
Enter the age(18-55) 76
Invalid input. Enter again

Enter the age(18-55) 45
Enter your salary(between 50k and 1 lakh) 54678468
Invalid input. Enter again

Enter your salary(between 50k and 1 lakh) 56789
Enter the city where you live(pune,mumbai,chennai,bangalore) ert
Invalid input. Enter again

Enter the city where you live(pune,mumbai,chennai,bangalore) mumbai
Do you have a 4-wheeler?(y/n) t
Invalid input. Enter again

Do you have a 4-wheeler?(y/n) n
Details of user are:
	Age= 45
	Salary= 56789
	City= mumbai
	Have a 4-wheeler? n


*/
