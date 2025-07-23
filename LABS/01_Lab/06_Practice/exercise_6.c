#include <stdio.h> 
#include <string.h> 
#include <math.h>
#include <stdlib.h>

float summation(float op1, float op2) {
    return op1 + op2;
}

float difference(float op1, float op2) {
    return fabs(op1 - op2);
}

float multiplication(float op1, float op2) {
    return op1 * op2;
}

float division(float op1, float op2) {
    return op1 / op2;
}

int main(void) {
    FILE *input_file, *output_file;
    char operator;
    float op1, op2;
    
    input_file = fopen("operations.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Unable to open the input file.\n");
        exit(1);
    }

    output_file = fopen("results.txt", "w");
    if(output_file == NULL) {
        printf("Error: Unable to open the output file.\n");
        fclose(input_file);
        return 2;
    }

    while (fscanf(input_file, " %c %f %f", &operator, &op1, &op2) == 3) {
        float result; 

        switch(operator) {
            case '+': 
                result = summation(op1, op2);
                break;
            case '-': 
                result = difference(op1, op2);
                break;
            case '*':
                result = multiplication(op1, op2);
                break;
            case '/':
                if(op2 == 0) {
                    fprintf(output_file, "Error: Division by zero\n");
                    continue;
                }
                result = division(op1, op2);
                break;

            default:
                fprintf(output_file, "Error: Unknown operator '%c'\n", operator);
                continue;
        }
        fprintf(output_file, "%c %0.2f\n",operator, result);
    }

    printf("Results have been written in the output file successfully.\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}