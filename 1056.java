import java.util.*;

class IdxSolver{
  TreeMap<String, Integer> mp;
  int cnt;

  IdxSolver(){
    mp = new TreeMap<String, Integer>();
    cnt = 0;
  }

  int getNameIdx(String name){
    Integer n = mp.get(name);
    if(n == null){
      n = cnt; cnt++; mp.put(name,n);
    }
    return n;
  }
}

class Main{

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in); int TC = 0;

    while(true){
      TC++;
      int P, R;
      P = sc.nextInt();
      R = sc.nextInt();
      if(P == 0 && R == 0)  break;

      // Handle Additional Input
      IdxSolver idxSolver = new IdxSolver();
      int degrees[][] = new int[P][P];
      for(int i = 0 ; i < P ; i++) Arrays.fill(degrees[i],-1);
      for(int i = 0 ; i < P ; i++) degrees[i][i] = 0;

      for(int i = 0 ; i < R ; i++){
        String a = sc.next(), b = sc.next();

        int na = idxSolver.getNameIdx(a),
            nb = idxSolver.getNameIdx(b);
        degrees[na][nb] = degrees[nb][na] = 1;
      }
      
      // floyd warshall
      for(int k = 0 ; k < P ; k++){
        for(int i = 0 ; i < P ; i++){
          for(int j = 0 ; j < P ; j++){
            if( degrees[i][k] > 0 && degrees[k][j] > 0 && 
              ( degrees[i][j] < 0 || 
                ( degrees[i][k] + degrees[k][j] < degrees[i][j]) ) ){
              degrees[i][j] = degrees[i][k] + degrees[k][j];
            }
          }
        }
      }

      // search for the maximum, or the graph is not connected
      int max = 0;
      for(int i = 0 ; i < P ; i++){
        for(int j = 0 ; j < P ; j++){
          if(degrees[i][j] == -1){
            max = -1; break;
          } else if(degrees[i][j] > max){
            max = degrees[i][j];
          }
        }
      }

      System.out.printf("Network %d: ",TC);
      if(max == -1){
        System.out.println("DISCONNECTED");
      } else{
        System.out.println(max);
      }
      System.out.println();
    }
  }
}
