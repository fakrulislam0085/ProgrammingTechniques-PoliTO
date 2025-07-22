#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

int verifyOrder(FILE *fp) {
    const int MAXC = 50;    //max char will be 50 in a single line
    char line0[MAXC + 1], line1[MAXC + 1];      //line0 = previous line, line1 = successive line

    fgets(line0, MAXC + 1, fp);     //reads first line separately
    if (line0 == NULL) {
        return 1;   //we can say, empty file is ordered as there are no lines to compare.        
    } 

    while (fgets(line1, MAXC + 1, fp) != NULL) {        //reads second line
        if (strcmp(line1, line0) < 0)       // If line1 is less than line0, strcmp returns us a negative value
            return 0;
        strcpy(line0, line1);       // copy line1 in line0
    }

    return 1;
}
int main(void) {
    char fileName[100]; 
    FILE *fp; 

    //1. Ask the user for the file name and check input validity
    printf("Enter the name of the text file: ");        //1. ordered.txt    2.unordered.txt
    if (scanf("%99s", fileName) != 1) {
        fprintf(stderr, "Failed to read filename.\n");
        return EXIT_FAILURE;
    }

    //2. Open the file 
    fp = fopen(fileName, "r"); 
    if (fp == NULL) {
        perror("Error opening file");    // prints “Error opening file: <system‐error>”
        return EXIT_FAILURE;
    }

    //3. Check order and report 
    //Lexicographical order = Alphabetical order = Dictionary order
    int result = verifyOrder(fp); 
    fclose(fp); 

    if (result) 
        printf("The list IS in alphabetical order.\n");
    else    
        printf("The list is NOT in alphabetical order.\n");

    return EXIT_SUCCESS;
}