#include <stdio.h> 
#include <string.h> 
#include <math.h> 

int main(void) {
    int a, b, c ; 
    float area;

    printf("Give us the sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c) ;
    
    if (a>b && a>c) {
        area = (0.5) * b * c;   //1/2 * height * base;  Caveat: we need to do real number division here,not the integer division
        printf("Hypotenuse is side a: %d\n", a);
    } else if (b>a && b>c) {
        area = (0.5) * a * c ;
        printf("Hypotenuse is side b: %d\n", b);
    } else if (c>a && c>b) {
        area = (0.5) * a * b ;
        printf("Hypotenuse is side c: %d\n", c);
    }
    else {
        printf("The given side lengths do not form a right triangle.");
        return 1;
    }
    printf("Area of the right triangle is: %0.3f\n", area);
 
    return 0;
}