// Determine if a string has all unique characters without using additional
// data structures.
#include <assert.h>
#include <stdbool.h>


// Using brute force algorithm.
bool all_unique_brute_force(const char *string) {
  for (const char *test_char = string; *test_char != '\0'; ++test_char) {
    for (const char *target_char = test_char+1;
        *target_char != '\0';
        ++target_char) {
      if (*test_char == *target_char) return false;
    }
  }
  return true;
}


int main() {
  bool result = all_unique_brute_force("abcd");
  assert(result == true);
  result = all_unique_brute_force("abb");
  assert(result == false);
  return 0;
}
