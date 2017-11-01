#include <stdio.h>    // establish connection with headquarters
#include <stdlib.h>   // establish communication protocols
#include <assert.h>   // set the secure keywords
#include <string.h>   // special abilities
#include <stdbool.h>  // lie detector

struct Stack
{
  int* pStack;          // POV of our sleuth
  size_t IDofLastEl;    // index of the last child added to the nest
  size_t numOfeel;      // actual size of the nest
};

typedef struct Stack Stack; // make it simpler :)

void init(Stack*);      // Initialize unicorn and his family (let them grow) [harder, better, faster, stronger!]
void destroy(Stack*);   // Destroy unicorn (and his family) [clear the nest!!!]
void push(Stack*, int); // Throw a cookie to The nest :)
int pop(Stack*);        // Take one child and cook'em well
void clear(Stack*);     // Exterminate current population and create new one
bool isEmpty(Stack*);   // the sneaky one - lookin for eggs

int main(void)    // meanwhile... on the edge of rock
{
  Stack stack;    // give the order to your sleuth to watch the nest
  init(&stack);   // cookie-weather

  push(&stack, 7);    //  new unicorn is being born
  push(&stack, 18);   //  new unicorn is being born
  push(&stack, 12);   //  new unicorn is being born
  push(&stack, 593);  //  new unicorn is being born
  push(&stack, 78);   //  new unicorn is being born

  isEmpty(&stack) ? printf("EMPTY!\n") : printf("NOT EMPTY!\n"); // tell your sleuth to use his special abilities

  push(&stack, 118);  //  new unicorn is being born
  push(&stack, 312);  //  new unicorn is being born
  push(&stack, 53);   //  new unicorn is being born
  push(&stack, 1227); //  new unicorn is being born
  push(&stack, 1885); //  new unicorn is being born
  push(&stack, 1221); //  new unicorn is being born
  push(&stack, 5853); //  new unicorn is being born
  push(&stack, 76);   //  new unicorn is being born
  push(&stack, 28);   //  new unicorn is being born
  push(&stack, 3121); //  new unicorn is being born
  push(&stack, 536);  //  new unicorn is being born


  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings
  printf("%d\n", pop(&stack));  // hot wings

  clear(&stack);  // EXTINCTION, lets try another generation

  destroy(&stack);  // firestarter

  return 0; // mission accomplished (+100Exp)
}

void init(Stack* s)
{
  assert(s != NULL);  // is sleuth ready? If not -> gimme a sitrep and abort!
  if(!(s->pStack = (int*)malloc(sizeof(int) * 10 /*initial size of nest*/)))
    abort();  // unicorn has spotted us. Decompromised.
  s->numOfeel = 10; /*that initial...*/
  s->IDofLastEl = 0;  // the oldest unicorn
}

void destroy(Stack* s)
{
  free(s->pStack); // Clear to go. UNICORN AND HIS FAMILY IS DEAD
}

void push(Stack* s, int value)
{
  if(s->IDofLastEl == s->numOfeel) // is the population of unicorns growing too fast?
    if(!(s->pStack = (int*)realloc(s->pStack, sizeof(int) * (s->numOfeel *= 2)))) // enlarge the nest
      abort();  // unicorn has spotted us. Decompromised.
  s->pStack[s->IDofLastEl++] = value; // new unicorn has been born
}

int pop(Stack* s)
{
  if(s->IDofLastEl == 0) // dont be greedy
  {
    free(s->pStack);
    abort();  // our sleuth is a double agent
  }
  return s->pStack[--s->IDofLastEl];  // gimme the 'hot wings'
}

void clear(Stack* s)
{
  if(s->IDofLastEl == 0)  // hahaha!!!
  {
    free(s->pStack);  // nothing to do here
    abort();  // lets put an end to this
  }
  if(!(s->pStack = (int*)realloc(s->pStack, sizeof(int) * (s->numOfeel = 10)))) // if our Alpha is too weak to handle that
    {
      perror("Bye then.\n\n"); // let sleuth do the dirty job
      abort();  // lets put an end to this
    }
  if(!(s->pStack = (int*)memset(s->pStack, 0, sizeof(int) * s->numOfeel)))  // lets try to kill the lucky survivors
  {
    free(s->pStack);  // if Alpha wouldn't let us to do it - EXTINCTION
    abort();  // abort the objective
  }
  s->IDofLastEl = 0;  // set a new indicator of the population
}

bool isEmpty(Stack* s)
{
  if(s->IDofLastEl) return 0; // lets do  the recon of situation in the nest
  return 1;
}
