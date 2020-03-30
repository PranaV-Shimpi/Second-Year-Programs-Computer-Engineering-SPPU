/*
	BRESENHAM'S CIRCLE DRAWING ALGORITHM
*/
#include<iostream>
#include<graphics.h>
using namespace std;
class BRESENHAM_CIRCLE 
{
		int gd=DETECT,gm,R,X0,Y0,X1,Y1,X,Y,S; 
	public:
	void getDATA();
	void putDATA();
	void drawCIRCLE();
};
void BRESENHAM_CIRCLE::getDATA()
{
	cout<<"PLEASE ENTER THE DATA OF THE CIRCLE"<<endl<<"RADIUS = ";cin>>R;
	cout<<"CO-ORDINATES OF THE CENTER"<<endl<<"X = ";cin>>X1;cout<<"Y = ";cin>>Y1;
}
void BRESENHAM_CIRCLE::putDATA()
{
	cout<<"DRAWING A CIRCLE OF "<<endl<<"RADIUS = "<<R<<endl<<"At THE POINT "<<endl<<"X = "<<X1<<"\tY = "<<Y1<<endl;
}
void BRESENHAM_CIRCLE::drawCIRCLE()
{
	initgraph(&gd,&gm,NULL);
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	putpixel(X0,Y0,WHITE);
	S=3-2*R;
	X=0;Y=R;
	putpixel(X0+X1,Y0+Y1,WHITE);
	putpixel(X0+X1+X,Y0+Y1+Y,WHITE);
	while(X<Y)
	{
		if(S<=0)
		{
			S=S+4*X+6;
			X+=1;
		}
		else
		{
			S=S+4*(X-Y)+10;
			X+=1;
			Y-=1;
		}
		putpixel(X0+X1+X,Y0+Y1+Y,WHITE);
		putpixel(X0+X1+Y,Y0+Y1+X,WHITE);
		putpixel(X0+X1-X,Y0+Y1+Y,WHITE);
		putpixel(X0+X1+Y,Y0+Y1-X,WHITE);
		putpixel(X0+X1+X,Y0+Y1-Y,WHITE);
		putpixel(X0+X1-Y,Y0+Y1+X,WHITE);
		putpixel(X0+X1-X,Y0+Y1-Y,WHITE);
		putpixel(X0+X1-Y,Y0+Y1-X,WHITE);
	}
	putpixel(X0,Y0,WHITE);
	delay(10000);
	closegraph();
}

int main()
{
	cout<<"BRESENHAM'S CIRCLE DRAWING ALGORITHM"<<endl;
	BRESENHAM_CIRCLE CIRCLE;
	CIRCLE.getDATA();
	CIRCLE.putDATA();
	CIRCLE.drawCIRCLE();
	return 0;
}
/*
	CREATED BY 
		HRUSHIKESH JOSHI
		27-03-2019 2:02
*/
