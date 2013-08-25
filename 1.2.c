// Reverse a C-Style String.
#include <assert.h>
#include <string.h>

void reverse_in_place(char *string) {
  char *begin = string;
  char *end = string;
  while (*(end+1) != '\0') ++end;
  while (begin < end) {
    char tmp = *begin;
    *begin = *end;
    *end = tmp;
    ++begin;
    --end;
  }
}

int main() {
  char string[] = "abcd";
  reverse_in_place(string);
  assert(strcmp(string, "dcba") == 0);
  char string1[] = "xyxcd";
  reverse_in_place(string1);
  assert(strcmp(string1, "dcxyx") == 0);
  return 0;
}
