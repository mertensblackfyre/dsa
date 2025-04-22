#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;

} TreeNode;

void traverse_pre(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  printf("%d -> ", cursor->value);
  traverse_pre(cursor->left);
  traverse_pre(cursor->right);
}

TreeNode *node_create(int value) {
  TreeNode *node = malloc(sizeof(TreeNode));
  *node = (TreeNode){value, NULL, NULL};
  return node;
}

void bst_insert(TreeNode **root, TreeNode *_root, int value) {
  TreeNode *node = node_create(value);
  if (node == NULL) {
    printf("Error allocating memory");
    return;
  };
  node->value = value;
  if (root == NULL) {
    *root = node;
    return;
  };

  if (_root == NULL) {
    return;
  };
  if (value < _root->value) {
    while (_root->left != NULL && _root->right) {
      bst_insert(root, _root->left, value);
    };
    _root = node_create(value);
  };

  if (value > _root->value) {
    while (_root->left != NULL && _root->right) {
      bst_insert(root, _root->right, value);
    };
    _root = node_create(value);
  };

  // return root;
};

int main() {
  TreeNode *root = NULL;

  bst_insert(&root, root, 4);
  bst_insert(&root, root, 3);
  bst_insert(&root, root, 6);
  // bst_insert(&root, root, 2);

  // traverse_pre(root);
};
