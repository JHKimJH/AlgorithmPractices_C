#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ans;
    while(scanf("%d", &ans)!=EOF){
        switch(ans){
        case 1:
            printf("Welcome to Algorithm");
            break;
        case 2:
            printf("Good luck for 2018 class");
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
            }
    }
    return 0;
}
