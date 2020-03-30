/*A4  Beginning with an empty binary search tree,
 construct binary search tree by inserting the
values in the order given. After constructing a
 binary tree -
i.  Insert new node
ii. Find number of nodes in longest path
iii.Minimum data value foundin the tree
iv. Search a value
*/

#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *left,*right;
	node()
	{
		left=right=NULL;
		data=0;
	}
	~node(){}
};


class bst
{
	node *root;
	int n;	//no of nodes
public:
	bst()
	{
		root=NULL;
	}
	~bst(){}
	void min();
	void search();
	void insert();
	int height(node*);
	void mirror(node*);
	node* getroot();
	void preorder(node*);
	void postorder(node*);
	void inorder(node*);
	void deletenode();
	int minValue(node*);
	node* del(node*,int);
};


void bst::insert()
{
	node *temp=new node;
	node *curr=root;
	cout<<"Enter data ";
	cin>>temp->data;

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
					curr->left=temp;n++;
					break;
				}
			}
			else if (curr->data<temp->data)
			{
				if(curr->right!=NULL)
					curr=curr->right;
				else
				{
					curr->right=temp;n++;
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

int bst::height(node *curr)
{
	int lh,rh;
	if(curr==NULL) return 0;
	else if(curr->left==NULL && curr->right==NULL) return 0;
	lh=height(curr->left);
	rh=height(curr->right);
	if(lh>rh) return lh+1;
	else return rh+1;
}

void bst::search()
{
	int key;
	cout<<"Enter the key to search ";
	cin>>key;
	node *curr=getroot();
	while(curr!=NULL)
	{
		if (curr->data==key)
		{
			cout<<"Element found!\n";
			return;
		}
		else if(key<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	cout<<"Element not found\n";
	return;
}

void bst::min()
{
	node *curr=getroot();
	if(root==NULL)
	cout<<"The tree is empty";
	while(curr->left!=NULL)
		curr=curr->left;
	cout<<"The min element is: "<<curr->data;
}

void bst::mirror(node *curr)
{
	if(curr!=NULL)
	{
		node *temp=curr->left;
		curr->left=curr->right;
		curr->right=temp;
		// temp=NULL;
		mirror(curr->left);
		mirror(curr->right);
	}
}


void bst::preorder(node *curr)
{
	if (curr!=NULL)
	{
		cout<<curr->data<<" ";
		preorder(curr->left);
		preorder(curr->right);
	}
}

void bst::postorder(node *curr)
{
	if (curr!=NULL)
	{
		postorder(curr->left);
		postorder(curr->right);
		cout<<curr->data<<" ";
	}
}

void bst::inorder(node *curr)
{
	if (curr!=NULL)
	{
		inorder(curr->left);
		cout<<curr->data<<" ";
		inorder(curr->right);
	}
}

node* bst::getroot()
{
	return root;
}

void bst::deletenode()
{
	int key;
	cout<<"\nEnter key to delete ";
	cin>>key;
	root=del(root,key);
}

int bst::minValue(node *curr)
{
	while (curr->left!=NULL)
		curr=curr->left;
	return(curr->data);
}

node* bst::del(node *curr,int key)
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

int main()
{
	bst b;
	int choice;
	do
	{
		cout<<"\n\n\tMENU\n";
		cout<<"\n1.Insert node\n2.Search\n3.Height\n4.Mirror\n5.Minimum element";
		cout<<"\n6.Recursive Preorder\n7.Recursive Postorder\n8.Recursive Inorder\n9.Delete key\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 0: break;
			case 1:
				b.insert();
				break;
			case 2:
				b.search();
				break;
			case 3:
				cout<<"Height of bst is: "<<b.height(b.getroot());
				break;
			case 4:
				b.mirror(b.getroot());
				break;
			case 5:
				b.min();
				break;
			case 6:
				b.preorder(b.getroot());
				break;
			case 7:
				b.postorder(b.getroot());
				break;
			case 8:
				b.inorder(b.getroot());
				break;
			case 9:
				b.deletenode();
				break;

			default:
				cout<<"Choice should be between 0 and 9\n\n";
		}
	}while(choice!=0);
	return 0;
}
