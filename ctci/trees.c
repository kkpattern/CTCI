#include "trees.h"

#include <stdlib.h>

// Initialize a BinarySearchTree.
// @in compare: The function used to compare values.
// @return: Pointer to the new intialized tree. NULL if any error on allocating
//   memory.
BinarySearchTree *binary_search_tree_init(CompareFunction *compare) {
  BinarySearchTree *tree = (BinarySearchTree *) malloc(
      sizeof(BinarySearchTree));
  if (NULL == tree) return NULL;

  tree->root = NULL;
  tree->compare = compare;
  return tree;
}

// Allocate a BinarySearchTreeNode.
// @in value: The value of the node.
// @return: Pointer to the new node. NULL if any error on allocating memory.
BinarySearchTreeNode *binary_search_tree_node_alloc(void *value) {
  BinarySearchTreeNode *new_node = (BinarySearchTreeNode *) malloc(
      sizeof(BinarySearchTreeNode));
  if (NULL == new_node) return NULL;
  
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->value = value;
  return new_node;
}

// Free a BinarySearchTreeNode and its children.
// @in node: The BinarySearchTreeNode to free.
// @return: NULL.
BinarySearchTreeNode *binary_search_tree_node_free(BinarySearchTreeNode *node) {
  if (NULL != node) {
    binary_search_tree_node_free(node->left);
    binary_search_tree_node_free(node->right);
    free(node);
  }
}

// Free a BinarySearchTree.
// @in tree: The BinarySearchTree to free.
// @return: NULL
BinarySearchTree *binary_search_tree_free(BinarySearchTree *tree) {
  tree->root = binary_search_tree_node_free(tree->root);
  free(tree);
  return NULL;
}
