/*
	PROBLEM STATEMENT:
	7:Write C++/JAVA program to implement Cohen-Sutherland line clipping algorithm for given window.
*/
#include<iostream>
#include<graphics.h>
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
			putpixel(X0+X+0.5,Y0+Y+0.5,RED);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC	
		if(colour==2)
			putpixel(X0+X+0.5,Y0+Y+0.5,WHITE);//PUT PIXEL WITH RESPECT TO MIDPOINT OF THE SCREEN & ALSO USING CEILING AND FLOOR FUNC
		X+=X_INC;											//X INCREMENTATION
		Y+=Y_INC;											//Y INCREMENTATION
		STEPS--;
	}
	putpixel(X0,Y0,GREEN);
}

class COHEN_SUTHERLAND
{
		int gd=DETECT,gm,NO,LINE[10][12],X_MAX,X_MIN,Y_MAX,Y_MIN,AND[4];float m;
	public:
		COHEN_SUTHERLAND()
		{
			for(int i=0;i<10;i++)
				for(int j=0;j<12;j++)
					LINE[i][j]=0;
			X_MAX=100;
			X_MIN=0;
			Y_MAX=100;
			Y_MIN=0;
			m=0;
		}
		void getLines();
		void putLines();
		void clipLines();
};
void COHEN_SUTHERLAND::getLines()
{
	do
	{
		cout<<"HOW MANY LINES DO YOU WANT TO DISPLAY(MAXIMUM NUMBER OF LINES IS 10):";cin>>NO;
	}while(NO<1||NO>10);
	cout<<"PLEASE ENTER THE CO-ORDINATES OF THE GIVEN LINES:"<<endl;
	for(int i=0;i<NO;i++)
	{
		cout<<"LINE:"<<i+1<<endl;
		cout<<"STARTING POINT:"<<endl;
		cout<<"X :";cin>>LINE[i][0];
		cout<<"Y :";cin>>LINE[i][1];
		cout<<"ENDING POINT:"<<endl;
		cout<<"X :";cin>>LINE[i][2];
		cout<<"Y :";cin>>LINE[i][3];
	}		
}
void COHEN_SUTHERLAND::putLines()
{
	cout<<"LINES TO BE DISPLAYED:"<<NO<<endl;
	for(int i=0;i<NO;i++)
	{
		cout<<"LINE:"<<i+1<<endl;
		cout<<"STARTING POINT:"<<endl;
		cout<<"X :"<<LINE[i][0]<<"\tY :"<<LINE[i][1]<<"\t"<<LINE[i][4]<<LINE[i][5]<<LINE[i][6]<<LINE[i][7]<<endl;
		cout<<"ENDING POINT:"<<endl;
		cout<<"X :"<<LINE[i][2]<<"\tY :"<<LINE[i][3]<<"\t"<<LINE[i][8]<<LINE[i][9]<<LINE[i][10]<<LINE[i][11]<<endl<<endl;
	}		
}
void COHEN_SUTHERLAND::clipLines()
{
	for(int i=0;i<NO;i++)
	{
		if(LINE[i][0]<X_MIN)
			LINE[i][7]=1;
		if(LINE[i][0]>X_MAX)
			LINE[i][6]=1;
		if(LINE[i][1]<Y_MIN)
			LINE[i][5]=1;
		if(LINE[i][1]>Y_MAX)
			LINE[i][4]=1;
			
		if(LINE[i][2]<X_MIN)
			LINE[i][11]=1;
		if(LINE[i][2]>X_MAX)
			LINE[i][10]=1;
		if(LINE[i][3]<Y_MIN)
			LINE[i][9]=1;
		if(LINE[i][3]>Y_MAX)
			LINE[i][8]=1;
	}
	cout<<"TBRL APPLIED"<<endl;
	for(int i=0;i<NO;i++)
	{
		cout<<"LINE:"<<i+1<<endl;
		cout<<"STARTING POINT:"<<endl;
		cout<<"X :"<<LINE[i][0]<<"\tY :"<<LINE[i][1]<<"\t"<<LINE[i][4]<<LINE[i][5]<<LINE[i][6]<<LINE[i][7]<<endl;
		cout<<"ENDING POINT:"<<endl;
		cout<<"X :"<<LINE[i][2]<<"\tY :"<<LINE[i][3]<<"\t"<<LINE[i][8]<<LINE[i][9]<<LINE[i][10]<<LINE[i][11]<<endl<<endl;
	}
	
	
	cout<<"DRAWING CLIPPED LINES"<<endl;
	cout<<"GREEN LINES ARE THE ORIGNAL NON-CLIPED LINES"<<endl;
	cout<<"WHITE LINES ARE CLIPED LINES"<<endl;
	initgraph(&gd,&gm,NULL);
	DDA line;
	for(int i=0;i<NO;i++)
		line.drawLINE(LINE[i][0],LINE[i][1],LINE[i][2],LINE[i][3],0);
	delay(2000);
	for(int i=0;i<NO;i++)
	{	
		cout<<"LINE:"<<i+1<<endl;
		if((LINE[i][4]==0)&&(LINE[i][5]==0)&&(LINE[i][6]==0)&&(LINE[i][7]==0)&&(LINE[i][8]==0)&&(LINE[i][9]==0)&&(LINE[i][10]==0)&&(LINE[i][11]==0))
		{
			cout<<"LINE TOTALLY INSIDE"<<endl;
			line.drawLINE(LINE[i][0],LINE[i][1],LINE[i][2],LINE[i][3],2);
		}
		else
		{
			cout<<"CLIPING REQUIRED"<<endl;
			cout<<"ANDING ENDPOINTS"<<endl;
			AND[0]=(LINE[i][4]&LINE[i][8]);
			AND[1]=(LINE[i][5]&LINE[i][9]);
			AND[2]=(LINE[i][6]&LINE[i][10]);
			AND[3]=(LINE[i][7]&LINE[i][11]);
			if((AND[0]==0)&&(AND[1]==0)&&(AND[2]==0)&&(AND[3]==0))
			{
				cout<<"LINE PARTIALLY INSIDE"<<endl;
				if((LINE[i][4]!=0)||(LINE[i][5]!=0)||(LINE[i][6]!=0)||(LINE[i][7]!=0))
				{
					cout<<"STARTING POINT OUTSIDE"<<endl;
					m=(((float)(LINE[i][3]-LINE[i][1]))/(LINE[i][2]-LINE[i][0]));
					cout<<"m="<<m<<endl;
					if(LINE[i][4]!=0)
					{
						cout<<"IN TOP"<<endl;
						LINE[i][0]=LINE[i][0]+(Y_MAX-LINE[i][1])/m;
						LINE[i][1]=Y_MAX;
					}
					if(LINE[i][5]!=0)
					{
						cout<<"IN BOTTOM"<<endl;
						LINE[i][0]=LINE[i][0]+(Y_MIN-LINE[i][1])/m;
						LINE[i][1]=Y_MIN;
					}
					if(LINE[i][6]!=0)
					{
						cout<<"IN RIGHT"<<endl;
						LINE[i][1]=LINE[i][1]+(X_MAX-LINE[i][0])*m;
						LINE[i][0]=X_MAX;
					}
					if(LINE[i][7]!=0)
					{
						cout<<"IN LEFT"<<endl;
						LINE[i][1]=LINE[i][1]+(X_MIN-LINE[i][0])*m;
						LINE[i][0]=X_MIN;
					}
				}
				cout<<"CORRECTED POINT\tX:"<<LINE[i][0]<<"\tY:"<<LINE[i][1]<<endl;
				if((LINE[i][8]!=0)||(LINE[i][9]!=0)||(LINE[i][10]!=0)||(LINE[i][11]!=0))
				{
					cout<<"ENDING POINT OUTSIDE"<<endl;
					m=(((float)(LINE[i][3]-LINE[i][1]))/(LINE[i][2]-LINE[i][0]));
					cout<<"m="<<m<<endl;
					if(LINE[i][8]!=0)
					{
						cout<<"IN TOP"<<endl;
						LINE[i][2]=LINE[i][2]+(Y_MAX-LINE[i][3])/m;
						LINE[i][3]=Y_MAX;
					}
					if(LINE[i][9]!=0)
					{
						cout<<"IN BOTTOM"<<endl;
						LINE[i][2]=LINE[i][2]+(Y_MIN-LINE[i][3])/m;
						LINE[i][3]=Y_MIN;	
					}
					if(LINE[i][10]!=0)
					{
						cout<<"IN RIGHT"<<endl;
						LINE[i][3]=LINE[i][3]+(X_MAX-LINE[i][2])*m;
						LINE[i][2]=X_MAX;
					}
					if(LINE[i][11]!=0)
					{
						cout<<"IN LEFT"<<endl;
						LINE[i][3]=LINE[i][3]+(X_MIN-LINE[i][2])*m;
						LINE[i][2]=X_MIN;
					}
				}
				cout<<"CORRECTED POINT\tX:"<<LINE[i][2]<<"\tY:"<<LINE[i][3]<<endl;
				line.drawLINE(LINE[i][0],LINE[i][1],LINE[i][2],LINE[i][3],2);
			}
			else
			{
				cout<<"LINE TOTALLY OUTSIDE"<<endl;
				cout<<"LINE NOT DRAWN"<<endl;
			}
		}
	}	
	delay(5000);
	closegraph();			
}

int main()
{
	cout<<"COHEN SUTHERLAND LINE CLIPING ALGORITHM"<<endl;
	COHEN_SUTHERLAND CLIP;
	CLIP.getLines();
	CLIP.putLines();
	CLIP.clipLines();
	return 0;
}
/*
	CREATED BY:
		HRUSHIKESH JOSHI
		04-04-2019 19:36 
*/
