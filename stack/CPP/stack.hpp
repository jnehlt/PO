#ifndef stack_hpp
#define stack_hpp

    #include <iostream>
    #include <cstdlib>
    #include <cassert>
    #include <cstring>
    #include <new>

    using namespace std;

    class Stack
    {
    private:
        int* pStack;
        size_t IDofLastEl;
        size_t numOfeel;

    public:
        void init(Stack& s);
        void destroy(Stack& s);
        void push(Stack& s , int value);
        int pop(Stack& s );
        void clear(Stack& s );
        bool isEmpty(Stack& s);
    };

#endif
