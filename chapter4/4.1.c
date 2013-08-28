#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ctci/trees.h"
#include "ctci/utility.h"


// Retrun the balance a of BinarySearchTreeNode.
int tree_balance(BinarySearchTreeNode *node, int *height) {
  if (NULL == node) {
    *height = 0;
    return 0;
  }

  int balance = 0;
  int left_height = 0;
  int left_balance = tree_balance(node->left, &left_height);
  int right_height = 0;
  int right_balance = tree_balance(node->right, &right_height);
  if (left_height >= right_height) {
    *height = left_height+1;
    balance = left_height-(right_height-right_balance);
  } else {
    *height = right_height+1;
    balance = right_height-(left_height-left_balance);
  }
  return balance;
}

// Tell if a BinarySearchTree is balanced.
// @return: true if the BinarySearchTree is balanced. false otherwise.
bool tree_balanced(BinarySearchTree *tree) {
  int height = 0;
  if (2 > tree_balance(tree->root, &height)) return true;
  else return false;
}

int main() {
  MemoryPool *pool = memory_pool_init(sizeof(int) * 100);

  BinarySearchTree *tree = binary_search_tree_init(int_compare_by_pointer,
                                                   int_compare_by_pointer);
  binary_search_tree_insert(tree, memory_pool_alloc_int(pool, 2), NULL);
  binary_search_tree_insert(tree, memory_pool_alloc_int(pool, 1), NULL);
  binary_search_tree_insert(tree, memory_pool_alloc_int(pool, 3), NULL);
  int height = 0;
  assert(true == tree_balanced(tree));
  tree = binary_search_tree_free(tree);

  // Construct an almost balanced tree.
  tree = binary_search_tree_init(int_compare_by_pointer,int_compare_by_pointer);
  int keys[] = {5, 3, 6, 2, 4, 1};
  for (size_t i = 0; i < sizeof(keys)/sizeof(int); ++i) {
    binary_search_tree_insert(tree, memory_pool_alloc_int(pool, keys[i]), NULL);
  }
  assert(false == tree_balanced(tree));
  tree = binary_search_tree_free(tree);

  pool = memory_pool_free(pool);
}
