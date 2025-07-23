#include <stdio.h>
int main(void) {
    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening input.txt for reading.\n");
        return 1;
    }

    int ch; //use int to store fgetc's return value
    //read characters until fgetc returs EOF 
    while ((ch == fgetc(fp)) != EOF) {
        putchar(ch);    //output each character to the screen
    }

    fclose(fp);
    return 0;
}