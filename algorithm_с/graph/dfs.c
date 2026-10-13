#include "dfs.h"
#include <stdio.h>
#include <malloc.h>
#include "../linklist/queue.c"

#define MAXV 100
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];
int time;

typedef struct edgenode {
  int y;
  int weight;
  struct edgenode *next;
} edgenode;

typedef struct {
  edgenode *edges[MAXV+1];
  int degree[MAXV+1];
  int nvertices;
  int nedges;
  int directed;
} graph;

void initialize_graph(graph *g, bool directed) {
  int i;
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (i = 1; i <= MAXV; i++) {
    g->degree[i] = 0;
  }

  for (i = 1; i <= MAXV; i++) {
    g->edges[i] = NULL;
  }
}

void insert_edge(graph *g, int x, int y, bool directed) {
  edgenode *p;
  p = malloc(sizeof(edgenode));
  p->weight = 0;
  p-> y = y;
  p->next = g->edges[x];
  g->edges[x] = p;
  g->degree[x]++;
  if(!directed) {
    insert_edge(g, y, x, true);
  } else {
    g->nedges++;
  }
}

void red_graph(graph *g, bool directed) {
  int i;
  int m;
  int x, y;

  initialize_graph(g, directed);
  scanf("%d%d", &(g->nvertices), &m);

  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    insert_edge(g, x, y, directed);
  }
}

void print_graph(graph *g) {
  int i;
  edgenode *p;

  for (i = 1; i <= g->nvertices; i++) {
    printf("%d:", i);
    p = g-> edges[i];
    while (p != NULL) {
      printf("%d",p->y);
      p = p->next;
    }
    printf("\n");
  }
}

void initialize_search(graph *g) {
  time = 0;
  for (int i = 0; i <= g->nvertices; i++) {
    processed[i] = false;
    discovered[i] = false;
    parent[i] = -1;
  }
}

void bfs(graph *g, int start) {

  int v, y;
  edgenode *p;

}
