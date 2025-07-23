#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

int compressing(FILE *fin, FILE *fout) {
    //edge case
    if(fin == NULL || fout == NULL) {
        return 0; 
    }

    int Cp = fgetc(fin); 
    if (Cp == EOF)  return 0;
    int Cc; 
    int cnt = 0;
    int reps = 0; 

    while((Cc = fgetc(fin)) != EOF) {

        if (Cp != Cc) {
            if (reps > 9) {
                int second = reps - 9; 
                fprintf(fout, "%c!%d",Cp,9);
                cnt += 3; 

                if (second >= 4) {
                    fprintf(fout, "%c!%d", Cp, second); 
                    cnt += 3; 
                } else {
                    for (int i=0; i<second; i++) {
                        fprintf(fout, "%c", Cp); 
                        cnt++;
                    }
                }
            }
            else if(reps >= 2 && reps <= 9) {
                fprintf(fout, "%c!%d", Cp, reps);
                cnt += 3;
            }
            else if (reps == 1) {
                fprintf(fout, "%c%c", Cp, Cp); 
                cnt += 2;
            } 
            else {
                fprintf(fout, "%c", Cp);
                cnt++;
            }
            reps = 0;
        }
        else if (Cp == Cc) {
            reps++;
        }

        //update char
        Cp = Cc;
    }
    return cnt; 
}
 
int decompressing(FILE *fin, FILE *fout) {

    //
}

int main(void) {
    printf("Type C for compression; type D for decompression: ");
    char userInput;   
    scanf("%c", &userInput);

    FILE *in_file, *out_file; 

    if (userInput == 'C') {
        if((in_file = fopen("source.txt", "r")) == NULL) {
            fprintf(stderr, "Unable to open the file.\n"); 
            exit(1);
        } 
        if ((out_file = fopen("compressed2.txt", "w")) == NULL) {
            fprintf(stderr, "Unable to open the file.\n"); 
            fclose(in_file); 
            exit(2); 
        }

        int totalChar = compressing(in_file, out_file); 

        if(totalChar > 0) {
            printf("Total characters that have been read: %d", totalChar); 
        }
    }
    else if (userInput == 'D') {
        if((in_file = fopen("source2.txt", "r")) == NULL) {
            fprintf(stderr, "Unable to open the file.\n"); 
            exit(1);
        } 
        if ((out_file = fopen("decompressed.txt", "w")) == NULL) {
            fprintf(stderr, "Unable to open the file.\n"); 
            fclose(in_file); 
            exit(2); 
        }

        int totalChar = decompressing(in_file, out_file); 

        if(totalChar > 0) {
            printf("Total characters that have been read: %d", totalChar); 
        }
    }
    else {
        printf("Invalid Input.\n");
    }

    fclose(in_file) ;
    fclose(out_file);


    return 0;
}