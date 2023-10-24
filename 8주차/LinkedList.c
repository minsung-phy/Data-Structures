#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* create_node(element data)
{
	ListNode* new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	
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
}

ListNode* search(ListNode* head, int x)
{
	ListNode* p;
	p = head;
	
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
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	
	insert_node(&head1, head1, create_node(10));
	display(head1);
	insert_node(&head1, search(head1, 10), create_node(20));
	insert_node(&head1, search(head1, 20), create_node(30));
	display(head1);
	remove_node(&head1, search(head1, 20), search(head1, 30));
	display(head1);
	
	insert_node(&head2, head2, create_node(40));
	display(head2);
	
	head3 = concat(head1, head2); 
	display(head3);
	
	return 0;
}
