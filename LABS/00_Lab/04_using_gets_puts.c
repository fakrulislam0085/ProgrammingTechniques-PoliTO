/*This method demonstrates how to read an entire line of text (a string) 
from the user using gets, and then output it using puts.*/

#include <stdio.h> 
int main() {
    char string[101]; //Buffer for up to 100 characters + the null terminator

    //prompt the user to enter a string
    printf("Enter a string: ");

    //read an entire line of input using gets 
    gets(string);  // Warning: gets is unsafe because it doesn't check buffer boundaries!


    //output the string using puts
    printf("You entered: ");
    puts(string);

    return 0;
}