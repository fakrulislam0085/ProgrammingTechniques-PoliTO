#include <stdio.h> 
int main() {
    for (char c = 'A'; c<= 'Z'; c++) {
        fputc(c, fout);
    }
}