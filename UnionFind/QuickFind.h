//
// Created by D on 2019/6/22.
//
#include <assert.h>

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H
using namespace std;

namespace UnionFindQuickFind {
//并查集,此方法可快速查找，但是连接时需要遍历，性能一般
    class QuickFind {

    private:
        int *id;
        int count;

    public:
        QuickFind(int n) {
            count = n;
            id = new int[n];
            for (int i = 0; i < count; ++i) {
                id[i] = i;
            }
        }

        ~QuickFind() {
            delete[] id;
        }

        void unionElements(int p, int q) {
            int cop = find(p);
            int coq = find(q);
            if (cop == coq) {
                return;
            }
            id[p] = coq;
            for (int i = 0; i < count; ++i) {
                if (id[i] == cop) {
                    id[i] = coq;
                }
            }
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
        }
    };
}

#endif //UNIONFIND_UNIONFIND_H
