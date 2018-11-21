#include <iostream>
#include "InsertSortMethod.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

int main() {
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 1, n);
    int *arrb = SortTestHelper::copyArray(arr, n);
    int *arrc = SortTestHelper::copyArray(arr, n);

    SortTestHelper::testSort("RandomArray:InsertSort", InsertSortMethod::insertSort, arr, n);
    SortTestHelper::testSort("RandomArray:SelectionSore", SelectionSort::selectionSort, arrb, n);
    SortTestHelper::testSort("RandomArray:ShellSort", ShellSort::shellSort, arrc, n);

    SortTestHelper::testSort("DescArray:InsertSort", InsertSortMethod::insertSort, arr, n);
    SortTestHelper::testSort("DescArray:SelectionSore", SelectionSort::selectionSort, arr, n);
    SortTestHelper::testSort("DescArray:ShellSort", ShellSort::shellSort, arr, n);

    int *arrA = SortTestHelper::generateAscArray(n, 0);
    int *arrB = SortTestHelper::copyArray(arrA, n);
    int *arrC = SortTestHelper::copyArray(arrA, n);

    SortTestHelper::testSort("AscArray:ShellSort", ShellSort::shellSort, arrC, n);
    SortTestHelper::testSort("AscArray:InsertSort", InsertSortMethod::insertSort, arrA, n);
    SortTestHelper::testSort("AscArray:SelectionSore", SelectionSort::selectionSort, arrB, n);
    return 0;

    /*
RandomArray:InsertSort:8.405s
RandomArray:SelectionSore:12.298s
RandomArray:ShellSort:0.027s
DescArray:InsertSort:0s
DescArray:SelectionSore:12.305s
DescArray:ShellSort:0.006s
AscArray:ShellSort:0.01s
AscArray:InsertSort:16.699s
AscArray:SelectionSore:12.776s
     */
}