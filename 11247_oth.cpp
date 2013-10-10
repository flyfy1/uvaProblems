#include <iostream>
#include <cstdio>
#include <cmath>
#define ERR        1e-10

using namespace std;

int main() {
int m, x;
double mm, t, res;

while (scanf("%d %d", &m, &x), m || x) {
    if (x == 100 || x == 0) {
        printf("Not found\n");
        continue;
    }

    mm = m;

    res = 100 * (mm - 1) / (100 - x);
    if (res - (t = floor(res)) > ERR)
        res = t;
    else
        res = t - 1;

    if (res >= m)
        printf("%.0lf\n", res);
    else
        printf("Not found\n");
}

return 0;
}
