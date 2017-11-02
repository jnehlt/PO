#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <string>
#include <new>

using namespace std;

class Stack
{
private:
	int* pStack;
	size_t IDofLastEl;
	size_t numOfeel;

public:
	void init(Stack&)
	{
		assert(this != NULL);
		if (!(pStack = new (nothrow) int[10]))
			abort();
		numOfeel = 10;
		IDofLastEl = 0;
	}

	void destroy(Stack&)
	{
		delete [] pStack;
	}

	void push(Stack&, int value)
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

	int pop(Stack&)
	{
		if (IDofLastEl == 0)
		{
      delete [] pStack;
			abort();
		}
		return pStack[--IDofLastEl];
	}

	void clear(Stack&)
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

	bool isEmpty(Stack&)
	{
		if (IDofLastEl) return 0;
		return 1;
	}
};

int main(void)
{
	Stack stack;
	stack.init(stack);

	stack.push(stack, 7);
	stack.push(stack, 18);
	stack.push(stack, 12);
	stack.push(stack, 593);
	stack.push(stack, 78);

	stack.isEmpty(stack) ? cout << "EMPTY!\n" : cout << "NOT EMPTY!\n";

	stack.push(stack, 118);
	stack.push(stack, 312);
	stack.push(stack, 53);
	stack.push(stack, 1227);
	stack.push(stack, 1885);
	stack.push(stack, 1221);
	stack.push(stack, 5853);
	stack.push(stack, 76);
	stack.push(stack, 28);
	stack.push(stack, 3121);
	stack.push(stack, 536);


	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;
	cout << stack.pop(stack) << endl;

	stack.clear(stack);

	stack.destroy(stack);

	return 0;
}
