#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdbool.h>
#define in_file "input.txt"
#define out_file "output.txt" 
#define line_limit 25

void solve_the_problem(FILE *read_file, FILE *write_file) {
    //edge case (if the files are sent to this funciton without proper checking) or in case the solve_the_problem function calls from another function other than main() without checking the edge cases
    if (read_file == NULL || write_file == NULL)    return; 
    
    int Cp, Cc, Cn;     //Cp = prev, Cc = curr, Cn = next
    int count = 0;      //to maintain line limit we will count every char in count variable
    //maintain a flag to check whether there is a sentence ending punctuation(.!?)
    bool flag = false; 

    Cp = getc(read_file); 
    Cc = getc(read_file);
 
    //check whether the first char is a number or not and print it in the console
    if (Cp != EOF && !(Cp >= '0' && Cp <= '9')) {   //Cp is not a number
        fputc(Cp, write_file);
        count++;
    } else if (Cp != EOF && (Cp >= '0' && Cp <= '9')) {     //Cp is a number
        fputc('*', write_file);
        count++;
    }
    
    while ((Cn = getc(read_file)) != EOF) {
        //repace all the numerical char with '*' 
        if (Cc >= '0' && Cc <= '9') {
            fprintf(write_file, "*");
            count++;
        }

        //add a space after each punctuation (unless it is already followed by a space, newline, another punctuation char)
        else if (strchr(".,;:!?()'", Cc) && !(strchr(".,;:!?\n ", Cn))) {
            //print the punctuation + space
            fprintf(write_file, "%c ", Cc);     
            count += 2;     //char + space


            //If it's really end-of-sentence, mark the next alpa for uppercase
            if (strchr(".!?", Cc)) {
                flag = true;
            }
        } 

        //After '.', '!', '?' the char will be alphabetic.
        else if (strchr(".!?", Cp) && strchr(" \n", Cc)) {
            //print the cc char then next 
            flag = true;
            
            if (Cc == ' ') {
                fputc(' ', write_file); 
                count++;
            }

            //if Cc == '\n', do nothing + does not count this word.
        } 

        else {
            if (flag) {
                fprintf(write_file, "%c", toupper(Cc));
                count++;
                flag = false;
            }
            else if (Cc != '\n') {
                fprintf(write_file, "%c", Cc); 
                count++;
            }

            //if Cc == '\n', we are not counting this word.
        }

        //each line should be of maximum 25 char 
        if (Cc == '\n' || count >= line_limit) {     //the problem was here. you didn't use it in your previous implementation. 
            //find out the spaces to fill out the lines with 25 chars
            int sp = line_limit - count;

            //print spaces to fill the line up to 25 chars
            for(int i=0; i<sp; i++) 
                fputc(' ', write_file);
            
            //tack on the counter and a single newline
            fprintf(write_file, "| c:%d\n", count);   //each line should be of 25 char without considering the newLine, and we didn't include newline char in our count
           
            //reset the counter for the new line
            count = 0;
        }

        Cp = Cc;    //update the prev char
        Cc = Cn;    //update the next char
    }
    // end of while

    // **flush any remaining characters on the last line**
    //print the char count for the last line
    if (count > 0) {
        int sp = line_limit - count; 

        while(sp --> 0) {
            fputc(' ', write_file);
        }

        fprintf(write_file, "| c:%d\n", count);
    }

    return;
}

int main(void) {
    FILE *read_file, *write_file; 

    //open the files 
    read_file = fopen(in_file, "r"); 
    if (read_file == NULL) {
        printf("Error: when trynna to open the input file.\n");
        return 1;   //for input file error
    } 

    write_file = fopen(out_file, "w"); 
    if (write_file == NULL) {
        printf("Error: When trynna to open the output file.\n"); 
        fclose(write_file); 
        return 2;   //for output file error
    }

    //Call the functions
    solve_the_problem(read_file, write_file);
    printf("File processing completed.\n");

    //close the files
    fclose(read_file);
    fclose(write_file);
 
    return 0;
}