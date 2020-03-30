/*
 * Assignment No:07		SE B 	Roll No:41
 Problem Statement:Line Clipping
 */




#include<iostream>
#include<graphics.h>
using namespace std;

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xl,yl,xh,yh;

int getcode(int x,int y)
{
	int resultCode = 0;
	if(y > yh)
		resultCode |=TOP;
	if(y < yl)
		resultCode |=BOTTOM;
	if(x < xl)
		resultCode |=LEFT;
	if(x > xh)
		resultCode |=RIGHT;
	return resultCode;
}

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	setcolor(RED);

	cout<<"Enter top left and bottom right co-ordinates of window: ";
	cin>>xl>>yl>>xh>>yh;

	rectangle(xl,yl,xh,yh);

	int x1,y1,x2,y2;
	cout<<"Enter the co-ordinates of the line: ";
	cin>>x1>>y1>>x2>>y2;

	line(x1,y1,x2,y2);
	getch();

	int c1=getcode(x1,y1);
	int c2=getcode(x2,y2);

	int accept = 0;
	if(accept)
			line(x1,y1,x2,y2);


	while(1)
	{
		float m =(float)(y2-y1)/(x2-x1);


		if(c1==0 && c2==0)
		{
			accept = 1;
			break;
		}

		else if((c1 & c2)!=0)
		{
			break;
		}
		else
		{
			int x,y;
			int temp;


			if(c1==0)
				temp = c2;
			else
				temp = c1;

			if(temp & TOP)
			{
				x = x1+ (yh-y1)/m;
				y = yh;
			}
			else if(temp & BOTTOM)
			{
				x = x1+ (yl-y1)/m;
				y = yl;
			}
			else if(temp & LEFT)
			{
				x = xl;
				y = y1+ m*(xl-x1);
			}
			else if(temp & RIGHT)
			{
				x = xh;
				y = y1+ m*(xh-x1);
			}

			if(temp == c1)
			{
				x1 = x;
				y1 = y;
				c1 = getcode(x1,y1);
			}
			else
			{
				x2 = x;
				y2 = y;
				c2=getcode(x2,y2);
			}
		}
	}
	cout<<"After clipping:";
	setcolor(YELLOW);

	if(accept)
		line(x1,y1,x2,y2);

	getch();
	closegraph();
    return 0;
}



