#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
 
#define MaxN 30

void rotate(int v[], int n, int p, int direction) {

    printf("\nOur rotated array: ");
    if (direction == -1) {          //right rotation
        int indx_from_position = n - p; 

        for(int j = indx_from_position; j<n; j++) {
            printf("%d ", v[j]);
        }

        for (int k = 0; k<indx_from_position; k++) {
            printf("%d ", v[k]);
        }
        printf("\n\n");
    } 
    else if (direction == 1) {      //left rotation
        for(int j = p; j<n; j++) {
            printf("%d ", v[j]);
        }

        for (int k = 0; k<p; k++) {
            printf("%d ", v[k]);
        }
        printf("\n\n");
    }
}

int main(void) {
    int n;
    printf("Enter the size of the array(maxN): "); 
    scanf("%d", &n); 

    int v[n]; 
    printf("Enter the values of the array: "); 
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]); 
    }

    while(true) {
        int p; 
        printf("Number of positions that we need to rotate(p<n): "); 
        scanf("%d", &p); 
        if (p == 0) {
            printf("Terminated by the developer!");
            exit(1);
        } 

        int direction; 
        printf("Give us the direction(-1 for right/ 1 for left): "); 
        scanf("%d", &direction); 

        rotate(v, n, p, direction);
    }
    return 0;
}