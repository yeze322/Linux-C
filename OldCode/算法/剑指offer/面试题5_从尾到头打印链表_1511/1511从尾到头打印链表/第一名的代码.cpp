#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int* addr;
    int size;
    int num;
    struct node* next;
}node;
 
int main()
{
    int i;
    int s = 16;
    node* h = NULL;
    while (scanf("%d", &i) != EOF) {
        if (i == -1)
            break;
        if (!h || h->num >= h->size) {
            node* n = (node*)malloc(sizeof(node));
            n->size = s;
            n->num = 0;
            n->next = h;
            n->addr = (int*)malloc(s * sizeof(int));
            h = n;
            s <<= 1;
        };
        h->addr[h->num++] = i;
    }
    while (h) {
        for (int i = h->num - 1;i >= 0; i--)
            printf("%d\n", h->addr[i]);
        free(h->addr);
        node* t = h;
        h = h->next;
        free(t);
    }
    return 0;
}
/**************************************************************
    Problem: 1511
    User: sbjbs
    Language: C
    Result: Accepted
    Time:70 ms
    Memory:1304 kb
****************************************************************/
