#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1;
    double j;
    int i;
    double result = 1.0;
    for(i=0;i<=5;i++){
        j=i*i;
        n=1;
        double result = 1.0;
        double taylor = 1.0;
        while(n<=30){

            double d = j/n;

            taylor = d*taylor;
            result += taylor;

            n++;
        }

        printf("x = %d ÀÏ¶§ exp(x) = %f\n", (int)j,result);
   }

}
