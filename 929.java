import java.util.*;


class Main{
  public static void main(String args[]){
    int TC, R, C; // 1 ~ 999
    int rAdd[] = {0,-1,1,0}, cAdd[] = {-1,0,0,1};
    
    Scanner sc = new Scanner(System.in);

    TC = sc.nextInt();
    
    while(TC-- > 0){
      R = sc.nextInt();
      C = sc.nextInt();

      int maze[][] = new int[R][C];
      int costTable[][] = new int[R][C];  // init to MaxInt

      for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++){
          maze[i][j] = sc.nextInt();
          costTable[i][j] = Integer.MAX_VALUE;
        }
      }

      // do calculation
      PriorityQueue<IntegerTriple> pq = new PriorityQueue<IntegerTriple>();
      pq.add(new IntegerTriple(maze[0][0],0,0)); costTable[0][0] = maze[0][0];

      int ans = -1;

      while(!pq.isEmpty()){
        IntegerTriple currentNode = pq.poll();
        int r = currentNode.b, c = currentNode.c, cost = currentNode.a;
        if(r == R - 1 && c == C - 1){
          ans = cost; break;
        }

        if(cost == costTable[r][c]){
          for(int i = 0 ; i < 4 ; i++){
            int nr = r + rAdd[i], nc = c + cAdd[i];
            if( nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            int nCost = cost + maze[nr][nc];

            if(nCost < costTable[nr][nc]){
              pq.add(new IntegerTriple(nCost, nr, nc));
              costTable[nr][nc] = nCost;
            }
          }
        }
      }
      System.out.println(ans);
    }
  }
}

class IntegerTriple implements Comparable<IntegerTriple>{
  int a,b,c;
  public int compareTo(IntegerTriple t){
    return a - t.a;
  }

  IntegerTriple(int a, int b, int c){
    this.a = a ; this.b = b ; this.c = c ;
  }
}
