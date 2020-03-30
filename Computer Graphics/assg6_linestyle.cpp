#include<graphics.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class myline
{
	public:
		void solid_line(float x1,float y1,float x2,float y2);	//DDA
		void thick_line(float x1,float y1,float x2,float y2,int w);
		void dot_line(float x1,float y1,float x2,float y2);
		void dash_line(float x1,float y1,float x2,float y2);
		void dash_dot_line(float x1,float y1,float x2,float y2);		
};

void myline::solid_line(float x1,float y1,float x2,float y2)	//DDA
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

void myline::thick_line(float x1,float y1,float x2,float y2,int w)
{
	float x,y,len,dx,dy,wy,wx,xd,yd;
	int i;
	xd=x2-x1;
	yd=y2-y1;
	float m=(yd/xd);
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
	if(yd>xd)		  //steep slope
	{
		wx=((w-1)/2)*((sqrt((xd*xd)+(yd*yd))/abs(y2-y1)));
		for(i=1;i<=len;i++)
		{
			putpixel(floor(x),floor(y),15);
			for(int j=1;j<=wx;j++)
			{
				putpixel(floor(x+j),floor(y),15);
				putpixel(floor(x-j),floor(y),15);
				
			}
			x=x+dx;
			y=y+dy;
			i++;
		}
	}
	else 		//gentle slope
	{
		wy=((w-1)/2)*((sqrt((xd*xd)+(yd*yd)))/abs(x2-x1));
		for(i=1;i<=len;i++)
		{
			putpixel(floor(x),floor(y),15);
			for(int j=1;j<=wy;j++)
			{
				putpixel(floor(x),floor(y+j),15);
				putpixel(floor(x),floor(y-j),15);	
			}
			x=x+dx;
			y=y+dy;
			i++;
		}
	}
}

void myline::dot_line(float x1,float y1,float x2,float y2)
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
		if((i%5)==0)
		{
			putpixel(floor(x),floor(y),15);
		}
			x=x+dx;
			y=y+dy;
			i++;
	}
}

void myline::dash_line(float x1,float y1,float x2,float y2)
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
		if((i%10)!=0)
		{
			putpixel(floor(x),floor(y),15);
		}
			x=x+dx;
			y=y+dy;
			i++;
	}
}

void myline::dash_dot_line(float x1,float y1,float x2,float y2)
{
	int cnt=0;
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
		if(cnt<=10)
		{
			putpixel(floor(x),floor(y),15);
			
		}
		else if(cnt==12)
		{
			putpixel(floor(x),floor(y),15);
		}
		else if(cnt==14)
			cnt=0;
			x=x+dx;
			y=y+dy;
			i++;
			cnt++;
	}
}
int main()
{
	int gd,gm,ch,w;
	float x1,x2,y1,y2;
	myline l;
	
	do
	{
		cout<<"\n1.solid line\n2.Thick line\n3.dotted line\n4.dash line\n5.dash dotted line";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\nEnter cordinates of line :";
			cin>>x1>>y1>>x2>>y2;
			initgraph(&gd,&gm,NULL);
			l.solid_line(x1,y1,x2,y2); 
			break;
			case 2:
			cout<<"\nEnter cordinates of line :";
			cin>>x1>>y1>>x2>>y2;
			cout<<"\nEnter thickness of line";
			cin>>w;
			initgraph(&gd,&gm,NULL);
			l.thick_line(x1,y1,x2,y2,w); 
			break; 
			case 3:
			cout<<"\nEnter cordinates of line :";
			cin>>x1>>y1>>x2>>y2;
			initgraph(&gd,&gm,NULL);
			l.dot_line(x1,y1,x2,y2); 
			break; 
			case 4:
			cout<<"\nEnter cordinates of line :";
			cin>>x1>>y1>>x2>>y2;
			initgraph(&gd,&gm,NULL);
			l.dash_line(x1,y1,x2,y2); 
			break;
			case 5:
			cout<<"\nEnter cordinates of line :";
			cin>>x1>>y1>>x2>>y2;
			initgraph(&gd,&gm,NULL);
			l.dash_dot_line(x1,y1,x2,y2); 
			break;
		}
	}while(ch<6);
	getch();
	closegraph();
	return 0;
}
