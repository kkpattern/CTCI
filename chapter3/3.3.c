// Imagine a (literal) stack of plates. If the stack gets too high, it might
// topple. Therefore, in real life, we would likely start a new stack when the
// previous stack exceeds some threshold. Implement a data structure
// SetOfStacks that mimics this. SetOfStacks should be composed of several
// stacks, and should create a new stack once the previous one exceeds
// capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically
// to a single stack (that is, pop() should return the same values as it would
// if there were just a single stack).
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SetOfStacks {
  int **stacks;
  size_t stack_number;
  size_t current_stack;
  size_t max_stack_size;
  size_t *heads;
} SetOfStacks;

// Initialize a SetOfStacks.
// @in initial_stack_number: The initial number of stacks.
// @in max_stack_size: The max size of a single stack.
// @return: Pointer to the new initialized stacks. NULL if any error on
//   allocating memory.
SetOfStacks *set_of_stacks_init(size_t initial_stack_number,
                                size_t max_stack_size) {
  SetOfStacks *stacks = (SetOfStacks *) malloc(sizeof(int) * max_stack_size);
  if (NULL == stacks) return NULL;

  stacks->stack_number = initial_stack_number;
  stacks->stacks = (int **) malloc(sizeof(int*) * stacks->stack_number);
  if (NULL == stacks->stacks) {
    free(stacks);
    return NULL;
  }

  stacks->current_stack = 0;
  stacks->max_stack_size = max_stack_size;
  stacks->stacks[stacks->current_stack] = (int *) malloc(
      sizeof(int) * stacks->max_stack_size);
  if (NULL == stacks->stacks[stacks->current_stack]) {
    free(stacks->stacks);
    free(stacks);
    return NULL;
  }

  stacks->heads = (size_t *) malloc(sizeof(size_t) * stacks->stack_number);
  stacks->heads[stacks->current_stack] = 0;

  return stacks;
}

// Push a value into SetOfStacks.
// @in stacks: The SetOfStacks to which the value is pushed.
// @in value: The value to push.
// @return: 0 if the value is successfully pushed. 1 if any error on allocating
//   memory.
int set_of_stacks_push(SetOfStacks *stacks, int value) {
  if (stacks->heads[stacks->current_stack] < stacks->max_stack_size) {
    int *current_stack = stacks->stacks[stacks->current_stack];
    size_t current_stack_head = stacks->heads[stacks->current_stack];
    current_stack[current_stack_head] = value;

    stacks->heads[stacks->current_stack] += 1;
  } else {
    if (stacks->current_stack >= stacks->stack_number-1) {
      size_t new_stack_number = stacks->stack_number*2;
      int **new_stacks = (int **) malloc(sizeof(int *) * new_stack_number);
      if (NULL == new_stacks) return 1;

      size_t *new_heads = (size_t *) malloc(sizeof(size_t) * new_stack_number);
      if (NULL == new_heads) {
        free(new_stacks);
        return 1;
      }

      memcpy(new_heads, stacks->heads, sizeof(size_t) * stacks->stack_number);
      memcpy(new_stacks, stacks->stacks, sizeof(int*) * stacks->stack_number);
      free(stacks->heads);
      free(stacks->stacks);
      stacks->stack_number = new_stack_number;
      stacks->heads = new_heads;
      stacks->stacks = new_stacks;
    }
    int *new_stack = (int *) malloc(sizeof(int) * stacks->max_stack_size);
    if (NULL == new_stack) return 1;

    new_stack[0] = value;
    stacks->current_stack += 1;
    stacks->heads[stacks->current_stack] = 1;
    stacks->stacks[stacks->current_stack] = new_stack;
  }
  return 0;
}

// Pop a value out of a sub-stack.
// @in stacks: The SetOfStacks.
// @in stack_id: The number of the sub-stack.
// @out value: The popped value.
// @return: 0 if the value is successfully popped. 1 if the sub-stack is empty.
int set_of_stacks_pop_at(SetOfStacks *stacks, size_t stack_number, int *value) {
  if (stack_number > stacks->current_stack) return 1;

  if (stacks->heads[stack_number] > 0) {
    size_t new_stack_head = stacks->heads[stack_number] - 1;
    *value = stacks->stacks[stack_number][new_stack_head];
    stacks->heads[stack_number] = new_stack_head;
  } else {
    return 1;
  }
  return 0;
}

// Pop a value out of SetOfStacks.
// @in stacks: The SetOfStacks from which the value is popped.
// @out value: The popped value.
// @return: 0 if the value is successfully popped. 1 if the stacks is empty.
int set_of_stacks_pop(SetOfStacks *stacks, int *value) {
  if (stacks->current_stack == 0 &&
      stacks->heads[stacks->current_stack] == 0) {
    return 1;
  } else {
    if (stacks->heads[stacks->current_stack] == 0) {
      free(stacks->stacks[stacks->current_stack]);
      stacks->current_stack -= 1;
    }
    int new_stack_head = stacks->heads[stacks->current_stack] - 1;
    *value = stacks->stacks[stacks->current_stack][new_stack_head];
    stacks->heads[stacks->current_stack] = new_stack_head;
  }
  return 0;
}

// Free a SetOfStacks.
// @in stacks: The SetOfStacks to free.
// @return: NULL.
SetOfStacks *set_of_stacks_free(SetOfStacks *stacks) {
  for (size_t i = 0; i <= stacks->current_stack; ++i) {
    free(stacks->stacks[i]);
  }
  free(stacks->stacks);
  free(stacks->heads);
  free(stacks);
  return NULL;
}

int main() {
  size_t stack_size = 10;
  SetOfStacks *stacks = set_of_stacks_init(3, stack_size);
  int value = 0;
  assert(1 == set_of_stacks_pop(stacks, &value));
  assert(0 == set_of_stacks_push(stacks, 9));
  assert(0 == set_of_stacks_pop(stacks, &value));
  assert(9 == value);
  const int max_pushed = 100;
  for (int i = 0; i < max_pushed; ++i) {
    assert(0 == set_of_stacks_push(stacks, i));
  }
  for (int i = 0; i < max_pushed; ++i) {
    assert(0 == set_of_stacks_pop(stacks, &value));
    assert(max_pushed-1-i == value);
  }
  assert(1 == set_of_stacks_pop(stacks, &value));

  for (int i = 0; i < stack_size+1; ++i) {
    assert(0 == set_of_stacks_push(stacks, i));
  }
  assert(0 == set_of_stacks_pop_at(stacks, 0, &value));
  assert(9 == value);
  for (int i = 0; i < stack_size; ++i) {
    assert(0 == set_of_stacks_pop(stacks, &value));
  }
  assert(1 == set_of_stacks_pop(stacks, &value));
  stacks = set_of_stacks_free(stacks);
}
