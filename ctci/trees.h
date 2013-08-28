#ifndef CTCI_TREES_H
#define CTCI_TREES_H


typedef struct _BinarySearchTreeNode {
  void *key;
  void *value;
  struct _BinarySearchTreeNode *left;
  struct _BinarySearchTreeNode *right;
} BinarySearchTreeNode;

// Allocate a BinarySearchTreeNode.
// @in value: The value of the node.
// @return: Pointer to the new node. NULL if any error on allocating memory.
BinarySearchTreeNode *binary_search_tree_node_alloc(void * key, void *value);

// Free a BinarySearchTreeNode and its children.
// @in node: The BinarySearchTreeNode to free.
// @return: NULL.
BinarySearchTreeNode *binary_search_tree_node_free(BinarySearchTreeNode *node);

typedef int (CompareFunction)(void *a, void *b);

typedef struct _BinarySearchTree {
  BinarySearchTreeNode *root;
  CompareFunction *key_compare;
  CompareFunction *value_compare;
} BinarySearchTree;

// Initialize a BinarySearchTree.
// @in compare: The function used to compare values.
// @return: Pointer to the new intialized tree. NULL if any error on allocating
//   memory.
BinarySearchTree *binary_search_tree_init(CompareFunction *key_compare,
                                          CompareFunction *value_compare);

// Insert a value into a BinarySearchTree with key. If the key is already
// exists, replace the value.
// @in tree: The tree into which the value is inserted.
// @in key: The key of inserted value.
// @in value: The inserted value.
// @return: 0 if the value is successfully inserted. 1 if any error on
//   allocating memory.
int binary_search_tree_insert(BinarySearchTree *tree, void *key, void *value);

// Find a value with key in a BinarySearchTree.
// @in tree: The tree to search.
// @in key: The key of value.
// @out value: The result value.
// @return: 0 if the value is found. 1 if the key does not exist.
int binary_search_tree_find(BinarySearchTree *tree, void *key, void **value);

// Free a BinarySearchTree.
// @in tree: The BinarySearchTree to free.
// @return: NULL
BinarySearchTree *binary_search_tree_free(BinarySearchTree *tree);

#endif
