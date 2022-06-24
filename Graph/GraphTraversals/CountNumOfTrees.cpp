#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<int>> l;

   public:
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs_helper(int src, map<int, bool>& visited) {
        visited[src] = true;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs() {
        map<int, bool> visited;

        for (auto x : l) {
            int node = x.first;
            visited[node] = false;
        }

        int res = 0;

        for (auto x : l) {
            if (visited[x.first] == false) {  // visited nahi hai
                dfs_helper(x.first, visited);
                res++;
            }
        }

        cout << res << "\n";
    }
};

int main() {
    Graph g;
    int n;
    cin >> n;
    while (n--) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.dfs();
}