#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <ctype.h> 
#include <math.h> 

const int MAXL = 1000 ;

typedef enum {
    c_date,     // 0
    c_departure,    // 1
    c_destination,  // 2
    c_delay,    //3
    c_tot_delay,    //4
    c_end       //5
} t_commands; 

typedef struct {
    char route[31]; 
    char departure[31]; 
    char destination[31]; 
    int yyyy, mm, dd; 
    int dep_h, dep_m, dep_s;    
    int arr_h, arr_m, arr_s; 
    int delay; 
} trip; 

void strToLower(char* cmd) {
    for(int i=0; i<strlen(cmd); i++) {
        cmd[i] = tolower(cmd[i]); 
    }
}

t_commands readCommand(void) {
    // make a cmd_table so we can compare the commands with enum{...} t_command; 
    char cmd_table[6][12] = {"date", "departure", "destination", "delay", "tot_delay", "end"}; 

    char cmd[12];     // to hold the command 
    printf("\n\nCommand (Date/Departure/Destination/Delay/Tot-delay/End): "); 
    scanf("%11s", cmd); 
    getchar();      // Consume the leftover space character in the input buffer from scanf() 

    //make the command lowercase letters 
    strToLower(cmd); 

    t_commands A = c_date;   // initialize a t_command A with the first command from enum t_command
    /* c_date = 0, so A = 0*/

    while(A<c_end && strcmp(cmd, cmd_table[A]) != 0) 
        A++; 
    
    return (A); 
}

void menuWord(trip *log, int n) {
    t_commands command;  // to hold the command 
    char line[100];    // to hold the rest of the line // suppose, we will have max 100 char 
    bool toContinue = true; 

    while (toContinue) {
        command = readCommand();

        fgets(line, MAXL, stdin);   /* rest of the command line*/ 
        //printf("\nline: %s", line); 

        //remove leading spaces if there is any 
        char *arg = line; 
        while(*arg == ' ' || *arg == '\t') 
            arg++; 
        arg[strcspn(arg, "\n")] = '\0';  // strip newline if there is any   

        //*Check
        // printf("command: %d\n", command); 
        // printf("arg: %s\n",arg);

        switch(command) {
            case c_date: {
                // printf("We will work on this now.\n"); 
                // printf("date is: %s", line); 
                printf("\n1. List of all rides departed within a certain interval of dates: \n");
                printf("Dates: %s\n", arg); 
                printf("---------------------------------------\n"); 

                int y1,m1,d1,y2,m2,d2; 
                if (sscanf(arg, "%4d/%2d/%2d %4d/%2d/%2d", &y1, &m1, &d1, &y2, &m2, &d2) != 6) {
                    printf("Invalid input fomat.\n"); 
                    continue;
                }

                for(int i=0; i<n; i++) {
                    if(log[i].yyyy >= y1 && log[i].yyyy <= y2) {
                        if(log[i].mm >= m1 && log[i].mm <= m2) {
                            if(log[i].dd >= d1 && log[i].dd <= d2) {
                                printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", log[i].route, log[i].departure, log[i].destination,
                                    log[i].yyyy, log[i].mm, log[i].dd,log[i].dep_h, log[i].dep_m, log[i].dep_s, log[i].arr_h, log[i].arr_m, log[i].arr_s, 
                                    log[i].delay);
                            }
                        }
                    }
                }

                break;
            }
            case c_departure: 
                printf("\n2. List of all the trips starting from a given departure: %s\n", arg);
                printf("--------------------------------------------\n");

                for(int i=0; i<n; i++) {
                    if(strcmp(log[i].departure, arg) == 0) {
                        printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", log[i].route, log[i].departure, log[i].destination, 
                            log[i].yyyy, log[i].mm, log[i].dd, log[i].dep_h, log[i].dep_m, log[i].dep_s, log[i].arr_h, log[i].arr_m, log[i].arr_s, 
                            log[i].delay);
                    }
                }
                break;

            case c_destination: 
                printf("\n3. List of all the trips with a given destination: %s\n", arg);
                printf("------------------------------------------------\n");

                for(int i=0; i<n; i++) {
                    if(strcmp(log[i].destination, arg) == 0) {
                        printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", log[i].route, log[i].departure, log[i].destination, 
                            log[i].yyyy, log[i].mm, log[i].dd, log[i].dep_h, log[i].dep_m, log[i].dep_s, log[i].arr_h, log[i].arr_m, log[i].arr_s, 
                            log[i].delay);
                    }
                }
                break; 

            case c_delay: {
                printf("\n4. List of all the trips that reaches their destination late within a certain interval of dates: \n");
                printf("Dates: %s\n", arg); 
                printf("----------------------------------------------\n");

                int y1,m1,d1,y2,m2,d2; 
                if (sscanf(arg, "%4d/%2d/%2d %4d/%2d/%2d", &y1, &m1, &d1, &y2, &m2, &d2) != 6) {
                    printf("Invalid input fomat.\n"); 
                    continue;
                }

                for(int i=0; i<n; i++) {
                    if(log[i].yyyy >= y1 && log[i].yyyy <= y2) {
                        if(log[i].mm >= m1 && log[i].mm <= m2) {
                            if(log[i].dd >= d1 && log[i].dd <= d2) {
                                if(log[i].delay > 0) {
                                    printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", log[i].route, log[i].departure, log[i].destination,
                                        log[i].yyyy, log[i].mm, log[i].dd,log[i].dep_h, log[i].dep_m, log[i].dep_s, log[i].arr_h, log[i].arr_m, log[i].arr_s, 
                                        log[i].delay);
                                }
                            }
                        }
                    }
                }

                break;
            }

            case c_tot_delay: {
                printf("\n5. Total accumulated delay for the route %s: ", arg); 
                printf("---------------------------------------\n");

                int totalDelay = 0; 
                for(int i=0; i<n; i++) {
                    if(strcmp(log[i].route, arg) == 0) {
                        totalDelay += log[i].delay;
                    }
                }
                if (totalDelay == 0) printf("Route does not found or no delays recorded.\n");
                else    printf("%d minutes.\n", totalDelay);

                break;
            }                

            case c_end: 
                printf("\n6. Exiting the program.\n"); 
                toContinue = false; 
                break;

            default: 
                printf("Wrong Command.\n"); 
        }
    }
} 

