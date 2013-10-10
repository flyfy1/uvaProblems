import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static BigInteger b400 = new BigInteger("400");
    static BigInteger b4 = new BigInteger("4");
    static BigInteger b100 = new BigInteger("100");
    static BigInteger b15 = new BigInteger("15");
    static BigInteger b55 = new BigInteger("55");

    static boolean isLeapYear(BigInteger y){
        return (
                (y.mod(b100) != BigInteger.ZERO) && 
                (y.mod(b4)   == BigInteger.ZERO)) ||
                (y.mod(b400) == BigInteger.ZERO);
    }
    static boolean isHuluFest(BigInteger y){
        return (y.mod(b15) == BigInteger.ZERO);
    }
    static boolean isBuluFest(BigInteger y){
        return isLeapYear(y) && (y.mod(b55) == BigInteger.ZERO);
    }
    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        BigInteger y;
        boolean first = true;
        while(sc.hasNextBigInteger()){
            if(first) first = false;
            else    System.out.println();

            boolean ordYear = true;
            y = sc.nextBigInteger();
            if(isLeapYear(y)){
                ordYear = false;
                System.out.println("This is leap year.");
            }
            if(isHuluFest(y)){
                ordYear = false;
                System.out.println("This is huluculu festival year.");
            }
            if(isBuluFest(y)){
                ordYear = false;
                System.out.println("This is bulukulu festival year.");
            }
            if(ordYear){
                ordYear = false;
                System.out.println("This is an ordinary year.");
            }
        }
    }
}
