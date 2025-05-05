#include <stdio.h> 
#include <string.h> 
 
int main(void) {
    int n;
    float HN;
    printf("Enter the number (<=0 to END): ");
    scanf("%d", &n) ;

    while (n > 0) {
        /*compute and print HN*/ 
        HN = 0.0;   //initialization
        for(int i=1; i<=n; i++) {         
            printf("Result: 1/%d\n", i);
        }
        
        printf("Number of terms (<=0 to END): ");
        scanf("%d", &n);
    }
 
    return 0;
}

