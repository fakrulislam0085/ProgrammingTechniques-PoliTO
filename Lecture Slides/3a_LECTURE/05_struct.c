#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

// Struct definition
//1. Basic Scheme
struct Student {
    char name[50]; 
    char subject[50]; 
    int studentID; 
    int age;
    float Grade;
};

//2. Contextual declaration of the struct and variables together
// Define the struct and variables at the same time, so we don't need a separate declaration later.
struct Book {
    char title[100];
    int pages; 
    float price;
} b1, b2;


//3. Anonymous struct declaration (without identifier) 
// defining a struct without giving it any name, we can't declare more variables of this struct later 
struct 
{
    int x;
    int y;
} point1, point2;



int main(void) {
    
    //1. declare variable of "struct Student" data type
    struct Student Phoenix;     //data type= struct Student;   variable= Phoenix
    
    strcpy(Phoenix.name, "Phoenix"); 
    strcpy(Phoenix.subject, "Compute Engineering");
    Phoenix.studentID = 339696; 
    Phoenix.age = 21; 
    Phoenix.Grade = 3.95f; 

    printf("Student: %s\nSubject: %s\n", Phoenix.name,Phoenix.subject);
    printf("Matricola: %d\nAge: %d\nGrade: %.2f\n",Phoenix.studentID,Phoenix.age,Phoenix.Grade);

    

    /*2. In C, you cannot directly assign a string literal to a char array after it has been 
    declared. The title field in the struct Book is a char array, and you need to use strcpy 
    to copy the string into it.
        b1.title = "The Alchemist";     -> it is wrong
    */
    strcpy(b1.title, "The Alchemist");
    b1.pages = 423; 
    b1.price = 49; 

    strcpy(b2.title, "Atomic Habits");



    //3. 
    point1.x = 5, point1.y = 6; 
    int sum = point1.x + point1.y; 

    return 0;
}