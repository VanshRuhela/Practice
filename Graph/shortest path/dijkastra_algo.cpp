/*=============================================================================
#  PROBLEM:          Dijkastra THeroem
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Graph {
    unordered_map<T, list<pair<T, int>>> m;

   public:
    void addEdge(T u, T v, int dist, bool bidir = true) {
        m[u].push_back({v, dist});
        if (bidir) {
            m[v].push_back({u, dist});
        }
    }

    void printAdj() {
        // iterate over all the key value paris in the map
        for (auto j : m) {
            cout << j.first << "->";

            for (auto k : j.second) {
                cout << "(" << k.first << "," << l.second << ")";
            }
            cout << "\n";
        }
    }

    void dijkastraSSSP(T src) {
        unordered_map<T, int> dist;
        // setting the dist to infinity
        for (auto j : m) {
            dist[j.first] = INT_MAX;
        }

        // making a set to find out node with min diff
        set<pair<int, T>> s;

        dist[src] = 0;
        s.insert({0, src});

        while (!s.empty()) {
            // finding the node at the front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over the neighbours/ of the current node
            for (auto childPair : m[node]) {
                if (nodeDist + childPair.second < dist[childPair.first]) {
                    // in set / pq updation of a particular node is node
                    // possible we have to remove old pair , and insert the new
                    // pair to simulate updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end()) s.erase(f);
                    // insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }

        for (auto d : dist) {
            cout << d.first << " is located at dist of " << d.second << "\n";
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(1, 2, 1);

    return 0;
}