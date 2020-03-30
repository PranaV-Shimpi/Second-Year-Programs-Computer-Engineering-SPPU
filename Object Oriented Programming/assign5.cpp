/*
Assignment 5:

Create a class publication that stores the title and price of a publication.
From this class derive two classes: book, which adds a
page count, and tape, which adds a playing time in minutes.
Write a program that instantiates the book and tape classes,
allows user to enter data and displays the data members.
If an exception is caught, replace all the data member
values with zero values.

Done by: Pranav Shimpi
*/
#include <iostream>
#include <cstring>
using namespace std;

class publication
{
protected:
	char title[20];
	float price;
public:
	publication()
	{
		strcpy(title,"");
		price=0;
	}
	~publication();
	virtual void getdata()=0;
	virtual void display()=0;
};

class book:public virtual publication
{
	int pages;//pages of the book
public:
	book():publication()
	{
		pages=0;
	}
	~book();
	void getdata();
	void display();
};

class tape:public virtual publication
{
	float time;//time in minutes
public:
	tape():publication()
	{
		time=0;
	}
	~tape();
	void getdata();
	void display();
};

void book::getdata()
{
	cout<<"Enter the title ";
	cin.ignore(256,'\n');
	cin.getline(title,20);
	cout<<"Enter the price ";
	cin>>price;
	cout<<"Enter the No. of pages ";
	cin>>pages;
	try
	{
		if (pages>500)
		throw pages;
	}
	catch(int)
	{
		cout<<"Pages cannot be greater than 500\n\n";
		pages=0;
	}

}
void book::display()
{
	cout<<"\n\tTitle= "<<title<<"\n\tPrice= "<<price<<"\n\tPages= "<<pages<<"\n";

}
void tape::getdata()
{
	cout<<"Enter the title ";
	cin.ignore(256,'\n');
	cin.getline(title,20);
	cout<<"Enter the price ";
	cin>>price;
	cout<<"Enter the playing time ";
	cin>>time;
	try
	{
		if (time>90)
			throw time;
	}
	catch(float)
	{
		cout<<"Time cannot be greater than 90 minutes\n\n";
		time=0;
	}
}
void tape::display()
{
	cout<<"\n\tTitle= "<<title<<"\n\tPrice= "<<price<<"\n\tPlaying time= "<<time<<"\n";
}

int main()
{
	int n,ch,i=0;
	cout<<"Enter No. of publications ";
	cin>>n;
	publication *p[n];

	do
	{
		cout<<"Enter 1 to give book data, 2 for tape data : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				p[i]=new book();
				p[i]->getdata();
			break;
			case 2:
				p[i]=new tape();
				p[i]->getdata();
			break;
			default:
			cout<<"Invalid input- Enter again\n";
			i--;
		}
		i++;
	}while(i<n);

	for (i = 0; i < n; i++)
	{
		cout<<"Details for publication "<<i+1<<":\n";
		p[i]->display();
	}
	return 0;
}

/*
Output:

Enter No. of publications 2
Enter 1 to give book data, 2 for tape data : 1
Enter the title programming
Enter the price 675
Enter the No. of pages 700
Pages cannot be greater than 500

Enter 1 to give book data, 2 for tape data : 2
Enter the title music
Enter the price 90
Enter the playing time 72

Details for publication 1:
		Title= programming
		Price= 675
		Pages= 0

Details for publication 2:
		Title= music
		Price= 90
		Playing time= 72
*/
