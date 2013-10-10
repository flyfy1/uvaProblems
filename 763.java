import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static int TABLE_NUM = 105;
    static BigInteger tbl[] = new BigInteger[TABLE_NUM];
    
    static BigInteger readFibinaryNum(String s){
        int l = s.length();
        BigInteger res = BigInteger.ZERO;
        for(int i=0;i<l;i++){
            if(s.charAt(l-1-i) == '1'){
                res = res.add(tbl[i]);
            }
        }
        return res;
    }

    static String toStrFibinaryNum(BigInteger a){
        // handle the special case first
        if(a.compareTo(BigInteger.ZERO) == 0)   return "0";

        // first find the start location
        int k = TABLE_NUM - 1;
        while(tbl[k].compareTo(a) > 0)  k--;
        StringBuffer buf = new StringBuffer();
        for(int i=0;i<=k;i++){
            if(tbl[k-i].compareTo(a) <= 0){
                a = a.subtract(tbl[k-i]);
                buf.append('1');
            } else{
                buf.append('0');
            }
        }
        return buf.toString();
    }

    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        tbl[0] = BigInteger.ONE; tbl[1] = new BigInteger("2");
        for(int i=2;i<TABLE_NUM;i++){
            tbl[i] = tbl[i-2].add(tbl[i-1]);
        }

        String s;
        BigInteger a,b,c;
        boolean first = true;
        while(sc.hasNext()){
            if(first) first = false;
            else System.out.println();
            a = readFibinaryNum(sc.next());
            b = readFibinaryNum(sc.next());
            c = a.add(b);
            System.out.println(toStrFibinaryNum(c));
        }
    }
}
