#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 34

int S[SIZE] = {0,8,25,31,4,3,15,27,13,12,30,19,17,24,18,11,29,14,16,20,21,2,28,5,10,7,6,1,25,24,23,22,21,31};
int h[SIZE] = {0};

int size = sizeof(S)/sizeof(S[0]);

int findmin(int h[], int x, int i){
    int c;
    if ((h[(2*i)] >= h[(2*i) +1]) && (h[(2*i)+2] >= h[(2*i) +1]) && (h[(2*i)+3] >= h[(2*i) +1])){
        c = (2*i)+1;
    }
    else if((h[(2*i)+1] >= h[(2*i)]) && (h[(2*i)+2] >= h[(2*i)]) && (h[(2*i)+3] >= h[(2*i)])){
        c = (2*i);
    }
    else if((h[(2*i)+1] >= h[(2*i)+2]) && (h[2*i] >= h[(2*i)+2]) && (h[(2*i)+3] >= h[(2*i)+2])){
        c = (2*i)+2;
    }
    else if((h[(2*i)+1] >= h[(2*i)+3]) && (h[(2*i)+2] >= h[(2*i)+3]) && (h[2*i] >= h[(2*i)+3])){
        c = (2*i)+3;
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
        c= findmin(h,x,i);
        if(c>size-1){
        c = -1;
        }

    }

    h[i] = x;
}

void makeheap(int S[], int h[]){
    for(int i =1; i< size; i++){
        h[i] = S[i];
    }

    for(int j=size; j >= 1; j--){
        shiftdown(h, h[j],j);
    }

}

void bubbleup(int h[], int x,int i){
    int p=i/4;
    while( i != 0 && h[p] > x){
        h[i] = h[p];
        i = p;
        p = i/4;
    }
    h[i] = x;
}

void insert(int h[],int x){
    size++;
    h[size-1] = x;
    bubbleup(h,x, size);
}


int deleteMin(int h[]){
    if ((size)==0){
        return -1000;}
    else{
        int x;
        x = h[1];
        shiftdown(h,h[size-1],1);
        return x;
    }
}


int main()
{

    int i = 33;


    for(int j =1; j<SIZE; j++){
        printf("%d ", S[j]);
    }


    makeheap(S, h);

    printf("\n");


    for(int j =1; j<size; j++){
        printf("%d ",deleteMin(h));
    }





}
