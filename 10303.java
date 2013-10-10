import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static BigInteger tbl[] = new BigInteger[1001];
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        BigInteger upperLimit = new BigInteger("1001");
        BigInteger b2 = new BigInteger("2");
        tbl[0] = tbl[1] = BigInteger.ONE;

        for(BigInteger i = b2; 
          i.compareTo(upperLimit) < 0;
          i = i.add(BigInteger.ONE)){
            tbl[i.intValue()] = 
                b2.multiply(b2.multiply(i).subtract(BigInteger.ONE)).multiply(tbl[i.intValue() - 1]).divide(i.add(BigInteger.ONE));
        }

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            System.out.println(tbl[n]);
        }
    }
}
