//
// Created by dyq94 on 2018/11/11.
//

#ifndef INSERTSORT_SELECTIONSORT_H
#define INSERTSORT_SELECTIONSORT_H

#include <iostream>

using namespace std;

namespace SelectionSort {
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
}

#endif //INSERTSORT_SELECTIONSORT_H
