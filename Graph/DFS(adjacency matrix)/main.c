#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8

int num[MAXSIZE];
int i;

int G[MAXSIZE][MAXSIZE] = {{0,1,1,1,0,0,0,0},
                            {1,0,0,1,1,0,1,0},
                            {1,0,0,1,0,0,0,0},
                            {1,1,1,0,0,1,0,0},
                            {0,1,0,0,0,0,1,1},
                            {0,0,0,1,0,0,0,0},
                            {0,1,0,0,1,0,0,1},
                            {0,0,0,0,1,0,1,0}};

struct edge{
    int start_vertex;
    int end_vertex;
    struct edge *next;
};

struct edge *head, *tail;

void DFS(int v){
    num[v] = i++;

    for(int u = 0; u<MAXSIZE; u++){
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
    head = NULL;
    tail = NULL;

    depthFirstSearch();
}


