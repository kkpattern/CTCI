// Remove duplicates from an unsorted linked list.
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "ctci/lists.h"
#include "ctci/utility.h"

void remove_duplicates_in_place(LinkedList *list) {
  if (NULL == list) return;

  LinkedList *tail = list;
  while (NULL != tail->next) tail = tail->next;

  LinkedList *test_node = tail;
  while (NULL != test_node) {
    while (NULL != test_node->next) {
      LinkedList *next = test_node->next;
      if (test_node->value > next->value) {
        // Switch two nodes.
        if (NULL != next->next) next->next->prev = test_node;
        if (NULL != test_node->prev) test_node->prev->next = next;
        next->prev = test_node->prev;
        test_node->next = next->next;
        test_node->prev = next;
        next->next = test_node;
      } else if (test_node->value == next->value) {
        // Found duplicates!
        if (NULL != test_node->prev) test_node->prev->next = next;
        next->prev = test_node->prev;
        test_node->next = NULL;
        linked_list_free(test_node);
        break;
      } else {
        break;
      }
    }
    test_node = test_node->prev;
  }
}

int main() {
  MemoryPool *pool = memory_pool_init(sizeof(100) * 100);
  LinkedList *list = NULL;
  list = linked_list_append(list, memory_pool_alloc_int(pool, 1));
  list = linked_list_append(list, memory_pool_alloc_int(pool, 2));
  list = linked_list_append(list, memory_pool_alloc_int(pool, 3));
  list = linked_list_append(list, memory_pool_alloc_int(pool, 2));
  list = linked_list_append(list, memory_pool_alloc_int(pool, 4));
  linked_list_print(list);
  remove_duplicates_in_place(list);
  linked_list_print(list);
  list = linked_list_free(list);
  memory_pool_free(pool);
  return 0;
}
