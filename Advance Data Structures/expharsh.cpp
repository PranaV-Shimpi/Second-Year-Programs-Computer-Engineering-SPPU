#include<iostream>
#include<ctype.h>
#include<stack>
using namespace std;
class node
{
public:
    char data;
    node *left,*right;
};
class stack1
{
    public:
    node * a[20];
    int top;

    stack1()
    {
        top=-1;
    }
    void push(node *x)
    {

        if(!isfull())
        {
            top++;
            a[top]=x;
        }

    }
    int isempty()
    {
        if(top==-1)
           return 1;
        return 0;
    }
    int isfull()
    {
        if(top==19)
            return 1;
        return 0;
    }
    node *pop()
    {
        node *temp;
        temp=a[top];
        top--;
        return temp;
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
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    node* getroot();
};
void exptree::create()
{
    int i;
    node* stack<int>s;
    char z[20];
    char c;
    node *p,*t1,*t2;
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
    while(z[i]!=NULL)
    {
        c=z[i];
        p=new node;
        p->left=p->right=NULL;
        p->data=c;
        if(c >= 'a' && c <= 'z')
        {
            s.push(p);
        }
        else
        {
            t2=s.pop();
            t1=s.pop();
            p->left=t1;
            p->right=t2;
            s.push(p);
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


