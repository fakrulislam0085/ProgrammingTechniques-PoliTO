#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

#define MAXR 30     // Maximum length for file name

int main(void) {
    char ch, namefile[MAXR + 1]; 
    FILE *fpin, *fpout;     // File pointers for input and output files

    // Prompt user for input file name
    printf("Name of input file: "); 
    scanf("%s", namefile);  
    fpin = fopen(namefile, "r");    // Open input file in read mode

    // Prompt user for output file name
    printf("Name of output file: ");
    scanf("%s", namefile); 
    fpout = fopen(namefile, "w");   // Open output file in write mode

    // Read the input file character by character
    while (fscanf(fpin, "%c", &ch) == 1) {

        // If character is a digit (0–9), mirror it: '0' ↔ '9', '1' ↔ '8', etc.
        if (ch >= '0' && ch <= '9') 
            ch = '0' + ('9' - ch); 
        
        // If character is a lowercase letter (a–z), mirror to uppercase reverse: 'a' ↔ 'Z', 'b' ↔ 'Y', etc.
        else if (ch >= 'a' && ch <= 'z')
            ch = 'A' + ('z' - ch);
        
        // If character is an uppercase letter (A–Z), mirror to lowercase reverse: 'A' ↔ 'z', 'B' ↔ 'y', etc.
        else if (ch >= 'A' && ch <= 'Z') 
            ch = 'a' + ('Z' - ch);
        
        // Write the transformed character to the output file
        fprintf(fpout, "%c", ch);
    }
    
    printf("File processed successfully!\n");

    // Close both input and output files
    fclose(fpin); 
    fclose(fpout); 
    
    return 0;
}
