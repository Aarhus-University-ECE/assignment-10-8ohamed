#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
if (t==NULL){

  t = malloc(sizeof(struct tree_node));
  t-> item = x;
  t->left = NULL;
  t->right = NULL;

  return t;
}

if (x<=t->item){
  t->left = Insert (x,t->left);
  return t;

}
if (x>t->item){
t->right = Insert (x,t->right);

  return t;
}

}


 struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

// 1. if x is not in tree, then return NULL

  if (t==NULL){
    return NULL;
  }

  // 2. if x is in tree and is a leaf node, then remove leaf node
  // 3. if x is not a leaf node and has either a left or a right child
  // 4. if x is not a leaf node and has both a leaf and a right child
 
  if (t->item > x)
  {
    t->left = Remove(x,t->left);
  }
  else if (t->item < x)
  {
    t->right = Remove(x,t->right);
  }
  else 
  {
    if (t->left == NULL) {
      return t->right;
    }

  else if (t->right == NULL)
    {
      return t->left;
    }

  else if (t->item==x) 
  {
    t=NULL;
  }
  return NULL;
}



int Contains(int x, struct tree_node *t) {
  if (t==NULL){
    return 0;
  }

  if (t->item == x)
  {
    /* code */
    return 1;
  }
  
  // Return true if the tree t contains item x. Return false otherwise.
 
  if (x > t->item)
  {
    return Contains (x,t->right);
  }
  if (x < t->item)
  {
    return Contains (x,t->left);
  }

  
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
    if (Full(t)==1) {
      t-> left = NULL;
      t-> right = NULL;
  }
  
  return NULL;
}

int Empty(struct tree_node *t) {
  // Test if empty
  if (t== NULL){
    return 1;
  }
    else
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  if (t==NULL){
  return 0;
  }
  else 
  return 1;
}
