#include <iostream>
#include "SquareSort.h"
#include "SortTestHelper.h"
#include "MegerSort.h"

int main() {
//    int n = 100000;
//    int *arr = SortTestHelper::generateRandomArray(n, 1, n);
//    int *arrb = SortTestHelper::copyArray(arr, n);
//    int *arrc = SortTestHelper::copyArray(arr, n);
//    int *arrd = SortTestHelper::copyArray(arr, n);
//
//    cout << "**************RandomArray**************" << endl;
//    SortTestHelper::testSort("RandomArray:InsertSort", SquareSort::insertSort, arr, n);
//    SortTestHelper::testSort("RandomArray:SelectionSore", SquareSort::selectionSort, arrb, n);
//    SortTestHelper::testSort("RandomArray:ShellSort", SquareSort::shellSort, arrc, n);
//    SortTestHelper::testSort("RandomArray:MergeSort", MegerSort::MegerSort, arrd, n);
//
//
//    cout << "**************DescArray**************" << endl;
//    SortTestHelper::testSort("DescArray:InsertSort", SquareSort::insertSort, arr, n);
//    SortTestHelper::testSort("DescArray:SelectionSore", SquareSort::selectionSort, arr, n);
//    SortTestHelper::testSort("DescArray:ShellSort", SquareSort::shellSort, arr, n);
//    SortTestHelper::testSort("DescArray:MergeSort", MegerSort::MegerSort, arr, n);
//
//    int *arrA = SortTestHelper::generateAscArray(n, 0);
//    int *arrB = SortTestHelper::copyArray(arrA, n);
//    int *arrC = SortTestHelper::copyArray(arrA, n);
//    int *arrD = SortTestHelper::copyArray(arrA, n);
//
//    cout << "**************AscArray**************" << endl;
//    SortTestHelper::testSort("AscArray:ShellSort", SquareSort::shellSort, arrC, n);
//    SortTestHelper::testSort("AscArray:InsertSort", SquareSort::insertSort, arrA, n);
//    SortTestHelper::testSort("AscArray:SelectionSore", SquareSort::selectionSort, arrB, n);
//    SortTestHelper::testSort("AscArray:MergeSort", MegerSort::MegerSort, arrD, n);


    /*
     * **************RandomArray**************
        RandomArray:InsertSort:8.219s
        RandomArray:SelectionSore:12.987s
        RandomArray:ShellSort:0.031s
        RandomArray:MergeSort:0.047s
        **************DescArray**************
        DescArray:InsertSort:0s
        DescArray:SelectionSore:12.391s
        DescArray:ShellSort:0.005s
        DescArray:MergeSort:0.02s
        **************AscArray**************
        AscArray:ShellSort:0.009s
        AscArray:InsertSort:16.639s
        AscArray:SelectionSore:14.328s
        AscArray:MergeSort:0.027s
     */

    //测试二
    int m = 50000000;
    int *BarrA = SortTestHelper::generateRandomArray(m, 1, m);
    int *BarrB = SortTestHelper::copyArray(BarrA, m);
    int *BarrC = SortTestHelper::copyArray(BarrA, m);
    SortTestHelper::testSort("AscArray:shellSort", SquareSort::shellSort, BarrA, m);
    SortTestHelper::testSort("AscArray:MergeSort", MegerSort::MegerSort, BarrB, m);
    SortTestHelper::testSort("AscArray:MergeSortBU", MegerSort::MegerSortBU, BarrC, m);
    /*
     * 差距较大
     *  AscArray:shellSort:49.545s
     *  AscArray:MergeSort:13.819s
     *  AscArray:MergeSortBU:15.264s
     */
    return 0;
}