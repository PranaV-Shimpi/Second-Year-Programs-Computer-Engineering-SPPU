/*A-9 phone_hashing*/

#include <iostream>
using namespace std;

const int MAX=10;
class node
{
public:
	long long int num;
	node *next;
	node()
	{
		num=-1;
		next=NULL;
	}
	~node(){}
};

class phonehash
{
	node *table[MAX];
public:
	phonehash()
	{
		for (int i = 0; i < MAX; ++i)
			table[i]=new node;
	}
	~phonehash(){}
	void insert();
	void search();
	void display();
};

void phonehash::insert()
{
	node *temp;
	node *curr;
	char ch;
	int key;
	char key1[10];
	do
	{
	    cout<<"\nEnter Name : ";
	    cin>>key1;
		cout<<"\nEnter the Phone Number : ";
		cin>>key;
		int i=key%MAX;
		if (table[i]->num==-1)
			table[i]->num=key;
		else
		{
			curr=table[i];
			temp=new node;
			temp->num=key;

			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;
		}
		cout<<"\nDo you want to continue ?(y/n) ";
		cin>>ch;
	}while(ch=='y'||ch == 'Y');

}
void phonehash::search()
{
	int key;
	cout<<"\nEnter key to search ";
	cin>>key;

	node *curr;
	for (int i = 0; i < MAX; ++i)
	{
		if(table[i]->num!=-1)
		{
			if(table[i]->num==key)
			{
				cout<<"\n\tPhone number found!\n";
				return;
			}
			else if(table[i]->next!=NULL)
			{
				curr=table[i]->next;
				while(curr!=NULL)
				{
					if(curr->num==key)
					{
						cout<<"\n\tPhone number found!\n";
						return;
					}
					curr=curr->next;
				}
			}
		}
	}
	cout<<"Phone number not found\n";
}
void phonehash::display()
{   cout<<"\n==============================================";
	node *curr;
	for (int i = 0; i < MAX; ++i)
	{

	    cout<<"\n\t";
		if(table[i]->num!=-1)
		{

			cout<<i<<" -> "<<table[i]->num;
			if(table[i]->next!=NULL)
			{
				curr=table[i]->next;
				while(curr!=NULL)
				{
					cout<<" -> "<<curr->num;
					curr=curr->next;
				}
			}
		}
		else
			cout<<i;
		cout<<"\n";

	}
	cout<<"\n==============================================";
}

int main()
{
	phonehash p;
	int choice;
	do
	{
		cout<<"\n\tMENU\n\n";
		cout<<"1.Insert\n2.Search\n3.Display\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 0: break;
			case 1:
				p.insert();
				break;
			case 2:
				p.search();
				break;
			case 3:
				p.display();
				break;
			default:
				cout<<"\n\tChoice should be between 0 and 3\n\n";
		}
	}while(choice!=0);
	return 0;
}
