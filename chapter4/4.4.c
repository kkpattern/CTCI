// Given a binary search tree, design an algorithm which creates a linked list
// of all the nodes at each depth.
#include <assert.h>

#include "ctci/lists.h"
#include "ctci/trees.h"
#include "ctci/utility.h"

LinkedList *nodes_at_each_depth(BinarySearchTree *tree) {
  LinkedList *nodes_list = NULL;
  if (NULL != tree->root) return NULL;

  int current_nodes = 0;
  LinkedList *current_nodes_list = NULL;
  current_nodes_list = linked_list_append(current_nodes_list, tree->root);
  ++current_nodes;
  while (current_nodes > 0) {
    LinkedList *nodes = NULL;
    int new_nodes = 0;
    while (current_nodes > 0) {
      BinarySearchTreeNode *n = NULL;
      linked_list_pop_head(current_nodes_list, (void **)&n);
      nodes = linked_list_append(nodes, n);

      if (NULL != n->left) {
        linked_list_append(current_nodes_list, n->left);
        ++new_nodes;
      }
      if (NULL != n->right) {
        linked_list_append(current_nodes_list, n->right);
        ++new_nodes;
      }
    }
    current_nodes = new_nodes;
    nodes_list = linked_list_append(nodes_list, nodes);
  }
  current_nodes_list = linked_list_free(current_nodes_list);
  return nodes_list;
}

int main() {
  MemoryPool *pool = memory_pool_init(sizeof(int)*100);
  BinarySearchTree *tree = binary_search_tree_init(int_compare_by_pointer,
                                                   int_compare_by_pointer);

  LinkedList *nodes_list = nodes_at_each_depth(tree);

  nodes_list = linked_list_free(nodes_list);
  tree = binary_search_tree_free(tree);
  memory_pool_free(pool);
  return 0;
}
