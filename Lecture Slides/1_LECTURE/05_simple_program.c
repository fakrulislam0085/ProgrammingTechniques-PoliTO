/*simple C program */
#include <stdio.h> 
int main(void) {
    int max, a, b;
    scanf("%d %d",&a, &b);

    if (a>=b) 
        max = a;
    else 
        max = b;
    
    printf("%d\n",max);
    
    return 0;
}