import java.io.*;
import java.math.*;

public class Main {
    public static String str;
    public static BigInteger num[]=new BigInteger[10];
    public static void main(String args[]) {
        try {
        //BufferedReader cin=new BufferedReader(new InputStreamReader(new FileInputStream("A.in")));
        BufferedReader cin=new BufferedReader(new InputStreamReader(System.in));
        for(int i=0;i<10;i++)
            num[i]=new BigInteger("1");
        while((str=cin.readLine())!=null) {
        //    System.out.println(str);
            if(str.length()==0)break;
            int i1=str.charAt(0)-'A',i2;
            if(str.charAt(1)=='='){
                i2=str.charAt(2)-'A';
                num[i1]=num[i2];
            }
            else if(str.charAt(1)=='+'){
                i2=str.charAt(3)-'A';
                num[i1]=num[i1].add(num[i2]);
            }
            else{
                i2=str.charAt(3)-'A';
                num[i1]=num[i1].multiply(num[i2]);
            }
        }
        for(int i=0;i<10;i++) 
            System.out.println(num[i].toString());
        }
        catch(Exception e){
        System.out.println("error"+e.toString());
        }
    }
}
