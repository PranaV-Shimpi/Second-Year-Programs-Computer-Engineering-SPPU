import java.util.*;
import java.lang.*;

class Bankx
{
	int ch=0;
	int dipo=0,with=0,fin=0;
	int am=0,years=0,interest=0;
	Scanner s = new Scanner(System.in);
	public void Deposit()
	{
		System.out.println("Enter amount to deposit");
		dipo = s.nextInt();
		fin =fin+dipo;
		System.out.println("Deposit amount::"+dipo);
		System.out.println("Final Amount::"+fin);
	}
	public void withdraw()
	{
		System.out.println("Enter amount to withdraw. If balance is less than 1000 then Withdrawal will not proceed");
		with=s.nextInt();
		if(fin<=1000)
		{
			System.out.println("Can't Proceed");
		}
		else
		{
			System.out.println("Processing...");
			fin=fin-with;
			System.out.println("Balance::"+fin);
		}
	}
}

class Saving extends Bankx
{
	//Deposit();
	//withdraw();
	void display()
	{	
		System.out.println("This is saving acount");
		System.out.println("Check Book available");
	}
}

class Current extends Bankx
{
	//Deposit();
	//withdraw();
	void display2()
	{	
		System.out.println("This is current acount");
		System.out.println("Check Book not available");
	}
}

class FD extends Bankx
{
	
	public void short1()
	{
		System.out.println("This FD will mature after 24 months. 100rs is interest on every month ");
		System.out.println("Enter amount for FD");
		am = s.nextInt();
		interest = 24*100;
		am = am+interest;
		System.out.println("Your amount is:: "+am);
		
	}
	public void Medium()
	{
		System.out.println("This FD will mature after 36 months. 100rs is interest on every month ");
		System.out.println("Enter amount for FD");
		am = s.nextInt();
		interest = 34*100;
		am = am+interest;
		System.out.println("Your amount is:: "+am);
		
	}
	public void Large()
	{
		System.out.println("This FD will mature after 60 months. 100rs is interest on every month ");
		System.out.println("Enter amount for FD");
		am = s.nextInt();
		interest = 60*100;
		am = am+interest;
		System.out.println("Your amount is:: "+am);
		
	}
}

class Bank
{
	public static void main(String arg[])
	{
		FD f = new FD();
		Saving sa = new Saving();
		Current cu = new Current();
		Scanner k = new Scanner(System.in);
		int ch,i;
		do
		{
			System.out.println("1. Saving 2.Current 3.FD enter your choice::");
			ch = k.nextInt();
			switch(ch)
			{
				case 1:
					sa.Deposit();
					sa.withdraw();
					sa.display();
					break;
				case 2: 
					cu.Deposit();
					cu.withdraw();
					cu.display2();
					break;
				case 3:
					f.short1();
					f.Medium();
					f.Large();			
					break;
			}
			
			System.out.println("Want to perform more then enter 1");
			i = k.nextInt();
		}while(i==1);
	}
}
