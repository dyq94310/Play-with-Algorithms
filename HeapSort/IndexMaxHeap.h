// 带索引的最大堆
// Created by dyq94 on 2/3/2019.
//

#ifndef HEAPSORT_INDEXMAXHEAP_H
#define HEAPSORT_INDEXMAXHEAP_H


#include <iostream>

using namespace std;

//带有索引堆的堆。
//好处 便于索引到具体的某一个节点
template<typename T>
class IndexMaxHeap {

private:
    int count;
    //数据
    T *date;
    //索引堆
    int *indexHeap;

    //put the value up
    void shiftUp(int index) {
        while (index > 1 && date[indexHeap[index]] > date[indexHeap[index / 2]]) {
            swap(indexHeap[index /= 2], indexHeap[index]);
        }
    }

    //put the value down
    void shiftDown(int index) {

        while (2 * index <= count) {
            int swapIndex = 2 * index;

            //选取大的子节点
            if ((swapIndex + 1 < count) && date[indexHeap[swapIndex + 1]] > date[indexHeap[swapIndex]]) {
                swapIndex++;
            }
            if (date[indexHeap[index]] >= date[indexHeap[swapIndex]]) {
                break;
            }
            //位置更换后 修改index
            swap(date[indexHeap[swapIndex]], date[indexHeap[index]]);
            index = swapIndex;
        }
    }

public:

    explicit IndexMaxHeap(int size) {
        date = new T[size + 1];
        indexHeap = new int[size + 1];
        //一开始索引堆都指向不存在的0
        for (int i = 0; i < size + 1; ++i) {
            indexHeap[i] = 0;
        }
        count = 0;
    }

    ~IndexMaxHeap() {
        delete[] date;
        delete[] indexHeap;
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
        indexHeap[count] = count;
        shiftUp(count);
    }

    T getMaxValue() {
        T temp = date[indexHeap[1]];
        indexHeap[1] = indexHeap[count];
        shiftDown(1);
        indexHeap[count] = 0;
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

#endif //HEAPSORT_INDEXMAXHEAP_H
