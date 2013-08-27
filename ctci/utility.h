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

// Allocate a int from a MemoryPool.
// @in pool: The MemoryPool.
// @in value: The value to initialize the int.
// @return: Pointer to the int. NULL if there is no enough memory.
int *memory_pool_alloc_int(MemoryPool *pool, int value);

// Free a MemoryPool.
// @in pool: The MemoryPool to free.
// @return: NULL.
MemoryPool *memory_pool_free(MemoryPool *pool);


// Compare two ints by pointers to them.
// @in a: Pointer the int a.
// @in b: Pointer the int b.
// @return: If a < b return -1. If a == b return 0. If a > b return 1.
int int_compare_by_pointer(void *a, void *b);


#endif
