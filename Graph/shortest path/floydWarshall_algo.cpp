/*=============================================================================
#  PROBLEM:          FLoyed warshall Algorithm

-All pair shortest path
-Shortest b/w all pair of vertices
-work with negative edges
-can detect negative cycles too , with one extra step
- DP Based Algo -> O(N^3) N<=>Vertices

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define INF 10000
vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
    vector<vector<int>> dist(graph);

    // Phases , in kth phase we include {1,2,3 ,,,, k} as intermediate veritces
    int V = graph.size();
    for (int k = 0; k < V; k++) {
        // iterate over the 2D Matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // if vertex k is included can we minimise the dist by taking it
                // as an intermediate vertex

                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0},
    };

    vector<vector<int>> sol = floyd_warshall(graph);

    for(auto i : graph){
        for(auto k : i){
            cout <<k <<" ";
        }
        cout<<"\n";
    }

    return 0;
}