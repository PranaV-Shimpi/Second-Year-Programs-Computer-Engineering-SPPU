import java.lang.*;
import java.awt.*;
import java.util.*;


class Scope
{
	int rollNo; 	//Global Parameter
	String name = ""; //Global Parameter
	Scanner s  = new Scanner(System.in);
	
	public void Demo(int r, String k) 	//This is the function having public access specifier and formal parameter
	{
		int rollNo;	//Local Parameter
		String n = ""; //Local Parameter
		rollNo = r;	
		n = k;
		System.out.println("Value of Local Parameter roll::"+rollNo); //Accessing Local Parameter
		System.out.println("Value of Global Parameter::"+this.rollNo); //Accessing Global Parameter
		System.out.println("Value in Local Parameter n::"+n);
	}
}

public class Exp13
{
	public static void main(String arg[])
	{
		Scope s = new Scope();
		s.Demo(20,"Hello");
	}
}

