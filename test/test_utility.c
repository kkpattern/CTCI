#include <assert.h>

#include "ctci/utility.h"

void test_memory_pool() {
  MemoryPool *pool = memory_pool_init(10);
  assert(memory_pool_alloc(pool, 2) == pool->pool);
  assert((char*)memory_pool_alloc(pool, 8)-(char*)pool->pool == 2);
  assert(NULL == memory_pool_alloc(pool, 1));
  memory_pool_free(pool);
}

void test_int_compare_by_pointer() {
  int a = 1;
  int b = 2;
  assert(-1 == int_compare_by_pointer(&a, &b));
  a = 2;
  assert(0 == int_compare_by_pointer(&a, &b));
  a = 3;
  assert(1 == int_compare_by_pointer(&a, &b));
}

int main() {
  test_memory_pool();
  test_int_compare_by_pointer();
  return 0;
}
