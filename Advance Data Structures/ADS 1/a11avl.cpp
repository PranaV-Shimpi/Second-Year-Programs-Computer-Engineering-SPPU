/*A-11 AVL DICTIONARY*/

#include <iostream>
#include <queue>
using namespace std;

class avlnode
{
public:
	int ht;
	string keyword,meaning;
	avlnode *left,*right;
	avlnode()
	{
		ht=0;
		keyword=meaning="";
		left=right=NULL;
	}
	~avlnode(){}
};

class avltree
{
	avlnode *root;
public:
	avltree()
	{
		root=NULL;
	}
	~avltree(){}
	int bf(avlnode* x);
	int ht(avlnode *curr);
	void read();
	void bfs();
	avlnode* getroot();
	void deletenode();
	string minValue(avlnode*);
	avlnode* del(avlnode*,string);
	void inorder(avlnode*);
	void preorder(avlnode*);
	void search();
	void printLevelOrder(avlnode* root);
	void printGivenLevel(avlnode* root,string);
	avlnode* ll(avlnode* t);
	avlnode* rr(avlnode* t);
	avlnode* lr(avlnode* t);
	avlnode* rl(avlnode* t);
	avlnode* rotateleft(avlnode* x);
	avlnode* rotateright(avlnode* x);
	avlnode* insert(avlnode* root,string newkey,string mean);

};

avlnode* avltree::rotateleft(avlnode* x)
{
	avlnode* y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=ht(x);
	y->ht=ht(y);
	return y;
}

avlnode* avltree::rotateright(avlnode* x)
{
	avlnode* y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=ht(x);
	y->ht=ht(y);
	return y;
}

avlnode* avltree::ll(avlnode* t)
{
	t=rotateright(t);
	return t;
}

avlnode* avltree::rr(avlnode* t)
{
	t=rotateleft(t);
	return t;
}

avlnode* avltree::lr(avlnode* t)
{
	t->left=rotateleft(t->left);
	t=rotateright(t);
	return t;
}

avlnode* avltree::rl(avlnode* t)
{
	t->right=rotateright(t->right);
	t=rotateleft(t);
	return t;
}

int avltree::bf(avlnode* x)
{
	return ht(x->left)-ht(x->right);
}

int avltree::ht(avlnode *curr)
{
	int lh,rh;
	if(curr==NULL) return 0;
	else if(curr->left==NULL && curr->right==NULL) return 0;
	lh=ht(curr->left);
	rh=ht(curr->right);
	if(lh>rh) return lh+1;
	else return rh+1;
}

avlnode* avltree::insert(avlnode* root,string newkey,string mean)
{
	avlnode* curr;
	int lh,rh;
	if (root==NULL)
	{
		curr=new avlnode;
		root=curr;
		curr->keyword=newkey;
		curr->meaning=mean;
		root=curr;
	}
	else if (newkey<root->keyword)
	{
		root->left=insert(root->left,newkey,mean);
		if (bf(root)==2)
		{
			if(newkey<root->left->keyword)
				root=ll(root);
			else
				root=rr(root);
		}
	}
	else if (newkey>root->keyword)
	{
		root->right=insert(root->right,newkey,mean);
		if (bf(root)==-2)
		{
			if(newkey>root->right->keyword)
				root=rr(root);
			else
				root=rl(root);
		}
	}
	else
		cout<<"duplicate\n";

	//cout<<curr->keyword<<" "<<bf(root)<<"\n";
	return root;
}
avlnode* avltree::getroot()
{
	return root;
}


void avltree::inorder(avlnode *curr)
{
	if (curr!=NULL)
	{
		inorder(curr->left);
		cout<<curr->keyword<<" ";
		inorder(curr->right);
	}
}

void avltree::preorder(avlnode *curr)
{
	if (curr!=NULL)
	{
		cout<<curr->keyword<<" ";
		preorder(curr->left);
		preorder(curr->right);
	}
}

void avltree::search()
{
	string key;
	cout<<"Enter keyword to search ";
	cin>>key;

	avlnode *curr=root;
	while(curr!=NULL)
	{
		if (curr->keyword==key)
		{
			cout<<"Element found!\n";
			cout<<"The meaning is: "<<curr->meaning<<"\n";
			return;
		}
		else if(key<curr->keyword)
			curr=curr->left;
		else
			curr=curr->right;
	}
	cout<<"Element not found\n";
}

void avltree::read()
{
	string k,m;
	char ch;
	do
	{
		cout<<"Enter key,meaning ";
		cin>>k>>m;
		root=insert(root,k,m);
		cout<<"continue (y/n)? ";
		cin>>ch;
	} while (ch=='y' || ch=='Y');

}

void avltree::deletenode()
{
	string key;
	cout<<"\nEnter key to delete ";
	cin>>key;
	root=del(root,key);
}

string avltree::minValue(avlnode *curr)
{
	while (curr->left!=NULL)
		curr=curr->left;
	return(curr->keyword);
}

avlnode* avltree::del(avlnode *curr,string key)
{
	if (curr==NULL)
		return curr;
	if (key<curr->keyword)
		curr->left=del(curr->left,key);
	else if (key>curr->keyword)
		curr->right=del(curr->right,key);
	else
	{
		if (curr->left==NULL)
			return curr->right;
		else if (curr->right==NULL)
			return curr->left;
		curr->keyword=minValue(curr->right);
		curr->right=del(curr->right, curr->keyword);
	}
	return curr;
}


int main()
{
	avltree a;

	int choice;
	do
	{
		cout<<"\n\n\tMENU\n";
		cout<<"\n1.Insert node\n2.Search\n3.Inorder";
		cout<<"\n4.Delete key\n0.Exit\nEnter choice ";
		cin>>choice;
		switch(choice)
		{
			case 0: break;
			case 1:
				a.read();
				break;
			case 2:
				a.search();
				break;
			case 3:
				a.inorder(a.getroot());
				break;
			case 4:
				a.deletenode();
				break;

			default:
				cout<<"Choice should be between 0 and 4\n\n";
		}
	}while(choice!=0);
	return 0;
}
