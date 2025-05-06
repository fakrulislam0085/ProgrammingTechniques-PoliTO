/*In this method, you'll learn how to read data from a file line by line 
(or in chunks) using the fgets function and then write that data to another 
file using fputs. This method is ideal when you want to process text data 
one line (or a fixed-size chunk) at a time.*/

#include <stdio.h> 
int main() {
    FILE *fp_read, *fp_write;
    char buffer[256];   //buffer to store each line or chunk

    //open the input file for reading
    fp_read = fopen("input.txt", "r");
    if (fp_read == NULL) {
        fprintf(stderr, "Error when opening file.\n");
        return 1;
    }

    //open the output file for writing
    fp_write = fopen("output.txt", "w");
    if(fp_write == NULL) {
        printf("Error when opening file.\n");
        fclose(fp_read);
        return 2;
    }

    char *line;  //pointer to hold the return value of fgets()
    // Read the file line by line using fgets() and write each line using fputs()
    line = fgets(buffer, sizeof(buffer), fp_read);
    while(line != NULL) {   // Continue until fgets() returns NULL (no more lines)
        fputs(buffer, fp_write);    // Write the current line to the output file
        line = fgets(buffer, sizeof(buffer), fp_read); // Read the next line
    }

    /*Intermediate way to write this loop*/ 
    // while(fgets(buffer, sizeof(buffer), fp_read) != NULL) {  //read from the input file line by line(or in chunks) 
    //     fputs(buffer, fp_write);
    // }

    
    printf("File content copied successfully using fgets and fputs.\n");

    //closing both files
    fclose(fp_read);
    fclose(fp_write);

    return 0;
} 
