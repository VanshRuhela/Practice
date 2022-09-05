#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
vector<vector<int>> floyd_warshall(vector<vector<int>> &g) {
    vector<vector<int>> dist = g;
    int V = g.size();
    // Phases , in kth phase we included vertices (1,2,3, .... k) as
    // intermediate vertices
    for (int k = 0; k < V; k++) {
        // iterate over the entire 2D{
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // if vertex k is included , and we can minimise the dist?
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0)
            cout << "Graph Contains Negative Cycle from node " << i <<"\n";

    return dist;
}

int main() {
    vector<vector<int>> g = {{0, 1, INF, INF},
                             {INF, 0, -1, INF},
                             {INF, INF, 0, -1},
                             {-1, INF, INF, 0}};

    auto ans = floyd_warshall(g);
    for (auto v : ans) {
        for (int j : v) {
            cout << j << "\t";
        }
        cout << "\n";
    }

    return 0;
}