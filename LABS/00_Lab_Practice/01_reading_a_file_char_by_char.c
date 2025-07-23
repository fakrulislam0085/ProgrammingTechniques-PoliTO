/*Reading a file char by char and printing the file in the console*/
#include <stdio.h> 
#include <string.h> 
int main(void) {
    FILE *fp_read;
    int ch;

    fp_read = fopen("data.txt", "r");
    if(fp_read == NULL) {
        printf("Error occurred when trying to open the data.txt file.\n");
        return 1;
    }

    while((ch = fgetc(fp_read)) != EOF) {   //fgetc returns EOF when the end of the file is reached.
        putchar(ch) ;
    }

    //closing the file
    fclose(fp_read);

    return 0;
}