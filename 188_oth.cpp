#include<stdio.h>
#include<string.h>
#include<ctype.h>
int head[30],next[30];
int st[30],w[30],n,C;
char b[200],temp[30];
int min(int x,int y)
{
    return x<y?x:y;    
}
int make()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if((C/w[i])%n==(C/w[j])%n)
            {
                C=min((C/w[i]+1)*w[i],(C/w[j]+1)*w[j]);
                return 0;
            }
    return 1;
}
int main()
{
    int i,j,k,p;
    while(gets(b)!=NULL)
    {
        n=0;
        memset(w,0,sizeof(w));
        k=strlen(b);
        for(i=0;i<k;i++)
            if(isalpha(b[i]))
            {
                sscanf(&b[i],"%s",temp);
                p=strlen(temp);
                i+=p;
                for(j=0;j<p;j++)
                    w[n]=(w[n]<<5)+(temp[j]-'a'+1);
                n++;
            }
        C=1<<31-1;
        for(i=0;i<n;i++)
            if(w[i]<C)
                C=w[i];
        while(!make());
        printf("%s\n",b);
        printf("%d\n",C);
        printf("\n");
    }
    return 0;    
}
