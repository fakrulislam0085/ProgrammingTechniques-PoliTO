#include <stdio.h>
int main() {
    int a = 5;
    float b;

    b = a;  // Implicit cast: int → float (5 becomes 5.0)
    printf("Value of b: %.1f\n", b);  // Output: 5.0

    return 0;
}