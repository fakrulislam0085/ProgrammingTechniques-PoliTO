#include <stdio.h> 

int main() {
    char letter;

    printf("Enter a character using getchar: ");
    letter = getchar(); //read the next character from standard input

    //output the character using putchar
    printf("You entered: ");
    putchar(letter);
    putchar('\n');

    return 0;
}