/*Pizza */

#include <iostream>
using namespace std;
#define M 10
class pizza
{
    int order[M];
    int front,rear;
public:
    pizza()
    {
     front=rear=-1;
    }
    int qfull()
    {
     if((front==0)&&(rear==(M-1))||(front==(rear+1)%M))
         return 1;
     else
         return 0;
    }
    int qempty()
    {
        if(front==-1)
            return 1;
        else
            return 0;
    }
    void acceptOrder(int);
    void makePayment(int);
    void queue();
};
void pizza::acceptOrder(int item)
{
    if(qfull())
        cout<<"\nOrders are full \n";
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%M;
        }
        order[rear]=item;
    }
}

void pizza::makePayment(int n)
{
    int item;
    char ans;
    if(qempty())
        cout<<"\nOrder is not there\n";
    else
    {
      cout<<"\nDeliverd orders\n";
      for(int i=0;i<n;i++)
      {
          item=order[front];
          if(front==rear)
          {
               front=rear=-1;
          }
          else
          {
              front=(front+1)%M;
          }
          cout<<"\t"<<item;
      }
      cout<<"\nTotal : "<<n*250;
   }
}

void pizza::queue()
{
    int temp;
    if(qempty())
    {
        cout<<"\nThere is no pending order\n";
    }
    else
    {
        temp=front;
        cout<<"\nPending Order as follows\n";
        while(temp!=rear)
        {
            cout<<"\t"<<order[temp];
            temp=(temp+1)%M;
        }
        cout<<"\t"<<order[temp];
    }
}
int main()
{
    pizza p1;
    int ch,z,n;
    do
    {
     cout<<"\n\tPizza Parlor\n";
     cout << "\n\t#1.acceptOrder\n\t#2.makePayment\n\t#3.pendingOrders\n\tEnter u r choice: ";
     cin>>ch;
     switch(ch)
     {
      case 1:cout<<"\n\n\tMEnu ";
             cout<<"\n\t1.Extra large\n\t2.Onion Pizza\n\t3.Veg Pizza\n\t4.Extra Cheez";
             cout<<"\nPlease enter u r order : ";
             cin>>z;
             p1.acceptOrder(z);
             break;
      case 2:cout<<"\nQuantity : ";
             cin>>n;
             p1.makePayment(n);
             break;
      case 3:cout<<"\nPending Orders : \n";
             p1.queue();
             break;
     }
    }while(ch!=4);

    return 0;
}
	
	
	

