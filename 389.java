import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    public static void main(String args[]){
        int base,to;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String val = sc.next();
            base = sc.nextInt(); to = sc.nextInt();
            String disp = Integer.toString(Integer.parseInt(val,base),to);
            disp = disp.toUpperCase();
            if(disp.length() > 7)   disp = "ERROR";
            System.out.printf("%7s\n",disp);
        }
    }
}
