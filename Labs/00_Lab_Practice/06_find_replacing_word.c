#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void replaceWordInLine(char *line, const char *oldWord, const char *newWord, char *result) {
    char *pos, temp[MAX_LINE_LENGTH];
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);
    int index = 0;

    result[0] = '\0'; // Clear result buffer

    while ((pos = strstr(line, oldWord)) != NULL) {
        // Copy part before the word
        strncpy(temp, line, pos - line);
        temp[pos - line] = '\0';

        // Add new word
        strcat(temp, newWord);

        // Add the rest of the line
        strcat(temp, pos + oldWordLen);

        strcpy(line, temp);  // Update line for further replacement
    }

    strcpy(result, line);
}

int main() {
    FILE *fp_read, *fp_write;
    char line[MAX_LINE_LENGTH], modifiedLine[MAX_LINE_LENGTH];
    char oldWord[50], newWord[50];

    // Get user input for word replacement
    printf("Enter word to find: ");
    scanf("%s", oldWord);
    printf("Enter word to replace with: ");
    scanf("%s", newWord);

    // Open files
    fp_read = fopen("findword.txt", "r");
    if (fp_read == NULL) {
        printf("Error: Could not open input.txt for reading.\n");
        return 1;
    }

    fp_write = fopen("replaceWord.txt", "w");
    if (fp_write == NULL) {
        printf("Error: Could not open output.txt for writing.\n");
        fclose(fp_read);
        return 2;
    }

    // Process file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp_read) != NULL) {
        replaceWordInLine(line, oldWord, newWord, modifiedLine);
        fputs(modifiedLine, fp_write);
    }

    // Close files
    fclose(fp_read);
    fclose(fp_write);

    printf("Word replacement complete. Check output.txt\n");

    return 0;
}
