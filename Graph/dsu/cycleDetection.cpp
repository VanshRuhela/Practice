#include <iostream>
#include <list>
using namespace std;

// edge list graph
class Graph {
    int V;
    list<pair<int, int>> l;

   public:
    Graph(int V) { this->V = V; }

    void addEdge(int u, int v) { l.push_back(make_pair(u, v)); }

    int findSet(int i, int parent[]) {
        if (parent[i] == -1) return i;

        return parent[i] = findSet(parent[i], parent);
    }

    void unionSet(int x, int y, int parent[], int rank[]) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2) {
            if (rank[s1] < rank[s2])
                parent[s1] = s2, rank[s2] += rank[s1];
            else
                parent[s2] = s1, rank[s1] += rank[s2];
        }
    }

    bool contains_cycle() {
        // checking using DSU

        // make everyone as their own parent i.e. -1
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }

        // iterate over the edge list
        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2)
                unionSet(s1, s2, parent, rank);

            else
                return true;
        }
        delete[] parent;
        return false;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    cout << g.contains_cycle() << endl;

    return 0;
}