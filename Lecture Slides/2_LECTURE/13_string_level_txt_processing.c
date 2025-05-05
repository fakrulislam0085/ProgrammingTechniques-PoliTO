/*
This program reads text from an input file and writes a formatted version to an output file, 
ensuring no line exceeds a specified maximum length (lmax). It performs the following formatting operations:

* Whitespace Normalization: Replaces multiple spaces, tabs, and newlines with a single space.
* Line Wrapping: Ensures that lines do not exceed lmax characters by wrapping words to the next line when needed.
* Word Integrity: Keeps words intact — no word is split across lines.
* Dynamic Formatting: Adapts line breaks based on the length of the next word and the current line.
* File Handling: Takes input and output filenames and lmax as arguments.
* Robust Parsing: Uses fscanf("%s", ...) to tokenize input based on whitespace.
* This utility is useful for pretty-printing, email formatting, or preparing text for narrow-width displays.
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

void formatting (char nin[], char nout[], int lmax) {
    const int STRLEN = 21;  //max  word length + 1 for '\0' 
    FILE *fin = fopen(nin, "r"); 
    FILE *fout = fopen(nout, "w"); 

    //handling edge case
    if (fin == NULL || fout == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char word[STRLEN];
    int n = 0;

    //read word by word, auto-handle spaces, tabs,  newlines as delimiters
    while (fscanf(fin, "%20s", word) == 1) {
        int word_len = strlen(word); 

        if (n + 1 + word_len > lmax) {      //1 accounts for the space
            // If adding this word would exceed max length, start a new line
            fprintf(fout, "\n%s", word); 
            n = word_len;
        } else {
            // Add space before word if it's not the first word on the line
            if (n != 0) {
                fprintf(fout, " "); 
                n += 1; 
            }

            fprintf(fout, "%s", word); 
            n += word_len;
        }
    }

    //close the files 
    fclose(fin); 
    fclose(fout); 
}

int main(void) {
    char input_file[100], output_file[100]; 
    int max_length; 

    printf("Enter input file name: "); 
    scanf("%s", input_file);    //sample.txt

    printf("Enter the output file name: "); 
    scanf("%s", output_file);   //formatted.txt

    printf("Enter the max length of the line (lmax): "); 
    scanf("%d", &max_length); 

    //call the function
    formatting(input_file, output_file, max_length); 

    printf("Text formatting complete. Output written to %s\n", output_file);
 
    return 0;
}