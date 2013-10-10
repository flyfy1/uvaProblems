import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static TreeMap<BigInteger,TreeMap<BigInteger,BigInteger> > mm = new TreeMap<BigInteger,TreeMap<BigInteger,BigInteger> >();

    // assume a,b already there
    static BigInteger getCHelper(BigInteger a, BigInteger b){
        if(a.compareTo(b) < 0)   return BigInteger.ZERO;
        if(b.compareTo(BigInteger.ZERO) == 0|| b.compareTo(a) == 0){
            return BigInteger.ONE;
        }
        return mm.get(a).get(b);
    }
    static BigInteger getC(BigInteger a, BigInteger b){
        if(a.compareTo(b) < 0)   return BigInteger.ZERO;
        if(b.compareTo(BigInteger.ZERO) == 0|| b.compareTo(a) == 0){
            return BigInteger.ONE;
        }
        if(mm.containsKey(a)){
            if(mm.get(a).containsKey(b))    return mm.get(a).get(b);
        }

        // build the table... otherwise it would cause stack overflow problem
        for(BigInteger n = BigInteger.ONE; n.compareTo(a) <= 0; n = n.add(BigInteger.ONE)){
            if(mm.containsKey(n))   continue;
            mm.put(n,new TreeMap<BigInteger,BigInteger>());
            for(BigInteger m = BigInteger.ONE; m.compareTo(n) <= 0; m = m.add(BigInteger.ONE)){
                BigInteger res = getCHelper(n.subtract(BigInteger.ONE),m.subtract(BigInteger.ONE)).add(getCHelper(n.subtract(BigInteger.ONE),m));
                mm.get(n).put(m,res);
            }
        }
        return mm.get(a).get(b);
    }
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextBigInteger()){
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            System.out.println(getC(a,b).toString().length());
        }
    }
}
