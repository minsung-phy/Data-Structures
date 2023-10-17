#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];	
	int front, rear;
} QueueType;

void init(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		fprintf(stderr, "Queue is full");
		return;
	}
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q)) {
		fprintf(stderr, "Queue is empty");
		exit(1);
	}
	element result = q->queue[q->front];
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return result;
}

int main() 
{
	return 0;
}
