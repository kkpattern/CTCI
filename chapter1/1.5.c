// Replace all spaces in a string with ‘%20’.
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Append '%20' to the position.
// @io position: The position to append.
// @return: The position next to the new appended '%20'.
char *append_space_escape(char *position) {
  *(position++) = '%';
  *(position++) = '2';
  *(position++) = '0';
  return position;
}

// Replace all spaces in a string with ‘%20’.
// @in string: The string to escape.
// @return: The new escaped string. Remember to free it.
char *escape_spaces(const char *string) {
  char *buffer = (char *) malloc(strlen(string)*3+1);
  char *insert_position = buffer;
  for (const char *c = string; *c != '\0'; ++c) {
    if (!isspace(*c)) {
      *insert_position = *c;
      ++insert_position;
    } else {
      insert_position = append_space_escape(insert_position);
    }
  }
  *insert_position = '\0';
  char *result = (char *) malloc(strlen(buffer)+1);
  strcpy(result, buffer);
  free(buffer);
  return result;
}

int main() {
  char *escaped_string = escape_spaces("abcd efg");
  assert(strcmp(escaped_string, "abcd%20efg") == 0);
  free(escaped_string);
  return 0;
}
