#include <iostream>
#include "SortTestHelper.h"
#include "quickSort.h"
#include "MegerSort.h"

int main() {
    int n = 10000000;
    int *arr = SortTestHelper::generateRandomArray(n, 1, n);
    int *arrb = SortTestHelper::copyArray(arr, n);

//    quickSort::quickSort(arr, n);
//    SortTestHelper::printArray(arr, n);
//    SortTestHelper::sortAesTrue(arr, n);
    SortTestHelper::testSort("RandomArray:quickSort", quickSort::quickSort, arr, n);
    SortTestHelper::testSort("RandomArray:MegerSort", MegerSort::MegerSort, arrb, n);

    return 0;
}