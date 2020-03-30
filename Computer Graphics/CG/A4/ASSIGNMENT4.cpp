/*
	PROBLEM STATEMENT:
	4:Write C++ program to fill polygon using scan line/flood fill / bopundary fill algorithm.
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
	void drawLINE(float x1,float y1,float x2,float y2,int colour);				//DRAWS A LINE USING DDA LINE DRAWING ALGORITHM
};

void DDA::drawLINE(float x1,float y1,float x2,float y2,int colour)
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
			putpixel(X0+X+0.5,Y0+Y+0.5,RED);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		if(colour==2)
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		X+=X_INC;											//X INCREMENTATION
		Y+=Y_INC;											//Y INCREMENTATION
		STEPS--;
	}
	putpixel(X0,Y0,GREEN);
}

class SCAN_FILL
{
		int gd=DETECT,gm,NO,E_NO,H_NO,Y,I_NO,X0,Y0,flag,S;float Y_MAX,Y_MIN,POINT[11][3],E[10][4],H[10][4],I[10][2],X_OLD,X_NEW,DX,DY,m;
	public:
		SCAN_FILL()
		{
			NO=E_NO=H_NO=0;
		}
		void drawPolygon();
};

void SCAN_FILL::drawPolygon()
{
	Y_MAX=Y_MIN=E_NO=H_NO=0;float t1,t2,t3,t4;
	do
	{
		cout<<"PLEASE ENTER THE NUMBER OF POINTS OF THE POLYGON(MAXIMUM NUMBER OF POINTS IS 10):";cin>>NO;
	}
	while(NO<3||NO>10);
	cout<<"PLEASE ENTER THE POINTS SEQUENTIALLY"<<endl;
	for(int i=0;i<NO;i++)
	{
		cout<<i+1<<" th POINT:"<<endl;
		cout<<"X:";cin>>POINT[i][0];POINT[i][2]=1;
		cout<<"Y:";cin>>POINT[i][1];
	}
	POINT[NO][0]=POINT[0][0];POINT[NO][1]=POINT[0][1];POINT[NO][2]=POINT[0][2];
	Y_MIN=POINT[0][1];
	for(int i=0;i<NO;i++)
	{
		if(Y_MAX<POINT[i][1])
			Y_MAX=POINT[i][1];
		if(Y_MIN>POINT[i][1])
			Y_MIN=POINT[i][1];
		if(POINT[i][1]==POINT[i+1][1])
		{
			H[H_NO][0]=POINT[i][0];H[H_NO][1]=POINT[i][1];H[H_NO][2]=POINT[i+1][0];H[H_NO][3]=POINT[i+1][1];
			H_NO++;
		}
		E[i][0]=POINT[i][0];E[i][1]=POINT[i][1];E[i][2]=POINT[i+1][0];E[i][3]=POINT[i+1][1];
	}
	for(int i=0;i<NO;i++)
	{
		if(E[i][1]<E[i][3])
		{
			t1=E[i][0];
			t2=E[i][1];
			E[i][0]=E[i][2];
			E[i][1]=E[i][3];
			E[i][2]=t1;
			E[i][3]=t2;
		}
	}
	cout<<"SORTING THE EDGES"<<endl;
	for(int j=0;j<NO;j++)
	{
		for(int i=0;i<NO-j-1;i++)
		{
			if(E[i][1]<E[i+1][1])
			{
				//cout<<"SWAPING "<<i<<","<<i+1<<endl;
				t1=E[i+1][0];
				t2=E[i+1][1];
				t3=E[i+1][2];
				t4=E[i+1][3];
				E[i+1][0]=E[i][0];
				E[i+1][1]=E[i][1];
				E[i+1][2]=E[i][2];
				E[i+1][3]=E[i][3];
				E[i][0]=t1;
				E[i][1]=t2;
				E[i][2]=t3;
				E[i][3]=t4;
			}
		}
	}
	cout<<"Y_MAX:"<<Y_MAX<<endl;
	cout<<"Y_MIN:"<<Y_MIN<<endl;
	cout<<"EGDES ARE:"<<endl;
	for(int i=0;i<NO;i++)
	{
		cout<<E[i][0]<<","<<E[i][1]<<"->"<<E[i][2]<<","<<E[i][3]<<endl;
	}
	cout<<"HORIZONTAL EGDES ARE"<<endl;
	for(int i=0;i<H_NO;i++)
	{
		cout<<H[i][0]<<","<<H[i][1]<<"->"<<H[i][2]<<","<<H[i][3]<<endl;
	}
	/*	*/
	initgraph(&gd,&gm,NULL);
	X0=getmaxx()/2;
	Y0=getmaxy()/2;
	DDA L2;
	L2.drawLINE(0,-Y0,0,Y0,0);
	L2.drawLINE(-X0,0,X0,0,0);
	L2.drawLINE(0,-Y0,0,Y0,0);
	L2.drawLINE(-X0,0,X0,0,0);
	L2.drawLINE(-10,50  ,10,50  ,0);
	L2.drawLINE(-10,100 ,10,100 ,0);
	L2.drawLINE(-10,-50 ,10,-50 ,0);
	L2.drawLINE(-10,-100,10,-100,0);
	L2.drawLINE(-10,150,10,150  ,0);
	L2.drawLINE(-10,200, 10 ,200,0);
	L2.drawLINE(-10,-150,10,-150,0);
	L2.drawLINE(-10,-200,10,-200,0);

	L2.drawLINE(100,-10,100,10,0);
	L2.drawLINE(50,-10,50,10,0);
	L2.drawLINE(-50,-10,-50,10,0);
	L2.drawLINE(-100,-10,-100,10,0);
	L2.drawLINE(200,-10,200,10,0);
	L2.drawLINE(150,-10,150,10,0);
	L2.drawLINE(-150,-10,-150,10,0);
	L2.drawLINE(-200,-10,-200,10,0);
	for(int i=0;i<NO;i++)
		L2.drawLINE(POINT[i][0],POINT[i][1],POINT[i+1][0],POINT[i+1][1],1);
	delay(1000);
	for(int i=0;i<10;i++)
		for(int j=0;j<2;j++)
			I[i][j]=0;
	for(Y=Y_MAX;Y>=Y_MIN;Y--)
	{
		//cout<<"Y = "<<Y<<endl;
		flag =0;
		for(int i=0;i<10;i++)
		{
			//cout<<"EGDE NO:"<<i<<endl;
			if(Y==E[i][1])
			{
				//cout<<"SETTING OLD X"<<endl;
				I[i][0]=E[i][0];
			}
			if((Y==E[i][1])&&(Y==E[i][3]))
			{
				//cout<<"HORZANTAL LINE"<<endl;
				L2.drawLINE(E[i][0],E[i][1],E[i][2],E[i][3],2);
				continue;
			}
			if((Y<=E[i][1])&&(Y>=E[i][3]))
			{
				//cout<<"INSIDE RANGE"<<endl;
				I[i][0]=I[i][0]-((E[i][0]-E[i][2])/(E[i][1]-E[i][3]));
				I[i][1]=Y;
				//cout<<I[i][0]<<","<<I[i][1]<<endl;
				flag++;
				if(flag==1)
					S=i;
				if(flag==2)
				{
					//cout<<I[S][0]<<","<<I[S][1]<<"->"<<I[i][0]<<","<<I[i][1]<<endl;
					L2.drawLINE(I[S][0],I[i][1],I[i][0],I[i][1],2);
					flag=0;
				}
			}
		}
	}
	delay(2000);
	closegraph();
}

int main()
{
	int c;
	cout<<"SCAN FILL ALGORITHM"<<endl;
	SCAN_FILL OBJECT;
	OBJECT.drawPolygon();
	return 0;
}
