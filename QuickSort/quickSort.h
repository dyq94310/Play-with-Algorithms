//
// Created by dyq94 on 1/31/2019.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H


#include <iostream>
#include "SquareSort.h"

using namespace std;

namespace quickSort {

    //use quicksort to find midle
    //return point where arr[l,p-1] < arr[point] ; arr[p+1,r]<arr[point]
    template<typename T>
    int __patition(T *arr, int l, int r) {
        swap(arr[rand() % (r - l + 1) + l], arr[l]);
        T val = arr[l];

        int point = l;
        for (int i = l + 1; i <= r; ++i) {
            //only care greater than
            if (arr[i] > val) {
                point++;
                swap(arr[point], arr[i]);
            }
        }
        swap(arr[l], arr[point]);
        return point;
    }

    //qucikSort arr[l,r] use quickSort
    template<typename T>
    void __quickSort(T *arr, int l, int r) {

        //同一个元素不进行排序
        if (r - l <= 16) {
            SquareSort::insertSort(arr, l, r);
            return;
        }

        int point = __patition(arr, l, r);

        // l and R all use quickSort
        __quickSort(arr, l, point - 1);
        __quickSort(arr, point + 1, r);
    }

    //qucikSort public
    template<typename T>
    void quickSort(T *arr, int n) {
        srand(time(NULL));
        __quickSort(arr, 0, n);
    }
}

#endif //QUICKSORT_QUICKSORT_H
