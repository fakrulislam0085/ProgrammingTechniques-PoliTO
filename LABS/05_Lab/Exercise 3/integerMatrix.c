#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

int mat[30][30]; 
int nr, nc;     // declare globally so that we can access these values from anywhere

void rotateRow(int index, char *d, int pos) {
    int ireal = index - 1;      //1-based to 0-based

    if(strcmp(d, "right") == 0) {
        // our values will be shifted to right by one position; and last value will be the first value
        for(int i=0; i<pos; i++) {  // iterate the loop by pos times
            int endVal = mat[ireal][nc-1]; 

            // Shift all values to the right by one position
            for(int j=nc-1; j>0; j--) {
                mat[ireal][j] = mat[ireal][j-1];    
            }

            mat[ireal][0] = endVal;     // Put last value at the beginning
        }
    }
    else if(strcmp(d, "left") == 0) {
        // rotate row 'ireal' to the left by 'pos' times
        for(int i=0; i<pos; i++) {
            int firstVal = mat[ireal][0]; 

            // Shift all values to the left by one position
            for(int j=0; j<nc-1; j++) {
                mat[ireal][j] = mat[ireal][j+1];
            }

            mat[ireal][nc-1] = firstVal;    // Put first value at the end
        }
    }
}

void rotateColumn(int index, char *d, int pos) {
    int jreal = index - 1;      //1-based to 0-based 

    if(strcmp(d, "up") == 0) {
        // Rotate column upwards by 'pos' positions
        for(int i=0; i<pos; i++) {
            int topVal = mat[0][jreal];

            // Shift all values up by one position
            for(int x=0; x<nr-1; x++) {
                mat[x][jreal] = mat[x+1][jreal];
            }

            mat[nr-1][jreal] = topVal;    // Move top value to bottom
        }
    } 
    else if (strcmp(d, "down") == 0) {
        // Rotate column downwards by 'pos' positions
        for(int i=0; i<pos; i++) {
            int bottomVal = mat[nr-1][jreal]; 

            // Shift all values down by one position
            for(int x=nr-1; x>0; x--) {
                mat[x][jreal] = mat[x-1][jreal];
            }

            mat[0][jreal] = bottomVal;   // Move bottom value to top
        }
    }
}

int main(void) {
    char fileName[19]; 
    printf("Enter the file name: "); 
    scanf("%s", fileName); 
    getchar();      // consume the leftover newline by scanf() into input buffer 


    FILE *fp_read = fopen(fileName, "r"); 
    if(!fp_read) {
        fprintf(stderr, "Couldn't open the file '%s'.\n", fileName); 
        return EXIT_FAILURE;
    }

    fscanf(fp_read, "%d %d", &nr, &nc); 
    for(int i=0; i<nr; i++) {
        for(int j=0; j<nc; j++) {
            fscanf(fp_read, "%d", &mat[i][j]); 
        }
    }

    char line[99]; 
    printf("Command: ");
    fgets(line, sizeof(line), stdin) ;  // <selector> <index> <direction> <locations>

    char selector[7];   // row/column/end
    int index;      // 1-based
    char direction[6];  //right/left/up/down
    int location;   //position of the rotation

   while(sscanf(line, "%s %d %s %d", selector, &index, direction, &location) == 4) {
        // printf("Parsed Command:\n");
        // printf("  Selector : %s\n", selector);
        // printf("  Index    : %d\n", index);
        // printf("  Direction: %s\n", direction);
        // printf("  Location : %d\n", location);    
        
        if(strcmp(selector, "row") == 0) {
            rotateRow(index, direction, location);

            //print the matrix
            for(int i=0; i<nr; i++) {
                for(int j=0; j<nc; j++) {
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
        } 
        else if(strcmp(selector, "column") == 0) {
            rotateColumn(index, direction, location); 

            //print the matrix
            for(int i=0; i<nr; i++) {
                for(int j=0; j<nc; j++) {
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
        }        
        
        printf("Command: ");
        fgets(line, sizeof(line), stdin) ;
    } 
    

    return 0;
}