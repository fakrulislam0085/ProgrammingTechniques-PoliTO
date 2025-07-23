#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

int main(void) {
    FILE *fp_read, *fp_write;
    char file_char, choice;

    fp_read = fopen("guide.txt", "r");
    if(fp_read == NULL) {
        fprintf(stderr, "Error openining the file.\n");
        return 1;
    }

    fp_write = fopen("output.txt", "w");
    if(fp_write == NULL) {
        printf("Error opening file.\n");
        fclose(fp_read);
        return 2;
    }

    printf("Print on console (C) or on file (F): ");
    choice = getchar();
    choice = toupper(choice);       //make the word uppercase if it is not

    while (!feof(fp_read)) {
        file_char = fgetc(fp_read);     //after the last char of the file, fgetc() will try to read another word, it will return feof

        /*The feof function in C checks the end-of-file indicator for the given stream. 
        However, it only returns true after an attempt to read past the end of the file. 
        This means that the feof function will not return true until you have tried to 
        read beyond the last character of the file.*/
        if (feof(fp_read)) {    //break the loop if the feof is reached after reading a char
            break;
        }
        //if (!feof(fp_read)) {
            switch (choice) {
                case 'C' :
                    printf("\nChar printed on the console: %c", file_char);
                    break;
                case 'F' :
                    fputc(file_char, fp_write);
                    //printf("\nChar saved on file.");
                    //putchar(file_char);
                    break;
                default :
                    printf("Wrong choice.\n");
                    return 3;
            }
        //}
    }

    if (choice == 'F')  printf("Char saved on the file.\n");
    fclose(fp_read), fclose(fp_write);

    return 0;
}