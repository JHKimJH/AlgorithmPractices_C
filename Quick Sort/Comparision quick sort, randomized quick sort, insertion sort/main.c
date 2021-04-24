#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int A[MAX_SIZE];

void swap(int * n1, int * n2) {
    int temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

int quick_sort_counter = 0;

int partition(int p, int r){
    int pivot = A[p];
    int h = p;
    for (int k = p+1;k<=r; k++){
        if (A[k] < pivot){
            h= h+1;
            swap(&A[h],&A[k]);
        }
        quick_sort_counter++;
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


int randomized_quick_counter = 0;

int random_partition(int p, int r){
    int loc;
    int num = r-p;
    loc = rand()%num;
    swap(&A[p+loc], &A[p]);
    int pivot = A[p];
    int h = p;
    for (int k = p+1;k<=r; k++){
        if (A[k] < pivot){
            h= h+1;
            swap(&A[h],&A[k]);
        }
        randomized_quick_counter++;
    }
    swap(&A[h],&A[p]);


    return h;
}

void randomized_quick_sort(int p, int r){
    if(p<r){
        int q = random_partition(p,r);
        randomized_quick_sort(p, q-1);
        randomized_quick_sort(q+1, r);
    }
}

insertion_sort_counter = 0;

void insertion_sort(n){
    int i,j, temp;
    for(i=1; i<=n; i++){
        temp = A[i];
        for (j=i; A[j-1]>temp &&j>0; j--){
            insertion_sort_counter++;
            A[j] = A[j-1];
            A[j-1] = temp;
        }
        A[j] = temp;
    }
}


int main()
{
    srand(time(NULL));

    FILE *fp = fopen("input.dat", "r");
    for (int i = 1; i<=100; i++){
        fscanf(fp, "%d  ", &A[i]);
    }

    quick_sort(0, MAX_SIZE-1);
    printf("Quick sort runs %d comparisions.\n", quick_sort_counter);

    FILE *fp2 = fopen("input.dat", "r");
    for (int i = 1; i<=100; i++){
        fscanf(fp2, "%d  ", &A[i]);
    }

    randomized_quick_sort(0,MAX_SIZE-1);

    printf("Randomized quick sort runs %d comparisons.\n", randomized_quick_counter);


    FILE *fp3 = fopen("input.dat", "r");
    for (int i = 1; i<=100; i++){
        fscanf(fp3, "%d  ", &A[i]);
    }

    insertion_sort(100);

    printf("Insertion sort runs %d comparisons.\n", insertion_sort_counter);


}
