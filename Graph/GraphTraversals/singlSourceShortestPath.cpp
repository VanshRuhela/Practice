#include <bits/stdc++.h>
using namespace std;
/*=============================================================================
#  PROBLEM: single source shortest path
You are given an undirected graph with n nodes (numbered from 1 to n). The graph
is represented by a list of edges where each edge consists of two nodes x and y,
indicating that there is an edge between node x and node y.

Your task is to implement a function that finds the shortest path from a given
source node src to all other nodes in the graph. The distance between two
adjacent nodes is considered as 1. If a node is unreachable from the source
node, the distance to that node should be represented as INT_MAX
=============================================================================*/

template <typename T>
class Graph {
    map<T, list<T> > l;

   public:
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src) {
        map<T, int> dist;
        queue<T> q;

        // All other nodes will have int_max
        for (auto node_pair : l) {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (int nbr : l[node]) {
                if (dist[nbr] == INT_MAX) {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        // print the dist to every node
        for (auto node_pair : l) {
            T node = node_pair.first;
            int d = dist[node];
            cout << "NODE : " << node << " DIst from src : " << d << "\n";
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.bfs(0);
}