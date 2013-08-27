// In the classic problem of the Towers of Hanoi, you have 3 rods and N disks
// of different sizes which can slide onto any tower. The puzzle starts with
// disks sorted in ascending order of size from top to bottom (e.g., each disk
// sits on top of an even larger one). You have the following constraints:
// (A) Only one disk can be moved at a time.
// (B) A disk is slid off the top of one rod onto the next rod.
// (C) A disk can only be placed on top of a larger disk.
// Write a program to move the disks from the first rod to the last using
// Stacks.
#include <assert.h>

#include "stacks.h"

void solve_hanoi(Stacks *stacks, size_t from, size_t to, size_t disk_count) {
  if (1 < disk_count) {
    size_t transit = 1;
    while (transit == from || transit == to) ++transit;

    solve_hanoi(stacks, from, transit, disk_count-1);

    int value = 0;
    stacks_pop(stacks, from, &value);
    stacks_push(stacks, to, value);

    solve_hanoi(stacks, transit, to, disk_count-1);

  } else {
    int value = 0;
    stacks_pop(stacks, from, &value);
    stacks_push(stacks, to, value);
  }
}

int main() {
  Stacks *stacks = stacks_init(3, 10);
  size_t disk_count = 3;
  int value = 0;
  for (int i = disk_count; i > 0; --i) {
    stacks_push(stacks, 1, i);
  }
  solve_hanoi(stacks, 1, 3, 3);

  assert(2 == stacks_pop(stacks, 1, &value));

  for (int i = 1; i <= disk_count; ++i) {
    assert(0 == stacks_pop(stacks, 3, &value));
    assert(value = i);
  }
  return 0;
}
