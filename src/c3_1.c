/**
 * @file c3_1.c
 * @author lancer (lancerstadium@163.com)
 * @brief 矩阵连乘问题
 * @version 0.1
 * @date 2023-12-29
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 * 
 * # 矩阵连乘：动态规划
 * 
 */


#include <stdio.h>

#define N 6
#define INF 999999999
int r[N+1] = {10, 30, 5, 60, 10, 20, 25};
int dp[N+1][N+1];   // dp[i][j] 表示矩阵i到矩阵j的最小连乘次数
// 求解值：dp[1][N]


int muti_matrix() {
    
    for(int l = 2; l <= N; l++) {               // l 当前矩阵链长度
        for(int i = 1; i <= N - l + 1; i++) {   // i 起始位置
            int j = i + l - 1;                  // j 结束位置
            dp[i][j] = INF;
            for(int k = i ; k < j; k++) {       // k 分割点
                int t = dp[i][k] + dp[k+1][j] + r[i-1]*r[k]*r[j];
                if(t < dp[i][j]) {
                    dp[i][j] = t;
                }
            }
        }
    }

    return dp[1][N];
}


int main() {
    printf("c3_1: ");
    int res = muti_matrix();
    // 打印矩阵维度信息
    for (int i = 0; i <= N; i++) {
        printf("%d ", r[i]);
    }
    printf("Min matrix n is: %d\n", res);
    return 0;
}