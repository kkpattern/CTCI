// Find the nth to last element of a singly linked list.
#include <assert.h>
#include <stddef.h>

#include "ctci/lists.h"

// Find the nth to last element of a singly linked list.
// @in list: The SinglyLinkedList.
// @in n: The nth.
// @out value: The nth to last element.
// @return: 0 if the element is successfully found. 1 if there is less than
//   n elements in the list.
int nth_to_last(SinglyLinkedList *list, int n, int *value) {
  int length = 0;
  SinglyLinkedList *counter = list;
  while (NULL != counter) {
    ++length;
    counter = counter->next;
  }
  if (length < n) return 1;

  n = length - n;
  SinglyLinkedList *target = list;
  while (n > 0) {
    target = target->next;
    --n;
  }
  *value = target->value;
  return 0;
}

int main() {
  SinglyLinkedList *list = NULL;
  list = singly_linked_list_append(list, 1);
  list = singly_linked_list_append(list, 2);
  list = singly_linked_list_append(list, 3);
  list = singly_linked_list_append(list, 4);
  list = singly_linked_list_append(list, 5);
  list = singly_linked_list_append(list, 6);
  int value = 0;
  assert(0 == nth_to_last(list, 1, &value));
  assert(6 == value);
  assert(1 == nth_to_last(list, 7, &value));
  singly_linked_list_free(list);
}
