/*
 * snowflake.cpp
 *
 *  Created on: 22-Mar-2017
 *      Author: student
 */
#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class snowflake
{
public:
    void init();
    void close();
    void koch(int, int, int, int, int);
    void plot();
};

void snowflake::init()
{
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
}

void snowflake::close()
{
    getch();
    closegraph();
}

void snowflake::plot()
{
    int n;
    cout<<"\nEnter the number of iterations: ";
    cin >> n;
    init();
    koch(n, 150, 20, 20, 280);
    koch(n, 280, 280, 150, 20);
    koch(n, 20, 280, 280, 280);
    close();
}

void snowflake::koch(int n, int x1, int y1, int x5, int y5)
{
    int dx, dy, x2, y2, x3, y3, x4, y4;

    if(n==0)
    	line(x1, y1, x5, y5);

    else
    {
    	dx = x5 - x1;
    	dy = y5 - y1;
    	x2 = x1 + dx/3;
    	y2 = y1 + dy/3;

    	x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
    	y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);

    	x4=x1+2*dx/3;
    	y4=y1+2*dy/3;

    	koch(n-1,x1,y1,x2,y2);
    	koch(n-1,x2,y2,x3,y3);
    	koch(n-1,x3,y3,x4,y4);
    	koch(n-1,x4,y4,x5,y5);

    }
}
int main()
{
    snowflake s;
    s.plot();
    return 0;
}
