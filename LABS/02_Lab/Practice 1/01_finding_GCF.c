#include <stdio.h> 
#include <string.h> 
 
int main(void) {
    int a, b; 
    printf("Enter two postive integers(a and b): ");
    scanf("%d %d", &a, &b) ;

    /* Euler's method or Remainder method or Euclidean algorithm: repeatedly divide the greater number by the smaller one
    and replace the greater with the smaller and the smaller with the remainder.*/
    if (a < b) {    //ensure that a is the greatest number
        int temp = a; 
        a = b;
        b = temp;
    }
    int remainder = a%b;
    while(remainder != 0) {     //b!= 0
        remainder = a%b ;
        a = b; 
        b = remainder; 
    }

    printf("GCF = %d\n",a);
 
    return 0;
}