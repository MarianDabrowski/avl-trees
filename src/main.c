#include "node.h"
#include "avltree.h"


int main(void)
{
	AVLTree *avltree = newAVLTree();
	int i;
	for(i = 1; i < 2; ++i) insert(avltree, rand() % 100);

	printAVLTreePLR(avltree);
	deleteNode(avltree, 83);
	printAVLTreePLR(avltree);

	return 0;
}
