#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Dnode {
	element data;
	struct Dnode* llink;
	struct Dnode* rlink;
} Dnode;

static element count = 0;

void error(char* message) 
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(Dnode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void display(Dnode* phead)
{
	Dnode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) 
		printf("<- %d ->", p->data);
	printf("\n");
}

Dnode* create(element data)
{
	Dnode* new_node;
	new_node = (Dnode *)malloc(sizeof(Dnode));
	new_node->data = data;
	new_node->llink = NULL;
	new_node->rlink = NULL;
	
	return new_node;
}

Dnode* node_which(Dnode* pnode, int num)
{
	int i;
	if (num == (count + 1)) {
		pnode = pnode->llink;	
	}
	else if (num <= (count+1) / 2) {
		for (i = 0; i < num - 1; i++)
			pnode = pnode->rlink;
	}
	else {
		for (i = 0; i < 2 + (count - num); i++)
			pnode = pnode->llink;
	}
	return pnode;
}

void dinsert_node(Dnode* p, Dnode* new_node, int num)
{
	if (num > count + 1)
		error("총 노드보다 높은 수를 입력\n");
	if (num == 1) {
		new_node->llink = p;
		new_node->rlink = p->rlink;
		p->rlink->llink = new_node;
		p->rlink = new_node;
	}
	else {
		Dnode* pnode = node_which(p, num);
		new_node->llink = pnode;
		new_node->rlink = pnode->rlink;
		pnode->rlink->llink = new_node;
		pnode->rlink = new_node;
	}
	count++;
}

void dremove_node(Dnode* p, int num)
{
	Dnode* remove = node_which(p, num+1);
	if (p->llink == p->rlink)
		error("삭제할 노드가 없습니다.");
	else {
		count--;
		remove->llink->rlink = remove->rlink;
		remove->rlink->llink = remove->llink;
		free(remove);
	}
}

void main()
{
	Dnode head_node;
	init(&head_node);
	dinsert_node(&head_node, create(10), 1);
	dinsert_node(&head_node, create(20), 2);
	dinsert_node(&head_node, create(30), 2);
	dinsert_node(&head_node, create(40), 2);
	dinsert_node(&head_node, create(50), 3);
	dinsert_node(&head_node, create(60), 1);
	dremove_node(&head_node, 2);
	dremove_node(&head_node, 5);
	dremove_node(&head_node, 3);
	display(&head_node);
}	
