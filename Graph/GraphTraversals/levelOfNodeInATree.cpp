/*=============================================================================
#  PROBLEM:          Given a tree with v vertices, find the level of each node
in a tree from the source node.

BFS(Breadth-First Search) is a graph traversal technique where a node and its
neighbours are visited first and then the neighbours of neighbours. In simple
terms, it traverses level-wise from the source. First, it traverses level 1
nodes (direct neighbours of source node) and then level 2 nodes (neighbours of
source node) and so on. The BFS can be used to determine the level of each node
from a given source node. Algorithm:

Algorithm:
Create the tree, a queue to store the nodes and insert the root or starting node
in the queue. Create an extra array level of size v (number of vertices) and
create a visited array. Run a loop while size of queue is greater than 0. Mark
the current node as visited. Pop one node from the queue and insert its
childrens (if present) and update the size of the inserted node as level[child]
= level[node] + 1. Print all the node and its level.


=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int>* l;

   public:
    Graph(int V) {
        this->V = V;
        l = new vector<int>[V];
    }

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printLevels(int src) {
        vector<int> level(V, 0);
        vector<bool> visited(V, false);

        visited[src] = true;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            // cout << "x "<<x<<endl;
            for (auto ele : l[x]) {  // l[x] = vector , x = element
                if (!visited[ele]) {
                    q.push(ele);
                    level[ele] = level[x] + 1;
                    visited[ele] = true;
                }
            }
        }

        // levels of the node output
        cout << "Node Level\n";
        for (int i = 0; i < V; i++)
            cout << " " << i << " --> " << level[i] << "\n";
    }
};

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(6, 7);
    g.printLevels(0);
    /*
        Tree Structure
            0
           / \
          1  2
         /|\  |
        3 4 5 6
              |
              7
    */
}