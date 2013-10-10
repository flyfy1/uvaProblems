import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        while(true){
            BigInteger n = sc.nextBigInteger();
            if(n.compareTo(BigInteger.ZERO) == 0)   break;
            String s = n.toString(2);
            int count = 0;
            for(int i = 0;i<s.length();i++){
                if(s.charAt(i) == '1')  count++;
            }
            System.out.println("The parity of "+ s + " is "+ count + " (mod 2).");
        }
    }
}
