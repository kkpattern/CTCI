// Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a
// given node in a binary search tree where each node has a link to its parent.
#include <assert.h>

#include "ctci/trees.h"
#include "ctci/utility.h"

BinarySearchTreeNode *pre_order_first(BinarySearchTreeNode *node) {
}

BinarySearchTreeNode *pre_order_next(BinarySearchTreeNode *node) {
  if (NULL != node->left) {
    return node->left;
  } else if (NULL != node->right) {
    return node->right;
  } else {
    BinarySearchTreeNode *parent = node->parent;
    while (NULL != parent) {
      if (NULL != parent->right) {
        if (node == parent->right) return NULL;
        else return parent->right;
      } else {
        parent = parent->parent;
      }
    }
    return parent;
  }
}

BinarySearchTreeNode *in_order_next(BinarySearchTreeNode *node) {
  if (NULL == node) return NULL;

  if (NULL != node->right) {
    BinarySearchTreeNode *node = node->right;
    while (NULL != node->left) {
      node = node->left;
    }
    return node;
  } else {
    if (NULL != node->parent && node == node->parent->right) return NULL;
    else return node->parent;
  }
}

BinarySearchTreeNode *post_order_next(BinarySearchTreeNode *node) {
  if (NULL == node->parent ||
      node->parent->right == node ||
      node->parent->right == NULL)
    return node->parent;

  BinarySearchTreeNode *next = node->parent->right;
  while (NULL != next->left) {
    next = next->left;
  }
  return next;
}

int main() {
  MemoryPool *pool = memory_pool_init(sizeof(int) * 100);

  BinarySearchTree *tree = binary_search_tree_init(
      int_compare_by_pointer, int_compare_by_pointer);
  int values[] = {3, 2, 4, 1};
  for (size_t i = 0; i < sizeof(values)/sizeof(int); ++i) {
    binary_search_tree_insert(
        tree, memory_pool_alloc_int(pool, values[i]), NULL);
  }
  assert(2 == *((int*)pre_order_next(tree->root)->key));
  assert(1 == *((int*)pre_order_next(tree->root->left)->key));
  assert(NULL == pre_order_next(tree->root->right));
  assert(4 == *((int*)pre_order_next(tree->root->left->left)->key));

  assert(4 == *((int*)in_order_next(tree->root)->key));
  assert(3 == *((int*)in_order_next(tree->root->left)->key));
  assert(NULL == in_order_next(tree->root->right));
  assert(2 == *((int*)in_order_next(tree->root->left->left)->key));

  assert(NULL == post_order_next(tree->root));
  assert(4 == *((int*)post_order_next(tree->root->left)->key));
  assert(3 == *((int*)post_order_next(tree->root->right)->key));
  assert(2 == *((int*)post_order_next(tree->root->left->left)->key));

  tree = binary_search_tree_free(tree);

  pool = memory_pool_free(pool);
  return 0;
}
