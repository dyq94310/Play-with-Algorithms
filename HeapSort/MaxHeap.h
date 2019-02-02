//
// Created by dyq94 on 1/31/2019.
//
#include <iostream>

using namespace std;

#ifndef HEAPSORT_HEAP_H
#define HEAPSORT_HEAP_H

template<typename T>
class MaxHeap {

private:
    int count;
    T *arry;

    //put the value up
    void shiftUp(int index) {
        while (index > 1 && arry[index] > arry[index / 2]) {
            swap(arry[index /= 2], arry[index]);
        }
    }

    //put the value down
    void shiftDown(int index) {

        while (2 * index <= count) {
            int swapIndex = 2 * index;

            //选取大的子节点
            if ((swapIndex + 1 < count) && arry[swapIndex + 1] > arry[swapIndex]) {
                swapIndex++;
            }
            if (arry[index] >= arry[swapIndex]) {
                break;
            }
            //位置更换后 修改index
            swap(arry[swapIndex], arry[index]);
            index = swapIndex;
        }
    }

public:

    explicit MaxHeap(int size) {
        arry = new T[size + 1];
        count = 0;
    }

    ~MaxHeap() {
        delete[] arry;
    }

    bool isEmpty() {
        return count == 0;
    }

    int getSize() {
        return count;
    }

    void insert(T item) {
        arry[count + 1] = item;
        shiftUp(count);

        count++;
    }

    T getMaxValue() {
        T temp = arry[1];
        arry[1] = arry[count];
        shiftDown(1);
        count--;
        return temp;
    }

    void printRowArray() {
        for (int i = 1; i <= count; ++i) {

            cout << arry[i] << " ";

            //换行显示
            if (i % 3 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
};


#endif //HEAPSORT_HEAP_H
