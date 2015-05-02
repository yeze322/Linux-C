#include<cstdio>
#include<cctype>
int read()
{
    static int D;
    static char ch;
    while(!isdigit(ch=getchar()));
    for(D=ch-'0'; isdigit(ch=getchar());)//多位数，他考虑到了int是4字节的，char只有1字节
        D=(D<<3)+(D<<1)+(ch-'0');//D*8+D*2+newnumber
    return D;
}
char buf[5000000];
int main()
{
    int N,t,m;
    while(~scanf("%d",&N))
    {
        scanf("%d",&m);
        while(--N)
        {
            scanf("%d",&t);
            if(t<m)
            {
                m = t;
                gets(buf);
                break;
            }
        }
        printf("%d\n",m);
    }
}