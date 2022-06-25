/*=============================================================================
#  PROBLEM:          Clone an Undirected Graph

=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

struct GraphNode {
    int val;
    vector<GraphNode *> neighbours;
};

void bfs(GraphNode *src) {
    map<GraphNode *, bool> visited;
    queue<GraphNode *> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        GraphNode *x = q.front();
        q.pop();
        cout << "Value of Node " << x->val << "\n";
        cout << "Address of Node " << x << "\n";

        auto v = x->neighbours;
        auto n = v.size();

        for (int i = 0; i < n; i++) {
            if (!visited[v[i]]) {
                visited[v[i]] = true;
                q.push(v[i]);
            }
        }
    }

    cout << "\n";
}

GraphNode *cloneGraph(GraphNode *src) {
    map<GraphNode *, GraphNode *> m;
    queue<GraphNode *> q;

    q.push(src);
    GraphNode *node;

    node = new GraphNode();
    node->val = src->val;

    m[src] = node;

    while (!q.empty()) {
        GraphNode *x = q.front();
        q.pop();

        vector<GraphNode *> v = x->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (m[v[i]] == NULL) {
                node = new GraphNode();
                node->val = v[i]->val;
                m[v[i]] = node;
                q.push(v[i]);
            }

            m[x]->neighbours.push_back(m[v[i]]);
        }
    }

    return m[src];
}

GraphNode *buildGraph() {
    GraphNode *node1 = new GraphNode();
    node1->val = 1;
    GraphNode *node2 = new GraphNode();
    node2->val = 2;
    GraphNode *node3 = new GraphNode();
    node3->val = 3;
    GraphNode *node4 = new GraphNode();
    node4->val = 4;
    vector<GraphNode *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}
int main() {
    GraphNode *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);
    GraphNode *newsrc = cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);
    return 0;
}