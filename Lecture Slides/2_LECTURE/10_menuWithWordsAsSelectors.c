/*The menu_word() function reads user input as a line of text, extracts the first word as a command 
(case-insensitive), and treats the rest of the line as arguments. Based on the command — "seek", "mod", 
"pr" — it calls the appropriate function (seek(), modify(), or print()). If the command is "end", the 
loop terminates. Any unrecognized command triggers an error message. It uses fgets() for safe input 
and string manipulation functions to process the command and arguments efficiently.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

void seek (char* args) {
    printf("SEEK called with: %s\n", args);
}

void modify(char* args) {
    printf("MODIFY called with: %s\n", args); 
}

void print(char* args) {
    printf("PRINT called with: %s\n", args);
}

void menu_word(void) {
    const int MAXL = 51;    //50 + '\0'
    char line[MAXL];    //full input line
    char command[MAXL];     //extracted command 
    bool toContinue = true; 

    while (toContinue) {
        printf("Command (seek/mod/pr/end): ");
        fgets(line, MAXL, stdin); 

        //remove trailing newline if present
        line[strcspn(line, "\n")] = '\0';

        // Declare two indexes
        int i=0, j = 0;

        //skip leading spaces 
        while(line[i] == ' ') i++;

        // Extract word into command 
        while(line[i] != ' ' && line[i] != '\0') {
            command[j++] = toupper(line[i++]);
        }
        command[j] = '\0';      //Null terminate

        //skip space after command to get the rest of the arguments 
        while (line[i] == ' ') i++;

        char *args = &line[i];      //This points ot the rest of the input 

        //match the command 
        if (strcmp(command, "SEEK") == 0 ) {
            seek(args);
        } else if (strcmp(command, "MOD") == 0) {
            modify(args);
        } else if (strcmp(command, "PR") == 0) {
            print(args);
        } else if (strcmp(command, "END") == 0) {
            toContinue = false;
        } else {
            printf("Not valid command.\n");
        }

    }
    
}
int main(void) {
    
    menu_word();    //call the function
    return 0;
}