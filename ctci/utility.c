#include "ctci/utility.h"

#include <stdlib.h>

// Initialize a MemoryPool.
// @in pool_size: The size of the MemoryPool.
// @return: Pointer to the MemoryPool. NULL if any error on allocating
//   memory.
MemoryPool *memory_pool_init(size_t pool_size) {
  MemoryPool *pool = (MemoryPool *) malloc(sizeof(MemoryPool));
  if (NULL == pool) return NULL;

  pool->size = pool_size;
  pool->pool = malloc(pool->size);
  if (NULL == pool->pool) {
    free(pool);
    return NULL;
  }

  pool->head = pool->pool;
  return pool;
}

// Allocate memory from a MemoryPool.
// @in pool: The MemoryPool.
// @in size: The size of bytes.
// @return: Pointer to the memory. NULL if there is no enough memory.
void *memory_pool_alloc(MemoryPool *pool, size_t size) {
  size_t used_size = (char *)pool->head - (char *)pool->pool;
  if (used_size + size > pool->size) return NULL;

  void *result = pool->head;
  pool->head = (void *)((char *)pool->head + size);
  return result;
}

// Free a MemoryPool.
// @in pool: The MemoryPool to free.
// @return: NULL.
MemoryPool *memory_pool_free(MemoryPool *pool) {
  free(pool->pool);
  free(pool);
  return NULL;
}


// Compare two ints by pointers to them.
// @in a: Pointer the int a.
// @in b: Pointer the int b.
// @return: If a < b return -1. If a == b return 0. If a > b return 1.
int int_compare_by_pointer(void *pa, void *pb) {
  int a = *(int *)pa;
  int b = *(int *)pb;
  if (a < b) return -1;
  else if (a == b) return 0;
  else return 1;
}
