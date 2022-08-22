#include <iostream>
#include <list>
using namespace std;

// edge list graph
class Graph {
    int V;
    list<pair<int, int>> l;

   public:
    Graph(int V) { this->V = V; }

    int addEdge(int u, int v) { l.push_back(make_pair(u, v)); }

    int findSet(int i, int parent[]) {
        if (parent[i] == -1) return i;

        return findSet(parent[i], parent);
    }

    int unionSet(int x, int y, int parent[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2) parent[s2] = s1;
    }

    bool contains_cycle() {
        // checking using DSU
        int *parent = new int[V];
        for (int i = 0; i < V; i++) parent[i] = -1;

        // iterate over the edge list
        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2)
                unionSet(s1, s2, parent);

            else
                return true;
        }
        delete[] parent;
        return false;
    }
};