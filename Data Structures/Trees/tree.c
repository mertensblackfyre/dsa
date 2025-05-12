#include "tree.h"
#include <stdio.h>

void traverse_pre(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  printf("%d->", cursor->value);
  traverse_pre(cursor->left);
  traverse_pre(cursor->right);
}

void traverse_in(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  traverse_pre(cursor->left);
  printf("%d->", cursor->value);
  traverse_pre(cursor->right);
}

void traverse_post(TreeNode *root) {
  TreeNode *cursor = root;

  if (cursor == NULL)
    return;

  traverse_post(cursor->left);
  traverse_post(cursor->right);
  printf("%d->", cursor->value);
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
  if (*root == NULL) {
    *root = node;
    return;
  };

  if (_root == NULL) {
    return;
  };

  if (value < _root->value) {
    if (_root->left != NULL) {
      _root = _root->left;
      bst_insert(root, _root, value);
    }
    _root->left = node_create(value);
    return;
  };

  if (value > _root->value) {
    if (_root->right != NULL) {
      _root = _root->right;
      bst_insert(root, _root, value);
    }
    _root->right = node_create(value);
    return;
  };
};

TreeNode *bst_remove(TreeNode *_root, int value) {

  if (_root == NULL) {
    printf("root is null");
    return NULL;
  }

  if (_root->value < value) {
    _root->left = bst_remove(_root->left, value);
  } else if (_root->value > value) {

    _root->right = bst_remove(_root->right, value);
  } else {
    if (_root->left == NULL) {
      TreeNode *node = _root->right;
      _root = NULL;
      return node;
    }
    if (_root->right == NULL) {
      TreeNode *node = _root->left;
      _root = NULL;
      return node;
    }
    TreeNode * t = getSuccessor(_root);
    _root->value = t->value;
    _root->right = bst_remove(_root, t->value);
  }

  return _root;
};

TreeNode *getSuccessor(TreeNode *curr) {
  curr = curr->right;
  while (curr != NULL && curr->left != NULL)
    curr = curr->left;
  return curr;
}
