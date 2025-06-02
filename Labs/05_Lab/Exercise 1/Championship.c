#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

void process_function(int outcome[][20], int n, int m) {
    int pts[n][m]; 

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (j==0) {
                pts[i][j] = outcome[i][j];
            } else {
                pts[i][j] = outcome[i][j] + pts[i][j-1];
            }
        }
    }

    //check the matrix 
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         printf("%d ", pts[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int j=0; j<m; j++) {
        int max = 0;
        int team = 0;
        for(int i=0; i<n; i++) {
            if (pts[i][j] > max) {
                max = pts[i][j];
                team = i;
            }
        }
        printf("After day: %d -> team: %d\n",j+1, team + 1 );
        
    }
}

int main(void) {
    FILE *fp_inFile; 
    char fileName[21];  //20 + NULL TERMINATOR

    //1. Ask the user for the input and check the input validity
    printf("Enter the file name: "); 
    if (scanf("%20s", fileName) != 1) {
        fprintf(stderr, "The file name is not found.\n"); 
        return EXIT_FAILURE;
    }

    //2. open the file 
    if ((fp_inFile = fopen(fileName, "r")) == NULL) {
        perror("File opening Error"); 
        return EXIT_FAILURE;
    }
    

    //3. Extract the matrix
    int outcome[20][20];
    
    int n, m;
    fscanf(fp_inFile, "%d %d", &n, &m); 

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            fscanf(fp_inFile, "%d", &outcome[i][j]);
        }
    }

    //check the matrix
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         printf("%d ", outcome[i][j]);
    //     }
    //     printf("\n");
    // }



    //4. Call a function to process this file 
    process_function(outcome, n, m); 

    fclose(fp_inFile);  //close the file

    return 0;
}