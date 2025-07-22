#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 
 
int main(void) {
    char word[50]; 
    printf("Give me the word: ");
    scanf("%s", word);
    
    for (int i=0; i<strlen(word); i++) {
        word[i] = toupper(word[i]);
    }

    printf("The modified string is: %s", word);
    
    return 0;
}