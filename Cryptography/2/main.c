#include <stdio.h>
#include <stdlib.h>


struct _node {
    int first;
    int second;
    int third;
};

struct _node *extended_Euclid(int a, int b)
{
    struct _node *n1, *n2;

    n1 = (struct _node *)malloc(sizeof(struct _node));
    n2 = (struct _node *)malloc(sizeof(struct _node));

    if(b == 0) {
        n1->first = 1;
        n1->second = 0;
        n1->third = a;
        return n1;
    }

    else {
        n1 = extended_Euclid(b, a % b);
        n2->first = n1->second;
        n2->second = (n1->first) - (a/b)*(n1->second);
        n2->third = n1->third;
        return n2;
    }
}

int main()
{
    struct _node *n;
    int u, v;

    printf("\n\n type two positive integers -> ");
    scanf("%d %d", &u, &v);


    if(u<0 || v<0){
        printf("Invalid inputs\n");
        exit(0);
    }
    if(u==0||v==0){
        exit(0);
    }
    n= extended_Euclid(u,v);


    printf("x is %d, y is %d and d is %d\n",n->first, n->second, n->third);
}
