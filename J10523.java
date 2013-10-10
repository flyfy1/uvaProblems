import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        BigInteger n,a;
        while(sc.hasNext()){
            n = new BigInteger(sc.next());
            a = new BigInteger(sc.next());
            BigInteger res = new BigInteger("0");
            for(BigInteger i = new BigInteger("1");
                i.compareTo(n) <= 0;i = i.add(BigInteger.ONE)){
                res = res.add( i.multiply(a.pow(i.intValue())));
            }
            System.out.println(res);
        }
    }
}
