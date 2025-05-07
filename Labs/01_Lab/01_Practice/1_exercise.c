#include <stdio.h> 
#include <string.h> 
int main(void) {
    int x, y;
    float z;

    printf("Insert an integer number: ");
    fflush(stdout);  //To immediately flush any buffered output, use fflush(stdout) here.
    scanf("%d", &x);
    y = 3;
    z = (float) (x) / y;

    printf("%d/%d=%.3f\n", x, y, z);
    return 0;
}