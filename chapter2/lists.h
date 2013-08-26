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


typedef struct _LinkedList {
  struct _LinkedList *prev;
  struct _LinkedList *next;
  int value;
} LinkedList;


// Allocate a linked list node.
LinkedList *linked_list_alloc(int value);

// Append a node to the LinkedList.
// @in list: The list to which the node is appended.
// @in value: The value of the node.
// @return: The new head of the LinkedList.
LinkedList *linked_list_append(LinkedList *list, int value);

// Free a LinkedList.
// @in list: The list to free.
// @return: NULL to clear the variable. E.g. 
//   list = linked_list_free(list);
LinkedList *linked_list_free(LinkedList *list);



#endif
