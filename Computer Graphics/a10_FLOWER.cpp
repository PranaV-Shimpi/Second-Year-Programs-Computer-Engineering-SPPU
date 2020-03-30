#include <stdio.h> 
#include <stdlib.h> 
#include <graphics.h> 
#include <math.h>
//#include<conio.h>
void bezier (int x[4][4], int y[4][4])
{
int gd = DETECT, gm; int i,j; double t;
   initgraph (&gd, &gm, "c:\\Turboc3\\BGI");
for(i=0;i<4;i++)
{
for (t = 0.0; t < 1.0; t += 0.0005)
 {
double xt = pow (1-t, 3) * x[i][0] + 3 * t * pow (1-t, 2) * x[i][1] + 3 * pow (t, 2) * (1-t) * x[i][2] + pow (t, 3) * x[i][3];
double yt = pow (1-t, 3) * y[i][0] + 3 * t * pow (1-t, 2) * y[i][1] + 3 * pow (t, 2) * (1-t) * y[i][2] + pow (t, 3) * y[i][3];
putpixel (xt, yt, WHITE);
}
}
setcolor(RED);
getch();
 closegraph();
 return;
 }
int  main()
{
 int x[4][4], y[4][4]; int i,j;
   printf ("Enter the x- and y-coordinates of the four control points.\n"); /* Co-ordinates for four petals total 16. If you want to increase petals increase the size of x & y array. Each petal will add four more points.*/
 for (i=0; i<4; i++)
  {
   for(j=0; j<4; j++)
    {
      scanf ("%d%d", &x[i][j], &y[i][j]);

     }
 }
bezier (x, y);

return 0;
}

//Sample Points Co-ordinates
/*
(200, 200) (160, 160) (240, 160) (200, 200) //for first petal
(200, 200) (240, 160) (240, 240) (200, 200) //for second petal
(200, 200) (240, 240) (160, 240) (200, 200) //for third petal
(200, 200) (160, 240) (160, 160) (200, 200) //for fourth petal

*/
