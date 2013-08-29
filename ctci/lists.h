// List implementations for CTCI.
#ifndef LISTS_H
#define LISTS_H


typedef struct _SinglyLinkedList {
  struct _SinglyLinkedList *next;
  int value;
} SinglyLinkedList;

// Allocate a singly linked list node.
SinglyLinkedList *singly_linked_list_alloc(int value);

// Append a node to the SinglyLinkedList.
// @in list: The list to which the node is appended.
// @in value: The value of the node.
// @return: The new head of the SinglyLinkedList.
SinglyLinkedList *singly_linked_list_append(SinglyLinkedList *list, int value);

// Free a SinglyLinkedList.
// @in list: The list to free.
// @return: NULL to clear the variable. E.g. 
//   list = singly_linked_list_free(list);
SinglyLinkedList *singly_linked_list_free(SinglyLinkedList *list);

// Print a SinglyLinkedList for debug.
// @in list: The SinglyLinkedList to print.
void singly_linked_list_print(SinglyLinkedList *list);


typedef struct _LinkedList {
  struct _LinkedList *prev;
  struct _LinkedList *next;
  void *value;
} LinkedList;


// Allocate a linked list node.
LinkedList *linked_list_alloc(void *value);

// Append a node to the LinkedList.
// @in list: The list to which the node is appended.
// @in value: The value of the node.
// @return: The new head of the LinkedList.
LinkedList *linked_list_append(LinkedList *list, void *value);

// Pop out the head node of a LinkedList.
// @in list: The LinkedList.
// @out value: The value of the head node. If the LinkedList is empty the value
//   is unchanged.
// @return: The new head of the LinkedList.
LinkedList *linked_list_pop_head(LinkedList *list, void **value);

// Free a LinkedList.
// @in list: The list to free.
// @return: NULL to clear the variable. E.g. 
//   list = linked_list_free(list);
LinkedList *linked_list_free(LinkedList *list);


// Print a LinkedList for debug.
// @in list: The LinkedList to print.
void linked_list_print(LinkedList *list);


#endif
