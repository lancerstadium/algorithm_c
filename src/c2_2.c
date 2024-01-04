/**
 * @file c2_2.c
 * @author lancer (lancerstadium@163.com)
 * @brief 归并排序
 * @version 0.1
 * @date 2023-12-26
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 *
 * # 归并排序
 * - 问题描述：对有序数组进行排序
 * - 算法思想：归并排序，将数组分为两半，递归调用自身，然后合并，最后得到有序数组
 * - 时间复杂度：$ T(n)=O(nlogn) $
 *
 */

#include <stdio.h>


/**
 * @brief 双指针合并
 * 
 * @param arr 数组
 * @param left 左下标
 * @param mid 中间下标
 * @param right 右下标
 * 
 * # 双指针合并
 * 
 * 1. Step 1: 生成数组
 */
void merge(double arr[], int left, int mid, int right)
{
    int length = right - left + 1;
    double temp[length];
    int lp = left, rp = mid + 1, tp = 0;

    while (tp < length && lp <= mid && rp <= right)
    {
        if (arr[lp] < arr[rp])
        {
            temp[tp++] = arr[lp++];
        }
        else
        {
            temp[tp++] = arr[rp++];
        }
    }
    while (lp <= mid)
    {
        temp[tp++] = arr[lp++];
    }

    while (rp <= right)
    {
        temp[tp++] = arr[rp++];
    }

    tp--;
    while (tp >= 0)
    {
        arr[left + tp] = temp[tp];
        tp--;
    }

    // for (int i = 0; i < tp; i++) {           // 4. 将临时数组的元素放入原数组
    //     arr[left + i] = temp[i];
    // }
}

/**
 * @brief 归并排序
 * 
 * @param arr 数组
 * @param left 左下标
 * @param right 右下标
 * 
 * # 归并排序
 * 1. 指定递归退出条件：
 * ```c
 * if(left > right) {
 *   return;
 * }
 * ```
 * 2. 求中间值，递归：
 * ```
 * int mid = (left + right) / 2;
 * merge_sort(arr, left, mid);
 * merge_sort(arr, mid + 1, right);
 * ```
 * 
 * 3. 后续操作（归并）：
 * ```c
 * merge(arr, left, mid, right);
 * ```
 */
void merge_sort(double arr[], int left, int right)
{
    if(left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);

}

int main()
{
    printf("c2_2: sorted ");
    double arr[] = {10, 2, 4, 8, 1, 3, 7, 9, 15, -4}; /** 无序数组 arr */
    merge_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
    return 0;
}