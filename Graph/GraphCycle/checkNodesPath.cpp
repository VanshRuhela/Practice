/*=============================================================================
#  PROBLEM:           Check if two nodes are on same path in a tree
Given a tree (not necessarily a binary tree) and a number of queries such that
every query takes two nodes of the tree as parameters. For every query pair,
find if two nodes are on the same path from the root to the bottom.

other children nodes are visited later until completely one child is
successfully visited till depth. To simplify this if we assume that we have a
watch in our hand, and we start walking from the root in DFS manner.

Intime – When we visit the node for the first time
Outtime- If we again visit the node later but there are no children unvisited we
call it outtime,

Note: Any node in its sub-tree will always have intime < its children (or
children of children) because it is always visited first before children (due to
DFS) and will have outtime > all nodes in its sub-tree because before noting the
outtime it waits for all of its children to be marked visited.

For any two nodes u, v if they are in the same path then,

Intime[v] < Intime[u] and Outtime[v] > Outtime[u]
                 OR
Intime[u] < Intime[v] and Outtime[u ]> Outtime[v]
If a given pair of nodes follows any of the two conditions, then they are on the
same root to the leaf path. Else not on the same path (If two nodes are on
different paths it means that no one is in the subtree of each other). Pseudo
Code

We use a global variable time which will be incremented as dfs for a node begins
and will also be incremented after

DFS(v)
    increment timer
    Intime[v] = timer
    mark v as visited
    for all u that are children of v
              DFS(u)
    increment timer
    Outtime[v] = timer
end
Time Complexity – O(n) for preprocessing and O(1) per query.
=============================================================================*/
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10001;

bool visit[MAX] = {0};

int intime[MAX];
int outtime[MAX];

int timer = 0;  // initally timer is zero

void dfs(vector<int> graph[], int v) {
    visit[v] = true;

    ++timer;

    intime[v] = timer;

    for (auto x : graph[v]) {
        if (visit[x] == false) dfs(graph, x);
    }

    ++timer;
    outtime[v] = timer;
}

bool query(int u, int v) {
    return ((intime[u] < intime[v] && outtime[u] > outtime[v]) ||
            (intime[v] < intime[u] && outtime[v] > outtime[u]));
}

int main() {
    int n = 9;  // total number of nodes
    vector<int> graph[n + 1];
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(6);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[5].push_back(7);
    graph[5].push_back(8);
    graph[5].push_back(9);

    // Start dfs (here root node is 1)
    dfs(graph, 1);

    // below are calls for few pairs of nodes
    query(1, 5) ? cout << "Yes\n" : cout << "No\n";
    query(2, 9) ? cout << "Yes\n" : cout << "No\n";
    query(2, 6) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}