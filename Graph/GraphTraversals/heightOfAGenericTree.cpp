/*=============================================================================
#  PROBLEM:           Height of a generic tree from parent array

We are given a tree of size n as array parent[0..n-1] where every index i in
the parent[] represents a node and the value at i represents the immediate
parent of that node. For root node value will be -1. Find the height of the
generic tree given the parent links. Examples:

Input : parent[] = {-1, 0, 0, 0, 3, 1, 1, 2}
Output : 2

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
vector<int> adj[MAX];

int Graph(int a[], int n) {
    int root_idx = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == -1)  // if root of the tree
            root_idx = i;
        else {
            adj[i].push_back(a[i]);
            adj[a[i]].push_back(i);
        }
    }
    return root_idx;
}

int height_BFS(int src) {  // using BFS

    map<int, int> vis;         // visited array
    queue<pair<int, int> > q;  // queue to store the current node and its height
    int max_level = 0;         // to store the max height of the tree

    q.push({src, 0});  // height of the src = 0; starting node

    pair<int, int> p;
    while (!q.empty()) {
        p = q.front();  // current node
        vis[p.first] = 1;

        max_level = max(max_level, p.second);

        q.pop();

        for (int i = 0; i < adj[p.first].size(); i++) {
            if (!vis[adj[p.first][i]]) {
                q.push({adj[p.first][i], p.second + 1});
            }
        }
    }

    return max_level;
}

int main() {
    int parent[] = {-1, 0, 0, 0, 3, 1, 1, 2};
    int n = sizeof(parent) / sizeof(parent[0]);
    // graph creation
    int root_index = Graph(parent, n);

    cout << "Max height : "<<height_BFS(root_index);
    return 0;
}