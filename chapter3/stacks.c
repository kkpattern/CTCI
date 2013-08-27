#include "stacks.h"

#include <stdlib.h>
#include <string.h>

// Initialize a stacks.
// @in stack_number: The number of stacks.
// @in initial_size: The initial size of the stacks.
// @return: Pointer to the initialized stack. NULL if any error on
//   allocating memory.
Stacks *stacks_init(size_t stack_number, size_t initial_size) {
  Stacks *new_stack = (Stacks *) malloc(sizeof(Stacks));
  if (NULL == new_stack) return NULL;

  new_stack->stack_size = initial_size;
  new_stack->stack = (int *) malloc(sizeof(int) * new_stack->stack_size);
  if (NULL == new_stack->stack) {
    free(new_stack);
    return NULL;
  }

  new_stack->stack_number = stack_number;
  new_stack->stack_head = (size_t *) malloc(sizeof(new_stack->stack_head));
  if (NULL == new_stack->stack_head) {
    free(new_stack->stack);
    free(new_stack);
    return NULL;
  }

  for (size_t i = 0; i < new_stack->stack_number; ++i) {
    new_stack->stack_head[i] = 0;
  }
  return new_stack;
}

// Push a value into stack.
// @in stacks: The Stacks to which the value is pushed.
// @in stack_id: The number of stack to which the value is pushed. The
//   value must be in [1, stacks->stack_number].
// @in value: The value to push.
// @return: 0 if the value is pushed successfully. 1 if the stack_id is
//   invalid. 2 if there is no memory.
int stacks_push(Stacks *stacks, int stack_id, int value) {
  if (stack_id < 1 || stack_id > stacks->stack_number) {
    return 1;
  }

  size_t insert_position = 
    stacks->stack_head[stack_id-1]*stacks->stack_number+stack_id-1;
  if (insert_position >= stacks->stack_size) {
    size_t new_stack_size = 2*stacks->stack_size;
    int *new_stack = (int *) malloc(sizeof(int) * new_stack_size);
    if (NULL == new_stack) return 2;

    memcpy(new_stack, stacks->stack, sizeof(int)*stacks->stack_size);
    free(stacks->stack);
    stacks->stack = new_stack;
    stacks->stack_size = new_stack_size;
  }
  stacks->stack[insert_position] = value;
  stacks->stack_head[stack_id-1] += 1;
  return 0;
}

// Pop a value out from stack.
// @in stacks: The Stacks from where the value is popped.
// @in stack_id: The number of stack from where the value is pushed. The
//   value must be in [1, stacks->stack_number].
// @out value: The popped out value.
// @return: 0 if the value is popped out successfully. 1 if the stack_id is
//   invalid. 2 if the stack is empty.
int stacks_pop(Stacks *stacks, int stack_id, int *value) {
  if (stack_id < 1 || stack_id > stacks->stack_number) {
    return 1;
  }
  size_t stack_head = stacks->stack_head[stack_id-1];
  if (0 == stack_head) return 2; // The stack is empty.

  size_t pop_position = (stack_head-1)*stacks->stack_number+stack_id-1;
  *value = stacks->stack[pop_position];
  stacks->stack_head[stack_id-1] -= 1;
  return 0;
}

// Free a Stacks.
// @in stacks: The Stacks to free.
// @return: NULL.
Stacks *stacks_free(Stacks *stacks) {
  free(stacks->stack_head);
  free(stacks->stack);
  free(stacks);
  return NULL;
}
