/* Assignment 5 : Sparse Matrix Operations

*/

#include<iostream>
using namespace std;
void read(int sp[20][3])
{
        int r,c,t;
      cout<<"Enter total no of rows ,columns and nonzero elements in sparse matrix\n";
      cin >>r >> c >> t;
        sp[0][0]=r;
        sp[0][1]=c;
        sp[0][2]=t;
      cout<<"Enter rows, column and the nonzero element\n";
      for (int i = 1; i <= t; ++i)
            cin>>sp[i][0]>>sp[i][1]>>sp[i][2];
}// end of read

void display(int sp[20][3])
{
      cout<<"The sparse matrix is:\n";
      cout<<"Row\tCol\tValue\n";
      for (int i = 1; i <=sp[0][2]; ++i)
        {
            cout << sp[i][0]<<"\t"<< sp[i][1]<< "\t"<<sp[i][2] <<"\n";
        }

} // end of display


void add(int sp1[20][3], int sp2[20][3], int sp3[20][3])
{
        int i=1,j=1,k=1,t1,t2;
      t1=sp1[0][2];
      t2=sp2[0][2];
      while (i <= t1 && j <= t2)
      {
           if (sp1[i][0] < sp2[j][0]) // row of sp1 < sp2
           {
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                i++; k++;
           }
           else if (sp1[i][0] > sp2[j][0]) // row of sp1 > sp2
                {
                    sp3[k][0]=sp2[j][0];
                    sp3[k][1]=sp2[j][1];
                    sp3[k][2]=sp2[j][2];
                    j++; k++;
                }
                else
                {
                     if (sp1[i][1] < sp2[j][1]) // col of sp1 < sp2
                  {
                          sp3[k][0]=sp1[i][0];
                          sp3[k][1]=sp1[i][1];
                          sp3[k][2]=sp1[i][2];
                          i++; k++;
                  }
                  else
                  {
                      if (sp1[i][1] > sp2[j][1]) // col of sp1 > sp2
                      {
                          sp3[k][0]=sp2[j][0];
                          sp3[k][1]=sp2[j][1];
                          sp3[k][2]=sp2[j][2];
                          j++; k++;
                     }
                     else  // row and col of sp1=sp2
                     {
                            sp3[k][0]=sp2[j][0];
                          sp3[k][1]=sp2[j][1];
                          sp3[k][2]=sp1[i][2]+sp2[j][2];
                          i++;j++; k++;
                     }
                  }
                }

      }// end of whiile

      // add remaining terms
      while (i<=t1)
      {
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                i++; k++;
      }

      while (j<=t2)
      {
            sp3[k][0]=sp2[j][0];
            sp3[k][1]=sp2[j][1];
            sp3[k][2]=sp2[j][2];
            j++; k++;
      }
       sp3[0][0]=sp1[0][0];
       sp3[0][1]=sp1[0][1];
       sp3[0][2]=k-1;

}

void transpose(int sp1[20][3],int sp3[20][3])
{
      int k=1,i=0,c=0;
      for (c = 0; c < sp1[0][1]; c++)
            for (i = 1; i <=sp1[0][2]; i++)
                  if (sp1[i][1]==c)
                  {
                        sp3[k][0]=sp1[i][1];
                        sp3[k][1]=sp1[i][0];
                        sp3[k][2]=sp1[i][2];
                        k++;
                  }
      sp3[0][0]=sp1[0][1];
      sp3[0][1]=sp1[0][0];
      sp3[0][2]=sp1[0][2];
}



void fastrans(int sp1[20][3],int sp3[20][3])
{
      int cnt[20],pos[20],i=0;
      pos[0]=1;
      for (int i = 0; i < sp1[0][1]; i++)//setting cnt to 0
            cnt[i]=0;
      for (int i = 1; i <=sp1[0][2]; i++)//counting nonzero elements in each column
      {
            int x=sp1[i][1];
            cnt[x]++;
      }
      for (i = 1; i <sp1[0][1]; i++)//position of elements to be put in transpose matrix
            pos[i]=pos[i-1]+cnt[i-1];
      for (i = 1; i <=sp1[0][2]; i++)
      {
            int c=sp1[i][1];
            int p=pos[c];
            sp3[p][0]=sp1[i][1];
            sp3[p][1]=sp1[i][0];
            sp3[p][2]=sp1[i][2];
            pos[c]++;
      }
      sp3[0][0]=sp1[0][1];
      sp3[0][1]=sp1[0][0];
      sp3[0][2]=sp1[0][2];
}


int main()
{
     int sp1[20][3], sp2[20][3],sp3[20][3];
     int ch;
     do
     {
 	cout<<"\n\n\t\tMenu";

	cout<<"\n\t#1. Read Sparse\n\t#2. Display\n\t#3. Addition\n\t#4. Transpose\n\t#5. Fast Transpose\n\t#6. Exit\n";
	cout<<"\n\n\t\tEnter choice : ";
	cin>>ch;

	switch(ch)
	{

	   case 6 :
		   break;

           case 1 :
		   cout << "\n Sparse 1 :\n";
                   read(sp1);
                   cout << "\n Sparse 2 :\n";
                   read(sp2);
		   break;

           case 2 :
                   display(sp1);
                   display(sp2);
                   break;

           case 3 :
                   add(sp1,sp2,sp3);
                   cout << "\n\n Addition is :\n";
                   display(sp3);
                   break;

           case 4 :
                   transpose(sp1,sp3);
                   cout << "\n Transpose is :\n";
                   display(sp3);
		   break;

           case 5 :

                   fastrans(sp1,sp3);
                   display(sp3);
                   break;

           default :
                    cout<<"\n\n\t\tWrong input...\n";
                    break;
        }

      } while (ch!=6);
      return 0;
}
// end of main





