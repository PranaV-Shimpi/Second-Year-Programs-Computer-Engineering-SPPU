//Exception handle

import java.util.Scanner;


class student
{
	
	public static void main(String[] args) 
	{

	
		
		Scanner sc=new Scanner(System.in);
		
		float tot=0;
		
		int[] marks=new int [5];
		
		String[] name=new String [5];
		
		System.out.println("Enter no of students ");
		
		int n=sc.nextInt();
		
		
		try 
		{
			
			for (int i=0; i<n; i++) 
			{
				
				System.out.println("Enter name");
								name[i]=sc.nextLine();
								System.out.println("Enter marks");
								marks[i]=sc.nextInt();

			
			}

			
			for (int i=0; i<n; i++) 
			{
				
				tot+=marks[i];
			
			}
			
			if(n==0)
                
			throw new ArithmeticException();
			
			float per=tot/n;
			
			System.out.println("Percentage is "+per);

		
		}
		
		catch(NumberFormatException ne)				
		//gsheet
		
		{
			
			System.out.println("Given string does not contain a number\n");
				}
			
		catch(StringIndexOutOfBoundsException ne)
		
		{
			
			System.out.println("Invalid string index\n");
		
		}
		
		catch(NullPointerException ne)
		
		{
			
			System.out.println("Null Pointer Exception\n");
		
		}
		
		catch(ArrayIndexOutOfBoundsException ne)
		
		{
			
			System.out.println("Invalid array index, index from 0 to 5 only\n");
			}
		
		catch(ArithmeticException ne)
		
		{
			
			System.out.println("Divide by zero error\n");
		
		}
		

	
	}

}
