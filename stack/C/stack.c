#include "stack.h"

void init(Stack* s)
{
  assert(s != NULL);
  if(!(s->pStack = (int*)malloc(sizeof(int) * (s->numOfeel = 1))))
    abort();
  s->IDofLastEl = 0;
}

void destroy(Stack* s)
{
  free(s->pStack);
}

void push(Stack* s, int value)
{
  if(s->IDofLastEl == s->numOfeel)
    if(!(s->pStack = (int*)realloc(s->pStack, sizeof(int) * (s->numOfeel *= 2))))
      abort();
  s->pStack[s->IDofLastEl++] = value;
}

int pop(Stack* s)
{
  if(s->IDofLastEl == 0)
  {
    free(s->pStack);
    abort();
  }
  return s->pStack[--s->IDofLastEl];
}

void clear(Stack* s)
{
  if(s->IDofLastEl == 0)
  {
    free(s->pStack);
    abort();
  }
  if(!(s->pStack = (int*)realloc(s->pStack, sizeof(int) * (s->numOfeel = 10))))
  {
    perror("Bye then.\n\n");
    abort();
  }
  if(!(s->pStack = (int*)memset(s->pStack, 0, sizeof(int) * s->numOfeel)))
  {
    free(s->pStack);
    abort();
  }
  s->IDofLastEl = 0;
}

bool isEmpty(Stack* s)
{
  if(s->IDofLastEl) return 0;
  return 1;
}
