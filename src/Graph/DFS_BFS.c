#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1002

typedef struct _QueueType{
    int queue[MAX_VERTICES];
    int front, rear;
} QueueType;

typedef struct {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited_dfs[MAX_VERTICES];
int visited_bfs[MAX_VERTICES];

void init_queue(QueueType *q)
{
    q->front = q->rear;
}

int is_empty(QueueType *q)
{
    return (q->rear == q->front);
}

int is_full(QueueType *q)
{
    return (((q->rear)+1) % MAX_VERTICES) == q->front;
}

void enqueue(QueueType *q, int item)
{
    if(is_full(q)){
        fprintf(stderr, "Queue: Overflow");
        return;
    }
    q->queue[++(q->rear)%MAX_VERTICES] = item;
}

int dequeue(QueueType *q)
{
    if(is_empty(q)){
        fprintf(stderr, "Queue is empty");
        exit(1);
    }
    return q->queue[++(q->front)%MAX_VERTICES];
}

void init(GraphType *g)
{
    g->n = 1;
    for(int i = 0; i < MAX_VERTICES; i++)
        for(int j = 0; j < MAX_VERTICES; j++)
            g->adj_mat[i][j] = 0;
}

void insert_vertex(GraphType *g, int v)
{
    if((g->n+1) >= MAX_VERTICES){
        fprintf(stderr, "Overflow\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int start, int end)
{
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "Graph: vertex number error\n");
        return;
    }
    if(g->adj_mat[start][end] || g->adj_mat[end][start])
        return;
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType *g, int v)
{
    visited_dfs[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < g->n; i++){
        if(g->adj_mat[v][i] && visited_dfs[i] != 1)
            dfs_mat(g, i);
    }
}

void bfs_mat(GraphType *g, int v)
{
    QueueType *q = (QueueType *)malloc(sizeof(QueueType));

    init_queue(q);

    visited_bfs[v] = 1;
    printf("%d ", v);
    enqueue(q, v);
    while(!is_empty(q)){
        v = dequeue(q);
        for(int i = 0; i < g->n; i++)
            if(g->adj_mat[v][i] && visited_bfs[i] != 1){
                enqueue(q, i);
                printf("%d ", i);
                visited_bfs[i] = 1;
            }
    }
}

int main()
{
    int N, M, V, start, end;
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    init(g);

    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0; i < N; i++)
        insert_vertex(g, i);

    for(int i = 0; i < M; i++){
        scanf("%d %d", &start, &end);
        insert_edge(g, start, end);
    }
    dfs_mat(g, V);
    printf("\n");
    bfs_mat(g, V);
}