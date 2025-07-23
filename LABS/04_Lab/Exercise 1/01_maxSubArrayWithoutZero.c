#include <stdio.h> 
#include <string.h> 

void subSequences(int v[], int n) {
    int mx_length = 0;      //to track the max length of the sub-array formed by contiguous elements, containing non-zero values.
    int r = 0;      //to track the right or the beginning part of the sub-array
    for(int i=0; i<n; i++) {
        if(v[i] != 0) {
            r++;
        } 
        else {
            if (mx_length < r) {
                mx_length = r;
            }
            r = 0;
        }
    }

    printf("Max length: %d\n", mx_length);      //here, we know the max_size of our sub-array

    //print all the non-zero sub-vectors of max size
    int tmpArr[mx_length];      //we declared a tmp array of mx_size to hold all of the values of our sub-array
    int cnt = 0;    //to track again the length of a sub-array by contiguous elements, containing non-zero values.
    int k = 0;  //the index of our tmpArray

    for(int i=0; i<n; i++) {
        if (v[i] != 0) {
            cnt++;
            tmpArr[k++] = v[i];

            if (cnt == mx_length) {
                for(int j=0; j<mx_length; j++) 
                    printf("%d ",tmpArr[j]);
                cnt = 0;
                k = 0;
            }
        }
        else {
            cnt = 0;
            k = 0;
        }
    }

    return;
}

int main(void) {
    int n; 
    printf("Give me the LENGTH of array(max 30): ");
    scanf("%d", &n); 

    int v[n]; 
    printf("Give me the array: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    subSequences(v, n);

 
    return 0;
}