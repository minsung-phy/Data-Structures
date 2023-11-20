#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
} element;

typedef struct treeNode* treePointer;
typedef struct treeNode {
	treePointer leftChild;
	element data;
	short int bf;
	treePointer rightChild;
} treeNode;

void leftRotation(treePointer* parent, int* unbalanced);
void rightRotation(treePointer* parent, int* unbalanced);

void avlInsert(treePointer* parent, element x, int* unbalanced)
{
	if (!*parent) {
		*unbalanced = TRUE;
		*parent = (treePointer)malloc(sizeof(treeNode));
		(*parent)->leftChild = (*parent)->rightChild = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}
	else if (x.key < (*parent)->data.key) {
		avlInsert(&((*parent)->leftChild), x, unbalanced);
		if (*unbalanced)
			switch ((*parent)->bf) {
				case -1:
					(*parent)->bf = 0;
					*unbalanced = FALSE;
					break;
				case 0:
					(*parent)->bf = 1;
					break;
				case 1:
					leftRotation(parent, unbalanced);
					break;
			}
	}
	else if (x.key > (*parent)->data.key) {
		avlInsert(&((*parent)->rightChild), x, unbalanced);
		if (*unbalanced)
			switch ((*parent)->bf) {
				case 1: 
					(*parent)->bf = 0;
					*unbalanced = FALSE;
					break;
				case 0:
					(*parent)->bf = -1;
					break;
				case -1:
					rightRotation(parent, unbalanced);
					break;
			}
	}
	else {
		*unbalanced = FALSE;
		printf("The key is already in the tree\n");
	}
}

void leftRotation(treePointer* parent, int* unbalanced)
{
	treePointer grandChild, child;
	child = (*parent)->leftChild;
	if (child->bf == 1) { /* LL rotation */
		(*parent)->leftChild = child->rightChild;
		child->rightChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else { /* LR rotation */
		grandChild = child->rightChild;
		child->rightChild = grandChild->leftChild;
		grandChild->leftChild = child;
		(*parent)->leftChild = grandChild->rightChild;
		grandChild->rightChild = *parent;
		switch (grandChild->bf) {
			case 1:
				(*parent)->bf = -1;
				child->bf = 0;
				break;
			case 0:
				(*parent)->bf = child->bf = 0;
				break;
			case -1:
				(*parent)->bf = 1;
				child->bf = 0;
				break;
		}
		*parent = grandChild;
	}
	(*parent)->bf = 0;
	*unbalanced = FALSE;
}

void rightRotation(treePointer* parent, int* unbalanced)
{
	treePointer grandChild, child;
	child = (*parent)->rightChild;
	if (child->bf == -1) { /* RR rotation */
		(*parent)->leftChild = child->leftChild;
		child->leftChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else { /* RL rotation */
		grandChild = child->leftChild;
		child->leftChild = grandChild->rightChild;
		grandChild->rightChild = child;
		(*parent)->rightChild = grandChild->leftChild;
		grandChild->leftChild = *parent;
		switch (grandChild->bf) {
			case -1: 
				(*parent)->bf = 1;
				child->bf = 0;
				break;
			case 0:
				(*parent)->bf = child->bf = 0;
				break;
			case 1:
				(*parent)->bf = 0;
				child->bf = -1;
				break;
		}
		*parent = grandChild;
	}
	(*parent)->bf = 0;
	*unbalanced = FALSE;
}

int main()
{
}	
