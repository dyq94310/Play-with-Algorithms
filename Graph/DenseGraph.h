//
// Created by D on 2019/8/9.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稠密图 -邻接矩阵
class DenseGraph {
    //点 ，边
    int n, m;
    //有向图或无向
    bool directed;
    vector<vector<bool>> g;

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {}

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

        if (hasEdge(v, w)) {
            return;
        }
        g[v][w] = true;
        if (!directed) {
            g[w][v] = true;
        }
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return g[v][w];
    }

    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }

        int begin() {
            index = 0;
            for (int i = 0; i < G.g[v].size(); ++i) {
                if (G.g[v][i]) {
                    index = i;
                    return i;
                }
            }

            return -1;
        }

        int next() {
            index++;
            for (int i = index; i < G.g[v].size(); ++i) {
                if (G.g[v][i]) {
                    index = i;
                    return i;
                }
            }
            index = G.g[v].size();
            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_DENSEGRAPH_H
