// Design a stack which, in addition to push and pop, also has a function min
// which returns the minimum element. Push, pop and min should all operate in
// O(1) time.
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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
  if (0 == stack->stack_head) {
    stack->min_value[stack->stack_head] = value;
  } else {
    int last_min_value = stack->min_value[stack->stack_head-1];
    if (value < last_min_value) {
      stack->min_value[stack->stack_head] = value;
    } else {
      stack->min_value[stack->stack_head] = last_min_value;
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
  if (0 == stack->stack_head) return 1;

  stack->stack_head -= 1;
  *value = stack->stack[stack->stack_head];
  return 0;
}

// Get the min value in the stack.
// @in stack: The stack.
// @out value: The min value.
// @return: 0 if the min value is successfully got. 1 if the stack is empty.
int min_stack_min(MinStack *stack, int *value) {
  if (0 == stack->stack_head) return 1;

  *value = stack->min_value[stack->stack_head-1];
  return 0;
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

int main() {
  MinStack *stack = min_stack_init(1);
  int value = 0;
  assert(1 == min_stack_pop(stack, &value));
  assert(1 == min_stack_min(stack, &value));

  assert(0 == min_stack_push(stack, 2));
  assert(0 == min_stack_min(stack, &value));
  assert(2 == value);
  assert(0 == min_stack_pop(stack, &value));
  assert(2 == value);

  assert(0 == min_stack_push(stack, 2));
  assert(0 == min_stack_push(stack, 1));
  assert(0 == min_stack_min(stack, &value));
  assert(1 == value);
  assert(0 == min_stack_push(stack, 3));
  assert(0 == min_stack_min(stack, &value));
  assert(1 == value);
  assert(0 == min_stack_push(stack, 0));
  assert(0 == min_stack_min(stack, &value));
  assert(0 == value);


  stack = min_stack_free(stack);
  return 0;
}
