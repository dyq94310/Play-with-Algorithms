#include <iostream>
#include "MaxHeap.h"
#include "SortTestHelper.h"

int main() {
    int n = 10000;
    auto *heap = new MaxHeap<int>(n);
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    for (int i = 0; i < n; ++i) {
        heap->insert(arr[i]);
    }

    cout << "size:" << heap->getSize() << endl;

    int *arrB = new int[n];

    for (int j = 0; j < n; ++j) {
        arrB[j] = heap->getMaxValue();
    }

    SortTestHelper::sortAesTrue(arrB, n);
    return 0;
}