#include <assert.h>

#include "ctci/lists.h"
#include "ctci/utility.h"

void test_linked_list_pop_head() {
  MemoryPool *pool = memory_pool_init(sizeof(int) * 100);
  LinkedList *list = NULL;
  list = linked_list_append(list, memory_pool_alloc_int(pool, 1));
  list = linked_list_append(list, memory_pool_alloc_int(pool, 2));
  int *value = NULL;
  list = linked_list_pop_head(list, (void**)&value);
  assert(*value = 1);
  list = linked_list_pop_head(list, (void**)&value);
  assert(*value = 2);
  assert(NULL == list);
  assert(NULL == linked_list_pop_head(list, (void**)&value));
  list = linked_list_free(list);
  memory_pool_free(pool);
}

int main() {
  test_linked_list_pop_head();
  return 0;
}
