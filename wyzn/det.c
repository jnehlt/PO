#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "det.h"
#include "val.h"

void printMatrix(float** matrix, int degree)
{
    int i = 0, j;
    printf("\n\n");
    for(; i < degree; ++i)
    {
        for(j = 0; j < degree; ++j)
            printf("%f ", matrix[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

int quickCheckOfDet(float** matrix, int degree)
{
    float sumR = 0, sumC = 0;
    int i = 0, j, numOfOperations = 2;
    for(; i < degree; ++i)
    {
        for(j = 0; j < degree; ++j)
        {
            sumR += matrix[i][j];
            sumC += matrix[j][i];
        }
        if(sumR == 0 || sumC == 0)
            return 0;
        sumR = sumC = 0;
    }
    for(j = 0; j < degree; ++j)
    {
        if(!matrix[j][j])
            numOfOperations = optimizeMatrix(matrix, j, degree);
    }
    return numOfOperations;
}

int optimizeMatrix(float** matrix, int j, int degree)
{   //switch rows
    int i = 0, numOfOperations = 0;
    for(; i < degree; ++i)
    {   //search non-zero diagonal...
        if(matrix[i][j] && matrix[j][i])
        {   //...and swap
            float* temp = NULL;
            temp = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = temp;
            ++numOfOperations;
        }
    }
    return numOfOperations;
}

float LUdecomposition(float** matrix, int degree)
{
    int LUi = 0, i, j, k;
    float** LU;
    float det = 0;
    if((LU = (float**)malloc(sizeof(float*) * degree)) == NULL) 
        err(NULL, NULL, matrix, LU, &degree, NULL, 7);
    for(; LUi < degree; ++LUi)
    {
        if((LU[LUi] = (float*)malloc(sizeof(float) * degree)) == NULL)
            err(NULL, NULL, matrix, LU, &degree, &LUi, 6);
        memset(LU[LUi], 0, degree);
    }

    for(i = 0; i < degree; ++i)
    {
        for(j = 0; j < degree; ++j)
        {
            if(i < j)
                LU[j][i] = 0;
            else
            {
                LU[j][i] = matrix[j][i];
                for(k = 0; k < i; ++k)
                    LU[j][i] = LU[j][i] - LU[j][k] * LU[k][i];
            }
        }
        for(j = 0; j < degree; ++j)
        {
            if(j < i)
                LU[i][j] = 0;
            else if(i == j)
                LU[i][j] *= 1;
            else
            {
                LU[i][j] = matrix[i][j] / LU[i][i];
                for(k = 0; k < i; ++k)
                    LU[i][j] = LU[i][j] - ((LU[i][k] * LU[k][j]) / LU[i][i]);
            }
        }
    }
    det = 1;
    for(i = 0; i < degree; ++i)
        det *= LU[i][i];
    i = 0;

    while(--LUi > -1)
        free(*(LU + LUi));
    free(LU);
    while(i < degree)
        free(*(matrix + i++));
    free(matrix);

    return det;
}
