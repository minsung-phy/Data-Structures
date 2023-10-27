#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[20];
	int dist;
	struct ListNode* link;
} ListNode;
	
ListNode* create_node(char data[20], int dist)
{
	ListNode* new_node = (ListNode* )malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "memory allocation error\n");
		exit(1);
	}
	
	strcpy(new_node->data, data);
	new_node->dist = dist;
	new_node->link = NULL;
	
	return new_node;
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node, int dist)
{
	if ((*phead) == NULL) {
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
		p->dist = dist;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed, int dist)
{
	if (p == NULL) {
		*phead = (*phead)->link;
	}
	else {
		p->link = removed->link;
		p->dist = dist;
	}
	free(removed);
}

ListNode* search(ListNode* head, char data[20])
{
	ListNode* p = head;
	
	while (p != NULL) {
		if (!strcmp(p->data, data))
			return p;
		p = p->link;
	}
	return p;
}

void time(ListNode* start, ListNode* finish)
{
	ListNode* p = start;
	int t = 0; 
	while (p != finish) {
		t = t + (p->dist);
		p = p->link;
	}
	printf("\n");
	printf("From %s to %s: %d\n", start->data, finish->data, t);
	printf("\n");
}

void display(ListNode* head)
{
	ListNode* p = head;
	
	while (p != NULL) {
		printf("%s(%d) ", p->data, p->dist);
		p = p->link;
		if (p != NULL)
			printf("-> ");
	}
	printf("\n");
}

int main()
{
	ListNode* subway = NULL;
	
	insert_node(&subway, subway, create_node("Airport", 0), 0);
	display(subway);
	
	insert_node(&subway, search(subway, "Airport"), create_node("Aewol", 0), 20);
	display(subway);
	
	insert_node(&subway, search(subway, "Aewol"), create_node("Seogwipo", 0), 40);
	display(subway);
	
	insert_node(&subway, search(subway, "Seogwipo"), create_node("Seongsan", 0), 30);
	display(subway);
	
	time(search(subway, "Aewol"), search(subway, "Seongsan"));
	
	insert_node(&subway, search(subway, "Aewol"), create_node("Moseulpo", 30), 30);
	display(subway);
	
	time(search(subway, "Aewol"), search(subway, "Seongsan"));
	
	remove_node(&subway, search(subway, "Aewol"), search(subway, "Moseulpo"), 40);
	display(subway);

	return 0;
}
