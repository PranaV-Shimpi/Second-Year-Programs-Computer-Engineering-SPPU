/*
Assignment No: 14

Problem Statement:->
 Pizza parlor accepting maximum M orders.Order are served in First come first serve basis.Order once placed cant be cancelled.
 write a c++ program to simulate the system using circular queue using array.
*/
#include <iostream>

using namespace std;

class cqueue
{
	private :
		int *arr ;
		int front, rear ;
		int MAX;
	public :
		cqueue(int maxsize = 10) ;
		void addq (int item) ;
		int delq() ;
		void display() ;
} ;
cqueue :: cqueue( int maxsize )
{
	MAX = maxsize ;
	arr = new int [ MAX ];                         //constructor initialize anarry of required size
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ )
		arr[i] = 0 ;
}
void cqueue :: addq ( int item )
{
	if ( ( rear + 1 ) % MAX == front )
	{
		cout<<"\nQueue is full";              //Adding an order of pizza
		return ;
	}
	rear = ( rear + 1 ) % MAX;
	arr[rear] = item ;
	if ( front == -1 )
		front = 0 ;
}
int cqueue :: delq( )
{
	int data ;
	if ( front == -1 )
	{
		cout << "\nQueue is empty" ;            //Serving an order
		return '\0';
	}
	data = arr[front] ;
	arr[front] = 0 ;
	if ( front == rear )
	{
		front = -1 ;
		rear = -1 ;
	}
	else
		front = ( front + 1 ) % MAX;
	return data ;
}
void cqueue :: display( )
{
	cout << endl ;
	for ( int i = 0 ; i < MAX ; i++ )

            switch(arr[i])
                      {
                        case 1:cout<<i+1<<".Onion pizza\n";
			break;                                       //Displaying all the orders

                        case 2:cout<<i+1<<".Tomato pizza\n";
			break;

                        case 3:cout<<i+1<<".Capsicum pizza\n";
			break;

                        case 4:cout<<i+1<<".chees burst pizza\n";
			break;
                     }

}
int main()
{
  cqueue a;
  int c,ch,data;


   do
{ cout<<"\n\nenter \n1:place order\n2:display orders\n3:To check order serving now\n4.exit";
    cin>>ch;
   switch(ch)
  {
              case 1:cout<<"\nenter type for pizza \n1:onion pizza\n2:Tomato pizza\n3:capsicum pizza\n4:chees burst pizza";
		        cin>>c;
                        a.addq(c);
			break;

              case 2:  cout << "\nPizza orders are: " ;
                         a.display();
                         break;

	      case 3: data=a.delq();
                      if(data)
                      {
                      cout<<"\nThe order serving now order no is:";
                        switch(data)
                      {
                        case 1:cout<<"Onion pizza\n";
			break;

                        case 2:cout<<"Tomato pizza\n";
			break;

                        case 3:cout<<"Capsicum pizza\n";
			break;

                        case 4:cout<<"chees burst pizza\n";
			break;
                     }
                    }
	                break;
             case 4:
			return(0);
			default:
			cout<<"\n invalid choice";


  }

}while(ch!=4);

}
/*
Output
enter
1:place order
2:display orders
3:To check order serving now
4.exit1

enter type for pizza
1:onion pizza
2:Tomato pizza
3:capsicum pizza
4:chees burst pizza1


enter
1:place order
2:display orders
3:To check order serving now
4.exit1

enter type for pizza
1:onion pizza
2:Tomato pizza
3:capsicum pizza
4:chees burst pizza1


enter
1:place order
2:display orders
3:To check order serving now
4.exit1

enter type for pizza
1:onion pizza
2:Tomato pizza
3:capsicum pizza
4:chees burst pizza2


enter
1:place order
2:display orders
3:To check order serving now
4.exit2

Pizza orders are:
1.Onion pizza
2.Onion pizza
3.Tomato pizza


enter
1:place order
2:display orders
3:To check order serving now
4.exit3

The order serving now order no is:Onion pizza


enter
1:place order
2:display orders
3:To check order serving now
4.exit3

The order serving now order no is:Onion pizza


enter
1:place order
2:display orders
3:To check order serving now
4.exit3

The order serving now order no is:Tomato pizza


enter
1:place order
2:display orders
3:To check order serving now
4.exit3

Queue is empty

enter
1:place order
2:display orders
3:To check order serving now
4.exit4
student@student-OptiPlex-3010:~/Desktop/Ashish$
*/
