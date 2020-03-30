/*
 *Assignment No: 5		SE B	Roll No:41
 Problem Statement: Geometric Figure
 */

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;

int sign(float x)
	{
		if(x<0)
			return -1;
		if(x>0)
			return 1;
		else
			return 0;
	}


void drawline(int x1, int y1,int x2, int y2)
	{
		int i,exchange,x,y,s1,s2,e;
		int dx,dy,temp;
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		x=x1;
		y=y1;
		e=(2*dy)-dx;
		s1=sign(x2-x1);
		s2=sign(y2-y1);
		if(dy>dx)
		{
			temp=dx;
			dx=dy;
			dy=temp;
			exchange=1;
		}
		else
			exchange=0;
		i=1;
		while(i<=dx)
		{
				putpixel(x,y,3);
				while(e>=0)
				{
					if(exchange==1)
						x=x+s1;
					else
						y=y+s2;
					e=e-(2*dx);
				}
				if(exchange==1)
					y=y+s2;
				else
					x=x+s1;
				e=e+2*dy;
				i++;
		}
		//delay(2000);
}
void mh(int *xi,int *yi,int *di)
{
	*xi=*xi+1;
	*di=*di+(2*(*xi))+1;
}

void md(int *xi,int *yi,int *di)
{
	*xi=*xi+1;
	*yi=*yi-1;
	*di=*di+(2*(*xi))-(2*(*yi))+2;
}

void mv(int *xi,int *yi,int *di)
{
	*yi=*yi-1;
	*di=*di-(2*(*yi))+1;
}

void drawCircle(int x,int y,int r)
{
	int xi,yi,dI,limit=0,D;
	xi=0;
	yi=r;
	dI=2*(1-r);
	while(yi>=limit)
	{
		putpixel(x+xi,y+yi,10);
		putpixel(x-xi,y-yi,10);
		putpixel(x-xi,y+yi,10);
		putpixel(x+xi,y-yi,10);
		if(dI<0)
		{
			D=(2*dI)+(2*yi)-1;
			if(D<=0)
				mh(&xi,&yi,&dI);
			else
				md(&xi,&yi,&dI);
		}
		else if(dI>0)
		{
			D=(2*dI)-(2*xi)-1;
			if(D<=0)
				md(&xi,&yi,&dI);
			else
				mv(&xi,&yi,&dI);
		}
		else if(dI==0)
			md(&xi,&yi,&dI);
	}
}

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	drawline(100,250,300,250);
	delay(2000);
	drawline(100,250,200,76);
	delay(2000);
	drawline(200,76,300,250);
	delay(2000);
	drawCircle(200,193,57);
	delay(2000);
	drawline(143,193,200,136);
	delay(2000);
	drawline(200,136,257,193);
	delay(2000);
	drawline(200,250,257,193);
	delay(2000);
	drawline(200,250,143,193);
	getch();
	delay(2000);
	closegraph();


	return 0;
}

