// http://uva.onlinejudge.org/external/119/11986.html
// Runtime: 0.016s
// Tag: power of 2


// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 100010
#define LL long long

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)

using namespace std;

int rat_cnt (LL n)
{
    LL res = 1;
    int power = 0;

    if ( n < 2 ) return 0;

    while ( true ) {
        res *= 2;
        power++;
        if ( n <= res ) return power;
    }
}

int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    int cases = 0;

    while ( testCase-- ) {
        LL n;
        cin >> n;

        n++;

        printf ("Case %d: %d\n", ++cases, rat_cnt (n));

    }

	return 0;
}

// @END_OF_SOURCE_CODE
