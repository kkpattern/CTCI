// Stack implementations for CTCI.
#ifndef CTCI_STACKS_H
#define CTCI_STACKS_H


#include <stddef.h>


typedef struct _Stacks {
  int *stack;
  size_t stack_number;
  size_t *stack_head;
  size_t stack_size;
} Stacks;

// Initialize a stacks.
// @in stack_number: The number of stacks.
// @in initial_size: The initial size of the stacks.
// @return: Pointer to the initialized stack. NULL if any error on
//   allocating memory.
Stacks *stacks_init(size_t stack_number, size_t initial_size);

// Push a value into stack.
// @in stacks: The Stacks to which the value is pushed.
// @in stack_id: The number of stack to which the value is pushed. The
//   value must be in [1, stacks->stack_number].
// @in value: The value to push.
// @return: 0 if the value is pushed successfully. 1 if the stack_id is
//   invalid. 2 if there is no memory.
int stacks_push(Stacks *stacks, int stack_id, int value);

// Pop a value out from stack.
// @in stacks: The Stacks from where the value is popped.
// @in stack_id: The number of stack from where the value is pushed. The
//   value must be in [1, stacks->stack_number].
// @out value: The popped out value.
// @return: 0 if the value is popped out successfully. 1 if the stack_id is
//   invalid. 2 if the stack is empty.
int stacks_pop(Stacks *stacks, int stack_id, int *value);

// Count the current elements in the stack.
// @in stacks: The Stacks.
// @in stack_id: The number of stack to count.
size_t stacks_count(Stacks *stacks, size_t stack_id);

// Free a Stacks.
// @in stacks: The Stacks to free.
// @return: NULL.
Stacks *stacks_free(Stacks *stacks);


#endif
