#include <stdio.h> 
#include <string.h>
#include <ctype.h>

#define MAXL 100 

// Function to convert a string to uppercase  
void stringToUpper(char s[]) {
    int len = strlen(s); 
    
    for(int i=0; i<len; i++) {
        s[i] = toupper(s[i]);
    }

    printf("The modified string is: %s\n", s);

    return;
}


int main(void) {
    char s[MAXL]; 

    // Read a line from a file or input 
    // In this program, we will only modify one line from out input file 
    FILE *fin = fopen("story.txt", "r"); 
    if (fin == NULL) {
        printf("Error: Cannot open the file.\n");
        return 1; 
    }

    fgets(s, MAXL, fin);
    // Remove the newline character as the end (if present) 
    if (s[strlen(s) - 1] == '\n')
        printf("\nNewline char is found at the last of the line.\n");
        s[strlen(s) - 1] = '\0';        //instead of newline, we put a null terminator
        printf("Newline char is removed.\n");
    
    //call the function to modify the char 
    stringToUpper(s);
    
    fclose(fin); 
    
    return 0;
}