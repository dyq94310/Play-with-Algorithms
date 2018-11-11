//
// Created by dyq94 on 2018/11/11.
//

#ifndef BUBBLESORT_BUBBLESORT_H
#define BUBBLESORT_BUBBLESORT_H

#endif //BUBBLESORT_BUBBLESORT_H

#include <iostream>

using namespace std;

namespace BubbleSort {
    template<typename T>
    void bubbleSort(T *arr, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i + 1; ++j) {
                if (arr[j] < arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}