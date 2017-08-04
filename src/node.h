/** @file
 * Interface of Node
 * @author Marian Dabrowski
 */

#ifndef __NODE_H__
#define __NODE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/**
  * Structure that represents the Node
  */
typedef struct Node {
    int data; ///< piece of data that the node contains
    int height; ///< node height
    struct Node *left; ///< left child of node
    struct Node *right; ///< right child of node
    struct Node *parent; ///< parent of node
} Node;

/**
 * Constructs a new instance of a node
 * @param[in] data: piece of data of the new instance of a node
 * @return new Node instance
 */
Node *newNode(int data);

/**
 * Prints the properties of a node to console as std output
 * @param[in] node: the node which properties will be printed
 */
static inline void printNode(Node *node)
{
	if(node) printf("Node: {Value: %d, height %d}\n", node->data, node->height);
	else printf("Node: {NULL, 0}\n");
}

#endif /*__NODE_H__*/