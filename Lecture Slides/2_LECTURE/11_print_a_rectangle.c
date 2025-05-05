#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

void printing_rectangle(int b, int h) {

    for(int i=0; i<h; i++) {    //iterates on rows
        for (int j=0; j<b; j++) {   //iterates on columns
            if(i==0 || i == h-1) {      //i at starting or ending position
                printf("*");
            }  else {
                //j at starting or ending position
                if (j==0 || j== b-1) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
int main(void) {
    int b, h; 
    printf("Enter the base of the rectangle: ");
    scanf("%d", &b);
    printf("Enter the height of the rectangle: "); 
    scanf("%d", &h); 

    //call the function
    printing_rectangle(b, h);
 
    return 0;
}