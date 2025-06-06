#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

// sequence.txt
#define MAX_Seq 20
#define MAX_Char_SeqWord 5

//text.txt
#define MAX_Char_Line 200       // per line
#define MAX_Char_word 25        // per word


typedef struct {
    char seqWord[MAX_Char_SeqWord];
} Array; 


void strToLower(char *Word) {
    for(int i=0; i<strlen(Word); i++) {
        Word[i] = tolower(Word[i]); 
    }
}

// global variable to check whether the substring is present in our text file or not 
bool found = false;

void printThePos(char mainWord[], char *lowerCaseWord, char seqWord[], int WordCount,  FILE *fp_Write) {
    char *pos = NULL; 

    pos = strstr(lowerCaseWord, seqWord); 

    if(pos) {
        fprintf(fp_Write, "  > %s (Position %d)\n", mainWord, WordCount);
        found = true;
    }
}

void processTheTextFile(FILE *fp_read, FILE *fp_write, int n, char* seqWord) {
    char line[MAX_Char_Line];
    int WordCount = 0;   // reset the wordCount for the whole file 
    found = false;      // reset the boolean value
    rewind(fp_read);    // reset file pointer to the beginning of the file 

    while(fgets(line, sizeof(line), fp_read) != NULL) {

        char mainWord[MAX_Char_word] = {0};      // clear the mainWord array  
        char lowerCaseWord[MAX_Char_word] = {0}; 
        int indxWord = 0; 

        for(int i=0; line[i] != '\0'; i++) {
            char Cp = line[i];

            if (!isspace(Cp) && !ispunct(Cp))  {              // If it is a letter or digit, add it to the current word 
                mainWord[indxWord++] = Cp;
                indxWord--;
                lowerCaseWord[indxWord++] = tolower(Cp); 
            }
            else {
                // If we hit space or punctuation and word is not empty 
                if(indxWord > 0) {
                    mainWord[indxWord] = '\0';       // Null-terminate the word 
                    lowerCaseWord[indxWord] = '\0';
                    WordCount++;

                    //now we will compare the mainWord with the seqWord 
                    printThePos(mainWord, lowerCaseWord, seqWord, WordCount, fp_write);

                    // reset the index for the next word 
                    indxWord = 0; 
                    memset(mainWord, 0, sizeof(mainWord));      // clear the array with all elements 0
                    memset(lowerCaseWord, 0, sizeof(lowerCaseWord));
                }  
            }
        }

        // Handle the last word in the line (if any)
        // edge case: the last word could be end without any space/punctuation/newline
        if (indxWord > 0) {
            mainWord[indxWord] = '\0';       // Null-terminate the word 
            lowerCaseWord[indxWord] = '\0';
            WordCount++;

            printThePos(mainWord, lowerCaseWord, seqWord, WordCount, fp_write);
        }
    }
    
    if (!found) {
        fprintf(fp_write, "\t->No string is matched!\n"); 
    }
} 

int main(void) {
    char FileName1[] = "text.txt" ; 
    char FileName2[] = "sequence.txt" ; 
    char FileName3[] = "output.txt"; 

    //1. Open the files 
    FILE *fp_in, *fp_in2, *fp_out ;
    fp_in = fopen(FileName1, "r"); 
    fp_in2 = fopen(FileName2, "r"); 
    fp_out = fopen(FileName3, "w"); 

    if(!fp_in) {
        fprintf(stderr, "Couldn't open the '%s' file.\n", FileName1); 
        return 1; 
    }
    if(!fp_in2) {
        fprintf(stderr, "Couldn't open the '%s' file.\n", FileName2); 
        fclose(fp_in);
        return 2; 
    }  if(!fp_out) {
        fprintf(stderr, "Couldn't open the '%s' file.\n", FileName3); 
        fclose(fp_in); 
        fclose(fp_in2);
        return 3; 
    }


    //2. Extract the values from sequence.txt in a custom array of strings 
    Array seqArr[MAX_Seq]; 
    int n; 
    fscanf(fp_in2, "%d", &n); 
    for(int i=0; i<n; i++) {
        fscanf(fp_in2, "%4s", seqArr[i].seqWord); 
    }
    for(int i=0; i<n; i++) {
        strToLower(seqArr[i].seqWord);      // make the words of lowecase char
    }
    // check your seqArra
    // for(int i=0; i<n; i++) {
    //     printf("%s\n", seqArr[i].seqWord);
    // }


    //3. Call the function 
    for(int i=0; i<n; i++) {
        fprintf(fp_out, "Sequence '%s' is found in:\n", seqArr[i].seqWord);
        processTheTextFile(fp_in, fp_out, n, seqArr[i].seqWord);   // print all pos for one seq word in our text.txt file 
        fprintf(fp_out, "\n"); 
    }


    //4. close the files and print a message. 
    fclose(fp_in); 
    fclose(fp_in2); 
    fclose(fp_out); 

    printf("File processed successfully. See Output.txt\n"); 

    return EXIT_SUCCESS;
}

