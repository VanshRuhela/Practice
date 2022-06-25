/*=============================================================================
#  PROBLEM:           Detect cycle in an undirected graph

Given an undirected graph, how to check if there is a cycle in the graph?

Example,

Input: n = 4, e = 4

Output: Yes

Explanation:  0 1, 1 2, 2 3, 0 2

Algorithm:

Create the graph using the given number of edges and vertices.
Create a recursive function that have current index or vertex, visited array and
parent node. Mark the current node as visited . Find all the vertices which are
not visited and are adjacent to the current node. Recursively call the function
for those vertices, If the recursive function returns true return true. If the
adjacent node is not parent and already visited then return true. Create a
wrapper function, that calls the recursive function for all the vertices and if
any function returns true, return true. (Because all the nodes in the graph
might not be connected or reachable from a starting vertex. To make sure every
vertex of graph is connected we are calling the recursive function for all
unvisited nodes.) Else if for all vertices the function returns false return
false.

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], int parent) {
        visited[v] = true;

        for (auto i : adj[v]) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, v)) return true;
            }

            else if (i != parent)
                return true;
        }

        return false;
    }

   public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclic() {
        bool* visited = new bool[V];
        memset(visited, false, V);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1)) return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";

    return 0;
}