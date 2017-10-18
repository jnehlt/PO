#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void validateInputData(double**, const int, const char**);
int checkAndOptimizeBuffer(char* buffer);

int main(const int argc, const char** argv)
{
    double det = -1;
    double* matrix;

    validateInputData(&matrix, argc, argv);    
 
    return 0;
}

void validateInputData(double** matrix, const int argc, const char** argv)
{
    int degree = 0;
    const int bufferSize = rand() % 289 + rand() % 13 + 1;

    srand(time(NULL));

    if(argc != 2)
    {   //InputError
        printf("Wrong number of arguments\nFinishing...\n\n");
        abort();
    }

    FILE* inputData = fopen(argv[1], "r");
    if(inputData == NULL)
    {   //fopen error
        printf("Function fopen() caused problem\nCheck is file %s exists.\nFinishing...\n\n", argv[1]);
        abort();
    }

    {
        char buffer[bufferSize];
        memset(buffer, 0, bufferSize);
        if(fgets(buffer, bufferSize, inputData) == NULL)
        {   //file error
            perror("ERROR WHILE READING FILE\nFile is empty or corrupted\nAborting...\n\n");
            abort();
        }

        if(checkAndOptimizeBuffer(buffer))
        {
            printf("rolling back...\n\n");
            //free(matrix) /new matrix itd
            abort();
        }
        degree = atoi(buffer);
        printf("degree = %d\n", degree);
    }
    fclose(inputData);
}

int checkAndOptimizeBuffer(char* buffer)
{
    const int sizeOfNewBuffer = strlen(buffer);
    char newBuffer[sizeOfNewBuffer];
    int i = 0, j = 0;
    
    memset(newBuffer, 0, sizeOfNewBuffer);
    while(i < sizeOfNewBuffer)
    {
        if(isdigit(buffer[i]))
        {
            while(i < sizeOfNewBuffer && isdigit(buffer[i]))
                newBuffer[j++] = buffer[i++];
            if(buffer[i] != 0x0A) // LF
            {
                perror("Input data error\nAborting...\n\n");
                return 1;
            }
        }
        else if(isspace(buffer[i]) && buffer[i] != 0x0A)  //whitespace without LF
            ++i;
        else if(buffer[i] == 0x0A)  // LF
        {   //EOL
            strcpy(buffer, newBuffer);
            return 0;
        }
        else
        {   //input data error
            perror("Input data error\nAborting...\n\n");
            return 1;
        }
    }
    return 0;

}
