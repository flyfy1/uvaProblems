import java.lang.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

class Main{
    static String regQFormat = "^\\d+:\\d+:\\d+$";
    static String regVFormat = "^(\\d{2}:\\d{2}:\\d{2}) (\\d+)$";
    static Pattern ptnQFormat = Pattern.compile(regQFormat);
    static Pattern ptnVFormat = Pattern.compile(regVFormat);

    // Unit is second
    static double strToTime(String str){
        String s[] = str.split(":");
        double res = 0;
        for(int i=0;i<s.length;i++){
            res *= 60;
            res += Double.parseDouble(s[i]);
        }
        return res;
    }
    static double ct=0,cd=0,lt=0,cv=0;
    static double getCurrentDist(){
        return cd + (ct - lt) * cv / 3600;
    }

    public static void main(String args[]){
        int tc;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String ln = sc.nextLine();
            Matcher mv = ptnVFormat.matcher(ln);
            if(mv.find()){
                ct = strToTime(mv.group(1));
                cd = getCurrentDist();
                lt = ct;
                cv = Double.parseDouble(mv.group(2));
                continue;
            }

            // otherwise execute the query
            ct = strToTime(ln);
            System.out.printf("%s %.2f km\n",ln,getCurrentDist());
        }
    }
}
