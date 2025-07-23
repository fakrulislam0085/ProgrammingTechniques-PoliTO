#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
 
int main(void) {
    FILE *readFile, *writeFile; 

    if ((readFile = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr, "something is wrong.\n");
        return 1;
    } 
    if ((writeFile = fopen("output.txt", "w")) == NULL) {
        fprintf(stderr, "here is wrong.\n"); 
        fclose(readFile);
        return 2;
    }

    char buffer[256]; 
    if (fgets(buffer, sizeof(buffer), readFile) != NULL) {
        printf("First Line: %s", buffer);
    }

    if(fgets(buffer, sizeof(buffer), readFile) != NULL) {
        printf("Second Line: %s", buffer);
    }

    rewind(readFile);   //using rewind() to reset the file pointer at the beginning of our file
    char ch;
    if ((ch = fgetc(readFile)) != EOF) {
        printf("First char of the file is: %c\n", ch);
    }

    //using rewind() function again to get the first word correctly 
    rewind(readFile); 
    
    if (fscanf(readFile, "%s", buffer) != EOF) {
        printf("Now we see our first word: %s", buffer);
    }
    fclose(readFile);
    fclose(writeFile); 
 
    return 0;
}