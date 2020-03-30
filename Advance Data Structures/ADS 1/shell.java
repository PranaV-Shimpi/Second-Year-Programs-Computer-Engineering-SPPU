//Shell sort

import java.util.Scanner;

public class shell

{
	
	public static void main(String args[])
	
	{
		
		int i,j,gap,temp;
		
		Scanner sc= new Scanner(System.in);
		
		System.out.println("Enter the no. of elements ");
		
		int n=sc.nextInt();
		
		int arr[]=new int[n];

		
		System.out.println("Enter the elements ");
		
		for (i=0;i<n;i++)
			
		arr[i]=sc.nextInt();

		
for(gap=n/2;gap>0;gap/=2)
			
		for(i=gap;i<n;i++)
				
		for(j=i-gap;j>=0 && arr[j]>arr[j+gap];j-=gap)
				
		{
					
			temp=arr[j];
					
			arr[j]=arr[j+gap];
					
			arr[j+gap]=temp;
				
		}
		
		for (i=0;i<n;i++)		
			
		System.out.print(arr[i]+" ");
		
		System.out.println();	
	
	}

}