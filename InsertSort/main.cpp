#include <iostream>
#include "InsertSortMethod.h"
#include "SortTestHelper.h"


using namespace std;


//插入排序
int main() {
    int n = 100;
    int *arr = SortTestHelper::generateRandomArray(n, 1, 100);
    InsertSortMethod::insertSort(arr, n);
    SortTestHelper::printArray(arr, n);
    int *arrb = SortTestHelper::copyArray(arr, n);

    SortTestHelper::printArray(arrb, n);

    return 0;
}