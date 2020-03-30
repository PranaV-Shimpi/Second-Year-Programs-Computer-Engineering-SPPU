/* Assignment 3 :

Program to store two matrices and calculate:
1.Addition
2.Subtraction
3.Multiplication
4.Transpose
5.summation of diagonal elements
6.Check if matrix is upper triangular or not

Done by: Pranav Shimpi	
         SEA-53 */


#include<iostream>
using namespace std;
#define N 5

void display(int a[N][N],int n,int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout<<a[i][j]<<"\t";
		cout<<"\n";
	}
}

void read(int a[N][N],int n,int m)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin>>a[i][j];
}

void add(int a[N][N],int b[N][N],int c[N][N],int n,int m)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			c[i][j]=a[i][j]+b[i][j];
}
void sub(int a[N][N],int b[N][N],int c[N][N],int n,int m)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			c[i][j]=a[i][j]-b[i][j];
	
}
void mul(int a[N][N],int b[N][N],int c[N][N],int n,int m,int p,int q)
{

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < q; ++j)
		{
			c[i][j]=0;
			for (int k = 0; k < m; ++k)
				c[i][j]+=a[i][k]*b[k][j];
		}
	
}
void transpose(int a[N][N],int trans[N][N],int n,int m)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			trans[j][i]=a[i][j];
}
int uppertri(int a[N][N],int n,int m)
{
	int flag=1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if(a[i][j]!=0)
				flag=0;
	return flag;
}
int sumdiag(int a[N][N],int n,int m)
{
	int tot=0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if(i==j)
				tot+=a[i][j];
	return tot;
}

int main()
{
	int a[N][N],b[N][N],c[N][N],n,m,p,q;
	cout<<"Enter No. of rows and columns of matrix 1\n";
	cin>>n>>m;
	cout<<"Enter Matrix 1 :\n";
	read(a,n,m);
	cout<<"Enter No. of rows and columns of matrix 2\n";
	cin>>p>>q;
	cout<<"Enter Matrix 2 :\n";
	read(b,p,q);
	int ch,ans;
	do
	{
		cout<<"\n\n\t\t*MENU*\n\t#1.Add\n\t#2.Subtract\n\t#3.Multiply\n\t#4.Transpose\n\t#5.Upper triangular or not\n\t#6.Sum of diagonal elements\n\t#0.Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
			break;
			case 1:
			if(n==p && m==q)
			{
				add(a,b,c,n,m);
				display(c,n,m);
			}
			else
				cout<<"Addition is not possible\n";
			
			break;
			case 2:
			if(n==p && m==q)
			{
				sub(a,b,c,n,m);				
				display(c,n,m);
			}
			else
				cout<<"Subtraction is not possible\n";
			break;
			case 3:
			if(m==p)
			{
				mul(a,b,c,n,m,p,q);
				display(c,n,q);
			}
			else
				cout<<"Matrix 1 * Matrix 2 is not possible\n";
			
			break;
			case 4:
			transpose(a,c,n,m);
			display(c,m,n);
			break;
			case 5:
			if(n==m)
			{
				ans=uppertri(a,n,m);
				if(ans==1)
					cout<<"Matrix 1 is upper triangular\n";
				else
					cout<<"Matrix 1 is not upper triangular\n";
			}
			else
				cout<<"Matrix is not square matrix\n";
			break;
			case 6:
			if(n==m)
			{	
				ans=sumdiag(a,n,m);
			    cout<<"Sum of elements of main diagonal = "<<ans<<"\n";
			}		
			else
				cout<<"Matrix is not square matrix\n";
			break;
			default:
			cout<<"Wrong input\n";
			break;
		}
	} while (ch!=0);
	return 0;
}

