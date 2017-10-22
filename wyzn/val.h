#ifndef VAL_H
#define VAL_H

    float** validateInputData(int*, const int, const char**);
    int checkFirstLineOfInputMatrix(char*);
    int loadMatrix(char*, int);
    int val(float*, int, FILE*);
    int fly(FILE*);
    int fillMatrix(float*, int, FILE*);
    void err(FILE*, char*, float**, float**, int*, int*, int);

#endif
