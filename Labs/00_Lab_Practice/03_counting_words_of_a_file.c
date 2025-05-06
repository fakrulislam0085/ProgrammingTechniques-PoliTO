#include <stdio.h> 
#include <string.h> 
int main(void) {
    FILE *fp_input, *fp_output;
    char word[101];     //buffer to hold each word (max 100 char + null termoinator)
    int count = 0;

    //open the input file for reading
    fp_input = fopen("words_for_counting.txt", "r");
    if(fp_input == NULL) {
        printf("Couldn't open the file!\n");
        return 1;
    }

    //read each word using fscanf and count them 
    while (fscanf(fp_input, "%100s", word) == 1) {
        count++;
    }

    fclose(fp_input);

    //print the word count to the console
    printf("Total number of words: %d\n", count);


    //open the output file for writing the word count
    fp_output = fopen("wordcount.txt", "w");
    if (fp_output == NULL) {
        printf("Couldn't open the file!\n");
        return 2;
    }

    //writing word count into the output file
    fprintf(fp_output, "Total number of words: %d\n", count);
    fclose(fp_output);

    return 0;
}