import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        BigInteger v = new BigInteger("131071");
        while(sc.hasNext()){
            String s = sc.next();
            while(s.charAt(s.length() - 1) != '#'){
                s = s + sc.next();
            }
            s = s.substring(0,s.length()-1);
            BigInteger b = new BigInteger(s,2);
            System.out.println(b.mod(v).compareTo(BigInteger.ZERO) == 0 ? "YES":"NO");
        }
    }
}
