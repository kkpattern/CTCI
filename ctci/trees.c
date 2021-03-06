#include "trees.h"

#include <stdlib.h>

// Initialize a BinarySearchTree.
// @in compare: The function used to compare values.
// @return: Pointer to the new intialized tree. NULL if any error on allocating
//   memory.
BinarySearchTree *binary_search_tree_init(CompareFunction *key_compare,
                                          CompareFunction *value_compare) {
  BinarySearchTree *tree = (BinarySearchTree *) malloc(
      sizeof(BinarySearchTree));
  if (NULL == tree) return NULL;

  tree->root = NULL;
  tree->key_compare = key_compare;
  tree->value_compare = value_compare;
  return tree;
}

// Allocate a BinarySearchTreeNode.
// @in value: The value of the node.
// @return: Pointer to the new node. NULL if any error on allocating memory.
BinarySearchTreeNode *binary_search_tree_node_alloc(void * key, void *value) {
  BinarySearchTreeNode *new_node = (BinarySearchTreeNode *) malloc(
      sizeof(BinarySearchTreeNode));
  if (NULL == new_node) return NULL;
  
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->key = key;
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

// Insert a value into a BinarySearchTree with key. If the key is already
// exists, replace the value.
// @in tree: The tree into which the value is inserted.
// @in key: The key of inserted value.
// @in value: The inserted value.
// @return: 0 if the value is successfully inserted. 1 if any error on
//   allocating memory.
int binary_search_tree_insert(BinarySearchTree *tree, void *key, void *value) {
  BinarySearchTreeNode *new_node = binary_search_tree_node_alloc(key, value);
  if (NULL == new_node) return 1;

  BinarySearchTreeNode **insert_position = &(tree->root);
  BinarySearchTreeNode *parent = NULL;
  while (NULL != *insert_position) {
    int compare_result = tree->key_compare(new_node->key,
                                           (*insert_position)->key);
    if (0 == compare_result) {
      parent = (*insert_position)->parent;
      binary_search_tree_node_free(*insert_position);
      *insert_position = NULL;
    } else if (0 > compare_result) {
      parent = *insert_position;
      insert_position = &((*insert_position)->left);
    } else {
      parent = *insert_position;
      insert_position = &((*insert_position)->right);
    }
  }
  *insert_position = new_node;
  new_node->parent = parent;

  return 0;
}

// Find a value with key in a BinarySearchTree.
// @in tree: The tree to search.
// @in key: The key of value.
// @out value: The result value.
// @return: 0 if the value is found. 1 if the key does not exist.
int binary_search_tree_find(BinarySearchTree *tree, void *key, void **value) {
  int result = 1;
  BinarySearchTreeNode *test_node = tree->root;
  while (NULL != test_node) {
    int compare_result = tree->key_compare(key, test_node->key);
    if (0 == compare_result) {
      *value = test_node->value;
      result = 0;
      break;
    } else if (0 > compare_result) {
      test_node = test_node->left;
    } else {
      test_node = test_node->right;
    }
  }
  return result;
}

// Free a BinarySearchTree.
// @in tree: The BinarySearchTree to free.
// @return: NULL
BinarySearchTree *binary_search_tree_free(BinarySearchTree *tree) {
  tree->root = binary_search_tree_node_free(tree->root);
  free(tree);
  return NULL;
}
