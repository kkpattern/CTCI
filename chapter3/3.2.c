// Design a stack which, in addition to push and pop, also has a function min
// which returns the minimum element. Push, pop and min should all operate in
// O(1) time.
#include <assert.h>

typedef struct _MinStack {
  int *stack;
  int *min_value;
  size_t stack_size;
  size_t stack_head;
} MinStack;

// Initialize a MinStack.
// @in initial_size: The initial size of stack.
// @return: Pointer to the new initialized stack.
MinStack *min_stack_init(size_t initial_size) {
  MinStack *stack = (MinStack *) malloc(sizeof(MinStack));
  if (NULL == stack) return NULL;

  stack->stack_size = initial_size;
  stack->stack = (int *) malloc(sizeof(int)*stack->stack_size);
  if (NULL == stack->stack) {
    free(stack);
    return NULL;
  }

  stack->min_value = (int *) malloc(sizeof(int)*stack->stack_size);
  if (NULL == stack->min_value) {
    free(stack->stack);
    free(stack);
    return NULL;
  }

  stack->stack_head = 0;
  return stack;
}

// Push a value into the stack.
// @in stack: The stack into which the value is pushed.
// @in value: The value to be pushed.
// @return: 0 if the value is successfully pushed. 1 if any error on allocating
//   memory.
int min_stack_push(MinStack *stack, int value) {
  if (stack->stack_head >= stack->stack_size) {
    size_t new_stack_size = 2*stack->stack_size;
    int *new_stack = (int *) malloc(sizeof(int)*new_stack_size);
    if (NULL == new_stack) return 1;

    int *new_min_value = (int *) malloc(sizeof(int)*new_stack_size);
    if (NULL == new_min_value) {
      free(new_stack);
      return 1;
    }

    memcpy(new_stack, stack->stack, sizeof(int)*stack->stack_size);
    memcpy(new_min_value, stack->min_value, sizeof(int)*stack->stack_size);
    free(stack->stack);
    free(stack->min_value);
    stack->stack = new_stack;
    stack->min_value = new_min_value;
    stack->stack_size = new_stack_size;
  }

  stack->stack[stack->stack_head] = value;

  // Update min value.
  if (0 == stack->header) {
    stack->min_value[stack_head] = value;
  } else {
    int last_min_value = min_value[stack_head-1];
    if (value < stack->last_min_value) {
      stack->min_value[stack_head] = value;
    } else {
      stack->min_value[stack_head] = last_min_value;
    }
  }

  stack->stack_head += 1;
  return 0;
}

// Pop a value out from stack.
// @in stack: The stack from which the value is popped.
// @out value: The popped out value.
// @return: 0 if the value is successfully popped. 1 if the stack is empty.
int min_stack_pop(MinStack *stack, int *value) {
}

// Free a stack.
// @in stack: The stack to free.
// @return: NULL.
MinStack *min_stack_free(MinStack *stack) {
  free(stack->stack);
  free(stack->min_value);
  free(stack);
  return NULL;
}
