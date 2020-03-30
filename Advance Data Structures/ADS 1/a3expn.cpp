 //a3 Expression TREE

#include "stack.h"
#include <iostream>
using namespace std;

class node
{
public:
	char data;
	node *left,*right;
	node(char c)
	{
		left=right=NULL;
		data=c;
	}
	node()
	{
		left=right=NULL;
		data=' ';
	}
	~node(){}
};

class expn
{
public:
	node *root;
	expn()
	{
		root=NULL;
	}
	~expn(){}
	void insert();
	void preorder(node*);
	void postorder(node*);
	void inorder(node*);
	void postorder();
	void inorder();
	void preorder();
	void convert();
	node* getroot();
};

void expn::insert()
{
	if (root==NULL)
	{
		root=new node;
		cout<<"Enter data ";
		cin>>root->data;
	}
	else
	{
		char ch;
		node *curr=root,*p=new node;
		while(curr!=NULL)
		{
			cout<<"Do you want to enter left or right node(l/r)? ";
			cin>>ch;
			if (ch=='l')
			{
				if (curr->left==NULL)
				{
					cout<<"Enter data ";
					cin>>p->data;
					curr->left=p;
					return;
				}
				else
					curr=curr->left;
			}
			else if (ch=='r')
			{
				if (curr->right==NULL)
				{
					cout<<"Enter data ";
					cin>>p->data;
					curr->right=p;
					return;
				}
				else
					curr=curr->right;
			}
		}
	}
}

void expn::preorder(node *curr)
{
	if (curr!=NULL)
	{
		cout<<curr->data<<" ";
		preorder(curr->left);
		preorder(curr->right);
	}
}

void expn::postorder(node *curr)
{
	if (curr!=NULL)
	{
		postorder(curr->left);
		postorder(curr->right);
		cout<<curr->data<<" ";
	}
}

void expn::inorder(node *curr)
{
	if (curr!=NULL)
	{
		inorder(curr->left);
		cout<<curr->data<<" ";
		inorder(curr->right);
	}
}


void expn::postorder()
{
	if (root== NULL)
		return;
	stack<node*> s1,s2;
	s1.push(root);
	node* temp;
	while (!s1.isempty()) {
		temp = s1.pop();
		s2.push(temp);
		if (temp->left)
			s1.push(temp->left);
		if (temp->right)
			s1.push(temp->right);
	}
	while (!s2.isempty()) {
		temp = s2.pop();
		cout<<" "<<temp->data;
	}
}

void expn::inorder()
{
	stack<node*> s;
	node *curr=root;
	while (!s.isempty() || curr != NULL)
	{
		if (curr != NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		else
		{
			curr=s.pop();
			cout<<curr->data << " ";
			curr=curr->right;
		}
	}
}

void expn::preorder()
{
	if (root == NULL)
	   return;
	stack<node*> s;
	s.push(root);
	while (!s.isempty())
	{
		node *curr = s.pop();
		cout << curr->data << " ";
		if (curr->right!=NULL)
			s.push(curr->right);
		if (curr->left!=NULL)
			s.push(curr->left);
	}
}


void expn::convert()
{
	string post;
	node *temp;
	cout<<"Enter the postfix expn ";
	cin>>post;
	stack<node*> s;
	for(int i=0;i<post.length();i++)
	{
		temp=new node(post[i]);
		if(isalpha(post[i]))
			s.push(temp);
		else
		{
			node *op2=s.pop();
			node *op1=s.pop();
			temp->left=op1;
			temp->right=op2;
			s.push(temp);
		}
	}
	root=temp;
}

node* expn::getroot()
{return root;}

int main()
{
	expn b;
	int choice;
	do
	{
		cout<<"\n\t\tMENU\n\n";//start with clear screen,
		cout<<"1.Convert postfix expn to tree\n2.Recursive Preorder\n3.Recursive Postorder\n4.Recursive Inorder\n";
		cout<<"5.Preorder\n6.Postorder\n7.Inorder\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 0: break;
			case 1:
				b.convert();
				break;
			case 2:
				b.preorder(b.root);
				break;
			case 3:
				b.postorder(b.root);
				break;
			case 4:
				b.inorder(b.root);
				break;
			case 5:
				b.preorder();
				break;
			case 6:
				b.postorder();
				break;
			case 7:
				b.inorder();
				break;
			default:
				cout<<"Choice should be between 0 and 7\n\n";
		}
	}while(choice!=0);
	return 0;
}
