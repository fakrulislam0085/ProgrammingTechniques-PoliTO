
/** The number of swaps 
 * The number of iterations of the outer loop 
 * Per each iteration of the outer loop, the number of iterations of the inner loop 
 * The total number of iterations
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

typedef struct {
    int total_swap;
    int itr_out_loop;
    int itr_inn_loop;
    int total_itr; 
} prt_info;

void selection_sort(int n, int vec[]) {
    prt_info stats = {0, 0, 0, 0};  // Initialize all fields to 0 

    int imin, temp; 

    for(int i=0; i<n-1; i++) {
        stats.itr_out_loop++;       // Increment outer loop counter 
        imin = i; 

        for(int j=i+1; j<n; j++) {
            stats.itr_inn_loop++;       // Increment inner loop counter 
            stats.total_itr++;      // Increment total iterations

            if(vec[j] < vec[imin]) {
                imin = j;
            }
        }

        if (imin != i) {
            temp = vec[i]; 
            vec[i] = vec[imin]; 
            vec[imin] = temp;
            stats.total_swap++;     //increment swap counter     
        }
    }

    printf("\n\nSelection Sort: \n"); 
    printf("The number of total swaps: %d\n", stats.total_swap); 
    printf("The number of outer loop iterations: %d\n", stats.itr_out_loop); 
    printf("Total number of inner loop iterations: %d\n",stats.itr_inn_loop); 
    printf("The total number of iterations: %d\n", stats.total_itr); 

}

void insertion_sort(int n, int vec[]) { 
    prt_info stats = {0}; 

    for(int i=1; i<n; i++) {
        stats.itr_out_loop++; 

        int currE = vec[i]; 
        int j; 

        for(j=i-1; j>=0 && vec[j] > currE; j--) {
            stats.itr_inn_loop++; 
            stats.total_itr++; 

            vec[j+1] = vec[j]; 
            stats.total_swap++;
        }
        vec[j+1] = currE; 
    }

    printf("\n\nInsertion Sort: \n"); 
    printf("The number of total Swaps: %d\n", stats.total_swap); 
    printf("The number of outer loop iterations: %d\n", stats.itr_out_loop); 
    printf("Total number of inner loop iterations: %d\n",stats.itr_inn_loop); 
    printf("The total number of iterations: %d\n", stats.total_itr); 
}

void shell_sort(int n, int vec[]) {
    prt_info stats = {0}; 

    for(int gap = n/2; gap>0; gap /= 2) {
        stats.itr_out_loop++; 

        for(int i=gap; i<n; i++) {
            int temp = vec[i];
            int j; 

            // shift elements that are gap apart 
            for(j=i; j>=gap && vec[j-gap] > temp; j -= gap) {
                vec[j] = vec[j- gap];
                stats.itr_inn_loop++; 
                stats.total_itr++; 
                stats.total_swap++;
            }

            vec[j] = temp;
        }
    }

    printf("\n\nShell Sort: \n"); 
    printf("The number of total Swaps: %d\n", stats.total_swap); 
    printf("The number of outer loop iterations: %d\n", stats.itr_out_loop); 
    printf("Total number of inner loop iterations: %d\n",stats.itr_inn_loop); 
    printf("The total number of iterations: %d\n", stats.total_itr); 

}

int main(void) {

    //1. File opening
    char file_name[21] = "sort.txt"; 
    FILE *fp_input = fopen(file_name, "r"); 
    if (!fp_input) {
        fprintf(stderr, "Error: Couldn't open the '%s' file\n", file_name);
        return EXIT_FAILURE;
    }

    //2. Declare the necessary variables
    int s;  // to hold the total number of line  
    fscanf(fp_input, "%d", &s);   // we have successfully read the first int of the file 
    int len_of_vec; 
    int vec[100];   // len_of_vec can be highest 100 

    while (s > 0) {
        fscanf(fp_input, "%d", &len_of_vec);

        for(int i=0; i<len_of_vec; i++) {
            fscanf(fp_input, "%d", &vec[i]);
        }
        // for(int i=0; i<len_of_vec; i++) 
        //     printf("%d ", vec[i]);
        // printf("\n");

        //3. Call the functions 
        int temp_vec[len_of_vec];

        memcpy(temp_vec, vec, len_of_vec * sizeof vec[0]);
        selection_sort(len_of_vec, temp_vec);
        
        memcpy(temp_vec, vec, len_of_vec * sizeof(int));
        insertion_sort(len_of_vec, temp_vec);
        
        memcpy(temp_vec, vec, sizeof temp_vec);
        shell_sort(len_of_vec, vec); 
        printf("\n***************************");

        s--;
    }

    //printf("%d", s); 

    fclose(fp_input); 

    return 0;
}

