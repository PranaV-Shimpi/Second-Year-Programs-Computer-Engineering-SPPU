// draw given pattern using DDA line drawing algorithm
#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;
class Line
{
	public:
		void DDA_line(float X1,float Y1,float X2,float Y2,int Color)
		{

			float Dx,Dy,Length,X,Y;
			Dx=abs(X2-X1);
			Dy=abs(Y2-Y1);

			if(Dx>Dy)
			{
				Length=Dx;
			}
			else
			{
				Length=Dy;
			}

			X=(X2-X1)/Length;
			Y=(Y2-Y1)/Length;

			for(int i=0;i<Length;i++)
			{
				putpixel(floor(X1),floor(Y1),Color);
				delay(5);
				X1=X1+X;
				Y1=Y1+Y;
			}
			delay(10);
		}//end of dda
};

int main()
{
	Line m;
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);

	m.DDA_line(100,100,300,100,YELLOW);
	delay(500);
	m.DDA_line(300,100,300,300,YELLOW);
	delay(500);
	m.DDA_line(300,300,100,300,YELLOW);
	delay(500);
	m.DDA_line(100,300,100,100,YELLOW);

	m.DDA_line(200,100,100,200,WHITE);
	delay(500);
	m.DDA_line(100,200,200,300,WHITE);
	delay(500);
	m.DDA_line(200,300,300,200,WHITE);
	delay(500);
	m.DDA_line(300,200,200,100,WHITE);
	delay(1000);

	m.DDA_line(150,150,250,150,GREEN);
	delay(500);
	m.DDA_line(250,150,250,250,GREEN);
	delay(500);
	m.DDA_line(250,250,150,250,GREEN);
	delay(500);
	m.DDA_line(150,250,150,150,GREEN);
	delay(1000);
	return 0;

}
