//BST

#include<iostream>
#include"stack.h"
#include<queue>
using namespace std;
class node
{
	public:
		int data;
		node *left,*right;
};

class bsttree
{
	public:
		node *root;
		bsttree()
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
		int Search();
		int minn();
		int maxx();
		int min(node *);
		int max(node *);
		int height(node *);
		void DFS();
		void BFS();

};
void bsttree :: create()
{
	root=new node;
	root->left=root->right=NULL;
	cout<<"\nEnter the root node : ";
	cin>>root->data;
	cout<<"\n\troot node created successfully...\n";
}

void bsttree :: insert()
{
	char ch;
	node *p,*temp;

	if(root==NULL)
		create();
	p=new node;
	p->left=p->right=NULL;
	cout<<"\nEnter node data : ";
	cin>>p->data;
	temp=root;
	while(temp!=NULL)
	{

		if(p -> data < temp -> data)
		{
			if(temp->left==NULL)
			{
				temp->left=p;
				break;
			}
			else
				temp=temp->left;
		}
		else if(p -> data > temp -> data)
		{
			if(temp->right==NULL)
			{
				temp->right=p;
				break;
			}
			else
				temp=temp->right;
		}
		else
			cout<<"\n\t Alredy Inserted Data ";
	}
}

void bsttree :: preOrder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<" "<<temp->data;
		preOrder(temp->left);
		preOrder(temp->right);
	}
}
void bsttree :: inOrder(node *temp)
{

	if(temp!=NULL)
	{
		inOrder(temp->left);
		cout<<" "<<temp->data;
		inOrder(temp->right);
	}
}
void bsttree :: postOrder(node *temp)
{

	if(temp!=NULL)
	{
		postOrder(temp->left);
		postOrder(temp->right);
		cout<<" "<<temp->data;
	}
}

void bsttree :: nrPre()
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
void bsttree :: nrIn()
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
void bsttree :: nrPost()
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

int bsttree :: Search()
{
	int key;
	cout<<"\nEnter key to be search : ";
	cin >> key;
	node *temp = root;
	if(temp == NULL)
		cout << "\nEmpty";
	else
	{
		while(temp!= NULL)
		{
			if(key == temp -> data)
				return 1;
			else if(key < temp -> data)
				temp = temp -> left;
			else
				temp = temp -> right;
		}
		cout<<"not found";
	}
}
int bsttree :: height(node *temp)
{
	int lh,rh;
	if(temp==NULL)
		return 0;
	else if(temp->left==NULL && temp->right==NULL)
		return 0;
	lh=height(temp->left);
	rh=height(temp->right);
	if(lh>rh)
		return lh+1;
	else
		return rh+1;
}

int bsttree :: minn()
{
	node *temp=root;
	while(temp->left!=NULL)
	{
		temp = temp->left;
	}
	cout<<temp->data;
}
int bsttree :: maxx()
{
	node *temp=root;
	while(temp->right!=NULL)
	{
		temp = temp->right;
	}
	cout<<temp->data;
}
int bsttree :: min(node *temp)
{
	if(temp!=NULL)
	{
		if(temp->left!=NULL)
			min(temp->left);
		else if(temp->right!=NULL)
			min(temp->right);
		else
			return temp->data;
	}
}
int bsttree :: max(node *temp)
{
	if(temp!=NULL)
	{
		if(temp->right!=NULL)
			max(temp->right);
		else if(temp->left!=NULL)
			min(temp->left);
		else
			return temp->data;
	}
}

int main()
{
	int ans,ch;
	bsttree b;
	int a;
	do
	{
		cout<<"\n\n*****Binary Search Tree*****\n";
		cout<<"\n\t*MENU*\n#1 INSERT\n#2 preOrder\n#3 inOrder\n#4 postOrder\n#5 preorder(non rec)\n#6 inorder(non rec)\n#7 postorder(non rec)";
		cout <<"\n#8 Search\n#9 Height\n#10 Min and Max\n#11 Exit\nEnter ur choice : ";
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
				cout<<"\n\tnon rec POSTORDER\n";
				b.nrPost();
				break;
			case 8:
				cout<<"\n\t SEARCH\n";
				a=b.Search();
				if(a==1)
					cout<<"\nfound\n";
				break;
			case 9:
				cout<<"\nHeight of tree : "<<b.height(b.root);
				break;
			case 10:
				do
				{
					cout<<"\n\tMin and maximum nodes\n";
					cout<<"\n#1 Minimum node(rec)\n#2 Maximum  node(rec)\n#3 Main Menu";
					cout<<"\nEnter ur choice : ";
					cin>>ch;

					switch(ch)
					{

						case 1:
							   cout<<"\nminimum node (rec) : "<<b.min(b.root);
							break;

						case 2:
							   cout<<"\nMaximum node (rec) : "<<b.max(b.root);
							break;
						case 3:
								break;
						default : cout<<"wrong input....";
							break;
					}
				}while(ch!=3);
				break;

			case 11:
				cout<<"Exit...";
				break;
			default : cout<<"wrong input....";
		}
	}while(ans!=11);
	return 0;
}

