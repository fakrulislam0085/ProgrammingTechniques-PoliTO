/*This program simulates an elevator problem panel that skips the 13th floor*/
#include <stdio.h>

int main(void) {
    int floor, actualfloor;
    printf("Floor: ");
    scanf("%d",&floor);

    if(floor > 13)  actualfloor = floor - 1 ;
    else    actualfloor = floor;

    //print the result
    printf("The elevator will travel to the "
    "actual floor %d\n", actualfloor);

    return 0;
}