#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 


enum { MAXLC = 201 }; 
#define MAXC 30     // suppose 

typedef struct myArray {
    char replacement[MAXC]; 
    char substr[MAXC]; 
} myArray; 

void encodedTheMainFile(FILE* fp_read, FILE* fp_write, myArray *conversionTable, int s) {
    char line[MAXLC];     // buffer for each line
    
    // Read the input file line by line
    while (fgets(line, sizeof(line), fp_read)) {
        char *token = strtok(line, " \t\n");    // tokenize the line by whitespaces, tab, newline

        while (token) {
            char *pos = NULL; 
            int j = -1;     // Index of the matching substring in conversionTable
            
            for(int i=0; i<s; i++) {
                pos = strstr(token, conversionTable[i].substr);

                if(pos) {
                    j = i;  // Store which substring matched
                    break;
                }
            }

           
            if (j != -1) {
                int indx = pos - token;     // Get index where match starts

                char result[50]; 
                result[0] = '\0';  // Initialize result string as empty

                //0.0 Copy part of original word before the match
                strncpy(result, token, indx);
                result[indx] = '\0';    // Manually null-terminate the string

                //0.1 Append the replacement string
                strcat(result, conversionTable[j].replacement); 

                //0.2 Append the rest of the original word after the matched substring
                strcat(result, pos + strlen(conversionTable[j].substr)); 

                fprintf(fp_write, "%s ", result);   // Write the modified word to output file with space
            }
            else {
                fprintf(fp_write, "%s ", token);
            }
            
            token = strtok(NULL, " \t\n");      // move to the next word
        }
        fputc('\n', fp_write);    
    }
}


int main(void) {
    char fileName1[] = "source.txt"; 
    char fileName2[] = "dictionary.txt"; 
    char fileName3[] = "output.txt"; 

    //1. open the files 
    FILE *fp_input = fopen(fileName1, "r"); 
    FILE *fp_input2 = fopen(fileName2, "r"); 
    FILE *fp_output = fopen(fileName3, "w"); 

    if(!fp_input) {
        fprintf(stderr, "Error: Couldn't open the '%s' file.\n", fileName1); 
        return 1; 
    }
    if(!fp_input2) {
        fprintf(stderr, "Error: Couldn't open the '%s' file.\n", fileName2); 
        return 2;
    }
    if (!fp_output) {
        fprintf(stderr, "Error: Couldn't open the '%s' file.\n", fileName3); 
        return 3;
    }


    //2. Extract the data from dictionary.txt 
    int s; 
    fscanf(fp_input2, "%d", &s);    //printf("%d", s); 
    
    myArray conversionTable[s]; 
    for(int i=0; i<s; i++) {
        fscanf(fp_input2, "%s %s", conversionTable[i].replacement, conversionTable[i].substr); 
    } 
    // for(int i=0; i<s; i++) {
    //     printf("%s %s\n", conversionTable[i].replacement, conversionTable[i].substring); 
    // }


    //3. process the fils
    encodedTheMainFile(fp_input, fp_output, conversionTable, s);


    //4. Close the files 
    fclose(fp_input); 
    fclose(fp_input2); 
    fclose(fp_output); 

    printf("Files have been successfylly processed by the programm!\n"); 

    return EXIT_SUCCESS;
}