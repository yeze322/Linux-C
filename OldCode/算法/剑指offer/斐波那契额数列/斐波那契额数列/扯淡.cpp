#include <stdio.h>
#include <malloc.h>
 
int main(int argc,char *argv[]){
    int m,n,t;
    scanf("%d%d",&m,&n);
    scanf("%d",&t);
    n = n % 1001;
    t = t % 1000001;
 
    int *(*a)[];
    int i,j,temp;
    a = (int *(*)[])malloc(m * sizeof(int));
    for(i = 0;i < m ;i++){
        (*a)[i] = (int*)malloc(n * sizeof(int));
        for(j = 0;j < n;j++){
            scanf("%d",&temp);
            (*a)[i][j] = temp;
        }   
    }
 
    for(i = 0;i < m ;i++){
        for(j = 0;j < n;j++){
            if((*a)[i][j] == t){
                printf("Yes\n");
                return 0;
            }
        }   
    }
    printf("No\n");
}