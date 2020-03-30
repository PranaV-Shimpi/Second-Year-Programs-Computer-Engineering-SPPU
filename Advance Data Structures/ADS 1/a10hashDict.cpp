    /*A-10 Hash Dictionary*/

#include <iostream>
using namespace std;

const int MAX=26;
class node
{
public:
	string keyword,mean;
	node *next;
	node()
	{
		keyword="";
		mean="";
		next=NULL;
	}
	~node(){}
};

class dicthash
{
	node *table[MAX];
public:
	dicthash()
	{
		for (int i = 0; i < MAX; ++i)
			table[i]=new node;
	}
	~dicthash(){}
	void insert();
	void search();
	void display();
};

void dicthash::insert()
{
	node *temp;
	node *curr;
	char ch;
	string key,m;
	do
	{
		cout<<"Enter the word and meaning to insert ";
		cin>>key>>m;

		int i=(key[0]-97)%MAX;
		if (table[i]->keyword=="")
		{
			table[i]->keyword=key;
			table[i]->mean=m;
		}
		else
		{
			curr=table[i];
			temp=new node;
			temp->keyword=key;
			temp->mean=m;

			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;
		}
		cout<<"Do you want to continue ?(y/n) ";
		cin>>ch;
	}while(ch=='y');

}
void dicthash::search()
{
	string key;
	cout<<"Enter key to search ";
	cin>>key;

	node *curr;
	for (int i = 0; i < MAX; ++i)
	{
		if(table[i]->keyword!="")
		{
			if(table[i]->keyword==key)
			{
				cout<<"Word found!\n";
				cout<<"The meaning is: "<<table[i]->mean<<"\n";
				return;
			}
			else if(table[i]->next!=NULL)
			{
				curr=table[i]->next;
				while(curr!=NULL)
				{
					if(curr->keyword==key)
					{
						cout<<"Word found!\n";
						cout<<"The meaning is: "<<table[i]->mean<<"\n";
						return;
					}
					curr=curr->next;
				}
			}
		}
	}
	cout<<"Word not found\n";
}
void dicthash::display()
{
	node *curr;
	for (int i = 0; i < MAX; ++i)
	{
		if(table[i]->keyword!="")
		{
			cout<<i+1<<"->"<<table[i]->keyword;
			if(table[i]->next!=NULL)
			{
				curr=table[i]->next;
				while(curr!=NULL)
				{
					cout<<"->"<<curr->keyword;
					curr=curr->next;
				}
			}
		}
		else
			cout<<i+1;
		cout<<"\n";
	}
}

int main()
{
	dicthash p;
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
				cout<<"Choice should be between 0 and 3\n\n";
		}
	}while(choice!=0);
	return 0;
}
