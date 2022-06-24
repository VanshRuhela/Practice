/*=============================================================================
#  PROBLEM:          Transpose of a directed graph G is another directed graph
on the same set of vertices with all of the edges reversed compared to the
orientation of the corresponding edges in G. That is, if G contains an edge (u,
v) then the converse/transpose/reverse of G contains an edge (v, u) and vice
versa. Given a graph (represented as adjacency list), we need to find another
graph which is the transpose of the given graph.


We traverse the adjacency list and as we find a vertex v in the adjacency list
of vertex u which indicates an edge from u to v in main graph, we just add an
edge from v to u in the transpose graph i.e. add u in the adjacency list of
vertex v of the new graph. Thus traversing lists of all vertices of main graph
we can get the transpose graph. Thus the total time complexity of the algorithm
is O(V+E) where V is number of vertices of graph and E is the number of edges of
the graph. Note : It is simple to get the transpose of a graph which is stored
in adjacency matrix format, you just need to get the transpose of that matrix.




=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {  // directed edge
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int v) {
    for (auto i = 0; i < v; i++) {
        cout << i << " --> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void transpose(vector<int> adj[], vector<int> transposed[], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++)
            addEdge(transposed, adj[i][j], i);
    }
}

int main() {
    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);

    // printing original graph
    cout<<"Original Graph\n";
    printGraph(adj, v);

    vector<int> transposed[v];
    transpose(adj, transposed, v);

    // printing transposed graph
    cout<<"Transposed Graph\n";
    printGraph(transposed, v);

    return 0;
}