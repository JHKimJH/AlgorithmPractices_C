#include <stdio.h>
#include <stdlib.h>
#define MAX 30

double my_taylor(double x, int n){
  if (n> MAX){
    return 1.0;
  }
  return 1+(x/n)*my_taylor(x,n+1);
}

void main(){
  int i, j;
  for (i=0;i<=5;i++){
    j = i*i;
    printf("x = %d ÀÏ¶§ exp(x) = %f\n", j, my_taylor((double)j, 1));
  }
  getchar();
  return 0;
}
