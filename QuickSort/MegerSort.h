//
// Created by dyq94 on 11/28/2018.
//

#ifndef MEGERSORT_MEGERSORT_H
#define MEGERSORT_MEGERSORT_H


#include <iostream>
#include "SquareSort.h"

using namespace std;

namespace MegerSort {


    //左右两边的进行合并
    template<typename T>
    void __Meger(T *arr, int l, int mid, int r) {

        //创建一个临时空间，用于存放当前数组
        T *temp = new T[r - l + 1];

        for (int j = 0; j < r - l + 1; ++j) {
            temp[j] = arr[l + j];
        }

        //左指针
        int lx = 0;
        //右指针
        int rx = mid + 1 - l;
        //对[l,r]所有元素进行排序
        for (int i = 0; i < r - l + 1; ++i) {
            //如果左边已近到了mid+1,右边的元素依次放入剩下的空间就好
            if (lx + l > mid) {
                arr[l + i] = temp[rx];
                rx++;
                continue;
            }
            //如果右边已近到了r,左边的元素依次放入剩下的空间就好
            if (rx + l > r) {
                arr[l + i] = temp[lx];
                lx++;
                continue;
            }
            //判断左右两边的，lx rx 哪个大，选哪个放到排序位置位置
            if (temp[lx] > temp[rx]) {
                arr[l + i] = temp[lx];
                lx++;
            } else {
                arr[l + i] = temp[rx];
                rx++;
            }
        }
        delete[] temp;
    }


    //对arr数组的[L,r]区间内的进行归并排序
    template<typename T>
    void __MegerSort(T *arr, int l, int r) {
        //同一个元素不进行排序
        if (r - l <= 15) {
            SquareSort::insertSort(arr, l, r);
            return;
        }
        //二分mid：左边最后一个下标
        int mid = ((l + r) / 2);

        //对左右两边分别进行归并排序;
        __MegerSort(arr, l, mid);
        __MegerSort(arr, mid + 1, r);
        //只有第二个数组比第一个数组的尾部大时，才进行合并。
        if (arr[mid] < arr[mid + 1]) {
            //排序后左右两边进行合并
            __Meger(arr, l, mid, r);
        }
    }


    //归并排序 对数组arr的n个元素进行归并排序
    template<typename T>
    void MegerSort(T *arr, int n) {

        //归并排序
        __MegerSort(arr, 0, n - 1);
    }

    //归并排序 自底向上归并 使用迭代的方法
    template<typename T>
    void MegerSortBU(T *arr, int n) {

        //左右数组的长度，每次增加两倍
        for (int size = 1; size < n; size = 2 * size) {

            //需要每次移动两个size
            for (int i = 0; i + size < n; i += 2 * size) {
                //元素少于16个时，使用插入排序
                if (size <= 16) {
                    SquareSort::insertSort(arr, i, min(i + 2 * size - 1, n - 1));
                    continue;
                }

                //只有右边尾部比左边大的时候，才进行归并
                if (arr[i + size - 1] < arr[i + size]) {
                    //对左右两边的元素进行归并，因为是从底向上，所以一开始就是有序的
                    __Meger(arr, i, i + size - 1, min(i + 2 * size - 1, n - 1));
                }
            }
        }

    }
}


#endif //MEGERSORT_MEGERSORT_H
