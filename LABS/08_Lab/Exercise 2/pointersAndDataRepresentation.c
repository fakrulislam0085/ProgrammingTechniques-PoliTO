#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

void printEncoding (void *p, int size, int bigEndian) {
    unsigned char *byte = (unsigned char *)p;

    if (!bigEndian) {
        // If little-endian, reverse the byte access
        for (int i = size - 1; i >= 0; i--) {
            for (int bit = 7; bit >= 0; bit--) {
                printf("%d", (byte[i] >> bit) & 1);
            }
            printf(" ");
        }
    } else {
        // If big-endian, read bytes in order
        for (int i = 0; i < size; i++) {
            for (int bit = 7; bit >= 0; bit--) {
                printf("%d", (byte[i] >> bit) & 1);
            }
            printf(" ");
        }
    }

    printf("\n");
}


int main(void) {
    //1. declare two variables- float and double
    float af; 
    double ad; 

    //2. Verify the endianness of the computer 
    int bigEndian = 0; 
    int num = 1; 
    char *bytePtr = (char *)&num; 
    if(bytePtr[0] == 0) {
        bigEndian = 1;      // Big Endian
    } else {
        bigEndian = 0;      // little Endian
    }

    printf("Endianness: %s\n", bigEndian ? "Big Endian" : "Little Endian"); 
    // sizes 
    printf("Size of float: %lu bytes (%lu bits)\n", sizeof(af), sizeof(af) * 8); 
    printf("Size of double: %lu bytes (%lu bits)\n", sizeof(ad), sizeof(ad) * 8); 
    
    
    //3. Get the user input 
    printf("Enter a real number: "); 
    scanf("%lf", &ad);  //double
    af = (float)ad;     // explicit cast to float 


    //4. Call the function to print the binary encodings 
    printf("Binary encoding of float (%f):\n", af); 
    printEncoding((void *)&af, sizeof(af), bigEndian); 

    printf("Binary encoding of double (%lf):\n", ad); 
    printEncoding((void *)&ad, sizeof(ad), bigEndian); 

    return 0;
}