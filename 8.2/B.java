import java.util.ArrayList;
import java.io.*;
import java.math.*;


public class Main {

    public static final long mod=1000000000000007L;
    public static String s1,s2;
    public static int[] r1=new int[10005];
    public static int[] r2=new int[10005];
    public static ArrayList<Integer> a1=new ArrayList<Integer>(),a2=new ArrayList<Integer>();
    public static long sh1,sh2,h;
    public static int m;
    public static long roll,seg2;

    public static Boolean rolling(int len) {
        int l=0,r=len;
        long tmpsh1=sh1;
        seg2=0;
        roll=1;
        for( int ci=1;ci<=len+1;ci++) {
            if(tmpsh1==sh2)return true;
            r=r==len?0:r+1;
            seg2=(seg2*m + r1[r]);
            if(seg2>mod)seg2-=mod;
            roll=roll*m;
            if(roll>mod)roll-=mod;
            tmpsh1=(tmpsh1*m +r1[r] + mod - h*r1[l]);
            while(tmpsh1>mod)tmpsh1-=mod;
            l++;
        }
        return false;
    }


    public static void main(String args[]) {

        try {
            BufferedReader cin =new BufferedReader(new InputStreamReader(new FileInputStream("A.in")));
            //BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
            //PrintWriter cout=new PrintWriter(System.out);
            PrintWriter cout=new PrintWriter(new BufferedOutputStream(new FileOutputStream("Ajava.out")));
            while ((s1= cin.readLine()) != null) {
                s2= cin.readLine();
                int len = s1.length();
                m = 0;
                for (int i = 0; i < len; i++) {
                    r1[i] = s1.charAt(i) - 'a';
                    r2[i] = s2.charAt(i) - 'a';
                    m = Math.max(m, r1[i]);
                    m = Math.max(m, r2[i]);
                }
                m++;
                a1.clear();
                a2.clear();
                for (int i = 0; i < m; i++) {
                    a1.add(0);
                    a2.add(0);
                }
                h = 1;
                sh1 = 0;
                sh2 = 0;
                seg2=-1;
                long seg1 = -1;
                long seg12, seg22 = -1;
                long tmpseg = -1, tmpseg2 = -1;
                for (int pos = 0; pos < len; pos++) {
                    h = h * m;
                    if (h > mod) h -= mod;
                    if (seg2 != -1) {
                        seg1 = (sh2 + mod - seg2);
                        while (seg1 > mod) seg1 -= mod;

                        seg12 = (sh2 + mod - seg22);
                        while (seg12 > mod) seg12 -= mod;

                        seg2 = (seg2 + r1[pos] * roll);
                        while (seg2 > mod) seg2 -= mod;

                        seg22 = (seg22 * m + r1[pos]);
                        while (seg22 > mod) seg22 -= mod;

                        roll = (roll * m);
                        if (roll > mod) roll -= mod;
                        tmpseg = (seg1 * m + seg2);
                        while (tmpseg > mod) tmpseg -= mod;
                        tmpseg2 = (seg12 * m + seg22);
                        while (tmpseg2 > mod) tmpseg2 -= mod;
                    }
                    sh1 = (sh1 * m + r1[pos]);
                    if (sh1 > mod) sh1 -= mod;
                    sh2 = (sh2 * m + r2[pos]);
                    if (sh2 > mod) sh2 -= mod;
                    a1.set(r1[pos],a1.get(r1[pos])+1);
                    a2.set(r2[pos],a2.get(r2[pos])+1);

                    if (!a1.equals(a2)) {
                        cout.write("0");
                        continue;
                    }
                    if (tmpseg == sh2 || tmpseg2 == sh2) {
                        //printf("0");
                        cout.write("1");
                    }
                    else {
                        if (rolling(pos)) {
                            seg22 = seg2;
                            cout.write("1");
                        } else
                            cout.write("0");
                    }
                }
                cout.println();
            }
            cout.close();
        }
        catch(Exception e) {
            System.out.println(e);
        }
    }

}

