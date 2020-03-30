/*
PROBLEM STATEMENT:
10:Write C++ program to draw any object such as flower, waves using any curve generation techniques.

PETAL CONTROL POINTS:
PETAL:1
(200,200)(160,160)(240,160)(200,200)
(200,200)(240,160)(240,240)(200,200)
(200,200)(240,240)(240,240)(200,200)
(200,200)(160,240)(160,160)(200,200)
U=0.0005
*/
#include<iostream>
#include<graphics.h>
using namespace std;

class BEZIER_CURVE
{
		int gd=DETECT,gm;float POINTS[16][2],X,Y,U,X0,Y0;
	public:
		BEZIER_CURVE()
		{	
			for(int i=0;i<4;i++)
				POINTS[i][0]=POINTS[i][1]=0;
				X=Y=X0=Y0=0;
				U=0.0005;
		}
		void getCurvePoints();
		void putCurvePoints();
		void drawCurve();
};
void BEZIER_CURVE::getCurvePoints()
{
	cout<<"A SYMMETRICAL FLOWER IS TO BE DRAWN"<<endl;
	cout<<"PLEASE ENTER THE CONTROL POINTS OF THE PETAL"<<endl;
	for(int j=0;j<16;j+=4)
	{
		cout<<endl<<"PETAL"<<j/4+1<<endl;
		for(int i=0;i<4;i++)
		{
			cout<<"CONTROL POINT:"<<i+1<<endl;
			cout<<"X:";cin>>POINTS[j+i][0];
			cout<<"Y:";cin>>POINTS[j+i][1];
		}
	}
}
void BEZIER_CURVE::putCurvePoints()
{
	cout<<"THE GIVEN CONTROL POINTS ARE:"<<endl;
	for(int j=0;j<16;j+=4)
	{
		cout<<endl<<"PETAL:"<<j/4+1<<endl;
		for(int i=0;i<4;i++)
		{
			cout<<"CONTROL POINT:"<<i+1<<endl;
			cout<<"X:"<<POINTS[j+i][0]<<endl;
			cout<<"Y:"<<POINTS[j+i][1]<<endl;
		}
	}
}
void BEZIER_CURVE::drawCurve()
{
	initgraph(&gd,&gm,NULL);
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	for(int i=0;i<16;i+=4)
	{
		for(U=0.0;U<1.0;U+=0.0005)
		{
			X=(POINTS[i+3][0]*U*U*U)+(3*POINTS[i+2][0]*U*U*(1-U))+(3*POINTS[i+1][0]*U*(1-U)*(1-U))+(POINTS[i+0][0]*(1-U)*(1-U)*(1-U));
			Y=(POINTS[i+3][1]*U*U*U)+(3*POINTS[i+2][1]*U*U*(1-U))+(3*POINTS[i+1][1]*U*(1-U)*(1-U))+(POINTS[i+0][1]*(1-U)*(1-U)*(1-U));
			putpixel(X,Y,WHITE);
		}
	}
	delay(5000);
	closegraph();
}

int main()
{
	cout<<"CURVE GENERATION BY BEZIER'S CURVE ALGORITHM"<<endl;
	BEZIER_CURVE PETAL;
	PETAL.getCurvePoints();
	PETAL.putCurvePoints();
	PETAL.drawCurve();
	return 0;
}

/*
	CREATED BY:
		HRUSHIKESH JOSHI
		05-04-2019 01:22
*/
