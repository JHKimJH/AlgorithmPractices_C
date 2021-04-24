#include <stdio.h>
#include <stdlib.h>

long combination(int n, int r){
  if (r==0|| r==n){
    return 1;
  }
  return combination(n-1,r-1) +combination(n-1,r);

}
int main() {
    int i = 0;
    while(i <= 10){
        printf("10c%d = %d\n", i, combination(10, i));
        i++;
    }
    return 0;
}
