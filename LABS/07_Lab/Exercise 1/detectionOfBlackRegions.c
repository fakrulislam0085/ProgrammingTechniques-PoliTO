#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

#define MAXR 50 
#define MAXC 50 

typedef struct {
    int x, y;   // top-left corner(0-based)
    int w, h;   // width, height
    int A;      // area
} Matrix;

// Globally declare our matrix to access it from anywhere 
int mat[MAXR][MAXC]; 

// Trackers-initialize all fields to -1
Matrix maxHeight = { -1, -1, -1, -1, -1 }; 
Matrix maxWidth = { -1, -1, -1, -1, -1 }; 
// Matrix maxArea = { -1, -1, -1, -1, -1 };
Matrix maxArea = { 0 }; 

void printData(void) {
    printf("Max-height region: upper left corner =(%d, %d), height=%d, width=%d, area=%d\n", maxHeight.x, maxHeight.y, maxHeight.w, maxHeight.h, maxHeight.A);
    printf("Max-width region: upper left corner =(%d, %d), height=%d, width=%d, area=%d\n", maxWidth.x, maxWidth.y, maxWidth.w, maxWidth.h, maxWidth.A);
    printf("Max-area region: upper left corner =(%d, %d), height=%d, width=%d, area=%d\n", maxArea.x, maxArea.y, maxArea.w, maxArea.h, maxArea.A);

}

void storeData(int i, int j, int width, int height, int area) {
    if (maxHeight.h < height) {
        maxHeight.x = i; 
        maxHeight.y = j; 
        maxHeight.w = width; 
        maxHeight.h = height; 
        maxHeight.A = area; 
    }

    if (maxArea.A < area) {
        // maxArea.x = i; 
        // maxArea.y = j; 
        // maxArea.w = width; 
        // maxArea.h = height; 
        // maxArea.A = area; 

        maxArea = (Matrix) {i, j, width, height, area};
    } 
     
    if (maxWidth.w < width) {
        // maxWidth.x = i; 
        // maxWidth.y = j; 
        // maxWidth.w = width; 
        // maxWidth.h = height; 
        // maxWidth.A = area; 

        maxWidth = (Matrix) {i, j, width, height, area};
    }
}

void detectBlackRegion(int nr, int nc) {

    for(int i=0; i<nr; i++) {
        for(int j=0; j<nc; j++) {
            // We only start a new rectangle when: 
            // mat[i][j] == 1 AND both above and left are 0 or out of bounds
            if(mat[i][j] == 1 && (i==0 || mat[i-1][j] == 0) && (j==0 || mat[i][j-1] == 0)) {
                
                //1. measure width 
                int width = 0; 
                while(j+width < nc && mat[i][j+width] == 1)
                    width++;
                
                //2. measure height (only as long as the full width remains black)
                int height = 0; 
                while (i+height < nr ) {
                    int k; 
                    for(k = 0; k<width; k++) {
                        if(mat[i+height][j+k] == 0) 
                            break;
                    }
                    if (k < width)
                        break;      // stop as soon as any column in this row fails
                    height++;
                }
                
                int area = height * width; 

                //3. record data if it's a new best
                storeData(i, j, width, height, area); 

                //4. erase the rectangle so we don't count it again
                for(int p = 0; p<height; p++) {
                    for(int q = 0; q<width; q++) {
                        mat[i + p][j + q] = 0; 
                    }
                }
            }
        }
    }
}

int main(void) {
    
    //1. open the file
    char fileName[] = "input.txt"; 
    FILE *fp_read = fopen(fileName, "r");
    if (! fp_read) {
        fprintf(stderr, "Couldn't open the '%s' file!\n", fileName);
        return EXIT_FAILURE;
    }

    //2. Read the matrix
    int nr, nc; 
    fscanf(fp_read, "%d %d", &nr, &nc); 

    for(int i=0; i<nr; i++) {
        for(int j=0; j<nc; j++) {
            fscanf(fp_read, "%d", &mat[i][j]);
        }
    }

    // 3. process the matrix 
    detectBlackRegion(nr, nc); 
    

    //4. print the data
    printData(); 


    //5. close the file 
    fclose(fp_read); 

    return 0;
}