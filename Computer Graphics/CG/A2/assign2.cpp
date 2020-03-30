/*
Assignment No: 02		
SE B	Roll no:41
Title: Write a C++ program to draw a circle using DDA algorithm and Bresenham's Algorithm. Inherit pixel class and use function
       Overloading.
 */

#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class Pixel
{
	float x,y,col;
public:
	void drawPixel(float x,float y,float col)
	{
		putpixel(x,y,col);
	}
};

class Circle : public Pixel
{
public:
	void mh(int *xi,int *yi,int *dI)
	{
		*xi=*xi+1;
		*dI=*dI+(2*(*xi))+1;
	}

	void mv(int *xi,int *yi,int *dI)
	{
		*yi=*yi-1;
		*dI=*dI-(2*(*yi))+1;
	}

	void md(int *xi,int *yi,int *dI)
	{
		*xi=*xi+1;
		*yi=*yi-1;
		*dI=*dI+(2*(*xi))-(2*(*yi))+2;
	}




	void drawCircle(int x,int y,int r)
	{
		int xi,yi,dI,D;
		xi=0;
		yi=r;
		dI=2*(1-r);

		while(yi>=0)
		{
			drawPixel(x+xi,y+yi,RED);
			drawPixel(x-xi,y+yi,RED);
			drawPixel(x+xi,y-yi,RED);
			drawPixel(x-xi,y-yi,RED);
			if(dI<0)
			{
				D=(2*dI)+(2*yi)-1;
				if(D<0)
					mh(&xi,&yi,&dI);
				else
					md(&xi,&yi,&dI);
			}
			else if(dI>0)
			{
				D=(2*dI)-(2*xi)-1;
				if(D<0)
					md(&xi,&yi,&dI);
				else
					mv(&xi,&yi,&dI);
			}
			else
				md(&xi,&yi,&dI);
		}

	}

	/*float dda(float x,float y,float r)
	{
		float x1,y1,xi,yi,v,e;
		x1=0;
		y1=r;
		xi=x1;
		yi=y1;

		int i=0;
		do
		{
			v=pow(2,i);
			i++;
		}while(v<r);

		e=((1/pow(2,i-1)));
		do
		{
			xi=xi+e*yi;
			yi=yi-e*xi;
			putpixel(x+xi,y+yi,2);
		}while(((yi-y1)<e) || ((x1-xi>e)));
	}*/

};

int main()
{
	int gd,gm;
	gd=DETECT;
	Circle c;
	initgraph(&gd,&gm,NULL);
	c.drawCircle(100,100,55);
	//c.dda(150,150,20);
	getch();
	closegraph();
	return 0;
}


