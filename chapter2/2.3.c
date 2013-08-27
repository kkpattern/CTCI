// Delete a node in the middle of a single linked list, given only access to
// that node.
#include <assert.h>
#include <stddef.h>

#include "ctci/lists.h"

// Delete a node in the middle of a single linked list, given only access to
// that node.
// @in node: The given node.
void delete_node(SinglyLinkedList *node) {
  SinglyLinkedList *last_node = NULL;
  while (NULL != node->next) {
    node->value = node->next->value;
    last_node = node;
    node = node->next;
  }
  last_node->next = NULL;
  singly_linked_list_free(node);
}

int main() {
  SinglyLinkedList *list = NULL;
  list = singly_linked_list_append(list, 1);
  list = singly_linked_list_append(list, 2);
  list = singly_linked_list_append(list, 3);
  list = singly_linked_list_append(list, 4);
  list = singly_linked_list_append(list, 5);
  singly_linked_list_print(list);
  delete_node(list->next->next);
  singly_linked_list_print(list);
  singly_linked_list_free(list);
}
