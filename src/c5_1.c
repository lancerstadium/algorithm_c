/**
 * @file c5_1.c
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
 * # 最大团问题：回溯法
 * - 问题描述：指在一个无向图中寻找一个完全子图，使得这个子图中的任意两个顶点都有一条边相连，并且这个完全子图的顶点数最大。
 * - 算法思想：回溯算法解决最大团问题思路：
 *      1. 从图中任选一个顶点作为起始点，将其加入当前团中；
 *      2. 逐个考察与当前团中的顶点相邻且未加入团中的顶点，直到无法再加入新的顶点，考虑两种情况：
 *          1. 若该顶点可以加入当前团，则将其加入当前团中；
 *          2. 若该顶点不可以加入当前团，则回溯到上一个顶点。
 *      3. 在递归搜索的过程中，记录最大的团的大小和对应的顶点集合。
 */

#include <stdio.h>
#include <stdbool.h>

/** 图顶点数 */
#define V 5

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

bool v[V];
int cli[V];
int max_cli[V];
int n = 0;
int max_n = 0;

void copy_cli() {
    max_n = n;
    for(int i = 0; i < V; i++) {
        max_cli[i] = cli[i];
    }
}

void dfs_cli(int i) {
    // 本质是 dfs，对于点 i
    if(i > V) {
        copy_cli();
        return;
    }
    bool OK = true; // `true` 代表进入左子树
    for(int j = 0; j < V; j++) {
        if(v[j] && !G[i][j]) {   // `j`已被选择且不与`i`相连
            // 结论：`i` 不能被选中
            OK = false;
            break;
        }
    }
    if(OK) {
        // 左子树：选中 `i`
        v[i] = true;
        cli[n++] = i;
        dfs_cli(i + 1);
        // 回溯
        --n;
    }
    // 右子树：不选中 `i`
    if(n + V - i > max_n) {
        v[i] = false;
        cli[n] = 0;
        dfs_cli(i + 1);
    }
}

void print_res() {
    printf("Maximum Clique: [");
    for (int i = 0; i < max_n; i++) {
        // if (v[i]) {
        //     printf("%d ", i);
        // }
        printf("%d,", max_cli[i]);
    }
    printf("], ");
    printf("Size: %d\n", max_n);
}


int main() {
    printf("c5_1: ");
    dfs_cli(0);
    print_res();
    return 0;
}


