// Remove the duplicate characters in a string without using any additional
// buffer.
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void remove_duplicate(char *string) {
  char *insert_position = string;
  char *test_char = string;
  while (*test_char != '\0') {
    // Find next unique character.
    bool unique = true;
    for (char *target_char = test_char-1;
        target_char >= string;
        --target_char) {
      if (*test_char == *target_char) {
        unique = false;
        break;
      }
    }
    // Insert the unique character.
    if (unique) {
      *insert_position = *test_char;
      ++insert_position;
    }
    ++test_char;
  }
  *insert_position = '\0';
}

int main() {
  char string [] = "aabcdd";
  remove_duplicate(string);
  assert(strcmp(string, "abcd") == 0);
  return 0;
}
