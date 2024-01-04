/**
 * @file c7_2.c
 * @author your name (you@domain.com)
 * @brief 计算圆周率
 * @version 0.1
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 * # 随机投点法计算圆周率
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double sqrt(double x) {
    return x * x;
}

double circle(double r, int n_p) {
    int sum = 0;
    srand(time(NULL));
    for(int i=0; i<n_p; i++) {
        double x = (double)rand() / RAND_MAX; 
        double y = (double)rand() / RAND_MAX; 
        if(sqrt(x) + sqrt(y) <= sqrt(r)) {
            sum++;
        }
    }
    double res = 4 * (double) sum / n_p;
    return res;
}


int main() {
    printf("c7_2: ");
    double res = circle(1, 100000);
    printf("%f", res);
    printf("\n");
    return 0;
}