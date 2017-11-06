#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

    struct Stack
    {
        int* pStack;
        size_t IDofLastEl;
        size_t numOfeel;
    };

    typedef struct Stack Stack;

    void init(Stack*);
    void destroy(Stack*);
    void push(Stack*, int);
    int pop(Stack*);
    void clear(Stack*);
    bool isEmpty(Stack*);
    
#endif