//Pure Binary encoding of a positive number 
//Classic Solution using array 
#include <stdio.h> 
#include <string.h> 
void print_binary(int n) {
    //edge case 
    if (n == 0) {
        printf("Number must be greater than 0!\n");
        return ;
    }

    //declare an array to store binary representation
    int Binary[32];     //this array can hold up to 32-bit integers 
    int index = 0; 

    while (n > 0)
    {
        /* code */
        int element = n % 2 ;
        Binary[index++] = element;
        n /= 2; 
    }


    //Reverse printing of the array to have the binary in correct order (MSB to LSB)
    printf("Binary: ");
    for (int i = index-1; i>=0; i--) {  //In out prev while loop, as we post-increment our index, so here, we need to minus 1 from our indext to stay in the index limit
        printf("%d",Binary[i]);
    }
    printf("\n");

    return;
}
int main(void) {
    int num; 
    printf("Enter a non-negative integer: ");
    //input validation
    if (scanf("%d", &num) != 1 || num < 0) {    //for valid input, scanf() returns 1, othewise 0.
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1; 
    }

    print_binary(num); 
 
    return 0;
}