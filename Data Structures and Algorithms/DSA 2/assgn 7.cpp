/*

Assignment No: 9

Problem statement : write a c++ program to ticket boking in cinemas using linked list
*/

#include<iostream>
using namespace std;

class node  // node
{
int info;
char stat;
node *next;
node *prev;

public:

node *getnext()
{
return next;
}

node *setnext(node *n)
{
next=n;
}

node *getprev()
{
return prev;
}

node *setprev(node *n)
{
prev=n;
}

int  getinfo()
{
return info;
}

int  setinfo(int n)
{
info=n;
}

char getstat()
{
return stat;
}

char setstat(char n)
{
stat=n;
}

};

class list
{
node *start;

public:
list()
{

start=NULL;

}

node *create(int);
void addl(int);
void display();
void book(int);
void cancel(int);
};

node* list::create(int no)
{
node *temp=new node;

temp->setinfo(no);
temp->setstat('A');
temp->setnext(NULL);
temp->setprev(NULL);
return temp;

}


void list::addl(int no)
{
node *temp,*n;
n=create(no);
if(start!=NULL)
{
  int flag=0;
  temp=start;
     do
    {
       if(temp->getinfo()==n->getinfo())
       {
           flag=1;
           return;
       }
       temp=temp->getnext();
    }while(temp!=start);

    if(flag==0)
    {
        temp=start;
        do
        {
            if(start->getinfo()>n->getinfo())
            {
                 (temp->getprev())->setnext(n);
                 n->setnext(temp);
                 n->setprev(temp->getprev());
                 temp->setprev(n);
                 start=n;
                 return;
            }
            else if(temp->getinfo()>n->getinfo())
            {
                 (temp->getprev())->setnext(n);
                 n->setnext(temp);
                 n->setprev(temp->getprev());
                 temp->setprev(n);
                 return;
            }
            else
            {
                temp=temp->getnext();

            }
        }while(temp!=start);

                (temp->getprev())->setnext(n);
                 n->setnext(temp);
                 n->setprev(temp->getprev());
                 temp->setprev(n);
    }

}

else
{
    start=n;
start->setprev(n);
start->setnext(n);

}


}


void list::display()
{
node *temp;
if(start==NULL)
{
    for(int i=1;i<=7;i++)
    cout<<"[A]\t";
}

else
{
temp=start;
for(int i=1;i<=7;i++)
{
if(temp->getinfo()==i)
{
    cout<<"["<<temp->getstat()<<"]"<<" \t";
    temp=temp->getnext();
}
else
{
    cout<<"[A]\t";
}
}
}

}

void list::book(int c)
{
    node *temp,*n;
    addl(c);
    temp=start;

    while(temp->getinfo()!=c)
    {
        temp=temp->getnext();
    }
    if(temp->getstat()=='A')
    {
        temp->setstat('B');
        cout<<"your booking was successful\n";
    }
    else
        cout<<"\nthe seat no. you selected is already booked\n";
}


void list::cancel(int c)
{
    node *temp;
    int flag=0;
    temp=start;
    if(start==NULL)
        cout<<"\nsorry you entered wrong booking details\n";
    else
    {
    do
    {
        if(temp->getinfo()==c)
        {
            flag=1;
            break;
        }
        temp=temp->getnext();
    }while(temp!=start);

    if(flag==1)
    {
        if(temp==temp->getnext())
        {
            start=NULL;
            delete temp;
            cout<<"cancellation \n";
        }

        else if(temp==start)
        {
            (temp->getprev())->setnext(temp->getnext());
            (temp->getnext())->setprev(temp->getprev());
            start=temp->getnext();
            delete temp;
            cout<<"cancellation  successful\n";
        }
        else
        {
            (temp->getprev())->setnext(temp->getnext());
            (temp->getnext())->setprev(temp->getprev());
            delete temp;
            cout<<"cancellation was successful\n";
        }
    }
    else
        cout<<"\nsorry you entered wrong booking details\n";
    }
}


