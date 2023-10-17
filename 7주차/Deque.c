#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

typedef struct DequeType {
	DlistNode* head;
	DlistNode* tail;
} DequeType;

int is_empty(DequeType* dq)
{
	return (dq->head == NULL && dq->tail == NULL);
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink)
{
	DlistNode* new_node = (DlistNode *)malloc(sizeof(DlistNode));
	new_node->data = item;
	new_node->llink = llink;
	new_node->rlink = rlink;
	return new_node;
}

void add_rear(DequeType* dq, element item)
{
	DlistNode* new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) 
		dq->head = new_node;
	else
		dq->tail->rlink = new_node;
	dq->tail = new_node;
}

void add_front(DequeType* dq, element item)
{
	DlistNode* new_node = create_node(NULL, item, dq->head);
	if (is_empty(dq))
		dq->tail = new_node;
	else 
		dq->head->llink = new_node;
	dq->head = new_node;
}

int main()
{
	return 0;
}
