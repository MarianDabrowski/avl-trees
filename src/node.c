#include "node.h"

Node *newNode(int data)
{
 	Node *node = malloc(sizeof(Node));
 	if(node == NULL) exit(1);
 	node->data = data;
 	node->height = 1;
 	node->left = NULL;
 	node->right = NULL;
 	node->parent = NULL;
 	return node;
}