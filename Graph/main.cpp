#include <iostream>
#include <vector>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> ve({1, 2, 3, 6, 0});
    vector<int>::iterator iter;

    for (iter = ve.begin(); iter != ve.end(); iter++) {
        cout << *iter << endl;
    }

    //测试用例
    int N = 20;
    int M = 100;

    srand(time(NULL));

    SparseGraph sparseGraph(N, false);
    DenseGraph denseGraph(N, false);
    //生成随机图
    for (int i = 0; i < M; ++i) {
        int a = rand() % N;
        int b = rand() % N;
        sparseGraph.addEdge(a, b);
        denseGraph.addEdge(a, b);
    }
    cout << "**********Traverse************" << endl;
    //遍历图节点
    for (int j = 0; j < N; ++j) {
        cout << j << " sparseIterator: ";
        SparseGraph::adjIterator sparseIterator(sparseGraph, j);
        for (int i = sparseIterator.begin(); !sparseIterator.end(); i = sparseIterator.next()) {
            cout << i << " ";
        }


        cout << "-------" << j << " denseIterator: ";
        DenseGraph::adjIterator denseIterator(denseGraph, j);

        for (int i = denseIterator.begin(); !denseIterator.end(); i = denseIterator.next()) {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}