/*=============================================================================
#  PROBLEM:           Topological Sorting

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void topologicalSortUtil(int v, bool visited[], stack<int>& s) {
        visited[v] = true;

        for (auto x : adj[v]) {
            if (!visited[x]) topologicalSortUtil(x, visited, s);
        }

        s.push(v);
    }

   public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int u) { adj[v].push_back(u); }

    void topologicalSort() {
        stack<int> s;
        bool* visited = new bool[V];
        memset(visited, false, V);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) topologicalSortUtil(i, visited, s);
        }

        cout << "Topological Sort\n";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given "
            "graph \n";

    // Function Call
    g.topologicalSort();
    return 0;
}