#include <stdio.h> 
#define PINUMBER 3.1459 

int main(void) {
    int num_int;
    double result; 

    //taking input from user
    printf("Enter an integer: ");
    scanf("%d",&num_int);

    //display the integer entered by the user
    printf("You entered: %d\n", num_int);

    //converting the integer to double, perform arithmetic, and printing the result
    result = (double) num_int / 3 * PINUMBER;
    printf("Result of (integer/3 * PINUMBER): %f\n", result);

    return 0;
}