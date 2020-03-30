/*
Assignment 6

Write C++ program to maintain club member's information using singly linked list.
First node is reserved for president of club and last node is reserved for secretary of club.
Store student PRN and Name.
Write functions to:
	a)Add and delete the members as well as president or even secretary.
	b)Compute total number of members of club
	c)Display members
	d)Display list in reverse order using recursion
	e)Two linked lists exists for two divisions. Concatenate two lists

Done by: Pranav Shimpi
 */
#include <iostream>
#include <cstring>
using namespace std;

class node
{
public:
	int prn;
	char name[20];
	node *next;
	node()
	{
		next=NULL;
	}
	~node(){}
};
class pinnacle
{
	node *head,*tail;
public:
	pinnacle()
	{
		head=tail=NULL;
	}
	~pinnacle(){}
	void create();
	void display();
	void insertafter(char a[]);
	void reverse();
	void concat(pinnacle&);
	int count();
	void makesecretary(char a[]);
	void makepresident(char a[]);
	node* searchprev(char a[]);
	void delete_mem(char a[]);
	void dispRev(node*);
	void recursivedisp();

};

void pinnacle::create()//add delete members and secretary, president
{
	char ans;
	node *curr,*prev;
	do
	{
		curr=new node;
		cout<<"Enter PRN and name\n";
		cin>>curr->prn;
		cin>>curr->name;
		if (head==NULL)
		{
			head=curr;
			prev=curr;
		}
		else
		{
			prev->next=curr;//create link to prev element
			prev=curr;
		}
		cout<<"Add more elements ?(y/n) ";
		cin>>ans;
	} while (ans=='y');
	tail=curr;
}

void pinnacle::display()
{
	node *curr;
	curr=head;
	if(curr!=NULL)
		cout<<"PRN\t\tName\n";
	while(curr!=NULL)
	{
		cout<<curr->prn<<"\t\t"<<curr->name<<"\n";
		curr=curr->next;
	}
	cout<<"\n";
}

int pinnacle::count()
{
	int count=0;
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		count++;
		curr=curr->next;
	}
	return count;
}

void pinnacle::makepresident(char name[])
{

	node *location=searchprev(name);


	if (location==NULL)
		cout<<"Member not found\n";
	if (location==head && strcmp(name,head->name)==0)//if head is to be made president
		return;
	else
	{
		node *temp=new node;
		strcpy(temp->name,location->next->name);
		temp->prn=location->next->prn;
		temp->next=head;
		node *p=(location->next)->next;
		delete(location->next);
		location->next=p;
		p=NULL;
		delete(p);
		head=temp;
	}
}

void pinnacle::makesecretary(char name[])
{
	node *location=searchprev(name);
	if (location==NULL)
		cout<<"Member not found\n";
	else if (location==head && strcmp(name,head->name)==0)//if head node is to be made secretary
	{
		node *temp=new node;
		strcpy(temp->name,head->name);
		temp->prn=head->prn;
		tail->next=temp;
		node *p=head;
		head=head->next;
		delete(p);
		tail=temp;
	}
	else
	{
		node *temp=new node;
		strcpy(temp->name,location->next->name);
		temp->prn=location->next->prn;
		tail->next=temp;
		node *p=(location->next)->next;
		delete(location->next);
		location->next=p;
		p=NULL;
		delete(p);
		tail=temp;
	}
}

void pinnacle::delete_mem(char name[])
{
	node *location=searchprev(name);
	if (location==NULL)
		cout<<"Member not found\n";
	else if (location==head)
	{
		node *p=head;
		head=head->next;
		delete(p);
	}
	else if (location->next==tail)//if tail is to be deleted
	{
		delete(location);
		tail=location;
	}
	else
	{
		node *p=location->next;
		location->next=location->next->next;
		delete(p);
	}
}

void pinnacle::insertafter(char name[])
{
	node* temp=new node;
	node *location=searchprev(name);
	if (location==NULL)
		cout<<"Member not found\n";
	else
	{
		cout<<"Enter PRN and name of new member\n";
		cin>>temp->prn;
		cin>>temp->name;
		if (location==head)
		{
			temp->next=head->next;
			head->next=temp;
		}
		else if(location==tail)
		{
			tail->next=temp;
			tail=temp;
		}
		else
		{
			temp->next=location->next->next;
			location->next->next=temp;
		}
	}
}

void pinnacle::reverse()
{
	node *curr=head,*prev=NULL,*next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
	tail=curr;
}

void pinnacle::concat(pinnacle &p)
{
	tail->next=p.head;
	tail=p.tail;
	p.head=NULL;
}

node* pinnacle::searchprev(char name[])
{
	if (!strcmp(name,head->name))
		return head;
	if (!strcmp(name,tail->name))
		return tail;
	node *curr=head;
	while(curr->next!=NULL)
	{
		if (!strcmp(name,curr->next->name))//to return previous element
			return curr;
		curr=curr->next;
	}
	return NULL;//if not found
}

void pinnacle::recursivedisp()
{
	cout<<"PRN\t\tName\n";
	dispRev(head);
}

