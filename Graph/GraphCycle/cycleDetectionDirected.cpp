/*=============================================================================
#  PROBLEM:           Detect Cycle in a Directed Graph
Given a directed graph, check whether the graph contains a cycle or not. Your
function should return true if the given graph contains at least one cycle, else
return false. Example,

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes

Algorithm:
Create the graph using the given number of edges and vertices.
Create a recursive function that initializes the current index or vertex,
visited, and recursion stack. Mark the current node as visited and also mark the
index in recursion stack. Find all the vertices which are not visited and are
adjacent to the current node. Recursively call the function for those vertices,
If the recursive function returns true, return true. If the adjacent vertices
are already marked in the recursion stack then return true. Create a wrapper
class, that calls the recursive function for all the vertices and if any
function returns true return true. Else if for all vertices the function returns
false return false.

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

    bool isCyclicUtil(int v, bool visited[], bool *recStack) {
        if (visited[v] == false) {
            visited[v] = true;
            recStack[v] = true;

            for (auto i : adj[v]) {
                if (!visited[i] && isCyclicUtil(i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

   public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {  // directed
        adj[v].push_back(w);
    }

    bool isCyclic() {
        bool *visited = new bool[V];
        bool *recStack = new bool[V];

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            recStack[i] = false;
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i] && isCyclicUtil(i, visited, recStack)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}