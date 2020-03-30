/*
Assignment 2:

Write a program Implement a class Complex which represents
the Complex Number data type. Implement the following operations:
1.Constructor (including a default constructor).
2.Overloaded operator+ to add two complex numbers.
3.Overloaded operator* to multiply two complex numbers.
4.Overloaded << and >> to print and read Complex Numbers.

Done by: Pranav Shimpi
*/
#include<iostream>
using namespace std;

class complex
{
	float real;
	float img;
	public:
	friend complex operator+(complex,complex);
	friend complex operator-(complex,complex);
	friend complex operator*(complex,complex);
	friend complex operator/(complex,complex);
	friend ostream & operator<<(ostream&,complex&);
	friend istream & operator>>(istream&,complex&);

	complex()
	{
		real=0;
		img=0;
	}
	~complex(){}
};

complex operator+(complex c,complex d)
{
	complex temp;
	temp.real=d.real+c.real;
	temp.img=d.img+c.img;
	return temp;
}

complex operator-(complex c,complex d)
{
	complex temp;
	temp.real=c.real-d.real;
	temp.img=c.img-d.img;
	return temp;
}

complex operator*(complex c,complex d)
{
	complex temp;
	temp.real=c.real*d.real-c.img*d.img;
	temp.img=c.real*d.img+c.img*d.real;
	return temp;
}

complex operator/(complex c,complex d)
{
	complex temp;
	int mod=d.real*d.real+d.img*d.img;
	d.img=-1*d.img;
	temp=c*d;
	temp.real/=mod;
	temp.img/=mod;
	return temp;
}

ostream & operator << (ostream &out, complex &c)
{
    if(c.img>=0)
	    out<<c.real<<"+"<<c.img<<"i\n";
    else
	    out<<c.real<<c.img<<"i\n";
    return out;
}

istream & operator >> (istream &in,  complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.img;
    return in;
}

int main()
{
	complex c1,c2,c3;
	int ch;
	cin>>c1;
	cin>>c2;
	do
	{
		cout<<"Enter\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n0.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
				c3=c1+c2;
				cout<<"Addition: ";
				cout<<c3;
			break;
			case 2:
				c3=c1-c2;
				cout<<"Subtraction: ";
				cout<<c3;
			break;
			case 3:
				c3=c1*c2;
				cout<<"Multiplication: ";
				cout<<c3;
			break;
			case 4:
				c3=c1/c2;
				cout<<"Division: ";
				cout<<c3;
			break;
			default:
				cout<<"Invalid choice\n";
		}
	}while(ch!=0);
}

/*
Output:

Enter Real Part 2
Enter Imaginary Part 5
Enter Real Part 3
Enter Imaginary Part 8
Enter
1.Addition
2.Subtraction
3.Multiplication
4.Division
0.Exit
Enter your choice: 1
Addition: 5+13i
Enter
1.Addition
2.Subtraction
3.Multiplication
4.Division
0.Exit
Enter your choice: 2
Subtraction: -1-3i
Enter
1.Addition
2.Subtraction
3.Multiplication
4.Division
0.Exit
Enter your choice: 3
Multiplication: -34+31i
Enter
1.Addition
2.Subtraction
3.Multiplication
4.Division
0.Exit
Enter your choice: 4
Division: 0.630137-0.0136986i
Enter
1.Addition
2.Subtraction
3.Multiplication
4.Division
0.Exit
Enter your choice: 0

*/
