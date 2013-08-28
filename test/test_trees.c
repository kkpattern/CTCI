#include <assert.h>

#include "ctci/trees.h"
#include "ctci/utility.h"

void test_binary_search_tree_init() {
  BinarySearchTree *tree = binary_search_tree_init(int_compare_by_pointer,
                                                   int_compare_by_pointer);
  assert(NULL == tree->root);
  assert(int_compare_by_pointer == tree->key_compare);
  assert(int_compare_by_pointer == tree->value_compare);
  tree = binary_search_tree_free(tree);
}

void test_binary_search_tree_insert() {
  BinarySearchTree *tree = binary_search_tree_init(int_compare_by_pointer,
                                                   int_compare_by_pointer);
  MemoryPool *pool = memory_pool_init(1000);
  assert(0 == binary_search_tree_insert(tree,
                                        memory_pool_alloc_int(pool, 1),
                                        NULL));
  void *value = NULL;
  assert(0 == binary_search_tree_find(tree,
                                      memory_pool_alloc_int(pool, 1),
                                      &value));
  assert(0 == binary_search_tree_insert(tree,
                                        memory_pool_alloc_int(pool, 2),
                                        NULL));
  assert(0 == binary_search_tree_find(tree,
                                      memory_pool_alloc_int(pool, 2),
                                      &value));


  pool = memory_pool_free(pool);
  tree = binary_search_tree_free(tree);
}

void test_binary_search_tree_find() {
  BinarySearchTree *tree = binary_search_tree_init(int_compare_by_pointer,
                                                   int_compare_by_pointer);
  MemoryPool *pool = memory_pool_init(1000);
  assert(0 == binary_search_tree_insert(tree,
                                        memory_pool_alloc_int(pool, 1),
                                        NULL));
  void *value = NULL;
  assert(0 == binary_search_tree_find(tree,
                                      memory_pool_alloc_int(pool, 1),
                                      &value));
  assert(1 == binary_search_tree_find(tree,
                                      memory_pool_alloc_int(pool, 2),
                                      &value));
  assert(0 == binary_search_tree_insert(tree,
                                        memory_pool_alloc_int(pool, 2),
                                        NULL));
  assert(0 == binary_search_tree_find(tree,
                                      memory_pool_alloc_int(pool, 2),
                                      &value));


  pool = memory_pool_free(pool);
  tree = binary_search_tree_free(tree);
}

int main() {
  test_binary_search_tree_init();
  test_binary_search_tree_insert();
  test_binary_search_tree_find();
  return 0;
}
