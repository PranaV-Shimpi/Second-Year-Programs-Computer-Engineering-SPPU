

/*A6 Dictionary
i.  Add
ii.  delete
iii. update
*/


#include <iostream>
using namespace std;

class node
{
public:
	string data,meaning;
	node *left,*right;
	node()
	{
		left=right=NULL;
		data="";
		meaning="";
	}
	~node(){}
};

class dictionary
{
	node *root;
public:
	dictionary()
	{
		root=NULL;
	}
	~dictionary(){}
	void search();
	void del();
	void insert();
	node* getroot();
	void inorder(node*);
	void update();
	void deletenode();
	string minValue(node*);
	node* del(node*,string);
};

void dictionary::insert()
{
	node *temp=new node;
	node *curr=root;
	cout<<"Enter data ";
	cin>>temp->data;
	cout<<"Enter meaning ";
	cin.ignore();
	getline(cin,temp->meaning);

	if (root==NULL)
	{
		root=temp;
		return;
	}
	else
	{
		while(curr!=NULL)
		{
			if (curr->data>temp->data)
			{
				if(curr->left!=NULL)
					curr=curr->left;
				else
				{
					curr->left=temp;
					break;
				}
			}
			else if (curr->data<temp->data)
			{
				if(curr->right!=NULL)
					curr=curr->right;
				else
				{
					curr->right=temp;
					break;
				}
			}
			else
			{
				cout<<"Duplicate value\n";
				break;
			}
		}
	}
}


void dictionary::inorder(node *curr)
{
	if (curr!=NULL)
	{
		inorder(curr->left);
		cout<<curr->data<<": "<<curr->meaning<<"\n";
		inorder(curr->right);
	}
}

void dictionary::search()
{
	string key;
	int count=0;
	cout<<"Enter the key to search ";
	cin>>key;
	node *curr=root;
	while(curr!=NULL)
	{
		count++;
		if (curr->data==key)
		{
			cout<<"Element found with "<<count<<" comparisons\n";
			cout<<curr->data<<": "<<curr->meaning<<"\n";

			return;
		}
		else if(key<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	cout<<"Key not found\n";
	return;
}


void dictionary::deletenode()
{
	string key;
	cout<<"\nEnter key to delete ";
	cin>>key;
	root=del(root,key);
}

string dictionary::minValue(node *curr)
{
	while (curr->left!=NULL)
		curr=curr->left;
	return(curr->data);
}

node* dictionary::del(node *curr,string key)
{
	if (curr==NULL)
		return curr;
	if (key<curr->data)
		curr->left=del(curr->left,key);
	else if (key>curr->data)
		curr->right=del(curr->right,key);
	else
	{
		if (curr->left==NULL)
			return curr->right;
		else if (curr->right==NULL)
			return curr->left;
		curr->data=minValue(curr->right);
		curr->right=del(curr->right, curr->data);
	}
	return curr;
}



void dictionary::update()
{
	string key;
	cout<<"Enter key to update ";
	cin>>key;
	node *curr=root;
	while(curr!=NULL)
	{
		if (curr->data==key)
		{
			cout<<curr->data<<": "<<curr->meaning<<"\n";
			cout<<"Enter new meaning ";
			cin>>curr->meaning;
			cout<<"The word after updation is: \n";
			cout<<curr->data<<": "<<curr->meaning<<"\n";
			return;
		}
		else if(key<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	cout<<"Key not found\n";
	return;
}

node* dictionary::getroot()
{	return root;}

int main()
{
	dictionary b;
	int choice;
	do
	{
		cout<<"\n\tMENU";
		cout<<"\n1.Insert node\n2.Display\n3.Search\n4.Delete\n5.Update\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 0: break;
			case 1:
				b.insert();
				break;
			case 2:
				b.inorder(b.getroot());
				break;
			case 3:
				b.search();
				break;
			case 4:
				b.deletenode();
				break;
			case 5:
				b.update();
				break;

			default:
				cout<<"Choice should be between 0 and 5\n\n";
		}
	}while(choice!=0);
	return 0;
}
