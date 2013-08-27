#include <assert.h>

#include "ctci/utility.h"

void test_memory_pool() {
  MemoryPool *pool = memory_pool_init(10);
  assert(memory_pool_alloc(pool, 2) == pool->pool);
  assert((char*)memory_pool_alloc(pool, 8)-(char*)pool->pool == 2);
  assert(NULL == memory_pool_alloc(pool, 1));
  memory_pool_free(pool);
}

int main() {
  test_memory_pool();
  return 0;
}
