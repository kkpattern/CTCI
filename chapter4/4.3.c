#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "ctci/trees.h"
#include "ctci/utility.h"

size_t _tree_height(BinarySearchTreeNode *node) {
  if (NULL == node) return 0;

  size_t left_height = _tree_height(node->left);
  size_t right_height = _tree_height(node->right);
  return (left_height > right_height ? left_height : right_height) +1;
}

size_t tree_height(BinarySearchTree *tree) {
  return _tree_height(tree->root);
}

BinarySearchTreeNode *_construct_minimal_height_tree(int sorted_array[],
                                                     int begin,
                                                     int end,
                                                     MemoryPool *pool) {
  if (begin > end) return NULL;

  int mid = (begin+end)/2;
  BinarySearchTreeNode *node = binary_search_tree_node_alloc(
      memory_pool_alloc_int(pool, sorted_array[mid]), NULL);
  node->left = _construct_minimal_height_tree(sorted_array, begin, mid-1, pool);
  node->right = _construct_minimal_height_tree(sorted_array, mid+1, end, pool);
  return node;
}

BinarySearchTree *construct_minimal_height_tree(int sorted_array[],
                                                int n,
                                                MemoryPool *pool) {
  BinarySearchTree *tree = binary_search_tree_init(int_compare_by_pointer,
                                                   int_compare_by_pointer);
  tree->root = _construct_minimal_height_tree(sorted_array, 0, n-1, pool);
  return tree;
}

int main() {
  MemoryPool *pool = memory_pool_init(sizeof(int)*100);
  int values[] = {1, 2, 3, 4, 5, 6, 7};
  BinarySearchTree *tree = construct_minimal_height_tree(
      values, sizeof(values)/sizeof(int), pool);
  assert(3 == tree_height(tree));
  memory_pool_free(pool);
  return 0;
}
