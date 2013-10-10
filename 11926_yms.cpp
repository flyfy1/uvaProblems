#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
#define LSOne(s) (s & (-s))

void ft_create(vi &t, int n) {
    t.assign(n + 1, 0);
}

int ft_rsq(const vi &t, int b) {
    int sum = 0;
    for (; b; b -= LSOne(b)) sum += t[b];
    return sum;
}

int ft_rsq(const vi &t, int a, int b) {
    return ft_rsq(t, b) - (a == 1 ? 0 : ft_rsq(t, a - 1));
}

void ft_adjust(vi &t, int k, int v) {
    for (; k <= (int)t.size(); k += LSOne(k)) {
        t[k] += v;
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
        vi calendar;
        ft_create(calendar, 1000001);

        bool conflict = false;

        for (int i = 0; i < n; i++) {
            int start, end;
            scanf("%d %d", &start, &end);

            if (conflict) continue;

            for (int k = start + 1; k <= end; k++) {
                if (ft_rsq(calendar, k, k) >= 1) {
                    conflict = true;
                    break;
                }
                ft_adjust(calendar, k, 1);
            }
        }
        for (int i = 0; i < m; i++) {
            int start, end, interval;
            scanf("%d%d%d", &start, &end, &interval);

            if (conflict) continue;

            int base = 0;
            while (base <= 1000000) {
                for (int k = start + 1; k <= end; k++) {
                    if (k + base > 1000000) break;

                    if (ft_rsq(calendar, k + base, k + base) >= 1) {
                        conflict = true;
                        break;
                    }

                    ft_adjust(calendar, k + base, 1);
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
