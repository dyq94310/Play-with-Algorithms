//
// Created by D on 2019/8/11.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稀疏图 -邻接表
class SparseGraph {
    //点 ，边
    int n, m;
    //有向图或无向
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<int>());
        }
    }

    ~SparseGraph() {}

    //有多少个顶点
    int V() {
        return this->n;
    }


    //有多少个边
    int E() {
        return this->m;
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
//一般邻接表 在添加边的时候，不处理平行边，因为处理平行边，需遍历节点[v]的所有元素
//        if (hasEdge(v, w)) {
//            return;
//        }
        g[v].push_back(w);
        //处理自环变
        if (v != w && !directed) {
            g[w].push_back(v);
        }
        m++;
    }

//处理平行边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] == w) {
                return true;
            }
        }
        return false;
    }

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }

        int begin() {
            index = 0;
            if (G.g[v].size()) {
                return G.g[v][0];
            }
            return -1;
        }

        int next() {
            index++;
            if (index < G.g[v].size()) {
                return G.g[v][index];
            }
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};


#endif //GRAPH_SPARSEGRAPH_H
