/*
 * floodfill.cpp
 *
 *  Created on: 22-Mar-2017
 *      Author: student
 */
#include<iostream>
#include<graphics.h>
using namespace std;

class floodFill
{
	int a[20][20], m;
public:
	void init();
	void close();
	void accept();
	void flood(int, int, int, int);

};

void floodFill::init()
{
    int gd, gm, i;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    for(i=0;i<m-1;i++)
    {

        line(a[i][0], a[i][1], a[i+1][0], a[i+1][1]);
    }

    line(a[0][0], a[0][1], a[i][0], a[i][1]);

}

void floodFill::close()
{
    getch();
    closegraph();
}

void floodFill::flood(int seedX, int seedY, int fillColor, int bgColor)
{
	if(getpixel(seedX, seedY)==bgColor)
	{
		delay(2);
		putpixel(seedX, seedY, fillColor);
		flood(seedX+1, seedY, fillColor, bgColor);
		flood(seedX-1, seedY, fillColor, bgColor);
		flood(seedX, seedY+1, fillColor, bgColor);
		flood(seedX, seedY-1, fillColor, bgColor);
	}
}

void floodFill::accept()
{
cout<<"\n" ;
 cout<<"Enter the Number Of Edges:";
    cin>>m;
    cout<<"\nEnter The Coordinates of vertices (x y) :";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j>=2)
            a[i][j]=1;
            else
            cin>>a[i][j];
        }
    }
}

int main()
{
	floodFill f;
	f.accept();
	f.init();
	/*line(10, 10, 100, 10);
	line(50, 60, 100, 10);
	line(10, 10, 50, 60);*/
	f.flood(40, 40, 7, 0);
	f.close();

}



