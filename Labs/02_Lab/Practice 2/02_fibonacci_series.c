#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

/*n can be highest 46, after that we will have garbage values*/
void fibonacci_series(int n) {
    int prev = 0; 
    int curr = 1; 
    int next = prev + curr;
    printf("Standard Fibonacci series where (next = prev + curr): ");

    //edge case 
    if (n == 1) {
        printf("%d", prev);
    } else {
        printf("%d %d ",prev, curr);

        for(int i=0; i<n-2; i++) {
            printf("%d ",next);
            prev = curr;
            curr = next;
            next = prev + curr;
        }
        printf("\n");
    }
}

/*n can be highest 9, after that we will have garbage values*/
void modified_fibonacci_series(int n) {
    int x0 = 1, x1 = 2, x_next = x0 * x1 ;
    printf("Modified fibonacci series where(next = prev * curr): "); 

    //edge case 
    if(n == 1) {
        printf("%d", x0);
    } else { 
        printf("%d %d ", x0, x1);

        for(int i=0; i<n-2; i++) {
            printf("%d ",x_next);
            x0 = x1; 
            x1 = x_next; 
            x_next = x0 * x1;
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    //unsigned int n;
    printf("Enter the number of turns for the Fibonacci series: "); 
    scanf("%d", &n); 

    //Corner or Edge case 
    if (n <= 0) {
        printf("Number of terms must be postive.\n");
        exit(1);
    }
    fibonacci_series(n);
    modified_fibonacci_series(n); 
 
    return 0;
}


/*
int:  (can hold positive and negative numbers) 
standard fibonacci series: n can be highest 46.
Modified fibonacci series: n can be highest 9.

*unsigned int: (can hold only positive numbers; from 0 to positive infinity)
standard fibonacci series: n can be highest 47.
Modified fibonacci series: n can be highest 9.
*/