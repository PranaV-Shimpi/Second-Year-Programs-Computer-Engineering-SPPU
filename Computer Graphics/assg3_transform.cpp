#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class transform
{
	public:
		int p[10][3];
		int n,x,y;
		int scale[3][3];
		int translate[3][3];
		double rotate[3][3];
		int result[10][3];
		double result_rot[10][3];
		void get_poly();
		void draw_poly();
		void disp_poly();
		void disp_poly_rotation();
		void scaling(int,int);
		void translation(int,int);
		void rotation(float);
		void mul(int[10][3],int[3][3]);
		void mul1(int[10][3],double[3][3]);
		void display_matrix(int,int,int[10][3]);
};

void transform::get_poly()
{
	int i,j;
	cout<<"\nEnter no. of vertices";
	cin>>n;
	cout<<"\nEnter coorinates as (x,y)";
	if(n<3)
	{
		cout<<"\nError";
		exit(0);

	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				cin>>p[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			p[i][2]=1;
		}
	}
}
void transform::draw_poly()
{
	int max_y,max_x,mid_x,mid_y,i;
	max_x=getmaxx();
	max_y=getmaxy();
	mid_x=max_x/2;
	mid_y=max_y/2;
	line(0,mid_y,max_x,mid_y);
	line(mid_x,0,mid_x,max_y);
	for(i=0;i<n-1;i++)
	{
		line(mid_x+p[i][0],mid_y-p[i][1],mid_x+p[i+1][0],mid_y-p[i+1][1]);
	}
	line(mid_x+p[n-1][0],mid_y-p[n-1][1],mid_x+p[0][0],mid_y-p[0][1]);
}

void transform::scaling(int sx,int sy)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i!=j)
				scale[i][j]=0;
			else
				scale[0][0]=sx;
				scale[1][1]=sy;
				scale[2][2]=1;
		}
	}
	display_matrix(3,3,scale);
	mul(p,scale);
	display_matrix(n,3,p);
	cout<<"\n";
	display_matrix(n,3,result);
}

void transform::translation(int tx,int ty)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				translate[i][j]=1;
			else
				translate[i][j]=0;
		}
	}
	translate[2][0]=tx;
	translate[2][1]=ty;
	
	display_matrix(3,3,translate);
	mul(p,translate);
	display_matrix(n,3,p);
	//cout<<"\n";
	display_matrix(n,3,result);
	
}

void transform::rotation(float theta)
{
	int i,j,tx,ty,direction;
	tx=p[0][0];
	ty=p[0][1];
	float rad;
	double pi=3.14159;
	rad=(theta*pi)/180;
    	cout<<"1. Anticlockwise"<<endl;
    	cout<<"2. Clockwise"<<endl;
    	cin>>direction;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			rotate[i][j]=0;
		}
	}
	if(direction==1)
	{
		rotate[0][0]=cos(rad);
		rotate[0][1]=sin(rad);
		rotate[1][0]=-sin(rad);
		rotate[1][1]=cos(rad);
		rotate[2][0]=ty*sin(rad)+tx*(1-cos(rad));
		rotate[2][1]=(-tx)*sin(rad)+ty*(1-cos(rad));
		rotate[2][2]=1;
	}
	else if(direction==2)
	{
		rotate[0][0]=cos(rad);
		rotate[0][1]=-sin(rad);
		rotate[1][0]=sin(rad);
		rotate[1][1]=cos(rad);
		rotate[2][0]=(-ty)*sin(rad)+tx*(1-cos(rad));
		rotate[2][1]=(tx)*sin(rad)+ty*(1-cos(rad));
		rotate[2][2]=1;
	}
	display_matrix(n,3,p);
	//display_matrix(3,3,rotate);
	mul1(p,rotate);
	
	
}


void transform::mul(int arr1[10][3],int arr2[3][3])
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			result[i][j]=0;
			for(int k=0;k<3;k++)
			{
				result[i][j]=result[i][j]+arr1[i][k]*arr2[k][j];
			}
		}
	}
}

void transform::mul1(int arr1[10][3],double arr2[3][3])
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			result_rot[i][j]=0;
			for(int k=0;k<3;k++)
			{
				result_rot[i][j]=result_rot[i][j]+arr1[i][k]*arr2[k][j];
			}
		}
	}
}

void transform::display_matrix(int r1,int c1,int result[10][3])
{
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}//end of display

void transform::disp_poly()
{
	int max_y,max_x,mid_x,mid_y;
	max_x=getmaxx();
	max_y=getmaxy();
	mid_x=max_x/2;
	mid_y=max_y/2;
	line(0,mid_y,max_x,mid_y);
	line(mid_x,0,mid_x,max_y);
	for(int i=0;i<n-1;i++)
	{
		line(mid_x+result[i][0],mid_y-result[i][1],mid_x+result[i+1][0],mid_y-result[i+1][1]);
	}
	line(mid_x+result[n-1][0],mid_y-result[n-1][1],mid_x+result[0][0],mid_y-result[0][1]);		
}

void transform::disp_poly_rotation()
{
	int max_y,max_x,mid_x,mid_y;
	max_x=getmaxx();
	max_y=getmaxy();
	mid_x=max_x/2;
	mid_y=max_y/2;
	line(0,mid_y,max_x,mid_y);
	line(mid_x,0,mid_x,max_y);
	for(int i=0;i<n-1;i++)
	{
		line(mid_x+result_rot[i][0],mid_y-result_rot[i][1],mid_x+result_rot[i+1][0],mid_y-result_rot[i+1][1]);
	}
	line(mid_x+result_rot[n-1][0],mid_y-result_rot[n-1][1],mid_x+result_rot[0][0],mid_y-result_rot[0][1]);		
}
int main()
{
    transform t;
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);
    char choice;
    int ch,tx,ty,sx,sy;
    float theta;
    //int result[10][3];
    //double result1[10][3];

    do
    {
        cout<<"1. Translate"<<endl;
        cout<<"2. Scaling"<<endl;
        cout<<"3. Rotate"<<endl;
        cout<<"Enter choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    t.get_poly();
                    t.draw_poly();
                    cout<<"\nEnter translation parameters";
                    cin>>tx>>ty;
                    t.translation(tx,ty);
                    t.disp_poly();
                    
                    break;

            case 2:
                    t.get_poly();
                    t.draw_poly();
                    cout<<"\nEnter scaling parameters";
                    cin>>sx>>sy;
                    t.scaling(sx,sy);
                    t.disp_poly();
                    break;    

            case 3 :
                    t.get_poly();
                    t.draw_poly();
                    setcolor(RED);
                    cout<<"\nEnter angle in degree";
                    cin>>theta;
                    t.rotation(theta);
                    t.disp_poly_rotation();
                    break;
            
        }
    }while(ch<4);
    getch();
    closegraph();
    return 0;
}
