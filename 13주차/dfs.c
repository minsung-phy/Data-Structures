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

void dfs_list(GraphType* g, int v)
{
	GraphNode* w;
	visited[v] = TRUE;
	printf("%d ", v);
	for (w = g->adj_list[v]; w; w = w->link) {
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
	}
}

void main()
{
	int i;
	GraphType g;
	
	graph_init(&g);
	
	for (i = 0; i < 4; i++)
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
	dfs_list(&g, 0);
	printf("\n");
}
