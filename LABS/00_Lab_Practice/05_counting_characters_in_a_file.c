#include <stdio.h> 
#include <string.h> 
int main(void) {
    FILE *fp_input, *fp_output;
    int ch;
    int charcount = 0;

    fp_input = fopen("input.txt", "r");
    if(fp_input == NULL) {
        printf("Error when opening the file.\n");
        return 1;
    }

    while ((ch = fgetc(fp_input)) != EOF) { //fgetc() return EOF when there is no other char
        charcount++;
    }

    fclose(fp_input);
    
    //printing the character count to the console
    printf("There are %d characters in our input.txt file.", charcount);


    //writing the char count to a new file named charcount.txt
    fp_output = fopen("charCount.txt", "w");
    if (fp_output == NULL) {
        printf("Error: when trynna to open the file!\n");
        return 2;
    }

    
    //printing the char count to a new file
    fprintf(fp_output, "There are total %d characters in our input.txt file.\n", charcount);
    fclose(fp_output);
    
    return 0;
}