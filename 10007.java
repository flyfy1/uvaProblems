import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static BigInteger tbl[] = new BigInteger[301];
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        BigInteger upperLimit = new BigInteger("301");
        BigInteger bnf1 = BigInteger.ONE;
        BigInteger b2nf = BigInteger.ONE;
        BigInteger b2 = new BigInteger("2");
        for(BigInteger i = BigInteger.ONE; 
          i.compareTo(upperLimit) < 0;
          i = i.add(BigInteger.ONE)){
            BigInteger b2i = i.multiply(b2);
            bnf1 = bnf1.multiply(i.add(BigInteger.ONE));
            b2nf = b2nf.multiply(b2i);
            b2nf = b2nf.multiply(b2i.subtract(BigInteger.ONE));
            tbl[i.intValue()] = b2nf.divide(bnf1);
        }
        while(true){
            int n = sc.nextInt();
            if(n == 0)  break;
            System.out.println(tbl[n]);
        }
    }
}
