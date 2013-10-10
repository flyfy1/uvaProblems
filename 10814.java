import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        tc = sc.nextInt();
        while(tc-- > 0){
            BigInteger a = sc.nextBigInteger();
            sc.next();
            BigInteger b = sc.nextBigInteger();
            BigInteger c = a.gcd(b);
            a = a.divide(c);
            b = b.divide(c);
            System.out.println(a + " / " + b);
        }
    }
}
