#include <iostream>
#include "MaxHeap.h"
#include "IndexMaxHeap.h"
#include "SortTestHelper.h"

int main() {
    int n = 100;
//    auto *heap = new MaxHeap<int>(n);

    auto *heap = new IndexMaxHeap<int>(n);
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    for (int i = 0; i < n; ++i) {
        heap->insert(arr[i]);
    }

    cout << "size:" << heap->getSize() << endl;

    int *arrB = new int[n];

    for (int j = 0; j < n; ++j) {
        arrB[j] = heap->getMaxValue();
    }

    SortTestHelper::printArray(arrB, n);
//    SortTestHelper::sortAesTrue(arrB, n);
    return 0;
}