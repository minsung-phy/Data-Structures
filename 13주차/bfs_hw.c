#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) 
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "Graph: vertex's count over");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) 
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "Graph: vertex's number error");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

int visited[MAX_VERTICES] = {0};
	
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q) 
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

int is_full(QueueType* q)
{
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("Queue is full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("Queue is empty");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("Queue is empty");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

void bfs_list(GraphType* g, int v)
{
	GraphNode* w;
	
	QueueType q;
	init(&q);
	
	visited[v] = TRUE;
	printf("%d ", v);
	enqueue(&q, v);
	
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link)
			if (!visited[w->vertex]) {
				visited[w->vertex] = TRUE;
				printf("%d ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
}

void main()
{
	int i;
	GraphType g;
	
	graph_init(&g);
	for (i = 0; i < 6; i++)
		insert_vertex(&g);
	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 0);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 3, 0);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 1);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 3, 1);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 2);
	insert_edge(&g, 2, 5);
	insert_edge(&g, 5, 2);
	insert_edge(&g, 3, 4);
	insert_edge(&g, 4, 3);
	insert_edge(&g, 4, 5);
	insert_edge(&g, 5, 4);
	
	bfs_list(&g, 0);
	printf("\n");
}
