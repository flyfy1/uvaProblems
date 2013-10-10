import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        tc = sc.nextInt();
        while(tc-- > 0){
            BigDecimal sum = new BigDecimal(0);
            BigDecimal num = BigDecimal.ZERO;
            do{
                sum = sum.add(num);
                num = sc.nextBigDecimal();
            } while(num.compareTo(BigDecimal.ZERO) != 0);
            if(sum.compareTo(BigDecimal.ZERO) == 0) System.out.println(0);
            else System.out.println(sum.stripTrailingZeros().toPlainString());
        }
    }
}
