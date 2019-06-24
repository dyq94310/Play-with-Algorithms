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

    public:
        QuickUnion(int n) {
            count = n;
            id = new int[n];
            for (int i = 0; i < count; ++i) {
                id[i] = i;
            }
        }

        ~QuickUnion() {
            delete[] id;
        }

        void unionElements(int p, int q) {
            int cop = find(p);
            int coq = find(q);
            if (cop == coq) {
                return;
            }
            id[p] = coq;
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
