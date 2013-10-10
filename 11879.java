import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        BigInteger seventeen = new BigInteger("17");
        String s = sc.next();
        while(!s.equals("0")){
            BigInteger b = new BigInteger(s);
            if(b.mod(seventeen) == BigInteger.ZERO){
                System.out.println(1);
            } else{
                System.out.println(0);
            }
            s = sc.next();
        }
    }
}
