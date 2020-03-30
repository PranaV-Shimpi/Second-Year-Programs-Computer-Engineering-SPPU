/*DSA Asssignment No. 6

 Purpose : Linked LiSt Operations
*/
#include<iostream>             //Header Files
#include<string.h>
using namespace std;

class SLL;             //forward declaration of class
class dnode            //class to create node
{
	int div;
	int prn;
	char name[20];
	dnode *next;
	friend SLL;
public:
	dnode()         //constructor
	{
		next = NULL;
		div = prn = 0;
	}

	dnode(int d, int p, char Name[])   // parameterised constructor
	{
		div = d;
		prn = p;
		next = NULL;
		strcpy(name,Name);
	}

};

class SLL
{
public:
	dnode *head;
	dnode *insert;
	dnode *end;

	void create();                      //function declarations
	void print();
	void insertMember();
	void deleteMember();
	void count();
	void mergeList();
	void recursionPrint(dnode *temp);

	SLL()
	{
		head = NULL;
		insert = NULL;
		end = NULL;
	}
}list1;

void SLL::create()                //function to create node
{
	int n, d, p;
	char Name[20];
	cout<<"Enter the number of students: ";
	cin >> n;
	cout<<"\nEnter the name, division and PRN of President: \n";
	cin >> Name >> d >> p;
	end = head = new dnode(d, p, Name);

	cout<<"\nEnter the name, division and PRN of members: \n";
	for(int i=1 ; i<n-1 ; i++)
	{
			cin >> Name >> d >> p;
			end -> next = new dnode(d, p, Name);
			end = end -> next;
	}
	insert = end;
	cout<<"\nEnter the name, division and PRN of SECRETARY: \n";
	cin >> Name >> d >> p;
	end -> next = new dnode(d, p, Name);
	end = end -> next;
	end -> next = NULL;
}

void SLL::insertMember()          //function to insert a member
{
	int d, p;
	char Name[20];
	cout<<"\nEnter the name, division and PRN of member to INSERT: \n";
	cin >> Name >> d >> p;
	insert -> next = new dnode(d, p, Name);
	insert = insert -> next;
	insert ->next = end;
}

void SLL::deleteMember()    //function to delete member
{
	int searchPRN;
	dnode *remove;
	cout<<"Enter the PRN of member to delete: ";
	cin >> searchPRN;
	if(searchPRN==head->prn)
    {
        remove = head;
        head = head->next;
        delete remove;
    }

    else
    {
    	for(dnode *temp = head; temp != insert ; temp = temp ->next)
        {
        	if(temp -> next ->prn == searchPRN)
            {
        		if(temp->next == insert)
        			insert = temp;
        		remove = temp->next;
                temp ->next = temp -> next -> next;
                delete remove;

                if(temp== insert)
                	break;
            }
        }
    }
	if(searchPRN==end->prn)
	{
		remove = end;
		insert->next=NULL;
		end = insert;
		delete remove;
	}
}
void SLL::count()      //function to count number of members
{
	int count = 0;
	for(dnode *temp=head ; temp!=NULL ; temp = temp->next)
		count ++;

	cout<<"\nTotal no. of students: " << count;

}
void SLL::print()      //function to display list
{
	cout<<"\n\nNAME\tDIV\tPRN\n";
	for(dnode *temp = head ; temp != NULL ; temp = temp ->next)
		cout << temp-> name <<"\t"<<temp->div << "\t" << temp->prn << "\n";

	cout<<"\nPresident is: " << head -> name;
	cout<<"\nSecretary is: " << end -> name << "\n";
}

void SLL::mergeList()     //function to murge two lists
{
	SLL list2;
	cout<<"\nEnter the contents for second list: \n";
	list2.create();
	list1.end->next = list2.head;
	list1.end = list2.end;
}

void SLL::recursionPrint(dnode *temp)  //function to reverse
{
	if(temp == NULL)
		return;
	else
		recursionPrint(temp->next);
	cout << temp-> name <<"\t"<<temp->div << "\t" << temp->prn << "\n";
}
int main()
{
	int choice;
	do
	{
		cout<<"\n1. Create List \n2. Insert Member \n3. Delete Member \n4. Print List \n5. Merge List \n6. Reverse List \n7. Count  \n8. Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
		switch(choice)          //switch case
		{
		case 1:
			list1.create();
			break;
		case 2:
			list1.insertMember();
			break;
		case 3:
			list1.deleteMember();
			break;
		case 4:
			list1.print();
			break;
		case 5:
			list1.mergeList();
			break;
		case 6:
			cout<<"\n\nNAME\tDIV\tPRN\n";
			list1.recursionPrint(list1.head);
			break;
		case 7:
			list1.count();
			break;
		case 8:
			return 0;
		default:
			cout<<"Invalid choice!";
		}
	}while(choice!=8);

	return 0;

}

/*
   OUTPUT:


chetanghate@chetanghate-Inspiron-660s:~$ cd Desktop
chetanghate@chetanghate-Inspiron-660s:~/Desktop$ cd final
chetanghate@chetanghate-Inspiron-660s:~/Desktop/final$ g++ dsa6.cpp
chetanghate@chetanghate-Inspiron-660s:~/Desktop/final$ ./a.out

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 1
Enter the number of students: 2

Enter the name, division and PRN of President:
chetan
1
12

Enter the name, division and PRN of members:

Enter the name, division and PRN of SECRETARY:
rahul 2
23

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 4


NAME	DIV	PRN
chetan	1	12
rahul	2	23

President is: chetan
Secretary is: rahul

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 2

Enter the name, division and PRN of member to INSERT:
malav
2
33

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 4


NAME	DIV	PRN
chetan	1	12
malav	2	33
rahul	2	23

President is: chetan
Secretary is: rahul

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 3
Enter the PRN of member to delete: 23

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 4


NAME	DIV	PRN
chetan	1	12
malav	2	33

President is: chetan
Secretary is: malav

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 5

Enter the contents for second list:
Enter the number of students: 2

Enter the name, division and PRN of President:
cg
1
2

Enter the name, division and PRN of members:

Enter the name, division and PRN of SECRETARY:
gh
2
4

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 5

Enter the contents for second list:
Enter the number of students: 1

Enter the name, division and PRN of President:
aj
5
6

Enter the name, division and PRN of members:

Enter the name, division and PRN of SECRETARY:
kl
2
5

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 4


NAME	DIV	PRN
chetan	1	12
malav	2	33
cg	1	2
gh	2	4
aj	5	6
kl	2	5

President is: chetan
Secretary is: kl

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 7

Total no. of students: 6
1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 6


NAME	DIV	PRN
kl	2	5
aj	5	6
gh	2	4
cg	1	2
malav	2	33
chetan	1	12

1. Create List
2. Insert Member
3. Delete Member
4. Print List
5. Merge List
6. Reverse List
7. Count
8. Exit

Enter your choice: 8







*/
