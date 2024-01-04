/**
 * @file c3_3.c
 * @author lancer (lancerstadium@163.com)
 * @brief 0-1背包问题
 * @version 0.1
 * @date 2023-12-26
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 * 
 * # 0-1背包问题：动态规划
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8
#define C 50

#define MAX(a, b)  (((a) > (b)) ? (a) : (b))

int w[N+1];
int v[N+1];
int dp[N+1][C+1];

int bag_prob_dp(int w[], int v[]) { /** dp[N+1][C+1] */
    // 处理边界
    // 填表
    for(int i = 1; i <= N; i++) {       // 物品编号`i`
        for(int j = 1; j <= C; j++) {   // 剩余容量`j`
            if(w[i - 1] > j) {
                // 若超过背包容量，则不选物品 i
                dp[i][j] = dp[i - 1][j];
            } else {
                // 不选和选物品 i 这两种方案的较大值
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    return dp[N][C];
}


int main() {
    printf("c3_3:  w   v   | w   v");

    // 生成随机种子
    srand(time(0));
    // 生成随机的重量和价值
    for (int i = 0; i < N; i++) {  /** 数据 0~N-1 */
        w[i] = rand() % 100 + 1; // 随机生成1到100的重量
        v[i] = rand() % 100 + 1; // 随机生成1到100的价值
        if(i % 2 == 0) {
            printf("\n       %-3d %-3d", w[i], v[i]);
        }else{
            printf(" | %-3d %-3d", w[i], v[i]);
        }
    }

    int res = bag_prob_dp(w, v);
    printf("\n       Cap = %d, Value = %d\n", C, res);
    return 0;
}


