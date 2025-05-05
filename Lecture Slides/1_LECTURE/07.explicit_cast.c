#include <stdio.h>

int main() {
    int x = 10, y = 3;
    float result;

    result = (float)x / y;  // Explicit cast: int → float

    printf("Result: %.2f\n", result);  // Output: 3.33

    return 0;
}
