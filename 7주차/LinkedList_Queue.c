#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode {
	element item;
	struct QueueNode *link;
} QueueNode;

typedef struct {
	QueueNode *front, *rear;
} QueueType;

int is_empty(QueueType *q)
{
	return (q->front == 0 && q->rear == 0);
}

void enqueue(QueueType *q, element item)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리를 할당할 수 없습니다.");
		return;
	}
	else {
		temp -> item = item;
		temp -> link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

element dequeue(QueueType *q)
{
	QueueNode *temp = q->front;
	element item;
	if (is_empty(q)) {
		fprintf(stderr, "큐가 비었습니다.");
		exit(1);
	}
	else {
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}

int main() 
{
	return 0;
}
