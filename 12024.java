import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static BigInteger tbl[] = new BigInteger[20];
    static BigInteger fac[] = new BigInteger[20];
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        tbl[0] = BigInteger.ONE; tbl[1] = BigInteger.ZERO;
        fac[0] = fac[1] = BigInteger.ONE;
        BigInteger upper = new BigInteger("20");

        for(BigInteger i=new BigInteger("2");i.compareTo(upper) < 0;i = i.add(BigInteger.ONE)){
            tbl[i.intValue()] = i.subtract(BigInteger.ONE).multiply(tbl[i.intValue() - 1].add(tbl[i.intValue() - 2]));
            fac[i.intValue()] = fac[i.intValue() - 1].multiply(i);
        }

        tc = sc.nextInt();
        while(tc-- > 0){
            int n = sc.nextInt();
            BigInteger a = tbl[n];
            BigInteger b = fac[n];
            BigInteger c = a.gcd(b);
            System.out.println(a + "/" + b);
        }
    }
}
