import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String args[]){
        int VAL = 1005;
        int n;
        BigInteger fib[] = new BigInteger[VAL];
        fib[0] = fib[1] = BigInteger.ONE;
        for(int i=2;i<VAL;i++){
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()){
            n = sc.nextInt();
            System.out.println(fib[n+1]);
        }
    }
}
