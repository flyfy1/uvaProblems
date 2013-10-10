import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        BigInteger tbl[] = new BigInteger[801];
        tbl[0] = BigInteger.ONE; tbl[1] = BigInteger.ZERO;
        BigInteger upper = new BigInteger("801");

        for(BigInteger i=new BigInteger("2");i.compareTo(upper) < 0;i = i.add(BigInteger.ONE)){
            tbl[i.intValue()] = i.subtract(BigInteger.ONE).multiply(tbl[i.intValue() - 1].add(tbl[i.intValue() - 2]));
        }
        while(true){
            tc = sc.nextInt();
            if(tc == -1)    break;
            System.out.println(tbl[tc]);
        }
    }
}
