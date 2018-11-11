#include <iostream>
#include "InsertSortMethod.h"
#include "SelectionSort.h"
#include "SortTestHelper.h"
#include "BubbleSort.h"

using namespace std;

int main() {
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 1, n);
    SortTestHelper::testSort("BubbleSort", BubbleSort::bubbleSort, arr, n);

}