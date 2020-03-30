/*
	MIDPOINT CIRCLE DRAWING ALGORITHM
*/
#include<iostream>
#include<graphics.h>
using namespace std;
class MIDPOINT 
{
		int gd=DETECT,gm,R,X0,Y0,X1,Y1,X,Y,P; 
	public:
	void getDATA();
	void putDATA();
	void drawCIRCLE();
};
void MIDPOINT::getDATA()
{
	cout<<"PLEASE ENTER THE DATA OF THE CIRCLE"<<endl<<"RADIUS = ";cin>>R;
	cout<<"CO-ORDINATES OF THE CENTER"<<endl<<"X = ";cin>>X1;cout<<"Y = ";cin>>Y1;
}
void MIDPOINT::putDATA()
{
	cout<<"DRAWING A CIRCLE OF "<<endl<<"RADIUS = "<<R<<endl<<"At THE POINT "<<endl<<"X = "<<X1<<"\tY = "<<Y1<<endl;
}
void MIDPOINT::drawCIRCLE()
{
	initgraph(&gd,&gm,NULL);
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	putpixel(X0,Y0,WHITE);
	P=1-R;
	X=0;Y=R;
	putpixel(X0+X1,Y0+Y1,WHITE);
	putpixel(X0+X1+X,Y0+Y1+Y,WHITE);
	while(X<Y)
	{
		if(P<=0)
		{
			P=P+2*X+1;
			X+=1;
		}
		else
		{
			P=P+2*X-2*Y+1;
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
	cout<<"MIDPOINT CIRCLE DRAWING ALGORITHM"<<endl;
	MIDPOINT CIRCLE;
	CIRCLE.getDATA();
	CIRCLE.putDATA();
	CIRCLE.drawCIRCLE();
	return 0;
}
/*
	CREATED BY 
		HRUSHIKESH JOSHI
		27-03-2019 2:14
*/
