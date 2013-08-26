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


// Print a SinglyLinkedList for debug.
// @in list: The SinglyLinkedList to print.
void singly_linked_list_print(SinglyLinkedList *list) {
  SinglyLinkedList *node = list;
  while (NULL != node) {
    printf("%d->", node->value);
    node = node->next;
  }
  printf("NULL\n");
}

// Allocate a linked list node.
LinkedList *linked_list_alloc(int value) {
  LinkedList *node = (LinkedList *) malloc(sizeof(LinkedList));
  node->prev = NULL;
  node->next = NULL;
  node->value = value;
  return node;
}

// Append a node to the LinkedList.
// @in list: The list to which the node is appended.
// @in value: The value of the node.
// @return: The new head of the LinkedList.
LinkedList *linked_list_append(LinkedList *list, int value) {
  if (NULL == list) return linked_list_alloc(value);

  LinkedList *tail = list;
  while (tail->next != NULL) tail = tail->next;

  LinkedList *new_node = linked_list_alloc(value);
  tail->next = new_node;
  new_node->prev = tail;
  return list;
}

// Free a LinkedList.
// @in list: The list to free.
// @return: NULL to clear the variable. E.g. 
//   list = linked_list_free(list);
LinkedList *linked_list_free(LinkedList *list) {
  LinkedList *node = list;
  while (NULL != node) {
    LinkedList *tmp = node->next;
    free(node);
    node = tmp;
  }
  return NULL;
}


// Print a LinkedList for debug.
// @in list: The LinkedList to print.
void linked_list_print(LinkedList *list) {
  LinkedList *node = list;
  while (NULL != node) {
    printf("%d->", node->value);
    node = node->next;
  }
  printf("NULL\n");
}
