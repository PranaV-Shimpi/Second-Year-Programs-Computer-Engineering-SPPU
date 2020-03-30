//TBST

#include <stack>
#include <iostream>
#include <stdlib.h>
using namespace std;

class tbt_node
{  
  public:
    int data;
    tbt_node *left;
    tbt_node *right;
    int lbit;
    int rbit;
    tbt_node()
    {
        left=right=NULL;
        lbit=rbit=1;
        data=0;
    }

};
class threadedBT
{
  public:
    tbt_node *head;
    tbt_node *root;
    int flag;
    threadedBT()
    {
        root=NULL;
        head=new tbt_node;
        head->lbit=0;
        head->rbit=1;
        head->data=0;
        flag=0;
    }
    bool create(int value);
    bool insert(int value);
    void preorder();
    void inorder();
};
bool threadedBT::create(int value)
{
    if(root==NULL)
    {
        tbt_node*create_root;
        create_root=new tbt_node;
        create_root->data=value;
        create_root->left=create_root->right=head;
        root=create_root;
        return 1;
    }
    else
    {
        return 0;
    }
}
bool threadedBT::insert(int value)
{
    if(root==NULL)
    {
        int check;
        cout<<"\nCreating root first";
        check=create(value);
        if(check==1)
            cout<<"\nRoot created successfully!";
        else
            cout<<"\nRoot already exists!";
    }
    else
    {
        tbt_node*free,*track;
        free=new tbt_node;
        free->data=value;
        track=root;
        while(1)
        {
            if(track->data>free->data)
            {
                if(track->lbit==1)
                {
                    free->left=track->left;
                    track->left=free;
                    free->right=track;
                    track->lbit=0;
                    return 1;
                }
                else
                {
                    track=track->left;
                }
            }
            if(track->data<free->data)
            {
                if(free->rbit==1)
                {
                    free->right=track->right;
                    track->right=free;
                    track->rbit=0;
                    free->left=track;
                    return 1;
                }
                else
                {
                    track=track->right;
                }
            }
        }//end of while(1)
        
    }
}
void threadedBT::preorder()
{
    tbt_node*track;
    track=root;
    flag=0;
    while(track!=head)
    {
        if(flag==0)
            cout<<track->data;
        if(track->lbit==0 && flag==0)
        {
            track=track->left;
        }
        else
        {
            if(track->rbit==0)
            {
                track=track->right;
                flag=0;
            }
            else
            {
                track=track->right;
                flag=1;
            }
        }
    }//end of while
}

void threadedBT::inorder()
{
    tbt_node*track;
    track=root;
    flag=0;
    while(track!=head)
    {   
        if(track->lbit==0 && flag==0)
        {
            track=track->left;
        }
        else
        {
            cout<<track->data;
            if(track->rbit==0)
            {
                track=track->right;
                flag=0;
            }
            else
            {
                track=track->right;
                flag=1;
            }
        }
    }//end of while
}
int main()
{
    threadedBT t;
    int value,n,check,ch;
    do
    {
        cout<<"\n***********Threaded Binary Tree***********";
        cout<<"\n1.Create root node";
        cout<<"\n2.Insert nodes";
        cout<<"\n3.Preorder traversal";
        cout<<"\n4.Inorder traversal";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"\nEnter data for root:";
                    cin>>value;
                    check=t.create(value);
                    if(check==1)
                        cout<<"\nRoot created successfully!\n";
                    else
                        cout<<"\nRoot already exists\n!";
                    break;

            case 2: cout<<"\nEnter no. of nodes:";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        cout<<"\nEnter data:";
                        cin>>value;
                        check=t.insert(value);
                        if(check==1)
                            cout<<"\nData inserted successfully!\n";
                        else
                            cout<<"\nData already exists!\n";
                    }
                    break;

            case 3: cout<<"\nPreorder:";
                    t.preorder();
                    break;

            case 4: cout<<"\nInorder:";
                    t.inorder();
                    break;
            case 5: break;
        }
    }while(ch=5);
return 0;
}
