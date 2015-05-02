#include <stdio.h>
#include <string.h>
 
int main() 
{
    int i, j, m, n, judge, t;
    char v[10], line[8004] = " ";
 
    while (scanf("%d%d%d\n", &m, &n, &t) == 3) 
    {
        sprintf(v, " %d ", t);
        for (i = judge = 0; i < m; ++i) 
        {
            gets(line+1);
            for (j = strlen(line); line[j-1] < '0' || line[j-1] > '9'; --j);
            line[j] = ' '; line[j+1] = 0;
            if (strstr(line, v)) {judge = 1; break;}
        }
         
        for (++i; i < m; ++i) 
            gets(line+1);
     
    judge?puts("Yes"): puts("No");
}
return 0;
}