/**
 * @file c7_1.c
 * @author lancer (you@domain.com)
 * @brief 计算定积分
 * @version 0.1
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 * # 计算定积分：使用随机数法
 * interger(m, n);
 * y = x , (0 <= x < 1) => 0.5
 * y = x ^ 2 , (0 <= x < 1) => 0.3333333
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double f(double x) {
    return x * x;
}
double f2(double x) {
    return x;
}

double interger(int n_p) {
    int sum = 0;
    srand(time(NULL));    // 随机撒种
    for(int i=0; i < n_p; i++) {
        double x = (double)rand() / RAND_MAX; // 随机数x
        double y = (double)rand() / RAND_MAX; // 随机数y
        if(y <= f2(x)) {
            sum++;
        }
    }
    double res = (double)sum/n_p;
    return res;
}


int main() {
    printf("c7_1: ");
    double res = interger(100000);
    printf("%f", res);
    printf("\n");
    return 0;
}