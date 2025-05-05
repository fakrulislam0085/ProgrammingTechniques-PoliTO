#include <stdio.h>
#include <math.h>

int cubeVolume(int sidelength) {
    int volume = pow(sidelength, 3);
    return volume;
}
int main(void) {
    int result;
    result = cubeVolume(2);

    printf("A cube with side length 2 has volume %d\n", result);

    return 0;
}