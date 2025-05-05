#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

void selectPoints (FILE *fi, FILE *fo, int x_sign, int y_sign) {
    float x, y;     // to hold the x, y values from the file
    int xOK, yOK;

    while (fscanf(fi, "%f %f", &x, &y) == 2) {
        xOK = x*x_sign>0.0 || (x==0.0 && x_sign>0);
        yOK = y*y_sign>0.0 || (y==0.0 && y_sign>0);

        if (xOK && yOK)
            fprintf(fo, "%0.1f %0.1f\n", x, y);

        if (x>0 && y>0) {}
    }
}

void sortPoints (const char *nin, char nout[]) {
    FILE *fin, *fout;

    fin = fopen(nin, "r");
    if (fin == NULL) {
        perror("Error opening the file");
        return;
    }

    fout = fopen(nout, "w");
    if (fout == NULL) {
        perror("Error opening the output file");
        fclose(fin);
        return;
    }

    //calling the selectPoints function for 4 times
    selectPoints(fin,fout,1,1);     //1st coordinate
    rewind(fin);        //reset file pointer

    selectPoints(fin,fout,-1,1);    //2nd coordinate
    rewind(fin);        //reset file pointer

    selectPoints(fin,fout,-1,-1);   //3rd coordinate
    rewind(fin);        //reset file pointer

    selectPoints(fin,fout,1,-1);    //4th coordinate
    rewind(fin);        //reset file pointer


    //closing the files
    fclose(fin);
    fclose(fout);
}

int main(void) {
    char input_fileName[100], output_fileName[100];   //points_input.txt,   sorted_points.txt

    printf("Enter input file name: ");
    scanf("%s", input_fileName);

    printf("Enter output file name: ");
    scanf("%s", output_fileName);

    //sortPointsByQuadrant(input_fileName, output_fileName);
    sortPoints(input_fileName, output_fileName);

    printf("Sorting is completed.\n");

    return EXIT_SUCCESS;
}