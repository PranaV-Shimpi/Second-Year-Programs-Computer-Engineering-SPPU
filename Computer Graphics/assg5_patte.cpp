#include<graphics.h>
#include<iostream>
using namespace std;

int  main()
{
	int gd,gm;
	gd = DETECT;


	initgraph(&gd,&gm,"");


	setcolor(YELLOW);


  	rectangle(100, 100, 400, 400);
  	delay(1000);
  	setcolor(WHITE);
  	line(250,100,100,250);
  	delay(1000);
  	line(100,250,250,400);
  	delay(1000);
  	line(250,400,400,250);
  	delay(1000);
  	line(400,250,250,100);
  	setcolor(BLUE);
  	delay(1000);
  	circle(250,250,105);
  	setcolor(RED);
  	delay(1000);
  	line(145,250,250,145);
  	delay(1000);
  	line(145,250,355,250);
  	delay(1000);
  	line(250,145,355,250);

	getch();

  closegraph();
  return (0);
}
