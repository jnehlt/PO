#include "stack.hpp"

void Stack::init(Stack& s)
{
    assert(this != NULL);
    if (!(pStack = new (nothrow) int[1]))
        abort();
    numOfeel = 1;
    IDofLastEl = 0;
}

void Stack::destroy(Stack& s)
{
    delete [] pStack;
}

void Stack::push(Stack& s, int value)
{
    if (IDofLastEl == numOfeel)
    {
        int* temp = new (nothrow) int[numOfeel *= 2];
        if(temp == NULL)
        {
            cout << "Bye then.\n";
            delete [] pStack;
            abort();
        }
        memcpy(temp, pStack, IDofLastEl * sizeof(int));
        delete [] pStack;
        pStack = temp;
    }

    pStack[IDofLastEl++] = value;
}

int Stack::pop(Stack& s)
{
    if (IDofLastEl == 0)
    {
        delete [] pStack;
        abort();
    }
    return pStack[--IDofLastEl];
}

void Stack::clear(Stack& s)
{
    if (IDofLastEl == 0)
    {
        delete [] pStack;
        abort();
    }

    int* temp = new (nothrow) int[numOfeel = 10];
    if(!temp)
    {
        cout << "Bye then.\n";
        delete [] pStack;
        abort();
    }
    delete [] pStack;
    pStack = temp;

    if (!(pStack = (int*)memset(pStack, 0, sizeof(int)* numOfeel)))
    {
        delete [] pStack;
        abort();
    }
    IDofLastEl = 0;
}

bool Stack::isEmpty(Stack& s)
{
    if (IDofLastEl) return 0;
    return 1;
}
