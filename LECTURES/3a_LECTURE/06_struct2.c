#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

//4. Synonym of "structStudent", with "typedef" (with struct identifier) 
struct Student {
    char firstName[50];
    int Age;
    float GPA;
};
typedef struct Student Student;

//or 
typedef struct Subjects {
    char course[50];
    char subject_name[50];
}   Subjects;

//5. Synonym of "structStudent", with "typedef" (without struct identifier) 
typedef struct {
    char course[50];
    int founded;
} University;

//In these way we can declare our variable without mentioning "struct" again and again


int main(void) {
    
    Student S1, S2;
    strcpy(S1.firstName, "Zahnbi"); 
    S1.Age = 22; 

    Subjects CS; 
    strcpy(CS.course, "073jki"); 
    strcpy(CS.subject_name, "Computer Science");

    University PoliTO; 
    strcpy(PoliTO.course, "Computer Engineering"); 
    PoliTO.founded = 1906;
    
    return 0;
}