#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

void check_the_correctness_of_expression(FILE* expr_file) {
    //edge case 
    if (!expr_file) {
        fprintf(stderr, "Something error occurred.\n");
        return;
    }

    bool beginning_of_expr = true; 
    bool beginning_close_bracket = false;       //if it is true, the expr is already wrong
    bool last_char_is_open_bracket = false;     //if it it true, the expr is wrong
    bool last_char_is_operator = false;         //if it is true, the expr is wrong 
    bool close_bracket_after_operator = false;  //if there is an immediate close bracket after an operator, the expr is wrong
    bool saw_space_after_digit = false;           // digit + space + digit
    bool ans = true;        //suppose, the ans is true for now 

    int opened_bracket = 0; 
    int closed_bracket = 0; 
    int line_number = 0;

    int Cp, Cc;     //Cp = previour char, Cc = current char 

    //Work on the first char
    Cp = fgetc(expr_file); 
    if (Cp == EOF)  return;       //in case, there is no char in the file 
    else if (Cp == ')') {
        beginning_close_bracket = true;
        ans = false;    //As there is a close brack at the beginning, the expr is wrong
        closed_bracket += 1;        //although it has no purpose if the first char is a closed bracket
        beginning_of_expr = false;      //make it false after doing the operation on the first char
    }
    else if (Cp == '(') {
        opened_bracket += 1;
        beginning_of_expr = false;      //make it false after doing the operation on the first char
    }


    while ((Cc = fgetc(expr_file)) != EOF) {

        if (Cc == '\n') {
            //end of this expression 
            line_number++; 

            if(opened_bracket != closed_bracket) {
                ans = false; 
            } 
            else if (Cp == '(' && Cc == '\n') {
                last_char_is_open_bracket = true; 
                ans = false; 
            } else if (strchr("+-*/%%", Cp) && Cc == '\n') {
                last_char_is_operator = true;
                ans = false; 
            }

            //check the correctness of the expression 
            if(!ans) {
                printf("Error in expression %d\n", line_number);
            }

            //if we encounter a newline char, we will start from the first char of the next line
            //Before starting again we will reset every variable
            beginning_of_expr = true; 
            beginning_close_bracket = false;       //if it is true, the expr is already wrong
            last_char_is_open_bracket = false;     //if it it true, the expr is wrong
            last_char_is_operator = false;         //if it is true, the expr is wrong 
            close_bracket_after_operator = false;  //if there is an immediate close bracket after an operator, the expr is wrong
            saw_space_after_digit = false;           //if it is true, the expr is wrong 
            ans = true;        //suppose, the ans is true for now 

            opened_bracket = 0; 
            closed_bracket = 0; 

            //Work on the first char
            Cp = fgetc(expr_file); 
            if (Cp == EOF)  return;       //in case, there is no char in the file 
            else if (Cp == ')'){
                beginning_close_bracket = true;
                ans = false;    //As there is a close brack at the beginning, the expr is wrong
                closed_bracket += 1;        //although it has no purpose if the first char is a closed bracket
                beginning_of_expr = false;      //make it false after doing the operation on the first char
            }
            else if (Cp == '(') {
                opened_bracket += 1;
                beginning_of_expr = false;      //make it false after doing the operation on the first char
            }

            continue;
        }
        else if (ans) {
            if (Cc != '\n') {

                if (strchr("+-*/%%()", Cp) && (isspace(Cc) || Cc == '\t')) {
                    continue;   //jump straight to the next fgetc() if there  is a space after an operator
                }
                if ((isdigit(Cp)) && (isspace(Cc) || Cc == '\t')) {
                    // digit + space + ...
                    saw_space_after_digit = true;

                    continue;   //jump straight to the next fgetc() if there is a space after a digit
                }

                //3rd point of question
                if (Cc == '(' && !(beginning_of_expr || Cp == '(' || strchr("+-/*%%", Cp))) {
                    ans = false;
                }
                //Do not flag digit after digit as wrong (23)
                else if (isdigit(Cc) && !(isdigit(Cp) || beginning_of_expr || Cp == '(' || strchr("+-*/%%", Cp))) {
                    ans = false;
                }
                else if ((Cc == ')' || strchr("+-*/%%", Cc)) && !((Cp == ')') || isdigit(Cp))) {
                    ans = false;
                }
                else if (saw_space_after_digit && (Cc != EOF && isdigit(Cc))) {
                    // ... + space + digit
                    ans = false;

                    //reset
                    saw_space_after_digit = false;
                }
                else if (!isspace(Cc)) {
                    // any non‑space that isn’t a digit after spaces clears the flag
                    saw_space_after_digit = false;
                }

                if (Cc == '(')     opened_bracket++;
                if (Cc == ')')     closed_bracket++;
            } 
        } 

        //update the char
        Cp = Cc; 
    }

    //handling last line if file doesn't end with '\n'
    if (!beginning_of_expr) {   //we saw at least one char on the last line
        //end of this expression 
        line_number++; 

        if(opened_bracket != closed_bracket) {
            ans = false; 
        } 
        else if (Cp == '(' && Cc == '\n') {
            last_char_is_open_bracket = true; 
            ans = false; 
        } else if (strchr("+-*/%%", Cp) && Cc == '\n') {
            last_char_is_operator = true;
            ans = false; 
        }

        //check the correctness of the expression 
        if(!ans) {
            printf("Error in expression %d\n", line_number);
        }
    }
}

int main(void) {
    FILE* in_file = fopen("expr.txt", "r"); 

    //edge case
    if (in_file == NULL) {
        fprintf(stderr, "Something error occurred.\n");
        return 1;
    }

    check_the_correctness_of_expression(in_file);

    //close the file 
    fclose(in_file);

    return 0;
}    
 