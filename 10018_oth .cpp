#include <iostream>   
using namespace std;   
  
unsigned Reverse(unsigned n)   
{   
    unsigned temp = n,m = 0;   
    while (temp)   
    {   
        m = 10 *m + temp % 10;   
        temp /= 10;   
    }   
    return m;   
}   
  
int main()   
{   
    int n;   
    scanf("%d",&n);   
    while (n--)   
    {   
        unsigned m,index = 0;   
        scanf("%u",&m);   
        while (m != Reverse(m))   
        {   
            index++;   
            m += Reverse(m);   
        }   
        printf("%u %u\n",index,m);   
    }   
    return 0;   
}  
