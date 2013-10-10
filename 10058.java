import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
    static String SPACE = " ";
    static String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
    static String VERB = "(hate|love|know|like)s*";
    static String ARTICLE = "(a|the)";
    static String ACTOR = "(" + NOUN + "|" + ARTICLE + SPACE + NOUN + ")";
    static String ACTIVE_LIST= "((" + ACTOR + SPACE + "and" + SPACE + ")*" + ACTOR + ")";
    static String ACTION = "(" + ACTIVE_LIST + SPACE + VERB + SPACE + ACTIVE_LIST + ")";
    static String STATEMENT = "((" + ACTION + SPACE + "," + SPACE + ")*" + ACTION + ")";
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String s = sc.nextLine();
            if(s.matches(STATEMENT)){ //".*" + ACTION + ".*")){
                System.out.println("YES I WILL");
            } else{
                System.out.println("NO I WON’T");
            }
        }
    }
}
