/**
 * @file c5_3.c
 * @author lancer (you@domain.com)
 * @brief 批处理作业调度问题
 * @version 0.1
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * - 测试数据：
 * ```
 *  3
 *  2 3 2
 *  1 1 3
 * 
 *  3
 *  2 5 4
 *  3 2 1
 * ```
 */


#include <stdio.h>


#define N 3
#define INF 99999

int m[2][N] = {
    {2, 3, 2},
    {1, 1, 3}
};

int x[N];           // 解
int bestx[N];       // 最优解
int f1=0;           // 机器1完成处理时间
int f2=0;           // 机器2完成处理时间
int f=0;            // 值：完成时间和
int bestf=INF;      // 最优值：最优的完成时间和


void init_batch() {
    for(int i=0; i<N; i++) {
        x[i] = i;
        bestx[i] = i;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void backtrace(int i) {
    if(i > N) { // 到达叶子节点
        if(f < bestf) {
            for(int i = 0; i < 1; i++){
                bestx[i] = x[i];
                bestf = f;
            }
            return;
        }
    } else {    // 到达i节点
        int tempf;
        for(int j = i; j < N; j++) {
            f1 += m[0][j];  // 第 j 个作业置于机器1
            tempf = f2;     // 记录上个作业在机器2的完成时间
            f2 = (f1 > f2 ? f1 : f2) + m[1][x[j]];  // 保存当前作业在机器2的完成时间
            f += f2;        // 更新总时间
            // 总时间比最优时间小，继续搜索
            if(f < bestf)  {
                swap(&x[i], &x[j]);
                backtrace(i+1);
                swap(&x[i], &x[j]);
            }
            // 总时间已经超过最优时间，就直接回溯
            f -= f2;
            f2 = tempf;
            f1 -= m[0][j];
        }

    }
}

void print_res() {
    for(int i=0; i<N; i++) {
        printf("%d ", bestx[i]);
    }
    printf("time: %d\n", bestf);
}


int main() {
    printf("c5_3: ");
    init_batch();
    backtrace(0);
    print_res();
    return 0;
}