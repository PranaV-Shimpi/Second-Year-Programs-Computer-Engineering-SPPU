/*
 Assignment 9 : Stack 
      Done by : Pranav Shimpi    
                SEA-53
*/

#include <iostream>
#include "stack.h"
using namespace std;

#define max 3

int main()
{
	stack <int> s; int choice; int n;
	do{
		cout << "\n\n\t\t*MENU*\n\t #1. Push \n\t #2. Pop\n\t #3. Gettop \n\t #4. Display \n\t #5. Exit ";
		cout  << "\n\n\t Enter choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1 :
				cout<<"Enter elements to push ";
				cin>>n;
				if (!s.isfull())
					s.push(n);
			break;
			case 2 :
				if (!s.isempty())
					cout << "\n Popped element " << s.pop();
				else
					cout << "Stack underflow\n";
			break;
            case 3 :
				if (!s.isempty())
					cout << "\n Popped element " << s.gettop();
				else
					cout << "Stack underflow\n";
			break;
			case 4 :
				if (!s.isempty())
					s.display();
				else
					cout << "Stack underflow\n";
		}
	}while (choice < 5);
	
	
	return 0;
}
