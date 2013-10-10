import java.lang.*;
import java.util.*;
import java.math.*;

class Main{
  public static void main(String args[]){
    // L: current lock code
    // U: target lock code
    // R: num
    int L,U,R;
    Scanner sc = new Scanner(System.in);
    int caseCnt = 1;

    while(true){
      // Input
      L = sc.nextInt();
      U = sc.nextInt();
      R = sc.nextInt();

      if(L == 0 && U == 0 && R == 0)  break;
      int[] RV = new int[R];
      for(int i = 0 ; i < R ; i++){
        RV[i] = sc.nextInt();
      }

      // search for output, U is the starting point
      boolean[] visited = new boolean[10001];
      
      // first: current digit, 
      // second: depth
      Queue<Pair> q = new LinkedList<Pair>();
      q.add(new Pair(L, 0));
      int ans = -1;
      while(!q.isEmpty()){
        Pair ele = q.poll();
        if(visited[ele.a]) continue;
        if(ele.a == U){ ans = ele.b; break; }
        visited[ele.a] = true;

        for(int i = 0 ; i < R ; i++){
          int nextValue = (ele.a + RV[i]) % 10000;
          if(!visited[nextValue]) q.add(new Pair(nextValue, ele.b + 1));
        }
      }

      System.out.printf("Case %d: ",caseCnt++);

      if(ans == -1) System.out.println("Permanently Locked");
      else System.out.println(ans);
    }
  }
}

class Pair{
  int a, b;
  Pair(int _a, int _b){
    this.a = _a; this.b = _b;
  }
}
