#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
    map<T, list<T> > l;

   public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited) {
        // graph traversal
        cout << src << " ";
        visited[src] = true;
        for (T nbr : l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }

        // helper caller
        dfs_helper(src, visited);
    }

    void dfs(T src) {
        map<T, bool> visited;

        for (auto p : visited) {
            T node = p.first;
            visited[node] = false;
        }

        // Iterate over all the vertices

        dfs_helper(src, visited);
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.dfs(0);
    return 0;
}