import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static BigInteger tbl[][] = new BigInteger[2][10000000];
    static BigInteger getC(int n,int m){
        if(n < m)   return BigInteger.ZERO;
        if(n == m || m == 0)  return BigInteger.ONE;
        return tbl[n&1][m];
    }
    public static void main(String args[]){
        boolean ctl = true;
        BigInteger upper = BigInteger.ONE;
        for(int i=0;i<60;i++) upper = upper.multiply(BigInteger.TEN);
        System.out.println("1");
        for(int n=1;ctl;n++){
            System.out.print("1");
            for(int m=1;m <= n; m++){
                tbl[n&1][m] = getC(n-1,m-1).add(getC(n-1,m));
                System.out.print(" " + tbl[n&1][m].toString());
                if(tbl[n&1][m].compareTo(upper) >= 0)   ctl = false;
            }
            System.out.println();
        }
    }
}
