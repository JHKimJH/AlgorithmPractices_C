#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int A[MAX_SIZE];

void insertion_sort(n){
    int i,j, temp;
    for(i=1; i<=n; i++){
        temp = A[i];
        for (j=i; A[j-1]>temp &&j>0; j--){
            A[j] = A[j-1];
            A[j-1] = temp;
        }
        A[j] = temp;
    }
}

int main()
{
    FILE *fp = fopen("input.dat", "r");
    for (int i = 1; i<=100; i++){
        fscanf(fp, "%d  ", &A[i]);
    }


    insertion_sort(100);


    for (int j = 1; j<=100; j++){
        printf("%d ", A[j]);
    }

}
