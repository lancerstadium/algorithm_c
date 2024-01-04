/**
 * @file c5_2.c
 * @author lancer (you@domain.com)
 * @brief 旅行商问题
 * @version 0.1
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 * # 旅行商问题：回溯法
 * 1. 当i==n时，当前遍历到了排列树的叶子节点的上一层节点(即n-1层)，
 *    这个时候要判断第n-1个点与第n个点以及第n个点与第1个点之间是否形成一条回路，
 *    如果形成一条回路，则可以判断当前回路的cost是否小于目前最优值，
 *    进而判断是否更新最优值和最优解。
 * 2. 当i<n的时候，还没有遍历到判断n个顶点是否形成回路。
 *    这个时候能够遍历当前节点的条件是当前节点i与上一节点i-1连通
 *    (即从第一个节点一直到第i个节点形成了一条路径)，
 *    并且这条路径的长度小于当前最优值，否则不遍历当前节点(约束函数)。
 * 
 */

#include <stdio.h>


#define V 4
#define E 6
#define INF 99999

int Edge[E][3] = {
    {1, 2, 30},
    {1, 3, 6},
    {1, 4, 4},
    {2, 3, 5},
    {2, 4, 10},
    {3, 4, 20},
};

int G[V+1][V+1];    // 邻接矩阵
int x[V+1];         // 解
int bestx[V+1];     // 最优解
int l = 0;          // 值
int bestl = INF;    // 最优值

void gen_graph() {
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            G[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++) {
        G[Edge[i][0]][Edge[i][1]] = Edge[i][2];
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init_tsp() {
    for(int i=1; i<=V; i++) {
        bestx[i] = i;
        x[i] = i;
    }
}

void tsp(int i) {
    // 1. 如果访问到n个节点,要判断是否形成回路
    if(i == V) {
        // 形成回路的条件就是x[n-1]与x[n]连通，x[n]与x[1]连通
        if(G[x[V-1]][x[V]] != INF && G[x[V]][x[1]] != INF) {
            // 如果当前值优于最优值，更新最优值和最优解
            // 或者bestl=INF说明还没有广搜到一条回路，那就先试着求出一个可行解
            if(l + G[x[V-1]][x[V]] + G[x[V]][x[1]] < bestl || bestl == INF) {
                for(int j=2; j<=V; j++){
                    bestx[j] = x[j];                        // 更新最优解
                }
                bestl= l + G[x[V-1]][x[V]] + G[x[V]][x[1]]; // 更新最优值
            }
        }
    } // 2. 否则继续寻找路线
    else {
        for(int j=i; j<=V; j++) {
            if((G[x[i-1]][x[j]] != INF && l + G[x[i-1]][x[j]] < bestl) || bestl == INF) {
                swap(&x[i], &x[j]);         // 交换
                l = l + G[x[i-1]][x[j]];    // 更新解
                tsp(i+1);                   // 进入i+1
                l = l - G[x[i-1]][x[j]];    // 回溯解
                swap(&x[i], &x[j]);         // 还原值
            }
        }
    }
}

void print_res() {
    for(int i=1; i<=V; i++) {
        printf("%d ", bestx[i]);
    }
    printf("length: %d\n", bestl);
}



int main() {
    printf("c5_2: ");
    gen_graph();
    init_tsp();
    tsp(2);
    print_res();
    return 0;
}

