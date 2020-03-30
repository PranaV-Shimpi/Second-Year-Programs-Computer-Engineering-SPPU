// A5 TBST

#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *left,*right;
		int lbit,rbit;
};

class TBST
{
	public:
		node *root,*head;
		int flag;
		TBST()
		{
			head=new node;
			head->data=9999;
			head->left=head->right=head;
			head->lbit=0;
			head->rbit=1;
			root=NULL;
			flag=0;
		}
		void create();
		void preorder();
		void inorder();
};

void TBST :: create()
{
	char ch;
	node *temp,*curr;
	do
	{
		curr=new node;
		cout<<"\nEnter data : ";
		cin>>curr->data;
		curr->lbit=curr->rbit=1;
		if(root==NULL)
		{
			root=curr;
			root->left=root->right=head;
			head->left=root;
			head->lbit=0;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->data<temp->data)
				{
					if(temp->lbit==1)
					{
						curr->left=temp->left;
						temp->left=curr;
						temp->lbit=0;
						curr->right=temp;
						break;
					}
					else
						temp=temp->left;
				}
				else
				{
					if(temp->rbit==1)
					{
						curr->right=temp->right;
						temp->right=curr;
						temp->rbit=0;
						curr->left=temp;
						break;
					}
					else
						temp=temp->right;
				}
			}
		}
		cout<<"\nDo you want to continue?(y/n)";
		cin>>ch;
	}while(ch=='y');
}

void TBST :: preorder()
{
	cout<<"\nPreorder : ";
	node *temp=root;
	flag=0;
	while(temp!=head)
	{
		if(flag==0)
			cout<<" "<<temp->data;
		if(temp->lbit==0 && flag==0)
			temp=temp->left;
		else
		{
			if(temp->rbit==0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		}
	}
}
void TBST :: inorder()
{
	cout<<"\nInorder : ";
	node *temp=root;
	flag=0;
	while(temp!=head)
	{
		if(temp->lbit==0 && flag==0)
			temp=temp->left;
		else
		{
			cout<<" "<<temp->data;
			if(temp->rbit==0)
			{
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp=temp->right;
				flag=1;
			}
		}
	}
}
int main()
{
	TBST t;
	t.create();
	t.preorder();
	t.inorder();
	cout<<endl;
	return 0;
}
