// Adds the two numbers and returns the sum as a linked list.
#include <stddef.h>

#include "lists.h"

LinkedList *add(LinkedList *a, LinkedList *b) {
  LinkedList *result = NULL;
  int incre = 0;
  while (!(NULL == a && NULL == b)) {
    int sum = incre;
    if (NULL != a) {
      sum += a->value;
      a = a->next;
    }
    if (NULL != b) {
      sum += b->value;
      b = b->next;
    }
    int digit = sum % 10;
    incre = sum / 10;
    result = linked_list_append(result, digit);
  }
  return result;
}

int main() {
  LinkedList *number_a = NULL;
  number_a = linked_list_append(number_a, 3);
  number_a = linked_list_append(number_a, 1);
  number_a = linked_list_append(number_a, 5);
  linked_list_print(number_a);
  LinkedList *number_b = NULL;
  number_b = linked_list_append(number_b, 5);
  number_b = linked_list_append(number_b, 9);
  number_b = linked_list_append(number_b, 2);
  number_b = linked_list_append(number_b, 1);
  linked_list_print(number_b);
  LinkedList *result = add(number_a, number_b);
  linked_list_print(result);
  linked_list_free(result);
  linked_list_free(number_b);
  linked_list_free(number_a);
  return 0;
}
