/*=============================================================================
#  PROBLEM:          Maximum edges that can be added to DAG so that it remains
DAGF

A DAG is given to us, we need to find maximum number of edges that can be added
to this DAG, after which new graph still remain a DAG that means the reformed
graph should have maximal number of edges, adding even single edge will create a
cycle in graph.
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;  // No. of vertices

    // Pointer to a list containing adjacency list
    list<int>* adj;

    // Vector to store indegree of vertices
    vector<int> indegree;

    // function returns a topological sort
    vector<int> topologicalSort();

   public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Prints all edges that can be added without making any
    // cycle
    void maximumEdgeAddtion();
};

//  Constructor of graph
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];

    // Initialising all indegree with 0
    for (int i = 0; i < V; i++) indegree.push_back(0);
}

//  Utility function to add edge
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);  // Add w to v's list.

    // increasing inner degree of w by 1
    indegree[w]++;
}

vector<int> Graph::topologicalSort() {
    vector<int> topo;
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        topo.push_back(t);

        for (auto i : adj[t]) {
            indegree[i]--;

            if (indegree[i] == 0) q.push(i);
        }
    }
    return topo;
}

void Graph::maximumEdgeAddtion() {
    bool* visited = new bool[V];
    vector<int> topo = topologicalSort();

    for (int i = 0; i < topo.size(); i++) {
        int t = topo[i];

        for (auto j : adj[t]) {
            visited[j] = true;
        }

        for (int j = i + 1; j < topo.size(); j++) {
            if (!visited[topo[j]]) {
                cout << t << " - " << topo[j] << " ";
            }
            visited[topo[j]] = false;
        }
        cout<<"\n";
    }
}

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.maximumEdgeAddtion();
    return 0;
}