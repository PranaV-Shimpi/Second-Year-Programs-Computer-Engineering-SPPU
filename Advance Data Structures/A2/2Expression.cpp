
/*
	Assignment 2
	Expresssion tree
	SE B 41
*/

#include<iostream>
using namespace std;
class node
{
	public:
	node *left;
	node *right;
	char data;
};

class extree
{
	public:
	node *root;
	extree()
	{
		root=NULL;
	}
	node *create(char);
	void insert(char*);
	void inr(node*);
	void innr(node*);
};

template<class g>
class stack
{
	g *a[20];
	int top;
	public:
	stack(){ top=-1;}
	void push(g *temp)
	{
		a[++top]=temp;
	}
	node *pop()
	{
		g *temp;
		temp = a[top--];
		return temp;
	}
	int isempty()
	{
		if(top==-1)
		return 1;
		return 0;
	}
};

node *extree :: create(char term)
{
	node *temp;
	temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=term;
	return temp;
}

void extree :: insert(char expr[])
{
	node *temp, *ptr1, *ptr2;
	stack <node>operators,operands;
	int i=0;
	while(expr[i]!='\0')
	{
		temp=create(expr[i]);
		if(expr[i]>='a' && expr[i]<='z')
		{
			operands.push(temp);
		}
		else
		{
			if(!operands.isempty())
			{
				ptr1=operands.pop();
				ptr2=operands.pop();
				temp->right=ptr1;
				temp->left=ptr2;
			}
			operands.push(temp);	
		}
	i++;	
	}
	ptr2 = operands.pop();
	if(!operands.isempty())
	{
		cout<<"\nInvalid Expression \n";
		return;
	}
	cout<<"\nInorder traversal :\n";
	innr(ptr2);
	
	
}
void extree :: inr(node *ptr)
{
	if(ptr!=NULL)
	{
		inr(ptr->left);
		cout<<ptr->data<<" ";
		inr(ptr->right);
	}	
}

void extree :: innr(node *root)
{
	node *temp=root;
	stack <node>st;
	while(1)
	{
		while(temp!=NULL)
		
		{
			st.push(temp);
			temp=temp->left;
		}
		if(!st.isempty())
		{
			temp=st.pop();
			cout<<" "<<temp->data;
			temp=temp->right;
		}
		else
			break;
	}
}

int main()
{
	char exp[10];
	extree t1;
	cout<<"\nEnter the expression in postfix form :\n";
	cin>>exp;
	t1.insert(exp);
	return 0;
}

/*
Enter the expression in postfix form :
abc+-d/

Inorder traversal :
 a - b + c / d

*/
