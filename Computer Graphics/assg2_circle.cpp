#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class mycircle
{
	public:
		int xi,yi, di,delta;
		void draw_circle(int,int,int);
		void mH();
		void mD();
		void mV();
};

void mycircle::draw_circle(int xc,int yc,int r)
{
	int max_x,max_y,mid_x,mid_y;

	xi=0;
	yi=r;
	di=2*(1-r);
	max_x=getmaxx();
	max_y=getmaxy();
	mid_x=max_x/2;
	mid_y=max_y/2;
	line(0,mid_y,max_x,mid_y);
	line(mid_x,0,mid_x,max_y);
	while(yi>=0)
	{
		putpixel(mid_x+(xc-xi),mid_y-(yc+yi),15);
		putpixel(mid_x+(xi+xc),mid_y-(yc+yi),15);
		putpixel(mid_x+(xi+xc),mid_y-(yc-yi),15);
		putpixel(mid_x+(xc-xi),mid_y-(yc-yi),15);
		delay(10);
		if(di<0)
		{
			delta=(2*di)+(2*yi)-1;
			if(delta<=0)
				mH();
			else
				mD();
		}
		else if(di>0)
		{
			delta=(2*di)-(2*xi)-1;
			if(delta<=0)
				mD();
			else
				mV();
		}
		else if(di==0)
			mD();
	}
}
void mycircle::mH()
{
	xi=xi+1;
	di=di+(2*xi)+1;
}

void mycircle::mV()
{
	yi=yi-1;
	di=di-(2*yi)+1;
}	

void mycircle::mD()
{
	xi=xi+1;
	yi=yi-1;
	di=di+(2*xi)-(2*yi)+2;	
}

int main()
{
	int gd,gm,x,y,r;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	mycircle c;
	cout<<"\nEnter co-ordinates of center";
	cin>>x>>y;
	cout<<"\nEnter radius";
	cin>>r;
	c.draw_circle(x,y,r);
	getch();
	closegraph();
	return 0;
}
