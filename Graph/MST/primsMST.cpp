/*=============================================================================
#  PROBLEM:         Prim’s Minimum Spanning Tree (MST)

Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find
the longest distances from s to all other vertices in the given graph.

Following is complete algorithm for finding longest distances.

Initialize dist[] = {NINF, NINF, ….} and dist[s] = 0 where s is the source
vertex. Here NINF means negative infinite. Create a topological order of all
vertices. Do following for every vertex u in topological order.
..Do following for every adjacent vertex v of u
……if (dist[v] < dist[u] + weight(u, v))
………dist[v] = dist[u] + weight(u, v)
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* adj;

   public:
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int v, int u, int weight) { adj[v].push_back({u, weight}); }

    void topologicalSort(int v , bool visited[] , stack<int>& Stack){
        visited[v] = true;

        for(auto i : adj[v]){
            if(!visited[i.first]){
                topologicalSort(i.first , visited, Stack);
            }
        }

        Stack.push(v);
    }
    void longestPath(int s) {
        stack<int> Stack;
        int dist[V];
        bool* visited = new bool[V];
        memset(visited, false, V);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSort(i, visited, Stack);
        
        }


    }

    // void topologicalSort() {
    //     stack<int> s;
    //     bool* visited = new bool[V];
    //     memset(visited, false, V);
    //     for (int i = 0; i < V; i++) {
    //         if (!visited[i]) topologicalSortUtil(i, visited, s);
    //     }

    //     cout << "Topological Sort\n";
    //     while (!s.empty()) {
    //         cout << s.top() << " ";
    //         s.pop();
    //     }
    // }
};
int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    return 0;
}