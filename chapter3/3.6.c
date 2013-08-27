// Write a program to sort a stack in ascending order. You should not make any
// assumptions about how the stack is implemented. The following are the only
// functions that should be used to write this program: push | pop | peek |
// isEmpty.
#include <assert.h>
#include <stddef.h>

#include "ctci/stacks.h"

void sort_stack(Stack *stack) {
  Stack *helper_stack = stack_init(20);
  int test_element = 0;
  while (0 == stack_pop(stack, &test_element)) {
    int compare = 0;
    while (0 == stack_pop(helper_stack, &compare)) {
      if (test_element < compare) {
        stack_push(stack, compare);
      } else {
        stack_push(helper_stack, compare);
        break;
      }
    }
    stack_push(helper_stack, test_element);
  }
  int value = 0;
  while (0 == stack_pop(helper_stack, &value)) {
    stack_push(stack, value);
  }
  helper_stack = stack_free(helper_stack);
}

int main() {
  Stack *stack = stack_init(10);
  for (int i = 1; i <= 10; ++i) {
    assert(0 == stack_push(stack, i));
  }
  sort_stack(stack);
  int value = 0;
  for (int i = 1; i <= 10; ++i) {
    assert(0 == stack_pop(stack, &value));
    assert(i == value);
  }
  stack = stack_free(stack);
  return 0;
}
