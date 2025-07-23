#include <stdio.h> 
#include <string.h> 
#include <math.h>
#define pi 3.14

void area_circle(char s_d_r, int side_diagonal_radius) {
    if (s_d_r == 'D') {
        float a = (float) pi * side_diagonal_radius * side_diagonal_radius;
        float area = a / 4; 
        printf("The area of the circle with diameter %d is %0.1f", side_diagonal_radius, area);
    }
    else {  //when s_d_r == 'R'
        float area = (float) pi * side_diagonal_radius * side_diagonal_radius;
        printf("The are of the circle with radius %d is %0.1f", side_diagonal_radius, area);
    }
}

void area_square(char s_d_r, int side_diagonal_radius) {
    if(s_d_r == 'D') {
        float a = (float) pow(side_diagonal_radius, 2); 
        float area = a/2 ;
        printf("The area of the square with diagonal %d is %0.1f", side_diagonal_radius, area);
    }
    else {  //s_d_r == 'S'
        float area = (float) side_diagonal_radius * side_diagonal_radius ;
        printf("The area of the square with side %d is %0.1f", side_diagonal_radius, area);
    }
}

int main(void) {
    char choice, s_d_r;     //s_d_r means side/diagonal/radius
    int side_diagonal_radius;
    printf("User Input: ");
    fflush(stdout);
    scanf("%c %c %d",&choice, &s_d_r, &side_diagonal_radius);
    //printf("perfect.");

    if(choice != 'Q' && choice != 'I') {
        printf("INVALID CHOICE.\n");
    }

    if(choice == 'Q') {
        area_square(s_d_r, side_diagonal_radius);
    }
    else {  //choice == 'I'
        area_circle(s_d_r, side_diagonal_radius);
    }
    return 0;
}