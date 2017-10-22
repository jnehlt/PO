#include <stdio.h>
#include <stdlib.h>

#include "val.h"
#include "det.h"

int main(const int argc, const char** argv)
{
    int deg = 0, i = 0, numOfOperations;
    float** inputMatrix = validateInputData(&deg, argc, argv);
    double det = 0;
    if(!(numOfOperations = quickCheckOfDet(inputMatrix, deg)))
    {
        printf("Wyznacznik = %lf\n", det);
        while(i < deg)
            free(*(inputMatrix + i++));
        free(inputMatrix);
    }
    printMatrix(inputMatrix, deg);

    det = LUdecomposition(inputMatrix, deg);
    det = (numOfOperations % 2) ? -det : det;
    printf("Wyznacznik wczytanej macierzy = %lf\n\n", det);

    return 0;
}
