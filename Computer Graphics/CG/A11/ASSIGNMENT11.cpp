/*
PROBLEM STATEMENT:
11:Write C++/JAVA program to generate fractal patterns by using KOCH CURVES.
*/
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class DDA
{
		float X1,Y1,X2,Y2,DX,DY,X,Y,X_INC,Y_INC;int X0,Y0,STEPS;int gd=DETECT,gm;
	public:
	DDA()
	{
		X0=0;
		Y0=0;
	}
	void drawLINE(int x1,int y1,int x2,int y2,int colour);				//DRAWS A LINE USING DDA LINE DRAWING ALGORITHM
};
void DDA::drawLINE(int x1,int y1,int x2,int y2,int colour)
{
	X1=x1;X2=x2;Y1=y1;Y2=y2;
	X0=getmaxx()/2;Y0=getmaxy()/2;					//FOR GETTING MIDPOINT OF THE SCREEN
	putpixel(X0,Y0,GREEN);								//PUTTING MIDPOINT
	DX=X2-X1;												
	DY=Y2-Y1;
	if(DX<0)
		DX=-DX;
	if(DY<0)
		DY=-DY;
	if(DX>=DY)												//TO DECIDE: COLUMN /ROW STEPING
		STEPS=DX;
	else
		STEPS=DY;
	DX=X2-X1;
	DY=Y2-Y1;
	X_INC=(float)DX/STEPS;								//X INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	Y_INC=(float)DY/STEPS;								//Y INCREMENTATION VALUE CORRESSPONDING TO THE SLOPE
	X=X1;Y=Y1;		
	while(STEPS)											//LOOP EXECUTES "STEPS" TIMES
	{
		if(colour==0)
			putpixel(X0+X+0.5,Y0+Y+0.5,BLUE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		if(colour==1)
			putpixel(X0+X+0.5,Y0+Y+0.5,GREEN);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC	
		if(colour==2)
			putpixel(X0+X+0.5,Y0+Y+0.5,RED);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC	
		if(colour==3)
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		X+=X_INC;											//X INCREMENTATION
		Y+=Y_INC;											//Y INCREMENTATION
		STEPS--;
	}
	putpixel(X0,Y0,GREEN);
}

class KOCH_CURVE
{
		float X0,Y0,THETA;
	public:
		KOCH_CURVE()
		{	
				X0=Y0=0;
				THETA=(60*3.142)/180;
		}
		void drawFractal(float x1,float y1,float x2,float y2,int n);
};
void KOCH_CURVE::drawFractal(float x1,float y1,float x2,float y2,int n)
{
	
	float X1,Y1,X2,Y2,X3,Y3,X4,Y4,X,Y;
	X1=x1;Y1=y1;X2=x2;Y2=y2;
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	DDA line;
	//cout<<"DIVIDING THE LINE"<<endl;
	//cout<<X1<<","<<Y1<<"->"<<X2<<","<<Y2<<endl;
	X3=(2*X1+X2)/3;
	X4=(X1+2*X2)/3;
	Y3=(2*Y1+Y2)/3;
	Y4=(Y1+2*Y2)/3;
	X=X3+(X4-X3)*cos(THETA)+(Y4-Y3)*sin(THETA);
	Y=Y3-(X4-X3)*sin(THETA)+(Y4-Y3)*cos(THETA);
	//cout<<"n="<<n<<endl;
	if(n>1)
	{
		//cout<<"INSIDE"<<endl;
		drawFractal(X1,Y1,X3,Y3,n-1);
		drawFractal(X3,Y3,X,Y,n-1);
		drawFractal(X,Y,X4,Y4,n-1);
		drawFractal(X4,Y4,X2,Y2,n-1);
		return;
	}
	//cout<<"DRAWING LINE"<<endl;
	//cout<<X1<<","<<Y1<<"->"<<X3<<","<<Y3<<endl;
	//cout<<X3<<","<<Y3<<"->"<<X<<","<<Y<<endl;
	//cout<<X<<","<<Y<<"->"<<X4<<","<<Y4<<endl;
	//cout<<X4<<","<<Y4<<"->"<<X2<<","<<Y2<<endl;
	if(n==1)
	{
		//cout<<"DRAWING"<<endl;
		line.drawLINE(X1,Y1,X3,Y3,3);
		line.drawLINE(X3,Y3,X,Y,3);
		line.drawLINE(X,Y,X4,Y4,3);
		line.drawLINE(X4,Y4,X2,Y2,3);
	}
}

int main()
{
	cout<<"FRACTAL PATTERN GENERATION BY KOCH'S CURVE ALOGORITHM"<<endl;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	KOCH_CURVE FRACTAL;
	FRACTAL.drawFractal(0,0,200,0,5);
	FRACTAL.drawFractal(200,0,100,173.2,5);
	FRACTAL.drawFractal(100,173.2,0,0,5);
	
	delay(10000);
	closegraph();
	return 0;
}

/*
	CREATED BY:
		HRUSHIKESH JOSHI
		05-04-2019 01:22
*/
/*
	CREATED BY:
		HRUSHIKESH JOSHI
		05-04-2019 00:46
*/
