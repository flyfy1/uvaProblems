import java.util.*;

class Main_10182 {
	public static void main(String[] args) {
		int pos[][] = new int[102000][2];
		pos[1][0] = pos[1][1] = 0;
		int i, j, k;
		int offset[][] = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
		for (i = 2, j = 6, k = 1; i < 100000; i+= j, j += 6, ++k) {
			
			for (int m = 1; m <= k; m++) {
				pos[i + m - 1][0] = k - m;
				pos[i + m - 1][1] = m;
			}
			for (int n = 0; n < 5; n++) {
				int x = i + k * (n + 1);
				for (int m = 0; m < k; m++) {
					pos[x + m][0] = pos[x + m - 1][0] + offset[n][0];
					pos[x + m][1] = pos[x + m - 1][1] + offset[n][1];
				}
			}
		}
		Scanner in = new Scanner(System.in);
		try {
			while (true) {
				int n = in.nextInt();
				System.out.printf("%d %d\n", pos[n][0], pos[n][1]);
			}
		} catch (Exception ex) {
		}
	}
}
