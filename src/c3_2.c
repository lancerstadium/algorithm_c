/**
 * @file c3_2.c
 * @author lancer (you@domain.com)
 * @brief 流水线作业调度问题
 * @version 0.1
 * @date 2023-12-28
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 * 
 * # 流水线作业调度问题：动态规划
 * - 问题描述：n个作业 N={1，2，…，n}要在2台机器M1和M2组成的流水线上完成加工。
 * 每个作业须先在M1上加工，然后在M2上加工。M1和M2加工作业 $i$ 所需的时间分别为 $a_i$ 和 $b_i$，
 * 每台机器同一时间最多只能执行一个作业。流水作业调度问题要求确定这n个作业的最优加工顺序，
 * 使得所有作业在两台机器上都加工完成所需最少时间。最优调度应该是？
 * ## 流水作业调度问题的Johnson算法
 * 1. 第一步：把作业的集合N={1,2,…,n}分为两个子集：N1和N2，令
 * 2. 第二步：将N1中作业依ai的非减序排序；将N2中作业依bi的非增序排序；
 * 3. 第三步：N1中作业接N2中作业构成满足Johnson算法的最优调度
 * 
 */

#include <stdio.h>
#include <stdbool.h>

#define N 5

int a[N] = {2,5,10,9,7};
int b[N] = {8,7,5,9,8};
//int a[N] = {0,5,12,4,8};
//int b[N] = {0,6,2,14,7};

int res[N];

int Job1[N][3];
int Job2[N][3];

int n1=0, n2=0;

void job_swap(int Jobv1[3], int Jobv2[3]) {
    int t1 = Jobv1[0], t2 = Jobv1[1], t3 = Jobv1[2];
    Jobv1[0] = Jobv2[0];
    Jobv1[1] = Jobv2[1];
    Jobv1[2] = Jobv2[2];
    Jobv2[0] = t1;
    Jobv2[1] = t2;
    Jobv2[2] = t3;
}


void job_sort(int Job[N][3], int n, bool up) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(Job[i][1] > Job[j][1] && up) {     // 顺序
                job_swap(Job[i], Job[j]);
            }
            if(Job[i][2] < Job[j][2] && !up) {     // 逆序
                job_swap(Job[i], Job[j]);
            }
        }
    }
}

void job_conact(int Job1[N][3], int n1, int Job2[N][3], int n2) {
    for(int i=0; i<n1; i++) {
        res[i]=Job1[i][0];
    }
    for(int i=n1; i<n1+n2; i++) {
        res[i]=Job2[i - n1][0];
    }
}

void schedule() {
    // 1. 分组
    for(int i=0; i<N; i++) {
        if(a[i] < b[i]){
            Job1[n1][0] = i;
            Job1[n1][1] = a[i];
            Job1[n1][2] = b[i];
            n1++;
        } else {
            Job2[n2][0] = i;
            Job2[n2][1] = a[i];
            Job2[n2][2] = b[i];
            n2++;
        }
    }

    // 2. N1递增排序，N2递减排序
    job_sort(Job1, n1, true);
    job_sort(Job2, n2, false);

    // 3. 合并
    job_conact(Job1, n1, Job2, n2);
}


int main() {
    printf("c3_2: ");
    schedule();
    for(int i = 0; i < N; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}