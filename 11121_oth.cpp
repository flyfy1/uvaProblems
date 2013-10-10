#include<stdio.h>
int main()
{
    /*
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    */
    long test;
    scanf("%ld",&test);
    for(long k=1;k<=test;k++)
    {
       const long maxn=20007,base=-2;
       long n,a[maxn],top;
       scanf("%ld",&n);
       top=0;
       while(n!=0)
       {
          long r=n%base;
          n/=base;
          if(r<0)
          {
             r-=base;
             n++;
          }
          top++;a[top]=r;
       }
       printf("Case #%ld: ",k);
       if(top==0)
       {
          printf("%ld\n",0);
          continue;
       }
       while(top>0)
       {
          printf("%ld",a[top]);top--;
       }
       putchar('\n');
    }
    return 0;
}
