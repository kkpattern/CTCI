// Use a single array to implement three stacks.
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "ctci/stacks.h"

int main() {
  Stacks *stacks = stacks_init(3, 10);
  int value = 0;
  assert(1 == stacks_push(stacks, 4, 1));
  assert(0 == stacks_push(stacks, 1, 1));
  assert(0 == stacks_push(stacks, 2, 2));
  assert(0 == stacks_push(stacks, 3, 3));
  assert(0 == stacks_pop(stacks, 1, &value));
  assert(1 == value);
  assert(2 == stacks_pop(stacks, 1, &value));
  assert(0 == stacks_pop(stacks, 2, &value));
  assert(2 == value);
  assert(2 == stacks_pop(stacks, 2, &value));
  assert(0 == stacks_pop(stacks, 3, &value));
  assert(3 == value);
  assert(2 == stacks_pop(stacks, 3, &value));
  stacks = stacks_free(stacks);
  return 0;
}
