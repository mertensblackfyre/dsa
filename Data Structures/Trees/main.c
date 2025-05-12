#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
  TreeNode *root = NULL;

  bst_insert(&root, root, 4);
  bst_insert(&root, root, 3);
  bst_insert(&root, root, 6);
  bst_insert(&root, root, 2);
  bst_insert(&root, root, 5);
  bst_insert(&root, root, 7);

  traverse_pre(root);
  printf("\n");
};
