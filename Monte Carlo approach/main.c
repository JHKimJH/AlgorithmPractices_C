#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>
int main()
{
    double x, y;
    int count = 0;

    srand((unsigned int)time(NULL));
    for(int n=0; n < 1000; n++){
        x = 10.0*rand()/RAND_MAX;
        y = 10.0*rand()/RAND_MAX;
        if (sqrt((x*x) + (y*y)) <= 10){
            count++;
        }
    }
    double pi ;
    pi= ((count*4.0)/1000);

    printf("%f", pi);
}

