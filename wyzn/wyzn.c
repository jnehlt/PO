#include <stdio.h>
#include <stdlib.h>

#include "val.h"
#include "det.h"

int main(const int argc, const char** argv)
{
    int deg = 0, i = 0;
    float** inputMatrix = validateInputData(&deg, argc, argv);
    float det = 0;
    if(quickCheckOfDet(inputMatrix, deg))
    {
        printf("Wyznacznik = %f\n", det);
        while(i < deg)
            free(*(inputMatrix + i++));
        free(inputMatrix);
    }
    printMatrix(inputMatrix, deg);

    det = LUdecomposition(inputMatrix, deg);
    printf("Wyznacznik wczytanej macierzy = %f\n\n", det);

    return 0;
}
