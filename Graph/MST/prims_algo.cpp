/*=============================================================================
#  PROBLEM:
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    // Adj list
    vector<pair<int, int>>* l;
    int V;
public:
    Graph(int V) {
        this->V = V;
        l = new vector<pair<int, int>>[V];
    }

    void addEdge(int x, int y, int w) {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst() {
        // min heap to store
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            Q;

        // visited array for denoting node included in mst or not
        bool* visited = new bool[V]{0};

        Q.push({0, 0});
        int mst = 0;
        while (!Q.empty()) {
            // pick out the edge with min weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (visited[to]) continue;

            mst += weight;
            visited[to] = true;

            // add new edges to the queue
            for (auto x : l[to]) {
                if (visited[x.first] == 0) {
                    Q.push({x.second, x.first});
                }
            }
        }

        return mst;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    cout << g.prim_mst();
    return 0;
}