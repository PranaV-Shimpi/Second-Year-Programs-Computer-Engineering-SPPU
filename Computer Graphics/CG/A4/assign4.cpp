/*
 * Assignment No: 04		SE B	Roll no:41
Title: Write a C++ program to perform scanline filling in polygon.
 */


#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class pixel
{
	public:
	void setpixel(int x, int y, int color)
	{
		putpixel(x, y, color);
	}
};

class polygon:public pixel
{
	public:
	int arrx[10];
	int arry[10];
	int n,halfx,halfy;

	void readpoly()
	{
		int i;
		cout<<"\nEnter the no of edges ";
		cin>>n;
		cout<<"\nEnter the vertices : ";
		//read verties
		for(i=0;i<n;i++)
			{
				cout<<"\n";
				cin>>arrx[i]>>arry[i];
			}
		cout<<"\n";

	}
	void displaypoly()
	{
		int i;

		for(i=0;i<n-1;i++)
			{
				//line(arrx[i],arry[i],arrx[i+1],arry[i+1]);
				line(arrx[i]+halfx, halfy-arry[i] , halfx+arrx[i+1] , halfy-arry[i+1]);   //for displaying in quadrants
				delay(20);
			}
		//line(arrx[n-1],arry[n-1],arrx[0],arry[0]);
		line(halfx+arrx[n-1],halfy-arry[n-1],halfx+arrx[0],halfy-arry[0]);			//for displaying in quadrants
	}
	//for filling color
	void scanline()									//for filling color in quadrant replace arrx= halfx+arrx and arry=halfy-arry
	{
		int ymax, ymin, cnt, dx, dy, y;
		float m[10];
		float xint[10];
		int temp;
		ymax=0;
		ymin=9999;
		for(int i=0;i<n;i++)
		{
			if(halfy-arry[i]>ymax)
				ymax=halfy-arry[i];
			if(halfy-arry[i]<ymin)
				ymin=halfy-arry[i];

			dx=halfx+arrx[i+1]-(halfx+arrx[i]);
			dy=(halfy-arry[i+1])-(halfy-arry[i]);
			if(dx==0)
				m[i] = 0;
			if(dy==0)
				m[i] = 1;
			if((dx!=0) && (dy!=0))
				m[i] = dx/dy;
		}
		for(y=ymax;y>ymin;y--)
		{
			cnt = 0;
			for(int i=0;i<n;i++)
			{
				if(((halfy-arry[i]>y) && (halfy-arry[i+1]<=y))||((halfy-arry[i]<=y) && (halfy-arry[i+1]>y)))
					{
						xint[cnt] =halfx+ arrx[i] + (m[i]*(y-(halfy-arry[i])));
						cnt++;
					}
			}
			for(int k=0;k<cnt-1;k++)
			{
				for(int i=0;i<cnt-1;i++)
				{
					if(xint[i]>xint[i+1])
					{
						temp = xint[i];
						xint[i] = xint[i+1];
						xint[i+1] = temp;
					}
				}
			}
			for(int i=0;i<cnt-1;i++)
			{
				line(xint[i],y,xint[i+1],y);
					delay(10);
			}
		}
	}
	void quadrant()
	{

		int maxx=getmaxx();
		int maxy=getmaxy();
		halfx=(maxx)/2;
		halfy=(maxy)/2;
		line(halfx,0,halfx,maxy);
		line(0,halfy,maxx,halfy);

	}
};

int main()
{
	polygon l1;
	l1.readpoly();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	l1.quadrant();
	l1.displaypoly();
	setcolor(15);
	l1.scanline();

	getch();
	closegraph();
}
