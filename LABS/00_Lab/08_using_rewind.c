/*Sometimes, after reading from a file, you might want to go back to the 
beginning to re-read it or perform a different type of processing. The 
rewind function resets the file pointer to the start of the file.*/

#include <stdio.h> 
int main(void) {
    FILE *fp;
    char buffer[100];

    //open the file for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening the input.txt file.\n");
        return 1;
    }

    //read and print the first line of the file
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("First read: %s", buffer);
    }
    //read and print the second line of the file
    if(fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Second Line: %s", buffer);
    }

    //use rewind to reset the file pointer back to the beginning
    rewind(fp);

    //read and print the first line again to verify rewind worked
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("After rewind, first line: %s", buffer);
    }

    //use rewind again to reset the file pointer back to the beginning
    rewind(fp);

    //now read the first character of the file
    char ch;
    if ((ch = fgetc(fp)) != EOF) {
        printf("First char of the file is: %c\n", ch);
    }

    //use rewind again to reset the file pointer back to the beginning
    rewind(fp);

    //now read the first word of the file
    if (fscanf(fp, "%s", buffer) != EOF) {
        printf("Now we see our first word: %s", buffer);
    }
    
    //close the file
    fclose(fp);
    return 0;
}