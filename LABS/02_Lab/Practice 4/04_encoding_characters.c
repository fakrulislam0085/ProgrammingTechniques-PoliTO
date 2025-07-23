#include <stdio.h> 
#include <string.h> 

int encoding(FILE* fin, FILE* fout) {
    //edge case 
    if (fin == NULL || fout == NULL)    return 0;

    int count = 0;  
    int c0 = fgetc(fin);    //read the first char of the file
    fprintf(fout, "%c", c0);
    count++;
    int Cc;     //to hold current char
    int k = 0;  //to track the numeric postion
    int newChar;    //to our new coded Char

    while((Cc = fgetc(fin)) != EOF) {

        //Numeric char should be encoded into the numeric char that is K position later in the ASCII table
        if(Cc >= '0' && Cc <= '9') { 
            if (Cc + k > '9') {
                newChar = '0' + ((Cc - '0' + k) % 10) ;
            } else {
                newChar = Cc + k;
            }
          
            fprintf(fout, "%c", newChar);
            count++;
            k++;
        }
        //if there is an space before a char specially before c0
        else if (((('A' <= Cc && Cc <= 'Z') || (Cc>= 'a' && Cc<='z'))) && (!(('A' <= c0 && c0 <= 'Z') || (c0 >='a' && c0 <='z')))) {
            fputc(Cc, fout);
            count++;
        }
        //If the alphabetic char is preceded by a non-alphabetic char, it should remain unchanged
        else if ( ! (('A' <= Cc && Cc <= 'Z') || (Cc>='a' && Cc<='z')) ) {
            fputc(Cc, fout);
            count++;
        } 
        //If the alphabetic char is preceded by an alphabetic char, it should be incremented by (h + c0) position
        else if('A' <= c0 && c0 <= 'Z')
        {
            int h = c0 - 'A';

            if('a' <= Cc && Cc <= 'z') {
                if (h + Cc > 122) {
                    newChar = 'a' + ((Cc - 'a' + h) % 26);
                    fprintf(fout, "%c", newChar);
                    count++;
                } else { 
                    int newChar = Cc + h;
                    fprintf(fout, "%c", newChar);
                    count++;
                } 
            } else {    //Cc is in the bound of chapital letter
                if (h+Cc > 90) {    //problem
                    newChar = 'A' + ((Cc - 'A' + h) % 26);
                    fprintf(fout, "%c", newChar);
                    count++;
                }
                else { 
                    newChar = Cc + h;
                    fprintf(fout, "%c", newChar);
                    count++;
                } 
            }
        }
        else if ('a' <= c0 && c0 <= 'z') {
            int h = c0 - 'a';

            if('a' <= Cc && Cc <= 'z') {
                if (h + Cc > 122) {
                    newChar = 'a' + ((Cc - 'a' + h) % 26);
                    fprintf(fout, "%c", newChar);
                    count++;
                } else { 
                    newChar = Cc + h;
                    fprintf(fout, "%c", newChar);
                    count++;
                } 
            } else {    //Cc is in the bound of chapital letter
                if (h+Cc > 90) {    //problem
                    newChar = 'A' + ((Cc - 'A' + h) % 26);
                    fprintf(fout, "%c", newChar);
                    count++;
                }
                else { 
                    newChar = Cc + h;
                    fprintf(fout, "%c", newChar);
                    count++;
                } 
            }   
        }
        c0 = Cc;

    }

    return count;
}

int decoding(FILE* fin, FILE* fout){
    printf("we will see it later.");
}

int main(void) {
    char user_input[50]; 
    printf("What to do? (encoding/decoding): ");
    scanf("%s", user_input);

    if(strcmp(user_input, "encoding") == 0) {
        FILE *in_file, *out_file;
        char file1[50], file2[50];

        //Taking the files name from the user
        printf("Enter the input file name: ");
        scanf("%s",file1);
        printf("Enter the output file name: "); 
        scanf("%s",file2);
        
        //open the files to read the input and write the output
        in_file = fopen(file1, "r");
        if (in_file == NULL) {
            printf("The file does not exist.\n");
            return 1;
        } 
        out_file = fopen(file2, "w");
        if(out_file == NULL) {
            printf("The file does not exist.\n");
            fclose(in_file);
            return 2;
        }

        //call the function to encode our source text
        int totalChar = encoding(in_file, out_file);
        if (totalChar == 0) {
            printf("Encoding failed.\n");
        } else {
            printf("Encoding successful! %d characters written to encoded.txt\n", totalChar);
        }

        //closing the files 
        fclose(in_file);
        fclose(out_file);
        
    } else if(strcmp(user_input, "decoding") == 0) {
        FILE *infile, *outfile; 
        char file1[50], file2[50]; 

        printf("Enter the input file name: ");
        scanf("%s", file1); 
        printf("Enter the output file name: ");
        scanf("%s", file2);

        //open the files 
        infile = fopen(file1, "r");
        if(infile == NULL) {
            printf("File opening error.\n");
            return 3;
        }
        outfile = fopen(file2, "w"); 
        if(outfile == NULL) {
            printf("File opening error.\n");
            fclose(infile);
            return 4;
        }

        //call the function to re-encode/decode our encoded text 
        int totalChar = decoding(infile, outfile); 
        if(totalChar == 0) {
            printf("Decoding failed!\n");
        } else {
            printf("Decoding successful with printing %d letters in our outfile.\n", totalChar);
        }


        //closing the files
        fclose(infile);
        fclose(outfile);
    } 
    else {
        printf("Please enter a valid input.\n");
    }
 
    return 0; 
}