#include <stdio.h>
#include <stdlib.h>
#define VERTEX_SIZE 8
#define MAX 9999
#define TRUE 1
#define FALSE 0

int dist[VERTEX_SIZE];
int tobechecked[VERTEX_SIZE];
int prev[VERTEX_SIZE];

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

int main()
{
    int First = 0;

    for(int i = 0; i < VERTEX_SIZE; i++){
        dist[i] = MAX;
    }

    dist[First] = 0;
    prev[First] = 0;


    for(int i = 0;i<VERTEX_SIZE;i++){
        tobechecked[i] = TRUE;
    }


    int mini = MAX+1;

    int u, v = 0;
    int check = 0;
    int m;

    while(check==0){
        mini = MAX+1;

        for(v = 0; v<VERTEX_SIZE; v++){
            if(tobechecked[v] == TRUE && dist[v] < mini){
                    mini = dist[v];
                    m = v;
            }
        }
        tobechecked[m] = FALSE;
        u = 0;
        while(u<VERTEX_SIZE){
            if(graph[m][u] != MAX && tobechecked[u] == TRUE){
                if(dist[u] > dist[m] + graph[m][u]){
                    dist[u] = dist[m]+graph[m][u];
                    prev[u] = m;
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
