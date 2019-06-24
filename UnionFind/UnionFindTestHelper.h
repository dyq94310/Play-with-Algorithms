//
// Created by D on 2019/6/22.
//

#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H

#include <ctime>
#include <iostream>
#include "QuickFind.h"
#include "QuickUnion.h"

using namespace std;
namespace UnionFindTestHelper {
    void TestUf(int n) {
        srand(time(nullptr));
        UnionFindQuickFind::QuickFind uf = UnionFindQuickFind::QuickFind(n);

        time_t startTime = clock();

        // 进行n次操作, 每次随机选择两个元素进行合并操作
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.connected(a, b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout << "UnionFindQuickFind, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"
             << endl;
    }

    void TestQU(int n) {
        srand(time(nullptr));
        UnionFindQuickUnion::QuickUnion uf = UnionFindQuickUnion::QuickUnion(n);

        time_t startTime = clock();

        // 进行n次操作, 每次随机选择两个元素进行合并操作
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionElements(a, b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.connected(a, b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout << "UnionFindQuickFind, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"
             << endl;
    }
}

#endif //UNIONFIND_UNIONFINDTESTHELPER_H
