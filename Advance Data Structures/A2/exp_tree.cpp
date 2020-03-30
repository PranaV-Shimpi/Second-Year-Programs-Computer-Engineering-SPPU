#include<iostream>
using namespace std;
class node
{
	public:
	char data;
	node *left;
	node *right;
};

class stack
{
	public:
	node *stk[20];
	int top;
	stack()
	{
		top=-1;
	}
	
	void push(node *ch1)
	{
		top++;
		stk[top]=ch1;
		
	}
	node* pop()
	{
		int x=top;
		top--;
		return stk[x];
	}
};


class bst_exp
{
	public:
	node *root;
	bst_exp()
	{
		root=NULL;
	}
	
	
	void construct();
	void inorder(node *root1);
	void preorder(node *root1);

};
	

	void bst_exp::construct()
	{
		stack s;
		node *temp,*t1,*t2;
		char ch;
		char postfix[20];
		cout<<"enter post fix expression: ";
		cin>>postfix;
		int i=0;
		temp=new node;
		while(postfix[i]!='\0')
		{
			ch=postfix[i];
			temp=new node;
			temp->data=ch;
			temp->left=NULL;
			temp->right=NULL;
			if(ch>='a'&& ch<='z')
			{
				s.push(temp);
			}
			else
			{
				t1=s.pop();
				t2=s.pop();
				//temp->data=ch;
				temp->left=t2;
				temp->right=t1;
				s.push(temp);
			}
			i++;
		}
		root=s.pop();
	}
		
		
	void bst_exp::inorder(node *root1)
	{
		node *curr;
		stack s;
		curr=root1;
		do
		{
			while(curr!=NULL)
			{
				s.push(curr);
				curr=curr->left;
			}
			if(s.top!=-1)
			{
				curr=s.pop();
				cout<<curr->data;
				curr=curr->right;
			}
			else
				break;
		}while(1);
	}
void bst_exp::preorder(node *root1)
	{
		node *curr;
		stack s;
		curr=root1;
		do
		{
			while(curr!=NULL)
			{
				cout<<curr->data;
				s.push(curr);
				curr=curr->left;
			}
			if(s.top!=-1)
			{
				curr=s.pop();
				
				curr=curr->right;
			}
			else
				break;
		}while(1);
	}		

int main()
	{
		bst_exp b;
		b.construct();
		cout<<endl;
		cout<<"inorder is: ";
		b.inorder(b.root);
		cout<<"\npreorder is: ";
		b.preorder(b.root);
		return 0;
	}







