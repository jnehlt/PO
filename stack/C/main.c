#include "stack.h"

int main(void)
{
  Stack stack;
  init(&stack);

  push(&stack, 7);
  push(&stack, 18);
  push(&stack, 12);
  push(&stack, 593);
  push(&stack, 78);

  isEmpty(&stack) ? printf("EMPTY!\n") : printf("NOT EMPTY!\n");

  push(&stack, 118);
  push(&stack, 312);
  push(&stack, 53);
  push(&stack, 1227);
  push(&stack, 1885);
  push(&stack, 1221);
  push(&stack, 5853);
  push(&stack, 76);
  push(&stack, 28);
  push(&stack, 3121);
  push(&stack, 536);

  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  printf("%d\n", pop(&stack));
  //printf("%d\n", pop(&stack));

  clear(&stack);

  destroy(&stack);

  return 0;
}