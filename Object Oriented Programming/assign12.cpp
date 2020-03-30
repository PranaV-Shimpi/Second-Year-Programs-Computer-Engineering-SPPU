/*
Assignment 12:

Write a program to create dequeue using STL.

Done by: Pranav Shimpi
*/

#include <iostream>
#include <stdlib.h>
#include <deque>
using namespace std;
int main()
{
	deque <int> dq;
	deque <int>::iterator it;
	int choice,item;
	do
	{
		cout<<"\n1.Insert element at the end\n2.Insert element at front\n3.Delete element at end\n4.Delete element at front\n5.Get front element\n6.Get back element\n7.Size of queue\n8.Display elements in queue\n9.Exit";
		cout<<"\nEnter the choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter value to be inserted at back";
				cin>>item;
				dq.push_back(item);
				break;
			case 2:
				cout<<"\nEnter value to be inserted at front";
				cin>>item;
				dq.push_front(item);
				break;
			case 3:
				item=dq.back();
				dq.pop_back();
				cout<<"\ndeleted item:"<<item;
				break;
			case 4:
				item=dq.front();
				dq.pop_front();
				cout<<"\ndeleted item:"<<item;
				break;
			case 5:
				cout<<"\nFront element is";
				cout<<dq.front();
				break;
			case 6:
				cout<<"\nBack element is";
				cout<<dq.back();
				break;
			case 7:
				cout<<"\nsize of deque";
				cout<<dq.size();
				break;
			case 8:
				cout<<"\nElements in queue are:";
				for(it=dq.begin();it!=dq.end();it++)
					cout<<"\n"<<*it;
				break;
			case 9:
				exit(0);
				break;
			default:
				cout<<"Invalid input\n\n";
		}
	}while(choice<9);
	return 0;
}

/*
Output:

1.Insert element at the end
2.Insert element at front
3.Delete element at end
4.Delete element at front
5.Get front element
6.Get back element
7.Size of queue
8.Display elements in queue
9.Exit
Enter the choice 1

Enter value to be inserted at back10

1.Insert element at the end
2.Insert element at front
3.Delete element at end
4.Delete element at front
5.Get front element
6.Get back element
7.Size of queue
8.Display elements in queue
9.Exit
Enter the choice 2

Enter value to be inserted at front20

1.Insert element at the end
2.Insert element at front
3.Delete element at end
4.Delete element at front
5.Get front element
6.Get back element
7.Size of queue
8.Display elements in queue
9.Exit
Enter the choice 8

Elements in queue are:
20
10
1.Insert element at the end
2.Insert element at front
3.Delete element at end
4.Delete element at front
5.Get front element
6.Get back element
7.Size of queue
8.Display elements in queue
9.Exit
Enter the choice 9
*/

