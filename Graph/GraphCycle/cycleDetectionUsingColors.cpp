#include <bits/stdc++.h>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

class Graph {
    int V;
    list<int>* l;

   public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) { l[u].push_back(v); }

    bool helper(int node, int color[]) {
        color[node] = GRAY;

        for (auto nbr : l[node]) {
            if (color[nbr] == GRAY) return true;
            if (color[nbr] == WHITE and helper(nbr, color)) return true;
        }

        return false;
    }

    bool isCyclic() {
        int* color = new int[V];
        for (int i = 0; i < V; i++) color[i] = WHITE;

        for (int i = 0; i < V; i++) {
            if (color[i] == WHITE)
                if (helper(i, color) == true) return true;
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