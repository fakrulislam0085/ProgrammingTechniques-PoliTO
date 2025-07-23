#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

#define NR 50 
#define NC 50 

// Function prototypes
void readMatrix(int mat[][NC], int maxR, int* nrp, int *ncp);
int detectRegion(int mat[][NC], int nr, int nc, int r, int c, int* w, int* h);

int detectRegion(int mat[][NC], int nr, int nc, int r, int c, int* w, int* h) {
    // Check is starting position is within bounds 
    if (r<0 || r>=nr || c<0 || c>=nc) {
        *w = 0;
        *h = 0; 
        return 0;
    }

    // Get the value at the starting position 
    int regionValue = mat[r][c]; 

    // If the starting cell is 0, it's not a region
    if (regionValue == 0) {
        *w = 0;
        *h = 0; 
        return 0; 
    }

    // Find the width of the region (scan right from starting position) 
    int width = 0; 
    for(int j=c; j<nc && mat[r][c] == regionValue; j++) {
        width++;
    }

    // Find the height of the region (scan down from starting postion) 
    int height = 0; 
    for(int i=r; i<nr && mat[r][c] == regionValue; i++) {
        height++; 
    }

    // Verify that all cells in the rectangle have the same value 
    for(int i=r; i<r+height && i<nr; i++) {
        for(int j=c; j<c+width && j<nc; j++) {
            if (mat[i][j] != regionValue) {
                *w = 0; 
                *h = 0; 
                return 0; 
            }
        }
    }

    // If we get here, we found a valid rectangular region
    *w = width; 
    *h = height; 
    return 1; 
}

void readMatrix(int mat[][NC], int maxR, int *nrp, int *ncp) {
    char fileName[] = "matrix.txt"; 
    FILE *fp_input = fopen(fileName, "r"); 

    if(!fp_input) {
        fprintf(stderr, "The '%s' file couldn't open.\n", fileName);
        *nrp = 0; 
        *ncp = 0;
        return ; 
    }

    fscanf(fp_input, "%d %d", nrp, ncp);    // store the actual dimentions into the pointer 
    // fscanf expects pointers
    // Inside fscanf, it does something like: *nrp = scanned_value;

    // Check if dimensions exceed maximum allowed
    if (*nrp > NR || *ncp > NC) {
        fprintf(stderr, "Matrix dimensions exceed max allowed size.\n");
        fclose(fp_input); 
        *nrp = 0; 
        *ncp = 0; 
        return;
    }

    // Read the matrix data
    for(int i=0; i<*nrp; i++) {
        for(int j=0; j<*ncp; j++) {
            fscanf(fp_input, "%d ", &mat[i][j]);
        }
    }

    fclose(fp_input); 
}

int main(void) {
    int M[NR][NC]; 
    int nr, nc;     // real dimensions of the matrix

    readMatrix(M, NR, &nr, &nc);
    
    if(nr == 0 || nc==0) {
        printf("Failed to read the matrix or matrix file is empty.\n"); 
        return 1; 
    }

    // print the matrix 
    printf("Matrix loaded successfully: nr-%d, nc-%d\n", nr, nc); 
    for(int i=0; i<nr; i++) {
        for(int j=0; j<nc; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }


    // Test detectRegion function
    printf("\nTesting BLACK region detection: \n");
    for(int r=0; r<nr; r++) {
        for(int c=0; c<nc; c++) {
            int w, h; 
            if(detectRegion(M, nr, nc, r, c, &w, &h)) {
                printf("Region found at (%d, %d) with dimensions %dx%d\n", r, c, w, h);
            }
        }
    }
    
    return 0;
}