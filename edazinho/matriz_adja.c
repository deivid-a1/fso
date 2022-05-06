#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int V;
    int E;
    int **adj;
} *Graph;
typedef struct Edge {
    int v;
    int w;
} *Edge;


int * pre;

Edge edge_init(int v, int w) {
    Edge E = malloc(sizeof(* E));
    E->v = v;
    E->w = w;

    return E;
}

Graph graph_init(int v) {
    Graph G = malloc(sizeof(* G));
    G->V = v;
    G->E = 0;
    G->adj = matrix_init(v, v, 0);

    return G;
}

int ** matrix_init(int l, int c, int init) {
    int ** matrix;

    matrix = (int **) calloc(l, sizeof(int *));

    for (int i = 0; i < l; i++) {
        matrix[i] = (int *) calloc(c, sizeof(int));
    }

    return matrix;
}

void graph_insert_edge(Graph G, Edge E) {
    int v = E->v;
    int w = E->w;

    if (G->adj[v][w] == 0) G->E++;

    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void graph_remove_edge(Graph G, Edge E) {
    int v = E->v;
    int w = E->w;

    if (G->adj[v][w] == 1) G->E--;

    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int graph_edges(Edge * a, Graph G) {
    int v, w, E = 0;

    for (v = 0; v < G->V; v++)
        for (w = v + 1; w < G->V; w++)
            if (G->adj[v][w] == 1)
                a[E++] = edge_init(v, w);
    
    return E;
}

void show_graph(Graph G) {
    int v, w;
    
    printf(" | ");
    for (int i = 0; i < G->V; i++)
        printf("%d| ", i);
    printf("\n");
    for (int i = 0; i <= G->V; i++)
        printf("---");

    printf("\n");

    for (v = 0; v < G->V; v++) {
        printf("%d| ", v);
        for (w = 0; w < G->V; w++)
            printf("%d| ", G->adj[v][w]);
        printf("\n");
    }
}

int cont = 0;
void dfsR(Graph G, Edge e) 
{
	int t, w = e->w;
	pre[w] = cont++;

	for (t = 0; t < G->V; t++)
		if (G->adj[w][t] != 0)
			if (pre[t] == -1)
				dfsR(G, edge_init(w, t));
}

void graph_search(Graph G) 
{
    int v;
    int conexos = 0;

    for(v = 0; v < G->V; v++) pre[v] = -1;

    for (v = 0; v < G->V; v++)
    {
        if(pre[v] == -1) 
        {
            dfsR(G, edge_init(v,v));
            conexos++;
        }
    }
}


int main() {
	int N, M, J;
 	Graph graph;
	Edge edge;
	graph = graph_init(N);

  return 0;  
}