int main(void) {
    //1. Read the file 
    char fileName[20] = "log.txt"; 
    FILE *fp_input = fopen(fileName, "r"); 
    
    if(! fp_input) {
        fprintf(stderr, "Error: Couldn't open the '%s' file.\n", fileName); 
        return EXIT_FAILURE; 
    }

    //2. Extract the file contents in a vector whose elements will be out custom data type trip
    int total_line; 
    fscanf(fp_input, "%d", &total_line); 

    trip tripsData[MAXL];
    for(int i=0; i<total_line; i++) {
        fscanf(fp_input, "%30s %30s %30s", tripsData[i].route, tripsData[i].departure, tripsData[i].destination); 
        fscanf(fp_input, "%4d/%2d/%2d", &tripsData[i].yyyy, &tripsData[i].mm, &tripsData[i].dd); 
        fscanf(fp_input, "%2d:%2d:%2d", &tripsData[i].dep_h, &tripsData[i].dep_m, &tripsData[i].dep_s); 
        fscanf(fp_input, "%2d:%2d:%2d", &tripsData[i].arr_h, &tripsData[i].arr_m, &tripsData[i].arr_s);
        fscanf(fp_input, "%d", &tripsData[i].delay); 
    }

    // Test your code 
    // for(int i=0; i<total_line; i++) {
    //     printf("%s %s %d\n", data[i].route, data[i].departure, data[i].delay);
    // }    // working fine 


    //3. Call the function 
    menuWord(tripsData, total_line); 


    //4. Closed the file 
    fclose(fp_input); 

    return 0;
}