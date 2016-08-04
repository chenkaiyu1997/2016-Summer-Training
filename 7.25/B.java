import java.io.*;
import java.math.*;
import java.util.*;

public class B{
	
	public static ArrayList<BigInteger> s=new ArrayList<BigInteger>();
	public static ArrayList<BigInteger> s2=new ArrayList<BigInteger>();
	public static final BigInteger b10=new BigInteger("10");

	public static boolean check(BigInteger a,int i){
		String str=a.toString();
		int len=str.length();
		for(int j=0;j<=i;j++){
			boolean is0=true;
			if(len-j-1>=0) is0=str.charAt(len-j-1)=='0';
			if(!(a.testBit(j) ^ is0))
				return false;
		}
		return true;
	}
	
	public static String work(int n) {
		s.clear();
		s.add(new BigInteger("0"));
		int cnt=0;
		BigInteger tmp=new BigInteger("1"); 
		for(int i=0;i<=10000;i++){
			s2.clear();
			if(i!=0)tmp=tmp.multiply(b10);
			for(int j=0;j<s.size();j++) {
				if(check(s.get(j),i))
					s2.add(s.get(j));
			}
			for(int j=0;j<s.size();j++) {
				BigInteger tmp2=s.get(j).add(tmp);
				if(check(s.get(j).add(tmp),i)){
					cnt++;
					if(cnt==n)
						return tmp2.toString();
					s2.add(tmp2);
				}
			}
			s.clear();
			s.addAll(s2);
		}
		return "0";
	}
	
	public static void main(String args[]) {
		try{
			Scanner cin = new Scanner(new BufferedInputStream(new FileInputStream("binary.in")));
			PrintWriter cout = new PrintWriter(new BufferedOutputStream(new FileOutputStream("binary.out")));
			int n=cin.nextInt();
			cout.println(work(n));
			cout.close();
		}
		catch(Exception e){
			System.out.println("File error!");
		}
	}
}
	
		
