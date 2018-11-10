#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

//选择排序，把数组的[0,n]个元素排序：升序
template<typename T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    int n = 200000;
    int *arr = SortTestHelper::generateRandomArray(n, 1, n);

    string str[] = {"a", "z", "c"};

    Student student[] = {{"AStu", 100},
                         {"BStu", 101},
                         {"CStu", 93}};
    selectionSort(student, 3);
    SortTestHelper::printArray(student, 3);

    SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

    delete[] arr;
    return 0;
}