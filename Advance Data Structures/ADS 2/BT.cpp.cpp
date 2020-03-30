//Binary Tree

#include<iostream>
#include"stack.h"
using namespace std;
class node
{
	public:
		int data;
		node *left,*right;
};
class bitree
{
	public:
		node *root;
		bitree()
		{
			root=NULL;
		}
		void create();
		void insert();
		void preOrder(node *);
		void inOrder(node *);
		void postOrder(node *);
		void nrPre();
		void nrIn();
		void nrPost();
};
void bitree :: create()
{
	root=new node;
	root->left=root->right=NULL;
	cout<<"\nEnter the root node : ";
	cin>>root->data;
	cout<<"\n\troot node created successfully...\n"; 
}
void bitree :: insert()
{
	char ch;
	node *p,*q;

	if(root==NULL)
		create();
	p=new node;
	p->left=p->right=NULL;
	cout<<"\nEnter node data : ";
	cin>>p->data;
	q=root;
	while(q!=NULL)
	{
		cout<<"\nDo you want to add left or right node ? ( left ->l or right -> r) : ";
		cin>>ch;
		
		if(ch=='l')
		{
			if(q->left==NULL)
			{
				q->left=p;
				return;
			}
			else
				q=q->left;
		}	
		else if(ch=='r')
		{
			if(q->right==NULL)
			{
				q->right=p;
				return;
			}
			else
				q=q->right;
		}
	}
}
void bitree :: preOrder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<" "<<temp->data;
		preOrder(temp->left);
		preOrder(temp->right);
	}
}
void bitree :: inOrder(node *temp)
{
	
	if(temp!=NULL)
	{
		inOrder(temp->left);
		cout<<" "<<temp->data;
		inOrder(temp->right);
	}
}
void bitree :: postOrder(node *temp)
{
	
	if(temp!=NULL)
	{
		postOrder(temp->left);
		postOrder(temp->right);
		cout<<" "<<temp->data;
	}
}
void bitree :: nrPre()
{
	stack<node *>s;
	node *temp;
	temp = root;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<" "<<temp->data;
			s.push(temp);
			temp = temp ->left;
		}
		if(s.isempty())
			return;
		temp = s.pop();
		temp = temp -> right;
	}

}
void bitree :: nrIn()
{
	stack<node *> s;
	node *temp;
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		if(s.isempty())
			return;
		temp=s.Top();
		s.pop();
		cout<<" "<<temp->data;
		temp=temp->right;
	}
}
void bitree :: nrPost()
{
	node *temp=root;
	stack<node *> s;     //to insert node
	stack<char > s1;		//to insert left or right node

	char flag;
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			s1.push('l');
			temp = temp -> left;
		}
		if(s.isempty())
			return;
		else
		{
			temp = s.pop();
			flag = s1.pop();
			if(flag == 'r')
			{
				cout <<" "<< temp -> data;
				temp = NULL;
			}
			else    // flag = left
			{
				s.push(temp);
				s1.push('r');
				temp = temp -> right;
			}
			
		}
	}

}
int main()
{
	int ans;
	bitree b;
	do
	{
		cout<<"\n\tBINARY TREE";
		cout<<"\n\t*MENU*\n#1 INSERT\n#2 preOrder\n#3 inOrder\n#4 postOrder\n#5 preorder(non rec)\n#6 inorder(non rec)\n#7 postorder(non rec)\n#8 Exit \nEnter ur choice : ";
		cin>>ans;
		switch(ans)
		{
			case 1: b.insert();
				break;
			case 2:
				cout<<"\n\tPREORDER\n"; 
				b.preOrder(b.root);
				break;
			case 3 :
				cout<<"\n\tINORDER\n";
				b.inOrder(b.root);
				break;
			case 4 : 
				cout<<"\n\tPOSTORDER\n";
				b.postOrder(b.root);
				break;
			case 5:
				cout<<"\n\tnon rec PREORDER\n";
				b.nrPre();
				break;
			case 6:
				cout<<"\n\tnon rec INORDER\n";
				b.nrIn();
				break;
			case 7:
				cout<<"\n\tnon rec POSTORDER";
				b.nrPost();
				break;
			case 8:
				cout<<"Exit...";
			default : cout<<"wrong input....";
		}
	}while(ans!=8);
	return 0;
}
