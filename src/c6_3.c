/**
 * @file c6_3.c
 * @author lancer (you@domain.com)
 * @brief 单源最短路径
 * @version 0.1
 * @date 2023-12-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 6
#define INF 99999

int G[V][V] = {
    {0  , INF, 10 , INF, 30 , 100},
    {INF, 0  , 5  , INF, INF, INF},
    {INF, INF, 0  , 50 , INF, INF},
    {INF, INF, INF, 0  , INF, 10 },
    {INF, INF, INF, 20 , 0  , 60 },
    {INF, INF, INF, INF, INF, 0  },
};

typedef struct node {
    bool visited[V];       // 访问
    int dist[V];           // 距离
    int i;                 // 节点
} node;

int dist[V];
int parent[V];

node* queue[100];
int front = -1, rear = -1;


void node_init(node* np, bool v[V], int d[V], int NO) {
    np->i = NO;
    if(!v || !d) {
        for(int i=0; i<V; i++) {
            np->visited[i] = false;
            np->dist[i] = INF;
        }
        np->dist[NO] = 0;
    }else {
        for(int i=0; i<V; i++) {
            np->visited[i] = v[i];
            np->dist[i] = d[i];
        }
    }
    np->visited[NO] = true;
}


void bfs() {
    // 1. 初始化
    int src = 0;
    for(int i=0; i<V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;
    parent[src] = src;
    node* root = (node*)malloc(sizeof(node));
    node_init(root, NULL, NULL, src);
    queue[++rear] = root;
    // 2. bfs
    while(front != rear) {
        node* np = queue[++front];
        for(int j=0; j<V; j++) {
            if(!np->visited[j] && G[np->i][j] != INF)  {
                // 更新：剪枝
                if(np->dist[np->i] + G[np->i][j] < dist[j]) {
                    dist[j] = np->dist[np->i] + G[np->i][j];
                    parent[j] = np->i;
                    np->visited[j];
                    node* next = (node*)malloc(sizeof(node));
                    node_init(next, np->visited , dist, j);
                    queue[++rear] = next;
                }
            }
        }
    }
}


void print_res() {
    for(int i=0; i<V; i++) {
        printf("%d ", dist[i]);
    }
}


int main() {
    printf("c6_3: ");
    bfs();
    print_res();
    printf("\n");
    return 0;
}