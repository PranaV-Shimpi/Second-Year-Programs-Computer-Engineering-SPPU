#include<iostream>
#include<ctype.h>
#include<stack>
using namespace std;


class node
{
public:
    char data;
    node *left,*right;
    node()
    {
        left = right = NULL;
    }
};


class exptree
{
public:
    node *root;
    exptree()
    {
        root=NULL;
    }
    void create();
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    node* getroot();
};


void exptree::create()
{
    int i;
    stack<node*> s;
    char z[20];
    char c;
    node *nnode,*t1,*t2;
    cout<<"Enter the postfix expression:";
    cin>>z;
    cout<<"The entered expression is:";
    i=0;
    while(z[i]!=NULL)
    {
        cout<<z[i];
        i++;
    }
    i=0;
    while(z[i]!= NULL)
    {
        c=z[i];
        nnode=new node;
        nnode->left=nnode->right=NULL;
        nnode->data=c;
        if(c >= 'a' && c <= 'z')
        {
            s.push(nnode);
        }
        else
        {
            t2=s.pop();
            t1=s.pop();
            nnode->left=t1;
            nnode->right=t2;
            s.push(nnode);
        }
        i++;
    }
    root=s.pop();
    cout<<"\n";

}
void exptree::preorder(node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void exptree::inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void exptree::postorder(node *root)
{
    if(root!= NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

node* exptree :: getroot()
{
    return root;
}

int main()
{
    exptree e;
    int ch;
    do
    {

        cout<<"\n1.create tree\n2.display inorder\n3.display preorder \n4.display postorder\n0.Exit\n";
        cout<<"choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
                e.create();
                break;
        case 2:
                cout<<"\nThe inorder traversal is:";
                e.inorder(e.getroot());
                break;
        case 3:

                cout<<"\n\nThe Preorder treavrsal is:";
                e.preorder(e.getroot());
                break;
        case 4:
                cout<<"\n\nThe postorder traversal is:";
                e.postorder(e.getroot());
                break;
        case 5:
                break;
        }
    }while(ch != 5);
    return 0;
}

