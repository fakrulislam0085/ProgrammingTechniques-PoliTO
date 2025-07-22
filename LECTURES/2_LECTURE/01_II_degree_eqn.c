#include <stdio.h> 
#include <string.h> 
#include <math.h>
 
int main(void) {

    /*We need to find out the solution of this equation:  ax^2 + bx +c = 0*/
    float a, b, c, delta, x1, x2, re, im;   //a, b, c = coefficients; x1, x2 = real solution; re, im = complex solutions (re=real, im=imaginary); determinant = delta 
    printf("Insert coefficients (a, b, c): ");
    scanf("%f %f %f", &a, &b, &c); 

    if (a==0 && b==0 && c==0) {
        printf("If all coefficients are zero, the final solution will be 0 == 0.\nSo This solution can not form any equation.\nIndetermined eqaution.\n");
    }
    else if(a==0 && b==0 && c!=0) {
        printf("The solution will be c = 0, where (c!=0). So mathematically this is an impossible equation.\n");
    }
    else if (a==0 && b!=0) {
        printf("The solution will be bx+c = 0.\nSo This is an I degree equation.\n");
        printf("Solution of x: %f\n", -c/b);
    }
    else if (a != 0) {
        delta = b*b - 4*a*c;   //determinant = b^2 - 4ac
        //solution of x = (-b +- sqrt(b^2 - 4ac)) / 2a 
        
        if (delta == 0) {
            //In this case, the solutions will be real and same/coincident 
            x1 = (-b) / (2*a) ;
            x2 = (-b) / (2*a) ; 

            printf("2 real coincident solutions: \n");
            printf("x1: %f\nx2: %f\n", x1, x2);
        }

        else if (delta > 0) {
            //In this case, the solutions will be real and distinct
            x1 = ((-b) + sqrt(delta) ) / (2*a);
            x2 = ((-b) - sqrt(delta) ) / (2*a);

            printf("2 real distincts solutions:\n");
            printf("x1: %f\nx2: %f\n", x1, x2);
        }
        else if(delta < 0) {
            //In this case, the solutions will be complex and conjugate 
            re = (-b) / (2*a) ;
            im = sqrt(-delta) / (2*a) ;
            
            printf("2 complex conjugate solutions are:\n"); 
            printf("x1 = %f + %fi\n", re, im);
            printf("x2 = %f - %fi\n", re, im);
        }
    }
 
    return 0;
}