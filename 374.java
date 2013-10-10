import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextBigInteger()){
            BigInteger b = sc.nextBigInteger();
            BigInteger p = sc.nextBigInteger();
            BigInteger m = sc.nextBigInteger();
            System.out.println(b.modPow(p,m));
        }
    }
}
