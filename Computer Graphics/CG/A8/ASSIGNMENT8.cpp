/*
8:Write c++/JAVA program to implement sheer and reflection of 2-D object about X axis,Y axis, about line
	Y=X, line Y=-X and ORIGIN.
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
 
class TRANSFORMATIONS_2D
{
		int gd=DETECT,gm,NO,c;float SX,SY,SHEAR_X[3][3],SHEAR_Y[3][3],ROTATE[3][3],X_MAX,Y_MAX,POINT[11][3],RESULT[11][3];
	public:
		TRANSFORMATIONS_2D()
		{
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					SHEAR_X[i][j]=SHEAR_Y[i][j]=ROTATE[i][j]=0;
			for(int i=0;i<11;i++)
				for(int j=0;j<3;j++)
					POINT[i][j]=RESULT[i][j]=0;
			SX=SY=0;
		}
		void getTransformationFactors();
		void putTransformationFactors();
		void createTransformationMatrix();
		void transform(int n);
		void multiply(float (&X)[11][3],float (&Y)[3][3],int n);
		void drawPoint();
		void drawLine();
		void drawPolygon();
};
void TRANSFORMATIONS_2D::getTransformationFactors()
{	
	cout<<"ACTIONS THAT CAN BE PERFORMED ON OBJECT ARE:"<<endl;
	cout<<"ACTIONS:\n1:SHEARING\n2:REFLECTION ALONG X AXIS\n3:REFLECTION ALONG Y AXIS\n4:REFLECTION ALONG Y=X LINE\n5:REFLECTION ALONG Y=-X LINE\nCHOICE:";cin>>c;
	if(c==1)
	{
		cout<<"SHEARING:"<<endl;
		cout<<"*PLEASE ENTER 0 FOR BOTH FACTORS IF YOU DON'T WANT TO SHEAR"<<endl;
		cout<<"X SHEARING FACTOR:";cin>>SX;
		cout<<"Y SHEARING FACTOR:";cin>>SY;
	}
}
void TRANSFORMATIONS_2D::putTransformationFactors()
{
	switch(c)
	{
		case 1:
			cout<<"SHEARING THE OBJECT BY:"<<endl;
			cout<<"X SHEARING FACTOR:"<<SX<<endl;
			cout<<"Y SHEARING FACTOR:"<<SY<<endl;
		break;
		case 2:
			cout<<"REFLECTING THE OBJECT ALONG Y=0:"<<endl;
		break;
		case 3:
			cout<<"REFLECTING THE OBJECT ALONG X=0:"<<endl;
		break;
		case 4:
			cout<<"REFLECTING THE OBJECT ALONG Y=X:"<<endl;
		break;
		case 5:
			cout<<"REFLECTING THE OBJECT ALONG Y=-X:"<<endl;
		break;
	}
}
void TRANSFORMATIONS_2D::createTransformationMatrix()
{	
	switch(c)
	{
		case 1:
			SHEAR_X[0][0]=1;SHEAR_X[1][1]=1;SHEAR_X[2][2]=1;SHEAR_X[1][0]=SX;
			SHEAR_Y[0][0]=1;SHEAR_Y[1][1]=1;SHEAR_Y[2][2]=1;SHEAR_Y[0][1]=SY;
		break;
		case 2:
			ROTATE[0][0]=1;ROTATE[1][1]=-1;ROTATE[2][2]=1;
		break;
		case 3:
			ROTATE[0][0]=-1;ROTATE[1][1]=1;ROTATE[2][2]=1;
		break;
		case 4:
			ROTATE[0][1]=1;ROTATE[1][0]=1;ROTATE[2][2]=1;
		break;
		case 5:
			ROTATE[0][0]=-1;ROTATE[1][1]=-1;ROTATE[2][2]=1;
		break;
	}
	/*
	cout<<"SCALE MATRIX:"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<SCALE[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<"TRANSLATE MATRIX:"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<TRANSLATE[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<"ROTATE MATRIX:"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<ROTATE[i][j]<<" ";
		cout<<endl;
	}
	*/
}
void TRANSFORMATIONS_2D::transform(int n)
{
	
	if(c==1)
	{
			multiply(POINT,SHEAR_X,n);
			multiply(POINT,SHEAR_Y,n);
	}
	else
		multiply(POINT,ROTATE,n);	
}
void TRANSFORMATIONS_2D::multiply(float (&X)[11][3],float (&Y)[3][3],int n)
{	
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			RESULT[i][j]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				RESULT[i][j]=RESULT[i][j]+X[i][k]*Y[k][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			X[i][j]=RESULT[i][j];
}
void TRANSFORMATIONS_2D::drawPoint()
{
	cout<<"PLEASE ENTER THE CO-ORDINATES OF THE POINT"<<endl;
	cout<<"X:";cin>>POINT[0][0];
	cout<<"Y:";cin>>POINT[0][1];POINT[0][2]=1;
	getTransformationFactors();
	putTransformationFactors();
	createTransformationMatrix();
	initgraph(&gd,&gm,NULL);
	X_MAX=getmaxx()/2;
	Y_MAX=getmaxy()/2;
	DDA L1;
	L1.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L1.drawLINE(-X_MAX,0,X_MAX,0,0);
	L1.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L1.drawLINE(-X_MAX,0,X_MAX,0,0);
	L1.drawLINE(-10,50  ,10,50  ,0);
	L1.drawLINE(-10,100 ,10,100 ,0);
	L1.drawLINE(-10,-50 ,10,-50 ,0);
	L1.drawLINE(-10,-100,10,-100,0);
	L1.drawLINE(-10,150,10,150  ,0);
	L1.drawLINE(-10,200, 10 ,200,0);
	L1.drawLINE(-10,-150,10,-150,0);
	L1.drawLINE(-10,-200,10,-200,0);
	
	L1.drawLINE(100,-10,100,10,0);
	L1.drawLINE(50,-10,50,10,0);
	L1.drawLINE(-50,-10,-50,10,0);
	L1.drawLINE(-100,-10,-100,10,0);
	L1.drawLINE(200,-10,200,10,0);
	L1.drawLINE(150,-10,150,10,0);
	L1.drawLINE(-150,-10,-150,10,0);
	L1.drawLINE(-200,-10,-200,10,0);
	
	L1.drawLINE(-X_MAX,0,X_MAX,0,0);
	L1.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L1.drawLINE(-X_MAX,0,X_MAX,0,0);
	putpixel(X_MAX+POINT[0][0],Y_MAX+POINT[0][1],RED);
	transform(1);
	putpixel(X_MAX+RESULT[0][0],Y_MAX+RESULT[0][1],WHITE);
	putpixel(X_MAX,Y_MAX,WHITE);
	delay(5000);
	closegraph();
}
void TRANSFORMATIONS_2D::drawLine()
{	
	cout<<"PLEASE ENTER THE CO-ORDINATES OF THE LINE"<<endl;
	cout<<"STARTING POINT:"<<endl;
	cout<<"X:";cin>>POINT[0][0];
	cout<<"Y:";cin>>POINT[0][1];
	cout<<"STARTING POINT:"<<endl;
	cout<<"X:";cin>>POINT[1][0];
	cout<<"Y:";cin>>POINT[1][1];
	POINT[0][2]=1;POINT[1][2]=1;
	getTransformationFactors();
	putTransformationFactors();
	createTransformationMatrix();
	initgraph(&gd,&gm,NULL);
	X_MAX=getmaxx()/2;
	Y_MAX=getmaxy()/2;
	DDA L2;
	L2.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
	L2.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
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
	
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
	L2.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
	L2.drawLINE(POINT[0][0],POINT[0][1],POINT[1][0],POINT[1][1],0);
	transform(2);
	L2.drawLINE(RESULT[0][0],RESULT[0][1],RESULT[1][0],RESULT[1][1],2);
	putpixel(X_MAX,Y_MAX,WHITE);
	delay(5000);
	closegraph();
}
void TRANSFORMATIONS_2D::drawPolygon()
{
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
	getTransformationFactors();
	putTransformationFactors();
	createTransformationMatrix();
	initgraph(&gd,&gm,NULL);
	X_MAX=getmaxx()/2;
	Y_MAX=getmaxy()/2;
	DDA L2;
	L2.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
	L2.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
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
	
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
	L2.drawLINE(0,-Y_MAX,0,Y_MAX,0);
	L2.drawLINE(-X_MAX,0,X_MAX,0,0);
	for(int i=0;i<NO;i++)
		L2.drawLINE(POINT[i][0],POINT[i][1],POINT[i+1][0],POINT[i+1][1],1);
	transform(NO+1);
	for(int i=0;i<NO;i++)
		L2.drawLINE(RESULT[i][0],RESULT[i][1],RESULT[i+1][0],RESULT[i+1][1],2);
	putpixel(X_MAX,Y_MAX,WHITE);
	delay(5000);
	closegraph();
	/*
	cout<<endl;
	cout<<"RESULT"<<endl;
	for(int i=0;i<11;i++)
	{	
		for(int j=0;j<3;j++)
			cout<<RESULT[i][j]<<" ";
		cout<<endl;
	}
	*/
}	

int main()
{
	int c;
	cout<<"2D TRANSFORMATIONS"<<endl;
	TRANSFORMATIONS_2D OBJECT;
	do
	{
		cout<<"WHAT TYPE OF OBJECT DO YOU WANT TO DRAW:\n1:POINT\n2:LINE\n3:POLYGON\n4:TO EXIT\nCHOICE: ";cin>>c;
		switch(c)
		{
			case 1:
				OBJECT.drawPoint();
			break;
			case 2:
				OBJECT.drawLine();
			break;
			case 3:
				OBJECT.drawPolygon();
			break;
			case 4:
				return 0;
			break;
			default:
				cout<<"PLEASE ENTER A VALID CHOICE"<<endl;
		}
	}while(1);
	return 0;
}
/*
	CREATED BY:
		HRUSHIKESH JOSHI
		04-04-2019 23:53 
*/