void pinnacle::dispRev(node *curr)
{
	if(curr==NULL)
		return;
	else
	{
		dispRev(curr->next);
		cout<<curr->prn<<"\t\t"<<curr->name<<"\n";
	}
}

int main()
{
	pinnacle a,b;
	char na[20];
	int ch;
	node *location;

	cout<<"Enter prn and name for students of SE-A\n";
	a.create();
	cout<<"Enter prn and name for students of SE-B\n";
	b.create();
	do
	{

		cout<<"Enter\n1.Elect a president\n2.Elect a secretary\n3.Search a member\n4.Insert new member after\n5.Delete a member\n";
		cout<<"6.Reverse the list\n7.Concatenate both lists\n8.Total members in SE-A and SE-B\n9.Display both lists\n10.Diplay reversed list by recursion\n0.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
			cout<<"Enter the name of the member to be made president ";
			cin>>na;
			a.makepresident(na);
			cout<<"List of SE-A with new president:\n";
			a.display();
			break;
			case 2:
			cout<<"Enter the name of the member to be made secretary ";
			cin>>na;
			a.makesecretary(na);
			cout<<"List of SE-A with new secretary:\n";
			a.display();
			break;
			case 3:
			cout<<"Enter the name of the member to be searched(SE-A) ";
			cin>>na;
			location=a.searchprev(na);
			if(location!=NULL)
				cout<<"The member is present in the list\n\n";
			else
				cout<<"The member is not present in the list\n\n";
			break;
			case 4:
			cout<<"Enter the name of the member after which you want to insert ";
			cin>>na;
			a.insertafter(na);
			cout<<"List of SE-A with new member:\n";
			a.display();
			break;
			case 5:
			cout<<"Enter name of member to be deleted ";
			cin>>na;
			a.delete_mem(na);
			cout<<"List of SE-A after deletion:\n";
			a.display();
			break;
			case 6:
			a.reverse();
			cout<<"List of SE-A after reversing:\n";
			a.display();
			break;
			case 7:
			a.concat(b);
			cout<<"List of SE-A after concatenation:\n";
			a.display();
			break;
			case 8:
			cout<<"Total members of SE-A= "<<a.count()<<"\n";
			cout<<"Total members of SE-B= "<<b.count()<<"\n\n";
			break;
			case 9:
			cout<<"Students of SE-A:\n";
			a.display();
			cout<<"Students of SE-B:\n";
			b.display();
			break;
			case 10:
			cout<<"List of SE-A after reversing:\n";
			a.recursivedisp();
			break;
			default:
			cout<<"Invalid input\n";
		}
	}while(ch!=0);

	return 0;
}

/*
Output:

Enter prn and name for students of SE-A
Enter PRN and name
1
abc
Add more elements ?(y/n) y
Enter PRN and name
2
lmn
Add more elements ?(y/n) y
Enter PRN and name
3
pqr
Add more elements ?(y/n) 4
Enter prn and name for students of SE-B
Enter PRN and name
4
quit
Add more elements ?(y/n) n
Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
0

C:\Users\Nikhil\Desktop\allprograms\dsa>a
Enter prn and name for students of SE-A
Enter PRN and name
1
qwe
Add more elements ?(y/n) y
Enter PRN and name
2
asd
Add more elements ?(y/n) y
Enter PRN and name
3
zxc
Add more elements ?(y/n) y
Enter PRN and name
4
rty
Add more elements ?(y/n) n
Enter prn and name for students of SE-B
Enter PRN and name
5
vbn
Add more elements ?(y/n) y
Enter PRN and name
6
iop
Add more elements ?(y/n) n
Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
1
Enter the name of the member to be made president asd
List of SE-A with new president:
PRN             Name
2               asd
1               qwe
3               zxc
4               rty

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
2
Enter the name of the member to be made secretary qwe
List of SE-A with new secretary:
PRN             Name
2               asd
3               zxc
4               rty
1               qwe

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
3
Enter the name of the member to be searched(SE-A) rty
The member is present in the list

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
4
Enter the name of the member after which you want to insert rty
Enter PRN and name of new member
8
jkl
List of SE-A with new member:
PRN             Name
2               asd
3               zxc
4               rty
8               jkl
1               qwe

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
5
Enter name of member to be deleted rty
List of SE-A after deletion:
PRN             Name
2               asd
3               zxc
8               jkl
1               qwe

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
6
List of SE-A after reversing:
PRN             Name
1               qwe
8               jkl
3               zxc
2               asd

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
8
Total members of SE-A= 4
Total members of SE-B= 2

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
10
List of SE-A after reversing:
PRN             Name
2               asd
3               zxc
8               jkl
1               qwe

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
7
List of SE-A after concatenation:
PRN             Name
1               qwe
8               jkl
3               zxc
2               asd
5               vbn
6               iop

Enter
1.Elect a president
2.Elect a secretary
3.Search a member
4.Insert new member after
5.Delete a member
6.Reverse the list
7.Concatenate both lists
8.Total members in SE-A and SE-B
9.Display both lists
10.Diplay reversed list by recursion
0.Exit
0
*/
