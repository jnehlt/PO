#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "val.h"

float** validateInputData(int* degree, const int argc, const char** argv)
{
    const int bufferSize = 20;
    float** inputMatrix = NULL;

    if(argc != 2)
        err(NULL, NULL, NULL, NULL, NULL, NULL, -2);

    FILE* inputData = fopen(argv[1], "r");

    if(inputData == NULL)
        err(NULL, NULL, NULL, NULL, NULL, NULL, -1);

    {
        int i = 0;
        char* buffer = (char*)malloc(bufferSize);
        memset(buffer, 0, bufferSize); //zastąp zerem na początku

        if(fgets(buffer, bufferSize, inputData) == NULL)
            err(inputData, buffer, NULL, NULL, NULL, NULL, 0);
        if(checkFirstLineOfInputMatrix(buffer))
            err(inputData, buffer, NULL, NULL, NULL, NULL, 1);
        if((inputMatrix = (float**)malloc(sizeof(float*)*(*degree = atoi(buffer)))) == NULL)
            err(inputData, buffer, NULL, NULL, NULL, NULL, 2);
        free(buffer);

        while(1)
        {
            int _val = 0;
            if(i >= *degree)
                err(inputData, NULL, inputMatrix, NULL, &i, NULL, 3);
            if((*(inputMatrix + i++) = (float*)malloc(sizeof(float)*(*degree))) == NULL)
                err(inputData, NULL, inputMatrix, NULL, &i, NULL, 4);
            if((_val = val(inputMatrix[i-1], *degree, inputData)))
            {
                if(_val == 13)
                {
                    if(i < *degree)
                        err(inputData, NULL, inputMatrix, NULL, &i, NULL, 3);
                    break;
                }
                err(inputData, NULL, inputMatrix, NULL, &i, NULL, 5);
            }
        }
        fclose(inputData);
        return inputMatrix;
    }
}

int checkFirstLineOfInputMatrix(char* buffer)
{
    const int sizeOfBuffer = strlen(buffer);
    int i = 0;

    if(isdigit(*(buffer + i)))
    {
        while(i < sizeOfBuffer && isdigit(*(buffer + i)))
            ++i;
        if(*(buffer + i) != 0x0A || *buffer == '0') // LF or incorrect number
            return 1;
        return 0;
    }
    return 1;
}

int val(float* matrix, int degree, FILE* inputData)
{
    fpos_t guard;
    int i = 0;
    memset(matrix, 0, degree);
    fgetpos(inputData, &guard); //stage 1
    if((i = fly(inputData)) != degree)
    {
        if(-i == degree)
        {
            fsetpos(inputData, &guard); //stage 2.2
            if(fillMatrix(matrix, degree, inputData))
                return -1;
            return 13;  //koniec pliku
        }
        return -2;
    }
    fsetpos(inputData, &guard); //stage 2.1
    fillMatrix(matrix, degree, inputData);
    return 0;
}

int fly(FILE* inputData)
{
    int i = 0, redundant = 0;
    char c;
    while(1)
    {
            c = fgetc(inputData);
        if(isdigit(c))
        {
            while(isdigit(c = fgetc(inputData)) || c == '.')
            {
                if(c == '.' || c == '-')
                    redundant = 1;
                else
                    redundant = 0;
            }
            if(redundant)
                return -1;
            ++i;
        }
        if(c == '-')
            continue;
        if(c == 0x0A)
            return i;
        if(c == EOF)
            return -i;
        if(isspace(c))
            continue;
        else
            return -1;
    }
}

int fillMatrix(float* matrix, int degree, FILE* inputData)
{
    int i = 0;
    for(; i < degree; ++i)
    {
        char c;
        if(fscanf(inputData, "%f", (matrix + i)) != 1)
            return -1;
        while(isdigit(c = fgetc(inputData)) || c == '-' || c == '.')
        while((c = fgetc(inputData)) && c != 0x0A);
    }
    return 0;
}

void err(FILE* file, char* buffer, float** matrix, float** LU, int* deg, int* i, int flag)
{
    switch(flag)
    {
        case -2:
            printf("Wrong number of arguments\nFinishing...\n\n");
            abort();
            break;
        case -1:
            printf("Function fopen() caused problem\nCheck is file exists.\nFinishing...\n\n");
            abort();
            break;
        case 0:
            perror("ERROR WHILE READING FILE\nFile is empty or corrupted\nAborting...\n\n");
            free(buffer);
            fclose(file);
            abort();
            break;
        case 1:
            perror("Input data error\nAborting...\n\n");
            printf("rolling back...\n\n");
            free(buffer);
            fclose(file);
            abort();
            break;
        case 2:
            perror("Memory error\nAborting...\n\n");
            free(buffer);
            fclose(file);
            abort();
            break;
        case 3:
            perror("Input Data error\nAborting...\n\n");
            while(--*deg > -1)
                free(*(matrix + *deg));
            free(matrix);
            fclose(file);
            abort();
            break;
        case 4:
            perror("Memory error\nAborting...\n\n");
            while(--*deg > -1)
                free(*(matrix + *deg));
            free(matrix);
            fclose(file);
            abort();
            break;
        case 5:
            perror("Input Data error\nAborting...\n\n");
            while(--*deg > -1)
                free(*(matrix + *deg));
            free(matrix);
            fclose(file);
            abort();
            break;
        case 6:
            perror("Allocation error\nAborting...\n\n");
            while(--*i > -1)
                free(*(LU + *i));
            free(LU);
        case 7:
            while(--*deg > -1)
                free(*(matrix + *deg));
            free(matrix);
            abort();
            break;
        default:
            printf("UNKNOWN ERROR\n");
            abort();
            break;
    }
}
