#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>

int compressing(FILE* fin, FILE* fout) {
    //edge case 
    if(fin == NULL || fout == NULL)     return 0;

    int past = fgetc(fin); 
    if (past == EOF)    return 0;   //handle empty file

    int current; 
    int repsCount = 0, total = 0;
    bool max_reps_reached = false;

    while((current = fgetc(fin)) != EOF) {
        if (current == past) {
            repsCount++;

            if (repsCount == 9) {
                fprintf(fout, "%c!%d",current,repsCount);
                total += 3;
                repsCount = 0;
                // max_reps_reached = true;
            }

        } else {
            // if (max_reps_reached)   continue;
            else lif (repsCount >= 2) {
                fprintf(fout, "%c!%d",past,repsCount);
                total += 3;
            }
            else {
                for(int i=0; i<=repsCount; i++) {
                    fprintf(fout, "%c", past);
                    total++;
                }             
            } 
            repsCount = 0;
        }
        past = current;
    }

    return total;
}

int decompressing(FILE* fin, FILE* fout) {
    //edge case 
    if (fin == NULL || fout == NULL)    return 0;

    int past = fgetc(fin); 
    if(past == EOF) return 0;   //handle empty file 

    int current, next;
    int total = 0; 

    while((current = fgetc(fin)) != EOF) {
        if(current == '!') {
            next = fgetc(fin) - '0';    //transform the ascii value to standard digit
            for(int i=0; i<next+1; i++) {   //if repetition is 5, the original char will be 6 times (according to the question)
                fprintf(fout, "%c", past);
                total += 1;
            }
        } else {
            if(past != '!') {
                fprintf(fout, "%c", past);
                total += 1;
            }
        }
        past = current;
    }

    //writing the last char
    fprintf(fout, "%c", past);
    total += 1;

    return total;

}

int main(void) {

    char user_input[50];
    printf("What should the program do?(compression/decompression): ");
    scanf("%s", user_input);

    FILE *input_file, *second_input_file, *output_file, *second_output_file; 

    if(strcmp(user_input, "compression") == 0) {

        //open the file for reading the normal text to do compression
        input_file = fopen("source.txt", "r"); 
        if(input_file == NULL) {
            printf("Error: opening the file.\n");
            return 1;
        }

        //open the file for writing compressed text
        output_file = fopen("compressed.txt", "w");
        if(output_file == NULL) {
            printf("Error: opening the file.\n");
            fclose(input_file);
            return 2;
        }

        //Call the compressing function to compress the file
        int result = compressing(input_file, output_file);

        if (result == 0) {
            printf("Compression failed.\n");
        } else {
            printf("Compression successful! %d characters written to compressed.txt\n", result);
        }

        //closing the files
        fclose(input_file);
        fclose(output_file);

    } else if (strcmp(user_input, "decompression") == 0) {
        
        //open the file for reading the compressed text to do decompression 
        second_input_file = fopen("source2.txt", "r");
        if (second_input_file == NULL) {
            printf("Error: file opening.\n");
            return 3;
        }

        //open the file for writing decompressed text
        second_output_file = fopen("decompressed.txt", "w"); 
        if (second_output_file == NULL) {
            printf("Error: opening the file.\n");
            fclose(second_input_file);
            return 4;
        }

        //Call the decompression funciton to decompress our source2.txt file
        int result = decompressing(second_input_file, second_output_file);

        if (result == 0) {
            printf("Decompression failed.\n");
        } else {
            printf("Decompression successful! %d characters written to decompressed.txt\n", result);
        }

        //closing the file
        fclose(second_input_file);
        fclose(second_output_file);

    } else {
        printf("Wrong Command.\n");
    }

    return 0;
}