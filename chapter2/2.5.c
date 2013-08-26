// Given a circular linked list, returns node at the begining of the loop.
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "lists.h"

typedef struct _ListOfLinkedList {
  struct _ListOfLinkedList *next;
  LinkedList *value;
} ListOfLinkedList;

ListOfLinkedList *list_of_linked_list_alloc(LinkedList *value) {
  ListOfLinkedList *node = (ListOfLinkedList *) malloc(
      sizeof(ListOfLinkedList));
  node->next = NULL;
  node->value = value;
  return node;
}

ListOfLinkedList *list_of_linked_list_free(ListOfLinkedList *list) {
  while (NULL != list) {
    ListOfLinkedList *tmp = list->next;
    free(list);
    list = tmp;
  }
  return NULL;
}

// Given a circular linked list, returns node at the begining of the loop.
// @in list: The corrupt list.
// @out value: The begining of loop.
// @return: The new non-corrupt list.
void begining_of_loop(LinkedList *list, int *value) {
  ListOfLinkedList *list_of_linked_list = NULL;
  ListOfLinkedList *tail = NULL;
  while (NULL != list->next) {
    if (NULL == list_of_linked_list) {
      tail = list_of_linked_list = list_of_linked_list_alloc(list);
    } else {
      tail->next = list_of_linked_list_alloc(list);
      tail = tail->next;
    }
    LinkedList *tmp = list->next;
    list->next = NULL;
    list = tmp;
  }
  *value = list->value;
  ListOfLinkedList *p = list_of_linked_list;
  while (NULL != p->next) {
    p->value->next = p->next->value;
    p = p->next;
  }
  list_of_linked_list_free(list_of_linked_list);
}

int main() {
  LinkedList *list = NULL;
  list = linked_list_append(list, 1);
  list = linked_list_append(list, 2);
  list = linked_list_append(list, 3);
  list = linked_list_append(list, 4);
  list = linked_list_append(list, 5);
  // Construct a corrupt list.
  LinkedList *third_node = list->next->next;
  LinkedList *tail = list;
  while (NULL != tail->next) tail = tail->next;
  tail->next = third_node;

  int value = 0;
  begining_of_loop(list, &value);
  assert(3 == value);
  linked_list_print(list);

  linked_list_free(list);
}
