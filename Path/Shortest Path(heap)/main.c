#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define VERTEX_SIZE 8
#define FALSE 0
#define TRUE 1
#define MAX 9999

int h[SIZE] = {0};

int size = sizeof(h)/sizeof(h[0]);

int findmin(int h[], int x, int i){
    int c;
    if (h[(2*i)] >= h[(2*i) +1]){
        c = (2*i)+1;
    }
    else{
        c = (2*i);
    }
    return c;
}

void shiftdown(int h[], int x, int i){
    int c;
    c= findmin(h,x,i);
    if(c>size-1){
        c = -1;
    }

    while((c != -1) && (h[c] < x)){
        h[i] = h[c];
        i = c;

        c = findmin(h,x,i);
        if(c>size-1){
            c = -1;
        }
    }

    h[i] = x;
}

void makeheap(int S[], int h[]){
    for(int i =0; i< SIZE; i++){
        h[i+1] = S[i];
    }

    for(int j=size; j >= 1; j--){
        shiftdown(h, h[j],j);
    }
}

void bubbleup(int h[], int x,int i){
    int p=i/2;
    while( i != 0 && h[p] > x){
        h[i] = h[p];
        i = p;
        p =i/2;
    }
    h[i] = x;
}

void insert(int h[],int x){
    size++;
    h[size-1] = x;
    bubbleup(h,x, size-1);
}


int deleteMin(int h[]){
    if (size==0){
        return -1000;}
    else{
        int x;
        x = h[1];
        shiftdown(h,h[size-1],1);
        size--;
        return x;
    }
}

int graph[VERTEX_SIZE][VERTEX_SIZE] = {{MAX,6,3,2,MAX,MAX,MAX,MAX},
                                        {6,MAX,MAX,2,3,MAX,MAX,MAX},
                                        {3,MAX,MAX,1,MAX,7,MAX,MAX},
                                        {2,2,1,MAX,MAX,4,3,MAX},
                                        {MAX,3,MAX,MAX,MAX,MAX,7,9},
                                        {MAX,MAX,7,4,MAX,MAX,MAX,MAX},
                                        {MAX,MAX,MAX,3,7,MAX,MAX,4},
                                        {MAX,MAX,MAX,MAX,9,MAX,4,MAX}};

int false_check(int a[]){
    for(int i = 0; i<VERTEX_SIZE; i++){
        if(a[i] != FALSE){
            return 0;
        }
    }
    return 1;
}

int dist[VERTEX_SIZE];
int tobechecked[VERTEX_SIZE];
int prev[VERTEX_SIZE];

int main()
{
    int check =0;

    int First = 0;

    for(int i = 0; i < VERTEX_SIZE; i++){
        dist[i] = MAX;
    }

    dist[First] = 0;
    prev[First] = 0;

    for(int i = 0;i<VERTEX_SIZE;i++){
        tobechecked[i] = TRUE;
    }

    makeheap(dist, h);

    int v,u;

    while(check == 0){

        int m = deleteMin(h);

        for(int i =0; i<VERTEX_SIZE; i++){
            if(dist[i] == m){
                v = i;
            }
        }

        tobechecked[v] = FALSE;

        u = 0;
        while(u<VERTEX_SIZE){
            if(graph[v][u] != MAX && tobechecked[u] == TRUE){
                if(dist[u] > dist[v] + graph[v][u]){
                    dist[u] = dist[v]+graph[v][u];
                    insert(h, dist[u]);
                    prev[u] = v;
                }
            }
            u++;
        }
        check = false_check(tobechecked);
    }

    for(int j = 0; j< VERTEX_SIZE; j++){
        printf("node %d: distance %d: %d\n",j+1, dist[j],prev[j]+1);
    }
}
