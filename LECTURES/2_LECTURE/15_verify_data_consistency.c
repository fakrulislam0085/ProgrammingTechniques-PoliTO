#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int verifyTemperature(FILE *read_file) {
    float t0, t1, t2; 
    
    //Try reading the first two values 
    if (fscanf(read_file, "%f", &t0) != 1) 
        return 1;   // Empty file is considered compliant 
    if (fscanf(read_file, "%f", &t1) != 1) 
        return 1;   // Only one value(t0 could be read) - no interval to check, still compliant 

    // Check first 10-minutes interval 
    if (fabs(t1 - t0) > 5.0) 
        return 0;   // If first two values do not comply, early exit 
    
        
    while (fscanf(read_file, "%f", &t2) == 1) {
        if (fabs(t2-t0) > 5.0 || fabs(t2-t1) > 5.0)
            return 0;
        
        //Slide the window: t0 <- t1,   t1 <- t2
        t0 = t1; 
        t1 = t2;
    }

    return 1;

}
int main(void) {
    FILE *fp_input; 
    char file_name[51];     //suppose, the char's in the file name <51 char    


    //1. Ask the user for the file name and check the Input validity 
    printf("Enter the file name: ");        //temperatures.txt
    if (scanf("%50s", file_name) != 1) {
        fprintf(stderr, "Failed to read the file name.\n");
        return EXIT_FAILURE;
    }


    //2. open the file
    if ((fp_input = fopen(file_name, "r")) == NULL) {
        perror("Error opening file");   // prints “Error opening file: <system‐error>”
        return EXIT_FAILURE;
    }


    //3. Verify temperature consistency
    int result = verifyTemperature(fp_input); 
    fclose(fp_input);   //close the file


    //4. Print the result 
    if (result) 
        printf("Temperatures are consistent (Variation <= 5 deg C per 10-mins.\n)");
    else 
        printf("Temperature variation exceeded 5 deg C in a 10-mins interval.\n");

    return EXIT_SUCCESS;
}