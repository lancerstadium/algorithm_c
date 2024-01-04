/**
 * @file c2_1.c
 * @author lancer (lancerstadium@163.com)
 * @brief 二分搜索
 * @version 0.1
 * @date 2023-12-26
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 *
 * # 二分搜索
 * - 问题描述：在有序数组中查找某个元素
 * - 算法思想：二分查找，将查找区间缩小为一半，递归调用自身，直到找到目标元素。
 *
 */

#include <stdio.h>

/**
 * @brief 二分查找函数
 *
 * @param arr 数组
 * @param left 左索引
 * @param right 右索引
 * @param target 目标值
 * @return int 目标索引
 * # 二分查找算法思想：分治
 * ## Step1. 定义递归出口
 * ```c
 * if (left > right) {
 *     return -1;
 * }
 * ```
 * ## Step2. 找到中间值
 * ```c
 * int mid = (left + right) / 2;
 * ```
 * 
 * ## Step2. 递归
 * ```c
 * if (arr[mid] > target) {
 *     // 遍历左边
 *     return binary_search(arr, left, mid, target);
 * } else if (arr[mid] < target) {
 *     // 遍历右边
 *     return binary_search(arr, mid + 1, right, target);
 * } else {
 *     // 如果相等，之间输出索引
 *     return left;
 * }
 * 
 * ```
 */
int binary_search(double arr[], int left, int right, double target)
{
    if(left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (arr[mid] > target)
    {
        return binary_search(arr, left, mid, target);
    }
    else if (arr[mid] < target)
    {
        return binary_search(arr, mid + 1, right, target);
    }
    else
    {
        return left;
    }
}

int main()
{
    printf("c2_1: ");
    double arr[] = {2, 4, 6, 8, 10, 12, 14, 16}; /** 有序数组 `arr` */
    int target = 12;                           /** 目标元素 `target` */
    int index = binary_search(arr, 0, sizeof(arr)/sizeof(arr[0]), target);
    printf("target index: %d\n", index);
    return 0;
}