#include <stdio.h>

#define N 15

struct guess
{
  int num[4];
  int a, b;
}g[N];

int main()
{
//  freopen("in", "r", stdin);
  int t, n, a, b, data;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d/%d", &data, &a, &b);
        g[i].num[0] = data / 1000; g[i].num[1] = (data % 1000) / 100;
        g[i].num[2] = (data % 100) / 10; g[i].num[3] = data % 10;
        g[i].a = a, g[i].b = b;
    }
    int num[4], mk[2][4], flag, count(0), ans[4];
    for(int i = 0; i < 10000; i++)
    {
        num[0] = i / 1000; num[1] = (i % 1000) / 100;
        num[2] = (i % 100) / 10; num[3] = i % 10;
        flag = 0;
        for(int j = 0; j < n; j++)
        {
            a = b = 0;
            for(int k = 0; k < 4; k++) mk[0][k] = mk[1][k] = 0;
            for(int k = 0; k < 4; k++)
            {
                if(num[k] == g[j].num[k])
                {
                    mk[0][k] = mk[1][k] = 1;
                    a++;
                }
            }
            for(int k = 0; k < 4; k++)
            {
                if(mk[0][k]) continue;
                for(int l = 0; l < 4; l++)
                {
                    if(mk[1][l]) continue;
                    if(g[j].num[k] == num[l])
                    {
                        mk[0][k] = mk[1][l] = 1;
                        b++;
                        break;
                    }
                }
            }
            if(a != g[j].a || b != g[j].b)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            count++;
            ans[0] = num[0], ans[1] = num[1];
            ans[2] = num[2], ans[3] = num[3];
        }
    }
    if(!count) puts("impossible");
    else if(count == 1) printf("%d%d%d%d\n", ans[0], ans[1], ans[2], ans[3]);
    else puts("indeterminate");
  }
  return 0;
}
