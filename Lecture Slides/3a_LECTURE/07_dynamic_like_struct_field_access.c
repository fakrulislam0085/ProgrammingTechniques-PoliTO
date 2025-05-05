#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define MAXL 100 

//define the struct 
typedef struct Students {
    char name[MAXL], surName[MAXL]; 
    int matricola; 
    float gpa; 
} Students; 


// Function to print a specific field based on the given string 
void printField(struct Students s1, char id[]) {
    if (strcmp(id, "name") == 0) 
        printf("Name: %s\n", s1.name);
    else if (strcmp(id, "surName") == 0) 
        printf("SurName: %s\n", s1.surName); 
    else if (strcmp(id, "matricola") == 0) 
        printf("Matricola: %d\n", s1.matricola); 
    else if (strcmp(id, "gpa") == 0) 
        printf("GPA: %0.2f\n", s1.gpa);
    else 
        printf("Invalid filed Name: %s\n", id); 
}

int main(void) {

    Students s1; 

    // Assign values to the struct fields 
    strcpy(s1.name, "Arif"); 
    strcpy(s1.surName, "Islam"); 
    s1.matricola = 339696; 
    s1.gpa = 3.95; 

    //Test the printField function 
    printField(s1, "name");
    printField(s1, "surName"); 
    printField(s1, "matricola"); 
    printField(s1, "gpa"); 
    printField(s1, "birthday");     // Invalid field, to test the else case


    return EXIT_SUCCESS;    
}