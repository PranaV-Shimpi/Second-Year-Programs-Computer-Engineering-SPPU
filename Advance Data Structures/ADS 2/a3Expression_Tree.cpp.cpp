//Expression Tree

#include<iostream>
#include<stack.h>
using namespace std;
class node
{
	public:
		char data;
		node *left,*right;
		node()
		{
			left=NULL;
			right=NULL;
		}
};
class exptree
{
	char a[10];

	public:
		node *root;
		exptree()
		{
			root=NULL;
		}
		void read();
		void create_tree();
		void pre(node *);
		void in(node *);
		void post(node *);
		void pre();
		void in();
		void post();
};
void exptree :: read()
{
	cout<<"\nEnter postfix expression : ";
	cin>>a;
}
void exptree :: create_tree()
{
	node *temp,*pop1,*pop2;
	char ch;
	stack<node *> s;
	int i=0;
	while(a[i]!='\0')
	{
		ch=a[i];
		if((ch>='a' || ch>='A') && (ch<='z' || ch<='Z'))
		{
			temp=new node;
			temp->data=ch;
			s.push(temp);
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		{
			temp=new node;
			temp->data=ch;
			pop1=s.pop();
			pop2=s.pop();
			temp->left=pop2;
			temp->right=pop1;
			s.push(temp);
			root=temp;
		}
		i++;
	}
}
void exptree :: pre(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data;
		pre(temp->left);
		pre(temp->right);
	}
}
void exptree :: in(node *temp)
{
	if(temp!=NULL)
	{
		in(temp->left);
		cout<<temp->data;
		in(temp->right);
	}
}
void exptree :: post(node *temp)
{
	if(temp!=NULL)
	{
		post(temp->left);
		post(temp->right);
		cout<<temp->data;
	}
}
void exptree :: pre()
{
	stack<node *> s;
	node *temp;
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->data;
			s.push(temp);
			temp=temp->left;
		}
		if(s.isempty())
			return;
		temp=s.pop();
		temp=temp->right;
	}
}
void exptree :: in()
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
		cout<<temp->data;
		temp=temp->right;
	}
}
void exptree :: post()
{
	node *temp=root;
	stack<node *> s;
	stack<char> s1;
	char flag;
	while(1)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			s1.push('l');
			temp=temp->left;
		}
		if(s.isempty())
			return;
		else
		{
			temp=s.pop();
			flag=s1.pop();
			if(flag=='r')
			{
				cout<<temp->data;
				temp=NULL;
			}
			else if(flag=='l')
			{
				s.push(temp);
				s1.push('r');
				temp=temp->right;
			}
		}
	}
}
int main()
{
	int ans;
	exptree e;
	do
	{
		cout<<"\nEnter your choice\n1.Read and Create Tree\n2.preorder\n3.inorder\n4.postorder\n5.preorder(non-rec)\n6.inorder(non-rec)\n7.postorder(non-rec)";
		cin>>ans;
		switch(ans)
		{
			case 1:
				e.read();
				e.create_tree();
			break;
			case 2:
				e.pre(e.root);
			break;
			case 3:
				e.in(e.root);
			break;
			case 4:
				e.post(e.root);
			break;
			case 5:
				e.pre();
			break;
			case 6:
				e.in();
			break;
			case 7:
				e.post();
			break;
		}
	}while(ans<8);
	return 0;
}
