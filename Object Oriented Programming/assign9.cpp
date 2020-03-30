/*
Assignment 9:

Write a C++ program using command line arguments to search for a word in a file and repla
ce
it with the specified word. The usage of the program is shown below.
$  change <old word> <new word> <file name>

Done by: Pranav Shimpi
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class filestr
{
public:
	char str[20],cstr[20],rstr[20];
	filestr()
	{
		strcpy(str,"");
		strcpy(cstr,"");
		strcpy(rstr,"");
	}
	~filestr(){}
	void create();
	void display();
	void search();
};

void filestr::create()
{
	cout<<"Enter data (write end to terminate)\n";
	ofstream out(str);
	cin.ignore();
	while(true)
	{
		cin.getline(str,20);
		if(!strcmp(str,"end"))
			break;
		else
			out<<str<<"\n";
	}
	out.close();
}

void filestr::search()
{
	fstream file(str,ios::in|ios::out);
	while(file>>str)
	{
		if (!strcmp(str,cstr))
		{
			if(!file.eof())
				file.clear();
			int pos=-1*strlen(str);
			file.seekp(pos,ios::cur);
			file<<""<<rstr<<"";
		}
	}
	file.close();
}

void filestr::display()
{
	ifstream infile(str);
	while(infile.getline(str,20))
		cout<<str<<"\n";
	infile.close();
}

int main(int argc, char const *argv[])
{
	filestr s1;
	strcpy(s1.cstr,argv[2]);
	strcpy(s1.rstr,argv[3]);
	int ch;
	do
	{
		strcpy(s1.str,argv[1]);
		cout<<"\n************MENU************";
		cout<<"\n1.Create\n2.Display\n3.Search\n0.Exit\nEnter choice ";
		cin>>ch;
		switch(ch)
		{
			case 0:break;
			case 1:
				s1.create();
				s1.display();
				break;
			case 2:
				s1.display();
				break;
			case 3:
				s1.search();
				s1.display();
				break;
			default:
				cout<<"Invalid choice\n";
		}

	}while(ch!=0);
	return 0;
}

/*
Output:

F:\oopedited>assign11 ttry.txt qwe abc

************MENU************
1.Create
2.Display
3.Search
0.Exit
Enter choice 1
Enter data (write end to terminate)
qwe qwe
asd qwe
qwe fhh
end

************MENU************
1.Create
2.Display
3.Search
0.Exit
Enter choice 2
qwe qwe
asd qwe
qwe fhh

************MENU************
1.Create
2.Display
3.Search
0.Exit
Enter choice 3

************MENU************
1.Create
2.Display
3.Search
0.Exit
Enter choice 2
qweabce
asd qwabcqabcfhh

************MENU************
1.Create
2.Display
3.Search
0.Exit
Enter choice 0
*/
