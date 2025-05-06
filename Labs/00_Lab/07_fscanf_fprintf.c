/*fscanf → Reads formatted data from a file (like scanf, but from a file).
fprintf → Writes formatted data to a file (like printf, but to a file).
Useful when handling structured data (like numbers, words, or CSV files).*/

#include <stdio.h> 
int main() {
    FILE *fp_read, *fp_write;
    char word[101]; //bufffer to store each word

    //open the input file for reading
    fp_read = fopen("input.txt", "r");
    if (fp_read == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    //open the output file for writing
    fp_write = fopen("output.txt", "w");
    if(fp_write == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        fclose(fp_read);
        return 2;
    }

    //fscanf() returns the number of input items successfully read.
    int itemsRead = fscanf(fp_read, "%100s", word);
    while(itemsRead == 1) {
        //write the word to the output file followed by a newline so each word appears on its own line.
        fprintf(fp_write, "%s\n", word);

        //read the next word from the input file
        itemsRead = fscanf(fp_read, "%100s", word);
    } 

    /*More advanced way to write the same loop*/
    //read words one by one using fscanf and write them using fprintf
    // while (fscanf(fp_read, "%s", word) != EOF) {
    //     fprintf(fp_write, "%s\n", word);    //write each word in a new line
    // }

    printf("File content copied successfully using fscanf and fprintf.\n");

    //closing the files
    fclose(fp_read);
    fclose(fp_write);

    return 0;
}