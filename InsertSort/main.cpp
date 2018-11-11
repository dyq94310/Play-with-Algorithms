#include <iostream>
#include "InsertSortMethod.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;


//插入排序
int main() {


    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 1, n);
    int *arrb = SortTestHelper::copyArray(arr, n);

    SortTestHelper::testSort("RandomArray:InsertSort", InsertSortMethod::insertSort, arr, n);
    SortTestHelper::testSort("RandomArray:SelectionSore", SelectionSort::selectionSort, arrb, n);

    SortTestHelper::testSort("DescArray:InsertSort", InsertSortMethod::insertSort, arr, n);
    SortTestHelper::testSort("DescArray:SelectionSore", SelectionSort::selectionSort, arr, n);

    int *arrc = SortTestHelper::generateAscArray(n, 0);
    int *arrd = SortTestHelper::copyArray(arrc, n);

    SortTestHelper::testSort("AscArray:InsertSort", InsertSortMethod::insertSort, arrc, n);
    SortTestHelper::testSort("AscArray:SelectionSore", SelectionSort::selectionSort, arrd, n);
    return 0;

    /*
    * 输出结果：1.选择排序稳定
     * 2.插入排序：最好和最差相差巨大。
     * 做好：线性n
     * 最差：最差情况下比选择排序还要差。我怀疑是做了很多的数组移动。
    * RandomArray:InsertSort:7.776s
    * RandomArray:SelectionSore:11.995s
    * DescArray:InsertSort:0s
    * DescArray:SelectionSore:12.039s
    * AscArray:InsertSort:15.429s
    * AscArray:SelectionSore:12.483s
    *
    */
}