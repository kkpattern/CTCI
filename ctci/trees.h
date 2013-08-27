#ifndef CTCI_TREES_H
#define CTCI_TREES_H


typedef struct _BinarySearchTreeNode {
  void *value;
  struct _BinarySearchTreeNode *left;
  struct _BinarySearchTreeNode *right;
} BinarySearchTreeNode;

typedef int (CompareFunction)(void *a, void *b);

typedef struct _BinarySearchTree {
  BinarySearchTreeNode *root;
  CompareFunction *compare;
} BinarySearchTree;

// Initialize a BinarySearchTree.
// @in compare: The function used to compare values.
// @return: Pointer to the new intialized tree. NULL if any error on allocating
//   memory.
BinarySearchTree *binary_search_tree_init(CompareFunction *compare);

// Free a BinarySearchTree.
// @in tree: The BinarySearchTree to free.
// @return: NULL
BinarySearchTree *binary_search_tree_free(BinarySearchTree *tree);

#endif
