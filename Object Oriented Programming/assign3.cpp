/*
Assignment 3:

Implement a class CppArray which is identical to a one-dimensional array
except for the following:
1.It performs range checking.
2.It allows one to be assigned to another array through
the use of the assignment operator (e.g. cp1= cp2).
3.It supports a function that returns the size of the array.
4.It allows the reading or printing of array through the use of
cout and cin.

Done by: Pranav Shimpi
*/
#include<iostream>
using namespace std;
class CppArray
{
public:
	int arr[20],n;
	int size();
	friend ostream & operator<<(ostream&,CppArray&);
	friend istream & operator>>(istream&,CppArray&);

	void operator=(CppArray a)
	{
		for (int i = 0; i < a.n; ++i)
			arr[i]=a.arr[i];
		n=a.n;
	}

	int& operator[](int index)
	{
		if (index<0||index>=20)
		{
			cout<<"Array index is out of bounds\n";
			return arr[0];
		}
		return arr[index];
	}

};

int CppArray::size()
{
	return n;
}


ostream & operator<<(ostream &out,CppArray &a)
{
	for (int i = 0; i < a.n; ++i)
		out<<a.arr[i]<<" ";
	return out;
}

istream & operator>>(istream &in,CppArray &a)
{
	cout<<"Enter the size of the array ";
	in>>a.n;
	cout<<"Enter an array\n";
	for (int i = 0; i < a.n; ++i)
		in>>a.arr[i];
	return in;
}

int main()
{
	CppArray a,b;
	int x;
	cin>>a;
	b=a;
	cout<<"Original array is:\n"<<a<<"\n";
	cout<<"The copied array is:\n"<<b<<"\n";
	cout<<"The array size is: "<<a.size()<<"\n";
	cout<<"Enter an array index between 0 and 20 ";
	cin>>x;
	a[x]=67;//accessing element which is out of bounds of array
}

/*
Output:

Enter the size of the array 5
Enter an array
1
2
3
4
5
Original array is:
1 2 3 4 5
The copied array is:
1 2 3 4 5
The array size is: 5
Enter an array index between 0 and 20 45
Array index is out of bounds

*/
