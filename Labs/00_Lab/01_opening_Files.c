#include <stdio.h> 

int main() {
    FILE *fp_read, *fp_write;

    //attempt to open a file for reading
    fp_read = fopen("input.txt", "r");
    if (fp_read == NULL) {
        printf("Error opening input.txt for reading.\n");
        return 1;   //exit if the file can not be opened
    }

    //attempt to open a file for writing
    fp_write = fopen("output.txt", "w");
    if (fp_write == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(fp_read);    //clean up by closing the file was already opened
        return 2;
    }

    printf("Files opened successfully!\n");

    //closing the files after our work
    fclose(fp_read);
    fclose(fp_write);
    return 0;
}