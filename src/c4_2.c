/**
 * @file c4_2.c
 * @author lancer (lancerstadium@163.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-28
 * 
 * @copyright Copyright (c) 2023
 * 
 * # 单源最短路径问题：贪心算法
 * Dijkstra
 */

#include <stdio.h>
#include <stdbool.h>

#define V 6 /** 节点数 */
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
    {0  , INF, 10 , INF, 30 , 100},
    {INF, 0  , 5  , INF, INF, INF},
    {INF, INF, 0  , 50 , INF, INF},
    {INF, INF, INF, 0  , INF, 10 },
    {INF, INF, INF, 20 , 0  , 60 },
    {INF, INF, INF, INF, INF, 0  },
};


bool visited[V];    /** 访问节点 */
int distance[V] = {INF, INF, INF, INF, INF, INF};
int path[V] = {-1, -1, -1, -1, -1, -1};

void dijkstra(int src) {
    // 初始化源
    path[src] = src;       
    distance[src] = 0;

    for(int i=0; i < V; i++) {
        // 1. 找到距离最小节点
        int min_dist = INF, u;
        for(int j = 0; j < V; j++) {
            if(!visited[j] && distance[j] < min_dist) {
                min_dist = distance[j];
                u = j;
            }
        }
        // 2. 加入点
        visited[u] = true;
        // printf("->%d", u);

        // 3. 更新路径
        for(int v = 0; v < V; v++) {
            if(distance[u] + G[u][v] < distance[v]) {
                distance[v] = distance[u] + G[u][v];
            }
        }
    }
}


void print_res() {
    for(int i=0; i<V; i++) {
        printf("%d ", distance[i]);
    }
}

int main() {
    printf("c4_2: ");
    dijkstra(0);
    print_res();
    printf("\n");
}




