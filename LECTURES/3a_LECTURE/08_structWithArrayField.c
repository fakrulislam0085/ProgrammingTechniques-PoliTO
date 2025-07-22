#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define NMAX 100 
#define MAXL 50 

// Struct definition 
typedef struct { 
    char name[MAXL] , surName[MAXL]; 
    int matricola; 
    float score;
} Students;


// Reads one student from standard input 
Students readStudent(void) {
    Students s; 
    printf(" Name: "); 
    scanf("%49s", s.name); 
    printf(" Surname: "); 
    scanf("%49s", s.surName); 
    printf(" Matricola (ID): "); 
    scanf("%d", &s.matricola); 
    printf(" Score: "); 
    scanf("%f", &s.score); 
    printf("\n");

    return s;
}


// Simple selection sort by score 
void sortStudents(Students list[], int n) {     //array always holds the address of the first value so we can write like this
    int min_idx; 
    Students temp; 

    for (int i=0; i<n-1; i++) {
        min_idx = i; 

        for (int j=i+1; j<n; j++) {
            if (list[j].score < list[min_idx].score) {
                min_idx = j;
            }
        }

        // swap list[i] and list[min_idx]
        if (min_idx != i) {
            temp = list[i]; 
            list[i] = list[min_idx]; 
            list[min_idx] = temp; 
        }
    }
    
}


// Print one student to standard output 
void printStudents(const Students *list_ptr) {      
    printf(" %-10s %-10s ID:%6d    Score:%.2f\n", 
        list_ptr->surName, list_ptr->name, list_ptr->matricola, list_ptr->score);
}

int main(void) {
    Students list[NMAX];    //we can have arrays whose elements are type struct
    
    int n;
    printf("How many students (max %d)? ", NMAX); 
    if (scanf("%d", &n) != 1 || n<1 || n>NMAX) {
        fprintf(stderr, "Invalid number of students.\n");
        return EXIT_FAILURE;
    } 

    // Read students from stdin
    for (int i=0; i<n; i++) {
        printf("Student %d: \n", i+1); 
        list[i] = readStudent();        //call the funct and store the values in list[i]
    }


    // Sort by score (ascending) 
    sortStudents(list, n);  // Pass by reference


    // Print sorted list 
    printf("\nStudents sorted by their score: \n"); 
    for(int i=0; i<n; i++) {
        printStudents(&list[i]);    //pass by reference of a specific element (list[i])
    }

    return 0;
}