#include<stdio.h>
#include<stdlib.h>
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m,n;
    int search;
    int **a=NULL;
    while((scanf("%d",&m)!=EOF)&&(scanf("%d",&n)!=EOF)&&(scanf("%d",&search)!=EOF))
    {
        int i,j;
        int  flag=0;
		if(m<=0||n<=0)
			goto ff;
        a=(int ** )calloc(m,sizeof(int*));
        for(i=0;i<m;i++)
        {
            a[i]=(int *)calloc(n,sizeof(int));
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(scanf("%d",&a[i][j])==EOF)
					goto ff;
                if(a[i][j]==search) flag=1;
            }
        }
    ff: flag==1?printf("Yes\n"):printf("No\n");
    }
    return 0;
}