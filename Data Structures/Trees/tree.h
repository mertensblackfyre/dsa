#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

void traverse_pre(TreeNode *root);
void traverse_in(TreeNode *root);
void traverse_post(TreeNode *root);
TreeNode *node_create(int value);
void bst_insert(TreeNode **root, TreeNode *_root, int value);
TreeNode *bst_remove(TreeNode *_root, int value);

TreeNode *getSuccessor(TreeNode *curr);
#endif
