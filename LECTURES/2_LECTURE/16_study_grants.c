#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
int main(void) {
    char inputFileName[51], outputFileName[51];  //students.txt, selected.txt
    FILE *fp_inFile, *fp_outFile;   //creating file pointer

    char matricola[20], surname[30], name[30];
    char line[100], next_line[100]; //to track the lines
    int ne, nmin;   //ne = number of exams,  nmin = minimum exams counter
    float current_score, avg_score, mmin;     //mmin = minimum average


    //1. Ask the user for the input+output file and check the input validity 
    printf("Enter the file name: ");    
    if (scanf("%50s", inputFileName) != 1) {
        fprintf(stderr, "The file is not found!\n"); 
        return EXIT_FAILURE;
    }

    printf("Enter the output file: ");      
    if(scanf("%50s", outputFileName) != 1) {
        fprintf(stderr, "Invalid output filename.\n");
        return EXIT_FAILURE;
    }; 

    printf("Enter the minimum number of exams(nmin): ");
    scanf("%d", &nmin); 
    printf("Enter the minimum average score(mmin): "); 
    scanf("%f", &mmin); 


    //2. open the files
    if ((fp_inFile = fopen(inputFileName, "r")) == NULL) {
        perror("Error opening the file");   // + <system-error> 
        return EXIT_FAILURE;
    }
    if ((fp_outFile = fopen(outputFileName, "w")) == NULL) {
        perror("Error opening the file");   // " + : <system-error"
        fclose(fp_inFile);
        return EXIT_FAILURE;
    }

    
    //3. Read and analyze students records
    while ((fgets(line, sizeof(line), fp_inFile)) != NULL) {
        if (line[0] != '#') continue;   // skip this line until we found a new student record; '#' this is the indicator of new student record

        sscanf(line+1, "%s", matricola);    // skip '#' and get matricola 

        if (fgets(line, sizeof(line), fp_inFile) == NULL)   break;
        sscanf(line, "%s %s", surname, name); 

        float total_sum = 0.0f;    //to calculate the total sum
        avg_score = 0.0f;
        ne = 0;

        //now read the scores 
        while (fgets(next_line, sizeof(next_line), fp_inFile) != NULL) {
            if (sscanf(next_line, "%f", &current_score) == 1) {     //check if the line contains a valid float
                total_sum += current_score;
                ne += 1;
            } else {
                break;  //stop reading scores if the line is not numeric
            }
            
        }

        //find the average and check the conditions
        avg_score = total_sum / ne ;

        if (avg_score >= mmin && ne >= nmin) {
            fprintf(fp_outFile, "%s %s %s\n", name, surname, matricola);
        }

    }

    printf("File processed successfully!\n");

    //closing the files 
    fclose(fp_inFile); 
    fclose(fp_outFile);
 
    return EXIT_SUCCESS;
}