//
// Created by dyq94 on 2018/11/8.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    //生成长度为n的随机数组，范围[rangl,rangR]
    int *generateRandomArray(int n, int rangL, int rangR) {
        assert(rangL <= rangR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangR - rangL + 1) + rangL;
        }
        return arr;
    }

    //数组个数n
    int *generateAscArray(int n, int swapTime) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int j = 0; j < swapTime; ++j) {
            int x = rand() % n;
            int y = rand() % n;
            swap(arr[x], arr[y]);
        }
        return arr;
    }

    //数组个数n
    int *generateDescArray(int n, int swapTime) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = n - i;
        }
        srand(time(NULL));
        for (int j = 0; j < swapTime; ++j) {
            int x = rand() % n;
            int y = rand() % n;
            swap(arr[x], arr[y]);
        }
        return arr;
    }


    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    void sortAesTrue(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            assert(arr[i] >= arr[i + 1]);
        }
    }


    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        sortAesTrue(arr, n);
    }

    template<typename T>
    T *copyArray(T *arr, int n) {
        T *t = new T[n];
        copy(arr, arr + n, t);
        return t;
    }
}


#endif //SELECTIONSORT_SORTTESTHELPER_H
