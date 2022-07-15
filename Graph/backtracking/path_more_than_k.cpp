/*=============================================================================
#  PROBLEM:          Find if there is a path of more than k length from a source

Given a graph, a source vertex in the graph and a number k, find if there is a
simple path (without any cycle) starting from given source and ending at any
other vertex such that the distance from source to that vertex is atleast ‘k’
length.

Example:

Input  : Source s = 0, k = 58
Output : True
There exists a simple path 0 -> 7 -> 1
-> 2 -> 8 -> 6 -> 5 -> 3 -> 4
Which has a total distance of 60 km which
is more than 58.

Input  : Source s = 0, k = 62
Output : False

In the above graph, the longest simple
path has distance 61 (0 -> 7 -> 1-> 2
 -> 3 -> 4 -> 5-> 6 -> 8, so output
should be false for any input greater
than 61.
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* adj;

   public:
    Graph(int v) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bool pathMoreThanKUtil(int src, int k, vector<bool>& path) {
        if (k <= 0) return true;

        for (auto i : adj[src]) {
            int v = i.first;
            int w = i.second;

            if (path[v] == true)  // already in the path
                continue;
            if (w >= k) return true;

            if (pathMoreThanKUtil(v, k - w, path)) return true;

            path[v] = false;  // backtrack
        }

        return false;
    }
    bool pathMoreThanK(int src, int k) {
        vector<bool> path(V, false);

        path[src] = 1;  // src

        return pathMoreThanKUtil(src, k, path);
    }
};

int main() {
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    k = 60;
    g.pathMoreThanK(src, k) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}