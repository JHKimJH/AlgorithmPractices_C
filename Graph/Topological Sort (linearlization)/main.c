#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8

int num[MAXSIZE];
int i,n, m = 0;

int G[MAXSIZE][MAXSIZE] = {{0,0,1,0,0,0,0,0},
                            {1,0,0,0,1,0,0,0},
                            {0,0,0,1,0,0,1,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,1,0,1,0,0},
                            {0,0,0,0,0,0,0,1},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,1,0}};

int pre[MAXSIZE];
int post[MAXSIZE];


struct edge{
    int start_vertex;
    int end_vertex;
    struct edge *next;
};

struct edge *head, *tail;

void DFS(int v){
    n++;
    num[v] = i++;
    pre[v] = n;
    for(int u = MAXSIZE-1; u>=0; u--){
        if(G[v][u] == 1){
            if(num[u] == 0){
                struct edge *edge = malloc(sizeof(struct edge));
                edge->start_vertex = v;
                edge->end_vertex = u;
                edge->next = NULL;
                if(head == NULL){
                    head = edge;
                    tail = edge;
                }
                else{
                    tail->next = edge;
                    tail = edge;
                }
                DFS(u);
            }
        }
    }
    n++;
    post[v] = n;
}

int depthFirstSearch(){
    for(int v = 0; v< MAXSIZE; v++){
        num[v] = 0;
    }

    i = 1;
    int v = 0;
    while(num[v] == 0){
        DFS(v);
        v++;
    }
    struct edge *temp;
    temp = head;
    while(temp != NULL){
        printf("(%d, %d)  ",temp->start_vertex+1, temp->end_vertex+1);
        temp = temp->next;
    }


}


int main()
{
    depthFirstSearch();

    printf("\n\nnode : 1  2  3  4  5  6  7  8");
    printf("\npre : ");
    for(int j = 0; j<MAXSIZE ;j++){
        printf("%2d ",pre[j]);
    }
    printf("\n");
    printf("post: ");
    for(int j = 0; j<MAXSIZE ;j++){
        printf("%2d ",post[j]);
    }
    printf("\n");


    int l = 0;
    int index[MAXSIZE] = {1,2,3,4,5,6,7,8};
    while(l < MAXSIZE){
        for(int k = 0; k<MAXSIZE; k++){
            if(post[l]>post[k]){
                int temp;
                int idx;

                temp = post[k];
                idx = index[k];
                post[k] = post[l];
                index[k] = index[l];
                post[l] = temp;
                index[l] = idx;
            }
        }
        l++;
    }

    printf("\ntopological sort: ");
    for(int j = 0; j<MAXSIZE ;j++){
        printf("%d ",index[j]);
    }
    printf("\n");

}

