#include <iostream>
#include "SortTestHelper.h"

using namespace std;

//把数组的[0,n]个元素排序：升序
template <typename T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    int n = 1000;
    int *arry = SortTestHelper::generateRandomArray(n, 1, n);
    selectionSort(arry, n);
    SortTestHelper::printArray(arry, n);
    delete[] arry;
    return 0;
}