#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <stdlib.h>

float summation(float op1, float op2) {
    return op1 + op2;
}

float difference(float op1, float op2) {
    return fabs(op1 - op2);     //use fabs for absolute differences between floating point numbers
}

float multiplication(float op1, float op2) {
    return op1 * op2;
}

float division(float op1, float op2) {
    return op1 / op2;
}

int main(void) {
    char operator;
    printf("Give the operator sign: ");
    operator = getchar();

    float op1, op2;
    printf("Give us the float values: ");
    scanf("%f %f", &op1, &op2);

    if(operator == '+') {
        float result = summation(op1, op2);
        printf("Ans: %c%0.2f",operator,result);
    }
    else if(operator == '-') {
        float result = difference(op1, op2);
        printf("Ans: %c%0.2f",operator, result); 
    }
    else if(operator == '*') {
        float result = multiplication(op1, op2);
        printf("Ans: %c%0.2f", operator, result);
    }
    else {  // operator == '/'
        if(op2 == 0) {
            fprintf(stderr, "Error: Division by Zero.");
            exit(1);
        }
        else {
            float result = division(op1, op2);
            printf("Ans: %c%0.2f", operator, result);
        }
    }


    //We can also use switch-case here
    // switch(operator) {
    // case '+': 
    //         ......
    // case '-': 
    //         ..... 
    // }

 
    return 0;
}