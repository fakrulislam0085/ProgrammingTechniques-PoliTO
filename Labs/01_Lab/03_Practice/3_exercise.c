#include <stdio.h>
int main() {
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;

    if ((fp_read = fopen("Bronte.txt", "r")) == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("Output_odd.txt", "w")) == NULL) {
        fprintf(stderr, "Error opening file\n");
        fclose(fp_read);    //close the file that has already been opened
        return 2;
    }
    if ((fp_write_even = fopen("Output_even.txt", "w")) == NULL) {
        printf("Error opening file\n");
        fclose(fp_read);
        return 3;
    }

    printf("What's your name? ");
    gets(name);
    puts(" "); 

    
    while (!feof(fp_read)) {
        counter++;

        if (counter%2==0) {
            int itemsRead = fscanf(fp_read, "%s", file_string);     //Counter is even-> take just a word

            if (!feof(fp_read) && itemsRead == 1) {         //Alwasy checks the return value of fscanf() or fgets()
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s\n", file_string);
            } 
        }
        else {
            char *line = fgets(file_string, 100, fp_read);   //counter is odd-> take a whole string of 100 char

            if (!feof(fp_read) && line != NULL) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }


    fclose(fp_read);
    fclose(fp_write_even);
    fclose(fp_write_odd);

    return 0;
}


//What happens when the counter is odd? What happens when the counter is even? 
//Which is the difference between fgets() and fscanf() ??