#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		bitset<1000001> calendar;
		calendar.reset();
		
		bool conflict = false;
		for (int i = 0; i < n; i++) {
			int start, end;
			scanf("%d %d", &start, &end);
			
			if (conflict) continue;
			
			for (int k = start; k < end; k++) {
				if (calendar.test(k)) {
					conflict = true;
					break;
				}
				calendar.set(k);
			}
		}
		for (int i = 0; i < m; i++) {
			int start, end, interval;
			scanf("%d%d%d", &start, &end, &interval);
				//cout << interval << endl;
			
			if (conflict) continue;
			
			int base = 0;
			while (base <= 1000000) {
				//cout << base << endl;
				for (int k = start; k < end; k++) {
					if (k + base > 1000000) break;
					
					if (calendar.test(k + base)) {
						conflict = true;
						break;
					}
					calendar.set(k + base);
				}
				if (conflict) break;
				base += interval;
			}
		}
		if (conflict) printf("CONFLICT\n");
		else printf("NO CONFLICT\n");
	}
	return 0;
}
