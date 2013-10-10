import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        String ts;
        tc = sc.nextInt();
        while(tc-- != 0){
            ts = sc.next();
            BigInteger a = new BigInteger((new StringBuffer(ts)).reverse().toString());
            ts = sc.next();
            BigInteger b = new BigInteger((new StringBuffer(ts)).reverse().toString());
            BigInteger r = a.add(b);
            System.out.println(new BigInteger( (new StringBuffer(r.toString()).reverse().toString())).toString());
        }
    }
}
