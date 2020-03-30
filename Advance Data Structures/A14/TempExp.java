import java.util.*;
/*java template is different from c++ template.It needs abstract class and 
 * one final method.In this method template methods are declared.The class which is 
 * extending abstract class should define every template function.
 * In java template method can have different signatures in different classes.     
*/

abstract class TempDemo{
public final void TDemo(){
 accept();
 display();
 perform();
}
protected  abstract void accept();  //template method
protected abstract void display();
protected abstract void perform();

}

class TempOmpl extends TempDemo{
	 int a,b,c,d;
	 Scanner sc = new Scanner(System.in);
	 protected void accept(){
			System.out.println("Enter first number");
			a=sc.nextInt();
			System.out.println("Enter second number");
			b=sc.nextInt();
	 }
	 protected void display(){
			System.out.println("first number is"+a);
			System.out.println("second number is"+b);
			 }
	 
	 protected void perform(){
		 do{
		System.out.println("Enter choice\n1.Multiply\n2.Divide\n3.Exit");
		d=sc.nextInt();		
		if(d==1){
			 d=a*b;
		 System.out.println("Multiplication of two numbers is"+d);
		}
		else if(d==2){
			try{
					d=a/b;
					System.out.println("Division of two numbers is"+d);
				}
	
			catch(ArithmeticException e){
				System.out.println(":Warning divide by zero error");
			}
			catch(Exception e1){
				System.out.println("Any exception");
			}
			finally{
				System.out.println("Executed any way");
			}
			System.out.println("Out of try catch");	
		}
		 }while(d!=3);
}
}

			public class TempExp{
				 
			 	 public static void main( String[] args){
					 TempDemo Td=new TempOmpl();  //upcasting
					 Td.accept();
					 Td.display();
					 Td.perform();
					 
				 }
			}





				
