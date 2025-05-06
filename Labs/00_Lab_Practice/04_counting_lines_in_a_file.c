#include <stdio.h> 
#include <string.h> 
int main(void) {
    FILE *fp_input, *fp_output;
    char buffer[256];
    int count = 0;

    //opening the input file
    fp_input = fopen("input.txt", "r");
    if (fp_input == NULL) {
        printf("Error: When opening the file.\n");
        return 1;
    }

    while((fgets(buffer, sizeof(buffer), fp_input)) != NULL) {
        count++;
    }

    fclose(fp_input);
    printf("There are %d lines in our input file.", count);

    
    //write the line count in the output file
    fp_output = fopen("linecount.txt", "w");
    if(fp_output == NULL) {
        printf("Error: When opening the file.\n");
        return 2;
    }
    
    fprintf(fp_output, "In our input.txt file, there has total %d number of lines.", count);
    fclose(fp_output);

    return 0;
}