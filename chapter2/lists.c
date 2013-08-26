#include "lists.h"

#include <stdlib.h>

// Allocate a singly linked list node.
SinglyLinkedList *singly_linked_list_alloc(int value) {
  SinglyLinkedList *node = (SinglyLinkedList *) malloc(
      sizeof(SinglyLinkedList));
  node->next = NULL;
  node->value = value;
  return node;
}

// Append a node to the SinglyLinkedList.
// @in list: The list to which the node is appended.
// @in value: The value of the node.
// @return: The new head of the SinglyLinkedList.
SinglyLinkedList *singly_linked_list_append(SinglyLinkedList *list,
                                            int value) {
  if (NULL == list) return singly_linked_list_alloc(value);

  SinglyLinkedList *tail = list;
  while (tail->next != NULL) tail = tail->next;

  SinglyLinkedList *new_node = singly_linked_list_alloc(value);
  tail->next = new_node;
  return list;
}

// Free a SinglyLinkedList.
// @in list: The list to free.
// @return: NULL to clear the variable. E.g. 
//   list = singly_linked_list_free(list);
SinglyLinkedList *singly_linked_list_free(SinglyLinkedList *list) {
  SinglyLinkedList *node = list;
  while (NULL != node) {
    SinglyLinkedList *tmp = node->next;
    free(node);
    node = tmp;
  }
  return NULL;
}
