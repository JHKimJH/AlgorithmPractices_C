#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int A[MAX_SIZE];

void swap(int * n1, int * n2) {
    int temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

int partition(int p, int r){
    int pivot = A[p];
    int h = p;
    for (int k = p+1;k<=r; k++){
        if (A[k] < pivot){
            h= h+1;
            swap(&A[h],&A[k]);
        }
    }
    swap(&A[h],&A[p]);


    return h;
}

void quick_sort(int p, int r){
    if(p<r){
        int q = partition(p,r);
        quick_sort(p, q-1);
        quick_sort(q+1, r);
    }
}

int main()
{

    FILE *fp = fopen("input.dat", "r");
    for (int i = 1; i<=100; i++){
        fscanf(fp, "%d  ", &A[i]);
    }

    quick_sort(1, 100);

    for (int j = 1; j<=100; j++){
        printf("%d ", A[j]);
    }
}
