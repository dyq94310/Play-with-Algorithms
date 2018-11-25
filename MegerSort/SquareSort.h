//
// Created by dyq94 on 11/26/2018.
//
// 时间复杂度未O(n2)的排序算法
#ifndef MEGERSORT_SQUARESORT_H
#define MEGERSORT_SQUARESORT_H

#include <iostream>

using namespace std;

namespace SquareSort {
    //插入排序,降序
    template<typename T>
    void insertSort(T *arr, int n) {
        for (int i = 1; i < n; ++i) {
            T temp = arr[i];
            int j;

            //每一数都和前面的数值作比较
            for (j = i; ((j > 0) && (temp > arr[j - 1])); --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }

    template<typename T>
    void selectionSort(T a[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int maxIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (a[maxIndex] < a[j]) {
                    maxIndex = j;
                }
            }
            if (maxIndex > i) {
                swap(a[i], a[maxIndex]);
            }
        }
    }


    int step = 3;

    template<typename T>
    void shellSort(T *arr, int n) {
        //选取步长
        for (int h = n / step; h > 0; h = (h + 1) / step) {

            //选择头指针
            for (int i = 0; i < h; ++i) {
                //插入排序
                for (int j = i; j < n; j = j + h) {
                    //选择初始元素arr[i],arr[i+h],arr[i+2h]
                    T t = arr[j];
                    int insertIndex = j;
                    //与数组中之前的元素进行匹配：
                    // 当比前元素要大的时：
                    //  前一个数组完后移动。
                    // 当相等或小于的时候，在前一个位置进行插入
                    for (int k = j; k - h >= 0 && t > arr[k - h]; k = k - h) {
                        arr[k] = arr[k - h];
                        insertIndex = k - h;
                    }
                    arr[insertIndex] = t;
                }
            }
        }
    }

}

#endif //MEGERSORT_SQUARESORT_H
