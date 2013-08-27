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
