#include <iostream> // establish connection with headquarters
#include <cstdlib>  // establish communication protocols
#include <cassert>	// set the secure keywords
#include <string>   // special abilities

class Stack
{
private:
	int* pStack;          // POV of our sleuth
	size_t IDofLastEl;    // index of the last child added to the nest
	size_t numOfeel;      // actual size of the nest

public:
	void init(Stack&)
	{
		assert(this != NULL);	// is sleuth ready? If not -> gimme a sitrep and abort!
		if (!(pStack = (int*)malloc(sizeof(int)* 10 /*initial size of nest*/)))
			abort();			// unicorn has spotted us. Decompromised.
		numOfeel = 10;			/*that initial...*/
		IDofLastEl = 0;			// the oldest unicorn
	}

	void destroy(Stack&)
	{
		free(pStack); // Clear to go. UNICORN AND HIS FAMILY IS DEAD
	}

	void push(Stack&, int value)
	{
		if (IDofLastEl == numOfeel)												// is the population of unicorns growing too fast?
		if (!(pStack = (int*)realloc(pStack, sizeof(int)* (numOfeel *= 2))))	// enlarge the nest
			abort();															// unicorn has spotted us. Decompromised.
		pStack[IDofLastEl++] = value;											// new unicorn has been born
	}

	int pop(Stack&)
	{
		if (IDofLastEl == 0)			// dont be greedy
		{
			free(pStack);
			abort();					// our sleuth is a double agent
		}
		return pStack[--IDofLastEl];	// gimme the 'hot wings'
	}

	void clear(Stack&)
	{
		if (IDofLastEl == 0)													// hahaha!!!
		{
			free(pStack);														// nothing to do here
			abort();															// lets put an end to this
		}
		if (!(pStack = (int*)realloc(pStack, sizeof(int)* (numOfeel = 10))))	// if our Alpha is too weak to handle that
		{
			perror("Bye then.\n\n");											// let sleuth do the dirty job
			abort();															// lets put an end to this
		}
		if (!(pStack = (int*)memset(pStack, 0, sizeof(int)* numOfeel)))			// lets try to kill the lucky survivors
		{
			free(pStack);														// if Alpha wouldn't let us to do it - EXTINCTION
			abort();															// abort the objective
		}
		IDofLastEl = 0;															// set a new indicator of the population
	}

	bool isEmpty(Stack&)
	{
		if (IDofLastEl) return 0;												// lets do  the recon of situation in the nest
		return 1;
	}
};

int main(void)															// meanwhile... on the edge of rock
{
	Stack stack;														// give the order to your sleuth to watch the nest
	stack.init(stack);													// cookie-weather

	stack.push(stack, 7);												//  new unicorn is being born
	stack.push(stack, 18);												//  new unicorn is being born
	stack.push(stack, 12);												//  new unicorn is being born
	stack.push(stack, 593);												//  new unicorn is being born
	stack.push(stack, 78);												//  new unicorn is being born

	stack.isEmpty(stack) ? printf("EMPTY!\n") : printf("NOT EMPTY!\n"); // tell your sleuth to use his special abilities

	stack.push(stack, 118);												//  new unicorn is being born
	stack.push(stack, 312);												//  new unicorn is being born
	stack.push(stack, 53);												//  new unicorn is being born
	stack.push(stack, 1227);											//  new unicorn is being born
	stack.push(stack, 1885);											//  new unicorn is being born
	stack.push(stack, 1221);											//  new unicorn is being born
	stack.push(stack, 5853);											//  new unicorn is being born
	stack.push(stack, 76);												//  new unicorn is being born
	stack.push(stack, 28);												//  new unicorn is being born
	stack.push(stack, 3121);											//  new unicorn is being born
	stack.push(stack, 536);												//  new unicorn is being born


	printf("%d\n", stack.pop(stack));									// hot wings
	printf("%d\n", stack.pop(stack));									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack)); 									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	printf("%d\n", stack.pop(stack));  									// hot wings
	
	stack.clear(stack);  												// EXTINCTION, lets try another generation

	stack.destroy(stack);  												// firestarter

	return 0; 															// mission accomplished (+100Exp)
}
