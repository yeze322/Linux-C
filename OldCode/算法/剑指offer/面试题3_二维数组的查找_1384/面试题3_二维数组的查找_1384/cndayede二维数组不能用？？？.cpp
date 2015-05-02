#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int m,n;
    int search;
    int a[10][100];
    while((scanf("%d",&m)!=EOF)&&(scanf("%d",&n)!=EOF)&&(scanf("%d",&search)!=EOF))
    {
        //a=(int **) malloc(m*sizeof(int));
        int i,j;
        for(i=0;i<m;i++)//巨傻逼的错误。for循环写错了
        {
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        i=m-1;j=n-1;
        if(a[i][j]<search)
        {
            printf("No\n");
continue;       }//太大了找不到,忘记考虑这种情况了
        while(i>=0&&j>=0&&a[i][j]>=search)//注意！i>=0和j>=0要写在前边。不然会出现访问a[-1][-1】的情况
        {
            i--;j--;
        }
        i++;j++;
 
        if(a[i][j]==search)
        {
            printf("Yes\n");
continue;       }//正好是这个节点直接找到
        for(int q=0;q<i;q++)
        {
            if(a[q][j]==search)
            {
                printf("Yes\n");
continue;           }
        }//竖着先找
        for(int q=0;q<j;q++)
        {
            if(a[i][q]==search)
            {
                printf("Yes\n");
continue;           }
        }//横着在找
        printf("No\n");
    }
    return 0;
}