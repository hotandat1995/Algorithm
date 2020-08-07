#include "tree_lib.h"

tree_node *create_new_node(int data)
{
  tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));

  if (NULL == new_node)
  {
    printf("Can't allocate new node for tree!\n");
    return NULL;
  }

  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

bool add_new_node_to_tree(tree_node *root, int data)
{
  tree_node *curr;

  if (is_Empty(root))
  {
    printf("Tree is EMPTY!\n");
    return false;
  }

  /* Go to right*/
  if (curr->data > data)
  {
  }
  else
  {
  }

  return true;
}

bool is_Empty(tree_node *root)
{
  return (root == NULL);
}