//Pure Binary encoding of a positive number 
//Iteratively computing the highest power of 2 that is<= of the number to convert 

#include <stdio.h> 
#include <string.h> 

void decimal_to_binary(int n) {
    //special case when the num == 0 
    if (n == 0) {
        printf("Please Enter a number greater than 0!\n");
        return;
    }

    int power = 1;
    //for (power=1; power*2 <=n; power *= 2);   //one way to findout the highest power of n (NuLL loop)
    while (power <= n) {        
        // >>=  (/2)  [Right shift- divide by 2] 
        // <<=  (*2)  [Left shift- multiply by 2]
        power <<= 1;
    }
    //after the loop, power is greater than n, so we shift to the right for once:
    power >>= 1;

    //Iterating from the higest power to the lowest(1) 
    printf("Binary of %d: ",n);
    while(power > 0) {
        if (n >= power) {
            printf("1");
            n -= power;
        } else {
            printf("0");
        }
        power >>= 1;    //move to the next lower power of 2
    }

    return;
}
int main(void) {
    int num; 
    printf("Enter the non-negative integer: "); 

    //input validation 
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Invalid input. Please, enter a non-negative integer.\n");
        return 1;
    }
    
    decimal_to_binary(num);

    return 0;
}
