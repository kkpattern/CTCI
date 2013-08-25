// Write code to check if s2 is a rotation of s1 using only one call to
// strstr.
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Check if s2 is a rotation of s1.
bool is_rotation(const char *s1, const char *s2) {
  if (strlen(s1) != strlen(s2)) return false;

  char *buffer = (char *) malloc(strlen(s1)*2+1);
  strcpy(buffer, s1);
  strcat(buffer, s1);
  bool result = false;
  if (NULL != strstr(buffer, s2)) result = true;
  free(buffer);
  return result;
}

int main() {
  assert(false == is_rotation("abcd", "cdba"));
  assert(false == is_rotation("abcd", "bc"));
  assert(true == is_rotation("abcd", "cdab"));
  return 0;
}

