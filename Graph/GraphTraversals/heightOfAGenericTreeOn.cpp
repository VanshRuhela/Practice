#include <bits/stdc++.h>
using namespace std;

int fillHeight(int parent[], int node, vector<int>& visited,
               vector<int>& height) {
    // root node
    if (parent[node] == -1) {
        visited[node] = 1;
        return 0;
    }

    if (visited[node]) return height[node];

    visited[node] = 1;
    return height[node] = 1 + fillHeight(parent , parent[node] , visited , height);

}

int findHeight(int parent[], int n) {
    vector<int> visited(n, 0);
    vector<int> height(n, 0);
    int max_height = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) height[i] = fillHeight(parent, i, visited, height);
        max_height = max(height[i], max_height);
    }

    return max_height;
}

int main() {
    int parent[] = {-1, 0, 0, 0, 3, 1, 1, 2};
    int n = sizeof(parent) / sizeof(parent[0]);

    cout << "Height of N-ary Tree = " << findHeight(parent, n);
    return 0;
}