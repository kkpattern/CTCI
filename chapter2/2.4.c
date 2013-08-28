// Adds the two numbers and returns the sum as a linked list.
#include <stddef.h>

#include "ctci/lists.h"
#include "ctci/utility.h"

LinkedList *add(LinkedList *a, LinkedList *b, MemoryPool *pool) {
  LinkedList *result = NULL;
  int incre = 0;
  while (!(NULL == a && NULL == b)) {
    int sum = incre;
    if (NULL != a) {
      sum += *((int *)a->value);
      a = a->next;
    }
    if (NULL != b) {
      sum += *((int *)b->value);
      b = b->next;
    }
    int digit = sum % 10;
    incre = sum / 10;
    result = linked_list_append(result, memory_pool_alloc_int(pool, digit));
  }
  return result;
}

int main() {
  MemoryPool *pool = memory_pool_init(sizeof(100)*100);
  LinkedList *number_a = NULL;
  number_a = linked_list_append(number_a, memory_pool_alloc_int(pool, 3));
  number_a = linked_list_append(number_a, memory_pool_alloc_int(pool, 1));
  number_a = linked_list_append(number_a, memory_pool_alloc_int(pool, 5));
  linked_list_print(number_a);
  LinkedList *number_b = NULL;
  number_b = linked_list_append(number_b, memory_pool_alloc_int(pool, 5));
  number_b = linked_list_append(number_b, memory_pool_alloc_int(pool, 9));
  number_b = linked_list_append(number_b, memory_pool_alloc_int(pool, 2));
  number_b = linked_list_append(number_b, memory_pool_alloc_int(pool, 1));
  linked_list_print(number_b);
  LinkedList *result = add(number_a, number_b, pool);
  linked_list_print(result);
  linked_list_free(result);
  linked_list_free(number_b);
  linked_list_free(number_a);
  memory_pool_free(pool);
  return 0;
}
