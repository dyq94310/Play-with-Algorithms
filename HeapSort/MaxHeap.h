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
    T *date;

    //put the value up
    void shiftUp(int index) {
        while (index > 1 && date[index] > date[index / 2]) {
            swap(date[index /= 2], date[index]);
        }
    }

    //put the value down
    void shiftDown(int index) {

        while (2 * index <= count) {
            int swapIndex = 2 * index;

            //选取大的子节点
            if ((swapIndex + 1 < count) && date[swapIndex + 1] > date[swapIndex]) {
                swapIndex++;
            }
            if (date[index] >= date[swapIndex]) {
                break;
            }
            //位置更换后 修改index
            swap(date[swapIndex], date[index]);
            index = swapIndex;
        }
    }

public:

    explicit MaxHeap(int size) {
        date = new T[size + 1];
        count = 0;
    }

    ~MaxHeap() {
        delete[] date;
    }

    bool isEmpty() {
        return count == 0;
    }

    int getSize() {
        return count;
    }

    void insert(T item) {
        count++;
        date[count] = item;
        shiftUp(count);
    }

    T getMaxValue() {
        T temp = date[1];
        date[1] = date[count];
        shiftDown(1);
        count--;
        return temp;
    }

    void printRowArray() {
        for (int i = 1; i <= count; ++i) {

            cout << date[i] << " ";

            //换行显示
            if (i % 3 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
};


#endif //HEAPSORT_HEAP_H
