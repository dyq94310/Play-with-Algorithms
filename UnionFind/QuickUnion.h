//
// Created by D on 2019/6/23.
//

#ifndef UNIONFIND_QUICKUNION_H
#define UNIONFIND_QUICKUNION_H


#include <cassert>

namespace UnionFindQuickUnion {
//并查集,此方法可快速查找，但是连接时需要遍历，性能一般
    class QuickUnion {

    private:
        int *id;
        int count;
        int *rank;

    public:
        QuickUnion(int n) {
            count = n;
            id = new int[n];
            rank = new int[n];
            for (int i = 0; i < count; ++i) {
                id[i] = i;
                rank[i] = 1;
            }
        }

        ~QuickUnion() {
            delete[] id;
            delete[] rank;
        }

        void unionElements(int p, int q) {
            int cop = find(p);
            int coq = find(q);
            if (cop == coq) {
                return;
            }
            if (rank[cop] > rank[coq]) {
                id[coq] = cop;
            } else if (rank[cop] < rank[coq]) {
                id[p] = coq;
            } else {
                id[coq] = cop;
                rank[cop]++;
            }
        }

        int find(int p) {
            assert(p >= 0 && p < count);

            //直接寻找根元素
            while (p != id[p]) {
                p = id[p];
            }
            return p;
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
        }
    };
}
#endif //UNIONFIND_QUICKUNION_H
