#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

// Converts a decimal number `n` to base `b` and prints the result
void conversion(int n, int b) {
    int p; 

    // Find the largest power of base `b` that is less than or equal to `n`
    for (p = 1; b * p <= n; p = p * b);  // Equivalent to finding the highest digit place

    printf("The final converted number is: ");
    // Convert and print the number in base `b` from the highest digit down to the lowest
    while (p > 0) {
        if (p <= n) {
            printf("%d", n / p);    // Print the digit at current position
            n = n % p;              // Reduce `n` by removing the most significant digit value
        } 
        else {
            printf("0");            // If current place value is greater than `n`, print 0
        }

        p = p / b;                  // Move to the next lower digit place
    }
    printf("\n");                   // Newline after printing the converted number

}

int main(void) {
    int b0, b1;         // b0 = base of the input number, b1 = base to convert to
    int n, p, digit;    
    int end = 0;        // Control flag to stop the program
    char c;             // Character input for digits

    // Prompt and read the input and output bases (valid range: 2 to 9)
    printf("b0 (2..9): ");  scanf("%d", &b0); 
    printf("b1 (2..9): ");  scanf("%d", &b1); 
    getchar();      // <---- EAT the newline so scanf("%c") works properly later

    n = 0;              // Initialize the number accumulator

    // Read input one character at a time until invalid digit is entered
    while (!end) {
        printf("Reads the digit one by one as char value: ");   
        scanf("%c", &c); 
        getchar();      // <---- EAT the newline so scanf("%c") works properly later

        // If space or newline is entered, treat it as end of number
        if (c == ' ' || c == '\n') {
            conversion(n, b1);  // Convert the collected number to base `b1` and print it
            n = 0;              // Reset number accumulator for the next input
        }
        else {
            digit = c - '0';    // Convert character digit to integer (e.g., '3' -> 3)

            // Check if digit is valid in base `b0`
            if (digit >= 0 && digit < b0) {
                // Update the number in base 10 (like rolling sum: n = n*b0 + digit)
                n = b0 * n + digit; 
            } else {
                // Invalid digit entered, stop the loop
                end = 1;
            }
        }

    }

    return 0;
}
