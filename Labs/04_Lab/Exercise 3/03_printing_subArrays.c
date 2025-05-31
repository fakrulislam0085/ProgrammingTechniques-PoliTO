#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int create_sub_matrix(int mat[][20], int dim, int x0, int y0) {
    int sum = 0; 

    for (int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            sum += mat[x0 + i][y0 + j];
            printf("%d ", mat[x0 + i][y0 + j]);
        }
        printf("\n");
    }
    printf("\n");

    return sum;
}

void print_square_sub_matrixes(int mat[][20], int dim, int r, int c) {
    int mx_sum_in_arr = 0;      //to hold the max sum of a sub-array
    int mx_arr[dim][dim];   //to store the sub-array with the max sum
    int s;

    for (int x0 = 0; x0<r; x0++) {
        for(int y0=0; y0<c; y0++) {
            if (x0 + dim <= r && y0 + dim <= c) {
                s = create_sub_matrix(mat, dim, x0, y0); 
            
                if (s > mx_sum_in_arr) {
                    mx_sum_in_arr = s; 

                    for(int i=0; i<dim; i++) {
                        for(int j=0; j<dim; j++) {
                            mx_arr[i][j] = mat[x0 + i][y0 + j];
                        }
                    }
                }
            }
        }
    }

    //print the submatrix with the highest sum of elements 
    printf("The submatrix with maximum sum of elements (%d) is:\n\n", s);
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            printf("%d ", mx_arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    
    char in_file[21]; 
    printf("Give us the input file name: "); 
    scanf("%s", in_file); 

    FILE *input_file = fopen(in_file, "r"); 
    if (input_file == NULL) {
        fprintf(stderr, "There is something wrong in file opening.\n"); 
        exit(1);
    }

    int r, c;       //to track row and column number
    fscanf(input_file, "%d", &r);
    fscanf(input_file, "%d", &c); 

    //declare our matrix
    int mat[20][20];

    for (int i=0; i<r; i++) {
        for (int j =0; j<c; j++) {
            fscanf(input_file, "%d", &mat[i][j]);
        }
    }

    int mn = MIN(r, c);

    while(true) {
        int dim; 
        printf("\nGive us the dimension of square matrix (between 1 and mn): "); 
        scanf("%d", &dim);

        if (dim < 1 || dim > mn) {
            printf("The dimension value is inconsistent.\n");
            exit(1);
        }
        print_square_sub_matrixes(mat, dim, r, c);
    }

    return 0;
}