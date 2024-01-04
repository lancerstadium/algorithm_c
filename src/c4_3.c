/**
 * @file c4_3.c
 * @author your name (you@domain.com)
 * @brief 最小生成树
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <stdio.h>
#include <stdbool.h>

#define V 7     /** 节点数 */
#define E 12    /** 边数 */
#define INF 9999999
#define MIN(a, b) (((a) < (b)) ? (a) : (b))


/** 无向图 */

int Edge[E][3] = {
    {0, 1, 23},
    {0, 5, 28},
    {0, 6, 36},
    {1, 2, 20},
    {1, 6, 1 },
    {2, 3, 15},
    {2, 6, 4 },
    {3, 4, 3 },
    {3, 6, 9 },
    {4, 5, 17},
    {4, 6, 16},
    {5, 6, 25}
};

int G[V][V];
bool v[V];
int dist[V];

void gen_graph() {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            G[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++) {
        G[Edge[i][0]][Edge[i][1]] = Edge[i][2];
        G[Edge[i][1]][Edge[i][0]] = Edge[i][2];
    }
}


int min_tree() {
    gen_graph();
    for(int i=0; i<V; i++) {
        v[i] = false;
        dist[i] = INF;
    }
    int src = 0;
    v[src] = true;
    dist[src] = 0;
    int sum =0;
    // 3. 更新距离
    for(int j =0; j<V; j++) {
        dist[j] = MIN(dist[j], G[0][j]);
    }
    int l_u = src;
    for(int i=0; i<V; i++) {
        // 1. 找到最小边连接点 u
        int u=-1, min_e=INF;
        for(int j=0; j<V; j++) {
            if(!v[j] && min_e > dist[j]) {
                u = j;
                min_e = dist[j];
            }
        }
        if(u==-1) {
            return INF;
        }
        // 2. 访问
        v[u] = true;
        sum += dist[u];
        printf("%d->%d[%d], ", l_u, u, dist[u]);
        l_u = u;
        // 3. 更新距离
        for(int j =0; j<V; j++) {
            dist[j] = MIN(dist[j], G[u][j]);
        }
    }
    return sum;
}

int main() {
    printf("c4_3: ");
    int res = min_tree();
    printf("\n");
    return 0;
}



