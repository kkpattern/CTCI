// Decide if two strings are anagrams or not.
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void *a, const void *b) {
  return *((char*)a) - *((char*)b);
}

// Rmove spaces in a string.
void remove_spaces(char *string) {
  char *insert_position = string;
  for (char *test_char = string; *test_char != '\0'; ++test_char) {
    if (!isspace(*test_char)) {
      *insert_position = *test_char;
      ++insert_position;
    }
  }
  *insert_position = '\0';
}

// Decide if two strings are anagrams or not.
// @in a: The first string.
// @in b: The second string.
// @return: true if the two strings are anagrams, otherwise false.
bool anagrams(const char *a, const char *b) {
  char *aa = (char *) malloc(strlen(a)+1);
  strcpy(aa, a);
  char *bb = (char *) malloc(strlen(b)+1);
  strcpy(bb, b);
  remove_spaces(aa);
  remove_spaces(bb);
  size_t length_aa = strlen(aa);
  size_t length_bb = strlen(bb);
  if (length_aa != length_bb) return false;

  for (char *c = aa; *c != '\0'; ++c) {
    *c = tolower(*c);
  }
  for (char *c = bb; *c != '\0'; ++c) {
    *c = tolower(*c);
  }
  
  qsort(aa, strlen(aa), sizeof(char), compare_char);
  qsort(bb, strlen(bb), sizeof(char), compare_char);
  bool result = true;
  char *pa = aa;
  char *pb = bb;
  while (*pa != '\0') {
    if (*pa != *pb) {
      result = false;
      break;
    }
    ++pa;
    ++pb;
  }
  free(bb);
  free(aa);
  return result;
}

int main() {
  bool result = anagrams("Abcd efg", "gf ecdba");
  assert(result == true);
  result = anagrams("", "  ");
  assert(result == true);
  result = anagrams("asfd34", "saf3");
  assert(result == false);
  return 0;
}