int main()
{
    list l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    int i,r,c,row,col;
    //cout<<"\nenter the no. of rows and columns you want to place in cinema hall\n";
/*cin>>row>>col;
for(i=1;i<=row;i++)
list*/
list a[10]={l1,l2,l3,l4,l5,l6,l7,l8,l9,l10};


    int op;
    char n,y,ch;
    do
    {
        cout<<"\nenter your choice\n";
        cout<<" 1.Available seats\n 2.Book seats\n 3.Cancel ticket\n";
        cin>>op;
        switch(op)
        {
        case 1:
            {
                cout<<"\n\t A\t B\t C\t D\t E\t F\t G\n\n";
                for(i=0;i<10;i++)
                {
                    cout<<i+1<<"\t";

                        a[i].display();


                    cout<<"\n\n";

                }
                break;
            }

        case 2:
            {
                cout<<"\nenter the number of seats you want to book\n";
                int n;
                cin>>n;
                for(i=0;i<n;i++)
                {
                    cout<<"\nenter the seat no. \nenter row: ";
                    cin>>r;
                    cout<<"\n";
                    cout<<"\nenter column:";
                    cin>>c;
                    cout<<"\n";
                    a[r-1].book(c);

                }


                break;
            }
        case 3:
            {
                cout<<"\nenter your booking details\n";
                cout<<"\nenter your seat row no. and column no.";
                int ro,co;
                cin>>ro>>co;
                a[ro-1].cancel(co);
                break;
            }
        }
        cout<<"\ndo you want to continue y/n\n";
        cin>>ch;
    }while(ch!='n');

    return 0;
}

/*
output:

enter your choice
 1.Available seats
 2.Book seats
 3.Cancel ticket

1

	 A	 B	 C	 D	 E	 F	 G

1	[A]	[A]	[A]	[A]	[A]	[A]	[A]

2	[A]	[A]	[A]	[A]	[A]	[A]	[A]

3	[A]	[A]	[A]	[A]	[A]	[A]	[A]

4	[A]	[A]	[A]	[A]	[A]	[A]	[A]

5	[A]	[A]	[A]	[A]	[A]	[A]	[A]

6	[A]	[A]	[A]	[A]	[A]	[A]	[A]

7	[A]	[A]	[A]	[A]	[A]	[A]	[A]

8	[A]	[A]	[A]	[A]	[A]	[A]	[A]

9	[A]	[A]	[A]	[A]	[A]	[A]	[A]

10	[A]	[A]	[A]	[A]	[A]	[A]	[A]


do you want to continue y/n
y

enter your choice
 1.Available seats
 2.Book seats
 3.Cancel ticket
2

enter the number of seats you want to book
5

enter the seat no.
enter row: 1


enter column:2

your booking was successful

enter the seat no.
enter row: 2


enter column:1

your booking was successful

enter the seat no.
enter row:
2


enter column:3

your booking was successful

enter the seat no.
enter row: 2


enter column:4

your booking was successful

enter the seat no.
enter row: 1


enter column:5

your booking was successful

do you want to continue y/n
y

enter your choice
 1.Available seats
 2.Book seats
 3.Cancel ticket
3

enter your booking details

enter your seat row no. and column no.1
5
cancellation was successful

do you want to continue y/n
y

enter your choice
 1.Available seats
 2.Book seats
 3.Cancel ticket
1

	 A	 B	 C	 D	 E	 F	 G

1	[A]	[B] 	[A]	[A]	[A]	[A]	[A]

2	[B] 	[A]	[B] 	[B] 	[A]	[A]	[A]

3	[A]	[A]	[A]	[A]	[A]	[A]	[A]

4	[A]	[A]	[A]	[A]	[A]	[A]	[A]

5	[A]	[A]	[A]	[A]	[A]	[A]	[A]

6	[A]	[A]	[A]	[A]	[A]	[A]	[A]

7	[A]	[A]	[A]	[A]	[A]	[A]	[A]

8	[A]	[A]	[A]	[A]	[A]	[A]	[A]

9	[A]	[A]	[A]	[A]	[A]	[A]	[A]

10	[A]	[A]	[A]	[A]	[A]	[A]	[A]


do you want to continue y/n
n
*/









