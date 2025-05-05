#include <stdio.h> 

#define N 3     //number of rows 
#define M 3     //number of columns
 
int main(void) {
    // Identity matrix (3x3) 
    int matrix_diagonal[3][3] = {
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}
    };

    //Declare the matrix and vectors 
    float M2[N][M] = {
        {1.0f, 2.0f, 3.0f}, 
        {4.0f, 5.0f, 6.0f}, 
        {7.0f, 8.0f, 9.0f}
    }; 

    float V[M] = {1.0f, 2.0f, 3.0f}; 
    float Y[N];


    // Matrix vector multiplication: Y = M2 * V 
    for (int r = 0; r<N; r++) {
        Y[r] = 0.0f; 
        for(int c = 0; c<M; c++) {
            Y[r] += M2[r][c] * V[c];
        }
    }

    // Output the result vector Y 
    printf("Result of matrix-vector multiplication (Y = M2 * V): \n");
    for(int i=0; i<N; i++) {
        printf("Y[%d] = %.2f\n", i, Y[i]);
    }

    return 0;
}