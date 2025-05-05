#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
 
int main(void) {
    int age[5], height[5];    //declaring two mono-dimensional array/vector 
    float avgAge = 0.0f;    
    float avgHeight = 0.0f;   // No implicit cast 

    for(int i=0; i<5; i++) {
        printf("Enter age and height for person %d: ", i+1); 
        scanf("%d %d", &age[i], &height[i]);
        avgAge += age[i]; 
        avgHeight += height[i];
    }


    //calculating average age and height 
    avgAge = avgAge / 5; 
    avgHeight = avgAge / 5;

    printf("\nAverage Age: %0.2f\n", avgAge); 
    printf("Average Height: %.2f\n", avgHeight);
 
    return 0;
}