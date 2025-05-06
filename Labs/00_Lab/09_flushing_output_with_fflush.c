/*Sometimes, you want to make sure that output is written to the console 
immediately—especially when you're prompting the user for input. The fflush 
function is used to flush a stream (most commonly stdout), ensuring that 
any buffered output is immediately written out.

Note:
Flushing the output stream with fflush(stdout) is standard and portable. 
However, using fflush(stdin) to clear the input buffer is not part of the 
C standard and may not work reliably across all platforms.*/

#include <stdio.h> 
int main() {
    char ch;

    //prompt the user to enter a character
    //without fflush(stdout), the prompt might not appear immediately.
    printf("Enter a character: ");
    fflush(stdout); //Force the output buffer to flush, ensuring the prompt is shown

    //read a character from the user
    ch = getchar();

    //display the entered character
    printf("You entered: %c\n", ch);

    return 0;
}