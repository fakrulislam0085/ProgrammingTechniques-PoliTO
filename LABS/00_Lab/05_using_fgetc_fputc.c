/*In this method, you'll learn how to read a file, one character at a time 
using fgetc and then write each character to another file using fputc. This 
approach is useful when you need to process or transform text at the character level.*/
#include <stdio.h> 

int main() {
    FILE *fp_read, *fp_write;
    int ch; //use an int to hold characters, so we can compare with EOF


    //open the input_files for reading 
    fp_read = fopen("input.txt", "r");
    if (fp_read == NULL) {
        printf("Error when opening file.\n");
        return 1;
    }

    //open the output files for writing 
    fp_write = fopen("output.txt", "w");
    if (fp_write == NULL) {
        printf("Error when opening the output file.\n");
        fclose(fp_read);    // close the file that we have already opened
        return 2;
    }

    while(!feof(fp_read)) {
        ch = fgetc(fp_read);
        fputc(ch, fp_write);
    }
    /*intermediate level looping*/
    // while((ch = fgetc(fp_read)) != EOF) {
    //     fputc(ch, fp_write);
    // }

    printf("File copied successfully character by character.\n");

    //closing the file after work
    fclose(fp_read);
    fclose(fp_write);

    return 0;

}