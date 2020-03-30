/*HARSHA KIRAN GONDHALEKAR 
SE B
ROLL NO 20
*/
#define MAX 30
#include<iostream>
using namespace std;
class treenode
{	public:
	char data;
	treenode *left,*right;
};
class expressiontree
{	public:
	treenode *root;
	expressiontree()
	{
		root=NULL;
	}
	void create();
	void inorder(treenode *root);
	void nrinorder(treenode *root);
	//void nrpostorder(treenode *);
	treenode* swap(treenode *root);
};
class stack
{	public:
	treenode *s[MAX];
	int top;
	stack()
	{
		top=-1;
	}
	void push(treenode *x)
	{
		top++;
		s[top]=x;
	}
	treenode* pop()
	{
		treenode* y;
		y=s[top];
		top--;
		return y;
	}
	int empty()
	{
		if(top==-1)
		return 1;
		else
		return 0;
	}
	int full()
	{
		if(top==MAX-1)
		return 1;
		else
		return 0;
	}
};
void expressiontree::create()
{
	treenode *curr,*t1,*t2;
	stack s;
	char postfix[MAX];
	cout<<"\nEnter the postfix expression:";
	cin>>postfix;
	char ch;
	int i=0;
	while(postfix[i]!='\0')
	{
		ch=postfix[i];
		curr=new treenode;
		curr->left=curr->right=NULL;
		curr->data=ch;
		if(ch>='a' && ch<='z')
		{
			s.push(curr);
		}
		else
		{
			t1=s.pop();
			t2=s.pop();
		curr->right=t1;
		curr->left=t2;
		s.push(curr);
		}
	i++;
	}//end of while
	root=s.pop();
}//end of create
void expressiontree::inorder(treenode *root)			//recursive
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<"\t "<<root->data;
		inorder(root->right);
	}
}
void  expressiontree::nrinorder(treenode *)			//non-recursive
{
	stack s;
	treenode *t;
	t=root;
	do
	{
		while(t!=NULL)
		{
			s.push(t);
			t=t->left;
		}
		if(s.empty())
		{
			break;
		}
		t=s.pop();
		cout<<"\t "<<t->data;
		t=t->right;
	}while(1);
}
treenode* expressiontree::swap(treenode *root)
{
	treenode *curr;
	if(root!=NULL)
	{
		curr=root->left;
        root->left=swap(root->right);
        root->right=swap(curr);
       }
    return (root);
}//end of swap nodes.

int main()
{
 expressiontree e;
e.create();
cout<<"\nInorder is:\n";
e.inorder(e.root);
cout<<"\nNon recursive Inorder is:\n";
e.nrinorder(e.root);
e.root=e.swap(e.root);
cout<<"\nTree is swapped\n";
cout<<"\nRecursive inorder of swapped tree:\n";
e.inorder(e.root);
return 0;
}	

/*OUTPUT:

Enter the postfix expression:abc+*

Inorder is:
	 a	 *	 b	 +	 c
Non recursive Inorder is:
	 a	 *	 b	 +	 c
Tree is swapped

Recursive inorder of swap tree:
	 c	 +	 b	 *	 a
*/
