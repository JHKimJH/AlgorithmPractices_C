#include <stdio.h>
#include <stdlib.h>

void moveTower(int diskID, int source, int spare, int target){
    if(diskID == 0){
        printf("move disk %d from tray %d to tray %d\n", diskID, source, target);
        return;
    }

    moveTower(diskID-1, source, target, spare);
    printf("move disk %d from tray %d to tray %d\n", diskID, source, target);
    moveTower(diskID-1, spare,source, target);
    }

int main()
{
    int num;
    printf("Input = ");
    scanf("%d",&num);
    moveTower(num-1, 1,2,3);
}
