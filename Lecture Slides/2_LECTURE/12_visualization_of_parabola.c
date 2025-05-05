#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
 
int main(void) {
    float a, b, c;  //coefficients 
    int n;    //number of intervals 
    float x0, xn, ymin, ymax;   //intervals 
    float step; //length of n intervals
    float x, y; 
    int i, j;   //counters to draw the graph
    
    FILE *fpout = fopen("out.txt", "w"); 

    //input the coefficients
    printf("Coefficients (a b c): "); 
    scanf("%f%f%f", &a, &b, &c); 
    
    //inut the number of intervals
    printf("Number of intervals (n): "); 
    scanf("%d", &n);

    //Interval for x-axis and y-axis
    printf("Interval for x-axis (x0 xn): ");
    scanf("%f%f", &x0, &xn);
    printf("Interval for y-axis (ymin, ymax): "); 
    scanf("%f%f", &ymin, &ymax);


    //determine the steps 
    step = (xn - x0) / n ;      //length of n-intervals
    
    for (i=0; i<=n; i++) {
        x = x0 + i*step; 
        y = a*x*x + b*x + c;    //ax^2 + bx + c 

        if (y>=ymin && y<=ymax) {
            for (j=round(y-ymin); j>0; j--) 
                fprintf(fpout, " "); 
            fprintf(fpout, "*");
        }

        fprintf(fpout, "\n"); 
    }

    printf("Successfully run the program!\n");

    //closing the file 
    fclose(fpout);

    return 0;
}