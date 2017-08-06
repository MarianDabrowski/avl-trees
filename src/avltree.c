#include "avltree.h"

void rotateLeft(AVLTree *avltree, Node *node)
{
  if(node && node->right) {

    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;

    if(node->right) node->right->parent = node;
    temp->parent = node->parent;
    node->parent = temp;

    if(temp->parent) {
      if(node == temp->parent->left) temp->parent->left = temp;
      else temp->parent->right = temp;
    }
    else avltree->root = temp;
  }
}

void rotateRight(AVLTree *avltree, Node *node)
{
  if(node && node->left) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;

    if(node->left) node->left->parent = node;
    temp->parent = node->parent;
    node->parent = temp;

    if(temp->parent) {
      if(node == temp->parent->left) temp->parent->left = temp;
      else temp->parent->right = temp;
    }
    else avltree->root = temp;
  } 
}

void printTreePLR(Node *node)
{
  if(node) {
    printNode(node);
    printTreePLR(node->left);
    printTreePLR(node->right);
  }
  else printNode(node);
}

void printAVLTreePLR(AVLTree *avltree)
{
  printTreePLR(avltree->root);
  printf("############################################################\n");
}

Node *findInorderSuccessor(Node *node)
{
  Node *successor = node->right;
  while(successor->left) successor = successor->left;
  return successor;
}

void insertBST(AVLTree *avltree, Node *node)
{
  bool inserted = false;
  int leftHeight, rightHeight;
  Node *itterator = avltree->root;
  if(isEmpty(avltree)) avltree->root = node;
  else {
    while(!inserted) {

      setHeights(itterator, &leftHeight, &rightHeight);
      if(itterator->data < node->data) {

        itterator->height = max(leftHeight, rightHeight + 1) + 1;

        if(itterator->right) itterator = itterator->right;
        else {
          itterator->right = node;
          node->parent = itterator;
          inserted = true;
        }
      }

      else if(itterator->data > node->data) {

        itterator->height = max(leftHeight + 1, rightHeight) + 1;
        
        if(itterator->left) itterator = itterator->left;
        else {
          itterator->left = node;
          node->parent = itterator;
          inserted = true;
        }
      }
      else inserted = true;
    }
  }
}

void insert(AVLTree *avltree, int value)
{
    if(findNode(avltree, value) == NULL) {
        Node *node = newNode(value);
        insertBST(avltree, node);
        if (isInserted(avltree, node)) balance(avltree, node);
        else free(node);
    }
}

void balance(AVLTree *avltree, Node *node)
{
  int leftHeight, rightHeight; 

  while(node) {
    setHeights(node, &leftHeight, &rightHeight);
    // left case
    if(leftHeight - rightHeight > 1) {
      setHeights(node->left, &leftHeight, &rightHeight);
      // left right
      if(leftHeight < rightHeight) {
        rotateLeft(avltree, node->left);
        setAccordingHeight(node->left->left);
        setAccordingHeight(node->left);
      }
      // left left
      rotateRight(avltree, node);
      setAccordingHeight(node);
      setAccordingHeight(node->parent);
    }
    // right case
    else if(rightHeight - leftHeight > 1) {
      setHeights(node->right, &leftHeight, &rightHeight);
      // right left
      if(leftHeight > rightHeight) {
        rotateRight(avltree, node->right);
        setAccordingHeight(node->right->right);
        setAccordingHeight(node->right);
      }
     
      // right right
      rotateLeft(avltree, node);
      setAccordingHeight(node);
      setAccordingHeight(node->parent);

    }
    else setAccordingHeight(node);
    node = node->parent;
  }
}

Node *findNode(AVLTree *avltree, int value)
{
  Node *node = NULL, *itterator = avltree->root;
  while(node == NULL && itterator) {
    if(itterator->data < value) itterator = itterator->right;
    else if(itterator->data > value) itterator = itterator->left;
    else node = itterator;
  }
  return node;
}

void deleteNode(AVLTree *avltree, int value)
{
  Node *node = findNode(avltree, value), *successor = NULL, *temp;
  if(node) {
    if(node->left && node->right) {
      successor = findInorderSuccessor(node);
      node->data = successor->data;
      node = successor;
    }
    if(node->left || node->right) {
      temp = node->left;
      if(temp == NULL) temp = node->right;

      node->parent->left = temp;
      temp->parent = node->parent;
    }
    else {
      if(node->parent) node->parent->left = NULL;
      temp = node->parent;
    }
    if(node == avltree->root) avltree->root = NULL;
    free(node);
    balance(avltree, temp);
  }
}
