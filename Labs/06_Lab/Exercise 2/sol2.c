#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQ        20
#define MAX_SEQ_WORD    5
#define MAX_LINE      200
#define MAX_WORD       25

typedef struct {
    char seqWord[MAX_SEQ_WORD];
} Sequence;

// lowercase in place
void toLowerStr(char *s) {
    for (size_t i = 0; s[i]; i++)
        s[i] = tolower((unsigned char)s[i]);
}

// print all positions for one seqWord in the text
void processSequence(FILE *in, const char *seqWord, FILE *out) {
    char line[MAX_LINE];
    int  wordCount = 0;
    int  foundAny = 0;

    rewind(in);

    while (fgets(line, sizeof(line), in)) {
        char lowered[MAX_WORD] = {0};
        char original[MAX_WORD] = {0};
        int  wi = 0;

        for (int i = 0; line[i]; i++) {
            if (!isspace((unsigned char)line[i]) &&
                !ispunct((unsigned char)line[i]))
            {
                // accumulate both original and lowered
                original[wi] = line[i];
                lowered [wi] = tolower((unsigned char)line[i]);
                wi++;
            }
            else if (wi > 0) {
                original[wi] = lowered[wi] = '\0';
                wordCount++;

                // does lowered contain seqWord?
                if (strstr(lowered, seqWord)) {
                    if (!foundAny) {
                        // header once
                        fprintf(out, "Sequence '%s' is found in:\n", seqWord);
                        foundAny = 1;
                    }
                    // print with "> " prefix
                    fprintf(out, "> %s (Position %d)\n", original, wordCount);
                }
                wi = 0;
            }
        }
        // handle trailing word
        if (wi > 0) {
            original[wi] = lowered[wi] = '\0';
            wordCount++;
            if (strstr(lowered, seqWord)) {
                if (!foundAny) {
                    fprintf(out, "Sequence '%s' is found in:\n", seqWord);
                    foundAny = 1;
                }
                fprintf(out, "> %s (Position %d)\n", original, wordCount);
            }
        }
    }

    // if you want a trailing period on the last line instead of newline:
    // you could rewrite the last '\n' to ".\n", but this simple version leaves a newline.
    if (foundAny) {
        // replace last '\n' with ".\n"
        fseek(out, -2, SEEK_CUR);   // go back before the final "\n"
        fprintf(out, ".\n\n");      // close with a period and blank line
    }
}

int main(void) {
    FILE *fText = fopen("text.txt",      "r");
    FILE *fSeq  = fopen("sequence.txt",  "r");
    FILE *fOut  = fopen("output.txt",    "w");
    if (!fText || !fSeq || !fOut) {
        perror("File open error");
        return EXIT_FAILURE;
    }

    Sequence seqArr[MAX_SEQ];
    int      nSeq;
    if (fscanf(fSeq, "%d", &nSeq) != 1 || nSeq > MAX_SEQ) {
        fprintf(stderr, "Invalid sequence count\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < nSeq; i++) {
        fscanf(fSeq, "%4s", seqArr[i].seqWord);
        toLowerStr(seqArr[i].seqWord);
    }

    for (int i = 0; i < nSeq; i++) {
        processSequence(fText, seqArr[i].seqWord, fOut);
    }

    fclose(fText);
    fclose(fSeq);
    fclose(fOut);

    printf("File processed successfully. See output.txt\n");
    return EXIT_SUCCESS;
}
