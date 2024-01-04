/**
 * @file c4_1.c
 * @author your name (you@domain.com)
 * @brief 最优装载问题
 * @version 0.1
 * @date 2023-12-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * # 最优装载问题：贪心算法
 * 
 */

#include <stdio.h>
#include <stdbool.h>

#define N 5
#define C 12
#define INF 9999999

int w[N] = {8, 4, 2, 5, 7};

bool v[N];


void best_contain() {

    int sum=0;
    for(int i=0; i<N; i++) {
        int min_j = -1, min_c = INF;
        for(int j=0; j<N; j++) {
            if(min_c > w[j] && sum + w[j] <= C && !v[j]) {
                min_j = j;
                min_c = w[j];
            }
        }
        if(min_j!=-1) {
            v[min_j] = true;
            sum += min_c;
            printf("%d ", min_j);
        }
    }
}


int main() {
    printf("c4_1: select: ");
    best_contain();
    printf("\n");
    return 0;
}