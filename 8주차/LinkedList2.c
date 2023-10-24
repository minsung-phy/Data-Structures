#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* create_node(element data)
{
	ListNode* new_node = (ListNode* )malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "memory allocation error\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else 	
		p->link = removed->link;
	free(removed);
}

void display(ListNode* head)
{
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

void display_recur(ListNode* head)
{
	ListNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
	printf("\n");
}

ListNode* search(ListNode* head, int x)
{
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return p;
}

ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;
		while (p->link != NULL) 
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head)
{
	ListNode* p;
	ListNode* q;
	ListNode* r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main()
{
	ListNode* head1 = NULL;
	
	insert_node(&head1, head1, create_node(20));
	display(head1);
	insert_node(&head1, search(head1, 20), create_node(40));
	display(head1);
	insert_node(&head1, NULL, create_node(30));
	display(head1);
	
	printf("\n");
	head1 = reverse(head1);
	display(head1);
	
	return 0;
}
































