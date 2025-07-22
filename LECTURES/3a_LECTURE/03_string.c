#include <stdio.h> 
#include <string.h> 

#define NP 100   // Max number of words 
#define MAXL 50     // Max length of a word

int main(void) {
    char words[NP][MAXL];   //creating a matrix

    FILE *fpin; 
    int n = 0;
    int sorted = 1; 


    //1. open the file for reading 
    fpin = fopen("input.txt", "r"); 
    if (fpin == NULL) {
        fprintf(stderr, "Error: Cannot open the file.\n");
        return 1;
    }


    //2. Read words from the file 
    while (n < NP && fscanf(fpin, "%s", words[n]) != EOF) {
        n++;
    }
    fclose(fpin);


    //3. Check if words are sorted alphabetically 
    for(int i=1; i<n && sorted; i++) {
        if (strcmp(words[i-1], words[i])  > 0) {
            sorted = 0;
        }
    }

    //4. 
    //output sorted status 
    if (sorted) 
        printf("The words are sorted alphabetically.\n"); 
    else 
        printf("The words are NOT sorted alphabetically.\n");
    
    
    // Copy the first and last words 
    char first[MAXL], last[MAXL]; 
    strcpy(first, words[0]);    //warning: first = words[0] is wrong
    strcpy(last, words[n-1]);

    //concatenate first and last words into one string 
    char firstAndLast[2 * MAXL]; 
    strcpy(firstAndLast, first);    // Start with first word
    strcat(firstAndLast, last);     // Append last word


    // Output the result 
    printf("First word: %s\n", first); 
    printf("Last word: %s\n", last); 
    printf("Concatenate (first + last): %s\n", firstAndLast);

    return 0;
}