#include<iostream>
#include<graphics.h>
#include<cmath>
#include<cstdlib>

using namespace std;

void display(int n, float c[][3])
{
	float maxx, maxy;
	int i=0;
	maxx=getmaxx();
	maxy=getmaxy();
	maxx=maxx/2;
	maxy=maxy/2;

						//draw polygon
	while(i<n-1)
	{
		line(maxx+c[i][0], maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++;
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);

						//draw X-Y axis
	setcolor(WHITE);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}

void mult(int n,float b[][3], float c[][3],float a[][3])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[i][j]=0;
		}
	}
		

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				a[i][j]+=(c[i][k]*b[k][j]);
			}
		}
	}
}

void ref_x(int n,float c[][3])		//reflection about x-axis
{
	float b[10][3],a[10][3];
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=1;
	b[1][1]=-1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void ref_y(int n,float c[][3])	//reflection about y-axis
{
	float b[10][3],a[10][3];
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=-1;
	b[1][1]=1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void ref_xy(int n,float c[][3])	//reflection about y=x line
{
	float b[10][3],a[10][3];
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][1]=1;
	b[1][0]=1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void ref_org(int n,float c[][3])	//reflection about origin
{
	float b[10][3],a[10][3];
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][0]=-1;
	b[1][1]=-1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void ref_nxy(int n,float c[][3])	//reflection about y=-x line
{
	float b[10][3],a[10][3];
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	b[0][1]=-1;
	b[1][0]=-1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void shear_x(int n,float c[][3])	//shear about x
{
	float b[10][3],a[10][3];
	int shear;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	
	cout<<"\nEnter the Shear factor : ";
	cin>>shear;
	
	
	b[0][0]=1;
	b[1][0]=shear;
	b[1][1]=1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

void shear_y(int n,float c[][3])	//shear about y 
{
	float b[10][3],a[10][3];
	int shear;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j]=0;
		}
	}
	
	cout<<"\nEnter the Shear factor : ";
	cin>>shear;

	b[0][0]=1;
	b[0][1]=shear;
	b[1][1]=1;
	b[2][2]=1;
	
	mult(n,b,c,a);
	setcolor(RED);
	display(n,a);
}

int main()
{
	int i,Choice,n,gd,gm;
	float c[10][3];
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	cout<<"\n REFLECTION AND SHEAR TRANSFORMATIONS ";
	cout<<"\nEnter the number of vertices of the polygon : ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the co-ordinates of vertex "<<i+1<<" : ";
		cout<<"\nX co-ordinate : ";
		cin>>c[i][0];
		cout<<"\nY co-ordinate : ";
		cin>>c[i][1];
		c[i][2]=1;
	}
	
	do
	{
		
		cout<<"\n         MENU";
		cout<<"\n1.Reflection about x-axis\n2.Reflection about y-axis\n3.Reflection about y=x\n4.Reflection about y=-x\n5.Reflection about origin \n6.Shear about X \n7.Shear about Y \n8.EXIT" ;
		cout<<"\n-------------------------";
		cout<<"\nEnter your choice : ";
		cin>>Choice;
		switch(Choice)
		{
			case 1:	cleardevice();
				ref_x(n,c);
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;

			case 2:	cleardevice();
				ref_y(n,c);
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;

			case 3:	cleardevice();
				ref_xy(n,c);
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;

			case 4:	cleardevice();
				ref_nxy(n,c);
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;
			
			case 5:	cleardevice(); 
				ref_org(n,c);
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;
				
			case 6:	cleardevice();
				shear_x(n,c); 	
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;
			
			case 7:	cleardevice();
				shear_y(n,c); 	
				setcolor(BLUE);
				display(n,c);
				delay(5000);
				break;

			case 8:	exit(0);
				
			default:cout<<"\nEnter valid choice !";
				break;
		}
	}while(iChoice!=8);
	return 0;
}
