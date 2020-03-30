/*
Assignment 13:

Write a program to search and sort user defined records using STL.

Done by: Pranav Shimpi
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Item
{
  public: char name[10];
		  int quantity;
		  int cost;
		  int code;

        bool operator==(const Item &i1)
		{
			 if(code==i1.code)
				 return 1;
			 return 0;
		}
		bool operator<(Item &i1)
		{
			 if(code<i1.code)
				 return 1;
			 return 0;
		}

};
vector<Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
void dlt();

void insert()
{
	Item i1;
	cout<<"\nEnter Item Name:";
	cin>>i1.name;
	cout<<"\nEnter Item Quantity:";
	cin>>i1.quantity;
	cout<<"\nEnter Item Cost:";
	cin>>i1.cost;
	cout<<"\nEnter Item Code:";
	cin>>i1.code;
	o1.push_back(i1);
}
void display()
{
	for_each(o1.begin(),o1.end(),print);
}
void print(Item &i1)
{
	cout<<"\n\nItem Name:"<<i1.name;
	cout<<"\nItem Quantity:"<<i1.quantity;
	cout<<"\nItem Cost:"<<i1.cost;
	cout<<"\nItem Code:"<<i1.code;
}
void search()
{
	vector<Item>::iterator p;
	Item i1;
	cout<<"\nEnter Item Code to search:";
	cin>>i1.code;
	p=find(o1.begin(),o1.end(),i1);
	if(p==o1.end())
		cout<<"\nNot found.";
	else
		cout<<"\nFound.";
}
void dlt()
{
  vector<Item>::iterator p;
	Item i1;
	cout<<"\nEnter Item Code to delete:";
	cin>>i1.code;
	p=find(o1.begin(),o1.end(),i1);
	 if(p==o1.end())
		 cout<<"\nNot found.";
	 else
	 {
		 o1.erase(p);
		 cout<<"\nDeleted.";
	 }
}

int main()
{
	int ch;
	do
	{
		cout<<"\n****** Menu ******";
		cout<<"\n1.Insert";
		cout<<"\n2.Display";
		cout<<"\n3.Search";
		cout<<"\n4.Sort";
		cout<<"\n5.Delete";
		cout<<"\n6.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:  insert();
			break;
		case 2:  display();
			break;
		case 3:  search();
			break;
		case 4:  sort(o1.begin(),o1.end());
			break;
		case 5:  dlt();
			break;
		case 6:  exit(0);
		}
	}while(ch!=7);

	return 0;
}

/*
Output:

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:1

Enter Item Name:Hammer

Enter Item Quantity:10

Enter Item Cost:50

Enter Item Code:01

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:2

Item Name:hammer
Item Quantity:10
Item Cost:50
Item Code:1
***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:3

Enter Item Code to search:1

Found.
***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:2


Item Name:Hammer
Item Quantity:10
Item Cost:50
Item Code:1
***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:4

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:5

Enter Item Code to delete:1

Deleted.
***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit
Enter your choice:6
*/
