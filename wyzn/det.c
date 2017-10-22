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
            numOfOperations += optimizeMatrix(matrix, &j, degree);
    }
    return numOfOperations;
}

int optimizeMatrix(float** matrix, int* j, int degree)
{   //switch rows
    int i = 0, numOfOperations = 0;
    for(; i < degree; ++i)
    {   //search non-zero diagonal...
        if(matrix[i][*j] && matrix[*j][i])
        {   //...and swap
            float* temp = NULL;
            temp = matrix[i];
            matrix[i] = matrix[*j];
            matrix[*j] = temp;
            ++numOfOperations;
            --*j;
            break;
        }
    }
    return numOfOperations;
}

double LUdecomposition(float** matrix, int degree)
{
    int Li = 0, Ui = 0, i, j, k;
    float** L, **U;
    double det = 0;
    if((L = (float**)malloc(sizeof(float*) * degree)) == NULL) 
        err(NULL, NULL, matrix, L, &degree, NULL, 7);
    for(; Li < degree; ++Li)
    {
        if((L[Li] = (float*)malloc(sizeof(float) * degree)) == NULL)
            err(NULL, NULL, matrix, L, &degree, &Li, 6);
        memset(L[Li], 0, degree);
    }

    if((U = (float**)malloc(sizeof(float*) * degree)) == NULL) 
        err(NULL, NULL, matrix, U, &degree, NULL, 7);
    for(; Ui < degree; ++Ui)
    {
        if((U[Ui] = (float*)malloc(sizeof(float) * degree)) == NULL)
            err(NULL, NULL, matrix, U, &degree, &Ui, 6);
        memset(U[Ui], 0, degree);
    }

    for(i = 0; i < degree; ++i)
    {
        for(j = 0; j < degree; ++j)
        {
            if(j >= i)
            {
                L[j][i] = matrix[j][i];
                for(k = 0; k < i; ++k)
                    L[j][i] = L[j][i] - L[j][k] * U[k][i];
            }
        }
        for(j = 0; j < degree; ++j)
        {
            if(j > i)
            {
                U[i][j] = matrix[i][j] / L[i][i];
                for(k = 0; k < i; ++k)
                    U[i][j] = U[i][j] - ((L[i][k] * U[k][j]) / L[i][i]);
            }
            else if(i == j)
                U[i][j] = 1;
        }
    }

    det = 1;
    for(i = 0; i < degree; ++i)
        det *= L[i][i];
    i = 0;

    while(--Li > -1)
        free(*(L + Li));
    free(L);
    while(--Ui > -1)
        free(*(U + Ui));
    free(U);
    while(i < degree)
        free(*(matrix + i++));
    free(matrix);

    return det;
}
