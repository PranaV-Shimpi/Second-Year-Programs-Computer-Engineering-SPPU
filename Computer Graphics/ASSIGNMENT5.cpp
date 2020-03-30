
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;





void drawLINE(float x1,float y1,float x2,float y2)	//DDA
{
   float dx,dy,x,y,len;
    if(abs(x2-x1) > abs(y2-y1))
     {
        len=abs(x2-x1);
     }

	else
    {
        len=abs(x2-x1);
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

int main()													//MAIN FUNCTION
{
    int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	cout<<"DRAWING SHAPE USING DDA LINE DRAWING ALGORITHM";
    float x1,y1,x2,y2;

													//CREATING OBJECT OF CLASS DDA WHER ALL DATA IS STORED
    							//INITALIZING GRAPH
	drawLINE(100,50,100,-50);
	drawLINE(100,-50,-100,-50);
	drawLINE(-100,-50,-100,50);
	drawLINE(-100,50,100,50);

	drawLINE(200,100,200,-100);
	drawLINE(200,-100,-200,-100);
	drawLINE(-200,-100,-200,100);
	drawLINE(-200,100,200,100);

	drawLINE(200,0,0,100);
	drawLINE(200,0,0,-100);
	drawLINE(-200,0,0,100);
	drawLINE(-200,0,0,-100);
	delay(10000);
	getch();											//DELAY FOR DISPLAY
	closegraph();

	cout<<endl<<"LINE DRAWN SUCCESSFULLY"<<endl;
	return 0;
}
