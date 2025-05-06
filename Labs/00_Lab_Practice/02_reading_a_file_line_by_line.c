#include <stdio.h> 
#include <string.h> 
int main(void) {
    FILE *fp_read, *fp_write;
    char buffer[50];

    //opening the input file
    fp_read = fopen("input.txt", "r");
    if (fp_read == NULL) {
        printf("Error when opening the input file.\n");
        return 1;
    }

    //opening the output file
    fp_write = fopen("output.txt", "w");
    if(fp_write == NULL) {
        printf("Error when opening the output file.\n");
        fclose(fp_read);
        return 2;
    }

    //as lines are strings so we have to take input using fgets() 
    while(fgets(buffer, sizeof(buffer), fp_read) != NULL) {
        fputs(buffer, fp_write);
    }
    printf("File copied line by line successfully!");

    //closing the files
    fclose(fp_read);
    fclose(fp_write);

    return 0;
}