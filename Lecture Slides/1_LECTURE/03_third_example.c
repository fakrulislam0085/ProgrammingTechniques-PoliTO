/*Print a square of asterisk*/
#include <stdio.h> 
int main(void) {
    int n = 0 ;
    printf("Insert an integer >=2: ");
    scanf("%d", &n);
    if(n<2) {
        printf("Error: Value < 2\n");
        return -1;
    }

    for(int i=0; i<n; i++) {
        printf("*");
    }
    printf("\n");

    for(int i=2; i<n; i++) {
        printf("*");

        for(int j=2; j<n; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    for(int i=0; i<n; i++)
        printf("*");
    printf("\n");

    return 0;
}