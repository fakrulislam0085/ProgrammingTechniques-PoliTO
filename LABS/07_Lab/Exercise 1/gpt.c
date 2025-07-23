#include <stdio.h>
#include <stdlib.h>

#define MAXR 50
#define MAXC 50

typedef struct {
    int x, y;   // top-left corner (0-based)
    int h, w;   // height, width
    int A;      // area
} Matrix;

// Our global matrix
int mat[MAXR][MAXC];

// Trackers—initialize all fields to -1
Matrix maxHeight = { -1, -1, -1, -1, -1 };
Matrix maxWidth  = { -1, -1, -1, -1, -1 };
Matrix maxArea   = { -1, -1, -1, -1, -1 };

// Update our three “bests”
void storeData(int i, int j, int height, int width) {
    int area = height * width;

    if (height > maxHeight.h) {
        maxHeight = (Matrix){ i, j, height, width, area };
    }
    if (width > maxWidth.w) {
        maxWidth = (Matrix){ i, j, height, width, area };
    }
    if (area > maxArea.A) {
        maxArea = (Matrix){ i, j, height, width, area };
    }
}

// Scan for all black rectangles
void detectBlackRegion(int nr, int nc) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            // We only start a new rectangle when:
            // mat[i][j]==1  AND  both above and left are 0 or out of bounds
            if (mat[i][j] == 1
                && (i == 0 || mat[i-1][j] == 0)
                && (j == 0 || mat[i][j-1] == 0))
            {
                // 1) measure width
                int width = 0;
                while (j + width < nc && mat[i][j + width] == 1) {
                    width++;
                }

                // 2) measure height (only as long as the full width remains black)
                int height = 0;
                while (i + height < nr) {
                    int k;
                    for (k = 0; k < width; k++) {
                        if (mat[i + height][j + k] != 1)
                            break;
                    }
                    if (k < width) break;
                    height++;
                }

                // 3) record if it's a new best
                storeData(i, j, height, width);

                // 4) “erase” the rectangle so we don’t count it again
                for (int di = 0; di < height; di++) {
                    for (int dj = 0; dj < width; dj++) {
                        mat[i + di][j + dj] = 0;
                    }
                }
            }
        }
    }
}

// Print our three results
void printData(void) {
    printf("Max-height region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           maxHeight.x, maxHeight.y,
           maxHeight.h, maxHeight.w, maxHeight.A);

    printf("Max-width region:  upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           maxWidth.x,  maxWidth.y,
           maxWidth.h,  maxWidth.w,  maxWidth.A);

    printf("Max-area region:   upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           maxArea.x,   maxArea.y,
           maxArea.h,   maxArea.w,   maxArea.A);
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("input.txt");
        return EXIT_FAILURE;
    }

    int nr, nc;
    fscanf(fp, "%d %d", &nr, &nc);
    for (int i = 0; i < nr; i++)
        for (int j = 0; j < nc; j++)
            fscanf(fp, "%d", &mat[i][j]);
    fclose(fp);

    detectBlackRegion(nr, nc);
    printData();
    return 0;
}
