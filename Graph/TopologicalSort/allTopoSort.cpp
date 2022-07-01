/*=============================================================================
#  PROBLEM:        All Topological Sorts of a Directed Acyclic Graph
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of
vertices such that for every directed edge uv, vertex u comes before v in the
ordering. Topological Sorting for a graph is not possible if the graph is not a
DAG.


We can go through all possible ordering via backtracking , the algorithm step
are as follows :


Initialize all vertices as unvisited.
Now choose vertex which is unvisited and has zero indegree and decrease indegree
of all those vertices by 1 (corresponding to removing edges) now add this vertex
to result and call the recursive function again and backtrack. After returning
from function reset values of visited, result and indegree for enumeration of
other possibilities.

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    vector<int> indegree;
    void alltopologicalSortUtil(vector<int>& res, bool visited[]) {
        bool flag = false;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0 and !visited[i]) {
                for (auto j : adj[i]) {
                    indegree[j]--;
                }

                res.push_back(i);
                visited[i] = true;
                alltopologicalSortUtil(res , visited);

                visited[i] = false;
            }
        }
    }

   public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        for (int i = 0; i < V; i++) indegree.push_back(0);
    }

    void addEdge(int v, int u) {
        adj[v].push_back(u);
        indegree[u]++;
    }

    void alltopologicalSort() {
        bool* visited = new bool[V];
        memset(visited, false, V);

        vector<int> res;
        alltopologicalSortUtil(res, visited);
    }
};

int main() { return 0; }