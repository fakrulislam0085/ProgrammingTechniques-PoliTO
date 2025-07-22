#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
 
int main(void) {
    char ch;
    scanf("%c", &ch); 

    isblank(ch) ;  //tab or space or another blank char
    isspace(ch);    //tab or newline or space or enter

    isalnum(ch) ;   //alphabet or number
    isalpha(ch);    //alphabet

    isascii(ch);    //an ascii value in the range of 0 through 127

    isdigit(ch);    //a char 0 through 9
    isnumber(ch);   //a char 0 through 9 

    isprint(ch);    //any printable char
    isgraph(ch);    //any printable char except space

    ishexnumber(ch);    //any hexadecimal digit, 0 through 9 or A through F
    isxdigit(ch);   //

    islower(ch);    //identify lower char
    isupper(ch);    //identify upper char
    
    tolower(ch);    //make upper char to lower
    toupper(ch);    //make lower char to upper
    
    return 0;
}