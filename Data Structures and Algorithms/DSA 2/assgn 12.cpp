/*
Assignment No: 12

PROBLEM STATEMENT:->
Implement c++ program for expression conversion as infix to postfix using stack based
on given conditions
    a) Operator and operand, both must be single character.
    b) Input infix expression must be in desired format.
    c) only '(' & ')' are used.

===============================================================================*/

#include <iostream>
using namespace std;
class stack
{
    char stk[25];
    int top;
public:
    stack()
{
        top=-1;
}
    void push(char ch);
    char pop();
    char stacktop() { return stk[top]; }
    int isfull();
    int isempty();
};
void stack:: push(char ch)
{
    if(isfull())
        cout<<"\n\n\tStack is full!!!";
    else
        stk[++top]=ch;
}

char stack:: pop()
{
    char ch='\0';
    if(top==-1)
        cout<<"\n\n\tStack is empty!!!";
    else
        ch=stk[top--];
    return ch;
}

int stack::isfull()
{
    if(top==24)
        return 1;
    else
        return 0;
}

int stack::isempty()
{if(top==-1)
    return 1;
else
    return 0;
}

class conversion
{
    char infix[25], postfix[25];
    stack stobj;
public:
    void readinfix();
    void intopost();
    int IEP(char ch);
    int ISP(char ch);
};

void conversion::readinfix()
{
    cout<<"\nEnter infix string:: ";
    cin>>infix;
    cout<<"\nYou entered infix string as:: "<<infix;
}

void conversion::intopost()
{
    int i,j=0,p1,p2;
    char ch,pch;
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];

        if(ch=='(')
            stobj.push(ch);

        else if(ch==')')
        {
            pch=stobj.pop();
            while(pch!='(')
            {
                postfix[j++]=pch;
                pch=stobj.pop();
            }
        }

        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            do
            {
                p1=IEP(ch);
                p2=ISP(stobj.stacktop());
                if(p1>p2)
                    stobj.push(ch);
                else
                {
                    pch=stobj.pop();
                    postfix[j++]=pch;
                }
            }while(p1<=p2);
        }

        else
            postfix[j++]=ch;
    }

    while(!stobj.isempty())
    {
        pch=stobj.pop();
        postfix[j++]=pch;
    }
    postfix[j]='\0';
    cout<<"\n\nPostfix form is = "<<postfix;
}


int conversion::IEP(char op)
{

    if(op=='+'||op=='-')
        return 1;
    if(op=='*'||op=='/')
        return 3;
    if(op=='(')
        return 5;
    else
        return 0;
}
int conversion::ISP(char op)
{
    if(op=='+'||op=='-')
        return 2;
    if(op=='*'||op=='/')
        return 4;
    else
        return 0;
}
int main()
{
    conversion obj;
    cout<<"!!Program to convert infix expression to postfix form!!\n";
    obj.readinfix();
    obj.intopost();
    return 0;
}






/*==============================================================================================OUTPUT==============================================================================================
        !!Program to convert infix expression to postfix form!!

        Enter infix string:: (A+B-C)*D

        You entered infix string as:: (A+B-C)*D

        Postfix form is = AB+C-D*
        */
