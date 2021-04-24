#include <stdio.h>
#include <stdlib.h>
#define QSize 8

int num[QSize];
int Queue[QSize];
int first, last = 0;
int i;

int G[QSize][QSize] = {{0,1,1,1,0,0,0,0},
                            {1,0,0,1,1,0,1,0},
                            {1,0,0,1,0,0,0,0},
                            {1,1,1,0,0,1,0,0},
                            {0,1,0,0,0,0,1,1},
                            {0,0,0,1,0,0,0,0},
                            {0,1,0,0,1,0,0,1},
                            {0,0,0,0,1,0,1,0}};

int isFull(){
    return ((first == 0&&last == QSize -1) || (first == last+1));
}

int isEmpty(){
    return first == last;
}

int enqueue(int v){
    if(isFull() == 0){
        if(last == 0){
            Queue[last] = v;
        }
        last = (last+1)%QSize;
        Queue[last] = v;
    }
    else{
        return -1;
    }
    return v;
}

int dequeue(){
    int v;
    if(isEmpty() == 0){
        v = Queue[first];
        first = (first+1)%QSize;
    }
    else{
        return -1;
    }
    return v;
}

struct edge{
    int start_vertex;
    int end_vertex;
    struct edge *next;
};

struct edge *head, *tail;

void BFS(){
    int w;
    for(int u = 0; u<QSize; u++){
        num[u] = 0;
    }
    head,tail = NULL;
    i = 1;
    int v = 0;
    while(num[v] == 0){
        num[v] = i++;
        enqueue(v);
        while(isEmpty() == 0){
            w = dequeue();
            for(int u = 0; u<QSize; u++){
                if(G[w][u] == 1){
                    if(num[u] == 0){
                        num[u] = i++;
                        enqueue(u);
                        struct edge *edge = malloc(sizeof(struct edge));
                        edge->start_vertex = w;
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
                    }
                }
            }
        }
    v++;
    }
    for(int v = 0; v< QSize; v++){
            num[v] = 0;
    }

    i = 1;

    struct edge *temp;
    temp = head;
    while(temp != NULL){
        printf("(%d, %d)  ",temp->start_vertex+1, temp->end_vertex+1);
        temp = temp->next;
    }
}


int main()
{
    BFS();
}
