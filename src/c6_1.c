/**
 * @file c6_1.c
 * @author lancer (lancerstadium@163.com)
 * @brief 最大团问题
 * @version 0.1
 * @date 2023-12-27
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 * 
 * # 最大团问题：分支限界法
 * - 问题描述：指在一个无向图中寻找一个完全子图，使得这个子图中的任意两个顶点都有一条边相连，并且这个完全子图的顶点数最大。
 * - 算法思想：分支限界法解决最大团问题思路：
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/** 图顶点数 */
#define V 5
#define INF 99999

/** 图 */
// int G[V][V] = {
//     {0, 1, 1, 0, 1},
//     {1, 0, 1, 1, 0},
//     {1, 1, 0, 1, 1},
//     {0, 1, 1, 0, 1},
//     {1, 0, 1, 1, 0}
// };

int G[V][V] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 1, 1, 1, 0}
};

// int G[V][V] = {
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 1, 1},
//     {0, 0, 0, 1, 1},
//     {0, 1, 1, 0, 0},
//     {0, 1, 1, 0, 0}
// };


int max_n;
bool v[V];


typedef struct node {
    bool v[V];
    int n;
    int i;
} node;


node* queue[100];
int front = -1, rear = -1;


void node_init(node* np, bool visit[V], int num, int NO) {
    np->n = num;
    np->i = NO;
    for(int i=0;i<V; i++) {
        np->v[i] = visit[i];
    }
    np->v[NO] = true;
}

void bfs(int src) {
    for(int i=0; i<V; i++) {
        v[i] = false;
    }
    v[src] = true;
    max_n = 0;
    node* root = (node*)malloc(sizeof(node));
    node_init(root, v, max_n + 1, src);
    queue[++rear] = root;
    while(rear != front) {
        node* np = queue[++front];
        for(int j=0; j<V; j++) {
            bool OK = true;
            for(int k=0; k<V; k++) {
                if(np->v[k] && G[j][k] == 0) {
                    OK = false;
                }
            }
            if(OK && max_n < (np->n)+1 && !np->v[j]) {
                max_n = np->n + 1;
                for(int i=0; i<V; i++) {
                    v[i] = np->v[i];
                }
                v[j] = true;
                node* next = (node*)malloc(sizeof(node));
                node_init(next, np->v, (np->n)+1, j);
                queue[++rear] = next;
            }
        }
    }
}



void print_res() {
    printf("Maximum Clique: [");
    for (int i = 0; i < V; i++) {
        if (v[i]) {
            printf("%d,", i);
        }
    }
    printf("], ");
    printf("Size: %d\n", max_n);
}


int main() {
    printf("c6_1: ");
    bfs(3);
    print_res();
    return 0;
}