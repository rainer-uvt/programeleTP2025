import java.math.BigInteger;
import java.util.Scanner;


public class numereMari{
	public static void main(String args[]){
		String s1, s2;
		Scanner sc=new Scanner(System.in);
		s1=sc.nextLine();
		s2=sc.nextLine();
		BigInteger b1=new BigInteger(s1);
		BigInteger b2=new BigInteger(s2);
		BigInteger su=b1.add(b2);
		BigInteger pr=b1.multiply(b2);
		System.out.println(su);
		System.out.println(pr);
	}
}