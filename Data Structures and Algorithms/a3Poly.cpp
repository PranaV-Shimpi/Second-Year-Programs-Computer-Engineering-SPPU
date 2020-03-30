/*
Assignment 3

Program to store polynomial of single variable
and write functions to:
a) evaluate
b) add two polynomials
c) multiply two polynomials

Done by: Pranav Shimpi
 */
#include<iostream>
#include<math.h>
using namespace std;

struct term
{
	float coef;
	int exp;
};

class polynomial
{
	term p[20];
	int n;
	public:
	void read();
	void display();
	float evaluate();
	polynomial add(polynomial);
	polynomial mul(polynomial);
};

void polynomial::read()
{
	cout<<"Enter no. of terms ";
	cin>>n;
	cout<<"Enter the coefficient and exponent for each term:\n";
	for(int i=0;i<n;i++)
		cin>>p[i].coef>>p[i].exp;
}

void polynomial::display()
{
	for(int i=0;i<n-1;i++)
		cout<<p[i].coef<<"x^"<<p[i].exp<<"+";
	cout<<p[n-1].coef<<"x^"<<p[n-1].exp<<"\n\n";
}

float polynomial::evaluate()
{
	float tot=0,x;
	cout<<"Enter value of x ";
	cin>>x;
	for(int i=0;i<n;i++)
		tot+=p[i].coef*pow(x,p[i].exp);
	return tot;
}

polynomial polynomial::add(polynomial p2)
{
	int i=0,j=0,k=0;
	polynomial temp;
	while(i<n&&j<p2.n)
	{
		if(p[i].exp>p2.p[j].exp)
		{
			temp.p[k].coef=p[i].coef;
			temp.p[k].exp=p[i].exp;
			i++;k++;
		}
		else if(p[i].exp<p2.p[j].exp)
		{
			temp.p[k].coef=p2.p[j].coef;
			temp.p[k].exp=p2.p[j].exp;
			j++;k++;
		}
		else
		{
			temp.p[k].coef=p[i].coef+p2.p[j].coef;
			temp.p[k].exp=p[i].exp;
			i++;j++;k++;
		}
	}
	//to put remaining terms
	while(i<n)
	{
		temp.p[k].coef=p[i].coef;
		temp.p[k].exp=p[i].exp;
		i++;k++;
	}
	while(j<p2.n)
	{
		temp.p[k].coef=p2.p[j].coef;
		temp.p[k].exp=p2.p[j].exp;
		j++;k++;
	}
	temp.n=k;
	return temp;
}

polynomial polynomial::mul(polynomial p2)
{
	polynomial temp;
	int i=0,j=0,k=0,x=0,flag=0;
	for (i = 0; i <n; i++)
	{
		for (j = 0; j < p2.n; j++)
		{
			float c=p[i].coef*p2.p[j].coef;
			int e=p[i].exp+p2.p[j].exp;
			flag=0;
			for (x = 0; x < k; x++)
			{
				if(temp.p[x].exp==e)
				{
					flag=1;
					break;
				}
			}
			if (flag==0)
			{
				temp.p[k].coef=c;
				temp.p[k].exp=e;
				k++;
			}
			else
				temp.p[x].coef+=c;
		}
	}
	temp.n=k;
	return temp;
}

int main()
{
	polynomial p1,p2,p3;
	p1.read();
	p2.read();
	int ch;
	do
	{
		cout<<"Enter\n1.Addition\n2.Multiplication\n3.Evaluate\n0.Exit\n";
        cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
			p3=p1.add(p2);
			cout<<"The addition is:\n";
			p3.display();
			break;
			case 2:
			p3=p1.mul(p2);
			cout<<"The multiplication is:\n";
			p3.display();
			break;
			case 3:
			cout<<"The value of the polynomial is "<<p1.evaluate()<<"\n\n";
			break;
			default:
			cout<<"Invalid input\n";
		}
	} while (ch!=0);
}

/*

Enter no. of terms 3
Enter the coefficient and exponent for each term:
3
3
2
1
5
0
Enter no. of terms 2
Enter the coefficient and exponent for each term:
5
2
4
1
Enter
1.Addition
2.Multiplication
3.Evaluate
0.Exit
1
The addition is:
3x^3+5x^2+6x^1+5x^0

Enter
1.Addition
2.Multiplication
3.Evaluate
0.Exit
2
The multiplication is:
15x^5+12x^4+10x^3+33x^2+20x^1

Enter
1.Addition
2.Multiplication
3.Evaluate
0.Exit
3
Enter value of x 2
The value of the polynomial is 33

Enter
1.Addition
2.Multiplication
3.Evaluate
0.Exit
0

*/
