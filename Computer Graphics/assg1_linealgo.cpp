#include<graphics.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class myline
{
	public:
		void draw_line(float x1,float y1,float x2,float y2);	//DDA
		void draw_line(int xx1,int yy1,int xx2,int yy2);	//Bresenham's
		int sign(int val);
};

void myline::draw_line(float x1,float y1,float x2,float y2)	//DDA
{
	float x,y,len,dx,dy;


	if(abs(x2-x1) > abs(y2-y1))
	{
		len=abs(x2-x1);
	}
	else
	{
		len=abs(y2-y1);
	}
	dx=(x2-x1)/len;

	dy=(y2-y1)/len;

	x=x1+0.5;
	y=y1+0.5;

	int i=1;
	while(i<=len)
	{
		putpixel(floor(x),floor(y),15);
		x=x+dx;
		y=y+dy;
		i++;
	}
}

int myline::sign(int val)
{
	if(val>0)
		return 1;
	else
		return -1;
}

void myline::draw_line(int xx1,int yy1,int xx2,int yy2)	//Bresenham's
{
	int x,y,s1,s2,dx,dy,temp,flag,g,max_x,max_y,mid_x,mid_y;

	max_x=getmaxx();
	max_y=getmaxy();
	mid_x=getmaxx()/2;
	mid_y=getmaxy()/2;
	line(0,mid_y,max_x,mid_y);
	line(mid_x,0,mid_x,max_y);

	x=xx1;
	y=yy1;

	dx=abs(xx2-xx1);
	dy=abs(yy2-yy1);
	s1=sign(xx2-xx1);
	s2=sign(yy2-yy1);

	if(dy > dx)
	{
		temp=dy;
		dy=dx;
		dx=temp;
		flag=1;
	}
	else
		flag=0;

	g=2*dy-dx;

	int i=1;
	for(i=1;i<=dx;i++)
	{
		putpixel(x+mid_x,mid_y-y,15);
		delay(10);
		while(g>0)
		{
			if(flag==1)
				x=x+s1;
			else
				y=y+s2;

			g=g-2*dx;
		}

		if(flag==1)
		{
			y=y+s2;
		}
		else
		{
			x=x+s1;
		}

		g=g+2*dy;
	}
}
int main()
{
	int gd,gm,ch;
	gd=DETECT;
	float x1,x2,y1,y2;
	int xx1,yy1,xx2,yy2;
	myline l;

	do
	{
		cout<<"\n1.DDA line drawing\n2.Bresenham's line drawing";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\nEnter cordinates of line :";
			cin>>x1>>y1>>x2>>y2;
			initgraph(&gd,&gm,NULL);
			l.draw_line(x1,y1,x2,y2); //DDA
			getch();
			closegraph();
			break;
			case 2:
			cout<<"\nEnter cordinates of line :";
			cin>>xx1>>yy1>>xx2>>yy2;
			initgraph(&gd,&gm,NULL);
			l.draw_line(xx1,yy1,xx2,yy2); //Bresenham's
			getch();
			closegraph();
			break;
		}
	}while(ch<3);

	return 0;
}
