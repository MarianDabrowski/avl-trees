/** @file
 * Interface of AVL tree
 * @author Marian Dabrowski
 */

#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "node.h"
#include <assert.h>

/**
  * Structure that represents the AVLTree
  */
typedef struct AVLTree {
  Node *root; ///< the node witch is the root of a tree
} AVLTree;

/**
 * Returns the maximum of two integers
 * @param[in] val1: integer
 * @param[in] val2: integer
 * @return the maximum of two integers
 */
static inline int max(int val1, int val2)
{
	if(val1 > val2) return val1;
	return val2;
}

/**
 * Constructs a new instance of a AVLTree
 * @return a new instance of a AVLTree
 */
static inline AVLTree *newAVLTree()
{
	AVLTree *avltree = malloc(sizeof(AVLTree));
	assert(avltree != NULL);
	avltree->root = NULL;
	return avltree;
}

/**
 * Checks if the AVLTree is empty
 * @param[in] avltree: a instance of a AVLTree
 * @return if the avltree is empty
 */
static inline bool isEmpty(AVLTree *avltree)
{
	return (avltree->root == NULL);
}

/**
 * Checks if a node was inserted into a AVLTree
 * @param[in] avltree: the AVLTree where we check if the node is inserted
 * @param[in] node: node that we check if it was inserted
 * @return if the node is inserted into this avltree
 */
static inline bool isInserted(AVLTree *avltree, Node *node)
{
	return ((avltree->root == node) || (node->parent));
}

/**
 * Sets the variables leftHeight and rightHeight with according heights of
 * nodes children
 * @param[in] node: node that heights we want to discover
 * @param[in] leftHeight: parameter where we save the left height
 * @param[in] rightHeight: parameter where we save the right height
 */
static inline void setHeights(Node *node, int *leftHeight, int *rightHeight)
{
	*leftHeight = 0;
	*rightHeight = 0;
	if(node->left) *leftHeight = node->left->height;
	if(node->right) *rightHeight = node->right->height;
}

/**
 * Sets the node height attribute correctly
 * @param[in] node: node which height is set
 */
static inline void setAccordingHeight(Node *node)
{
	if(node) {
		int leftHeight, rightHeight;
		setHeights(node, &leftHeight, &rightHeight);
		node->height = max(leftHeight, rightHeight) + 1;
	}
}

/**
 * Rotates the tree left in the node position
 * @param[in] avltree: tree to be rotated
 * @param[in] node: node to be rotated
 */
void rotateLeft(AVLTree *avltree, Node *node);

/**
 * Rotates the tree right in the node position
 * @param[in] avltree: tree to be rotated
 * @param[in] node: node to be rotated
 */
void rotateRight(AVLTree *avltree, Node *node);

/**
 * Prints the avltree in preorder left right
 * @param[in] avltre: tree to be printed
 */
void printAVLTreePLR(AVLTree *avltre);

/**
 * Prints the node in preorder left right
 * @param[in] node: node to be printed
 */
void printTreePLR(Node *node);

/**
 * Inserts as if into a BST tree
 * @param[in] avltree: tree into which the node is to be inserted
 * @param[in] node: node to be inserted
 */
void insertBST(AVLTree *avltree, Node *node);

/**
 * Inserts a node into a AVLTree
 * @param[in] avltree: the tree into which we want to insert
 * @paramp[in] value: value that we insert
 */
void insert(AVLTree *avltree, int value);

/**
 * Find inoreder successor of a node
 * @param[in] node: node which successor we wish to find
 * @return the inoreder successor
 */
Node *findInorderSuccessor(Node *node);

/**
 * Restores the values of a AVLTree
 * @param[in] avltree: the avltree to be corrected
 * @param[in] node: node that was just inserted
 */
void balance(AVLTree *avltree, Node *node);

/**
 * Finds the pointer to a node
 * @param[in] avltree: the tree to look into
 * @param[in] value: the value to look for
 * @return the pointer to the node with value
 */
Node *findNode(AVLTree *avltree, int value);

/**
 * Deletes a value of a tree
 * @param[in] avltree: the tree where we want to delete the value
 * @param[in] value: the value we want to delete
 */
void deleteNode(AVLTree *avltree, int value);

#endif /*__AVLTREE_H__*/