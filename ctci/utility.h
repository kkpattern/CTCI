#ifndef CTCI_UTILITY_H
#define CTCI_UTILITY_H

#include <stddef.h>

typedef struct _MemoryPool {
  void *pool;
  void *head;
  size_t size;
} MemoryPool;

// Initialize a MemoryPool.
// @in pool_size: The size of the MemoryPool.
// @return: Pointer to the MemoryPool. NULL if any error on allocating
//   memory.
MemoryPool *memory_pool_init(size_t pool_size);

// Allocate memory from a MemoryPool.
// @in pool: The MemoryPool.
// @in size: The size of bytes.
// @return: Pointer to the memory. NULL if there is no enough memory.
void *memory_pool_alloc(MemoryPool *pool, size_t pool_size);

// Free a MemoryPool.
// @in pool: The MemoryPool to free.
// @return: NULL.
MemoryPool *memory_pool_free(MemoryPool *pool);


#endif
