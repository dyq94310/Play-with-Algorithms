//
// Created by dyq94 on 2018/11/10.
//

#ifndef INSERTSORT_INSERTSORT_H
#define INSERTSORT_INSERTSORT_H

#include <iostream>

using namespace std;

namespace InsertSortMethod {

    //插入排序,降序
    template<typename T>
    void insertSort(T arr[], int n) {
        for (int i = 1; i < n; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; ((j > 0) && (temp > arr[j - 1])); --j) {
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }
}


#endif //INSERTSORT_INSERTSORT_H
