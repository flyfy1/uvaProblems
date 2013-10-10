import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static BigInteger tbl[] = new BigInteger[1000001];
    public static void main(String args[]){
        int tc;
        BigInteger upperLimit = new BigInteger("1000001");
        BigInteger b2 = new BigInteger("2");
        tbl[3] = BigInteger.ZERO; 
        for(BigInteger i = new BigInteger("4");
          i.compareTo(upperLimit) < 0;
          i = i.add(BigInteger.ONE)){
            BigInteger k = i.divide(b2);
            tbl[i.intValue()] = tbl[i.intValue() - 1].
                add(k.multiply(i.testBit(0)?(k.add(BigInteger.ONE)):k)).
                subtract(i.subtract(BigInteger.ONE));
        }

        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if( n == 0) break;
            System.out.println(tbl[n]);
        }
    }
}
