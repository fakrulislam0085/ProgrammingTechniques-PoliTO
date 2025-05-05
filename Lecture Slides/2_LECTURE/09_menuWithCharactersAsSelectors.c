/*
    * This program demonstrates a reusable menu loop where the user types a single
    * letter command (A, L, T, or E) followed by optional text.  The first
    * non-whitespace character determines which handler function is called, and
    * the rest of the line is passed as an argument string.
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

//placeholder function definitions 
void fA(char str[]) {
    printf("Function A called with argument: %s\n", str);
}

void fL(char str[]) {
    printf("Function L called with argument: %s\n", str);
}

void fT(char str[]) {
    printf("Function T called with argument: %s\n", str);
}

void menuCharacters(void) {
    const int MAXL = 51;    //with the null terminator, the max size is 50+1 = 51
    char sel;       //to hold the first visible char as selector
    char line[MAXL];     //to hold the remainder of the input line
    int toContinue = 1; 

    while(toContinue) {
        printf("Command (A/L/T, E=exit): "); 
        scanf(" %c", &sel);     //space before %c to consume any newline
        getchar();      //Clear the newline that scanf leaves behind
        fgets(line, MAXL, stdin);  //Read up to MAXL-1 characters of the argument (may include spaces)
        
        //remove trailing newline (if present) added by fgets()
        line[strcspn(line, "\n")] = '\0' ;

        switch (toupper(sel)) {     //make lowercase to uppercase
            case 'A': 
                fA(line);
                break;
            case 'L' :
                fL(line);
                break;
            case 'T':
                fT(line);
                break;
            case 'E':
                toContinue = 0; 
                break;
            default:
                printf("non-valid command!\n");
        }


    }
    
}
int main(void) {
    menuCharacters();       //call the functions
    return 0; 
}