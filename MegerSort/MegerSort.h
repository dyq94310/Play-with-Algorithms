//
// Created by dyq94 on 11/28/2018.
//

#ifndef MEGERSORT_MEGERSORT_H
#define MEGERSORT_MEGERSORT_H


#include <iostream>

using namespace std;

namespace MegerSort {


    //左右两边的进行归并排序
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


    template<typename T>
    void __MegerSort(T *arr, int l, int r) {
        //同一个元素不进行排序
        if (l >= r) {
            return;
        }
        //二分mid：左边最后一个下标
        int mid = ((l + r) / 2);

        //对左右两边分别进行归并排序;
        __MegerSort(arr, l, mid);
        __MegerSort(arr, mid + 1, r);
        //排序后左右两边进行合并
        __Meger(arr, l, mid, r);
    }


    template<typename T>
    void MegerSort(T *arr, int n) {

        //归并排序
        __MegerSort(arr, 0, n - 1);
    }
}


#endif //MEGERSORT_MEGERSORT_H
