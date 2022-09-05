#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, bool* vis, vector<int>& stack) {
    vis[i] = true;
    for (auto nbr : graph[i]) {
        if (!vis[nbr]) {
            dfs(graph, nbr, vis, stack);
        }
    }
    stack.push_back(i);
    cout<< i <<" ";
}

void dfs2(vector<int> graph[], int i, bool* vis) {
    vis[i] = true;
    cout << i << " ";
    for (auto nbr : graph[i]) {
        if (!vis[nbr]) {
            dfs2(graph, nbr, vis);
        }
    }
}

void solve(vector<int> graph[], vector<int> rev_graph[], int N) {
    bool visited[N];
    memset(visited, 0, N);

    vector<int> stack;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack);
            cout<<"\n";
        }
    }

    // ordering = stack
    // step - 2 reverse
    // step - 3 do dfs acc to ordering given in the stack

    memset(visited, 0, N);

    char comp_name = 'A';
    for (int x = stack.size() - 1; x >= 0; x--) {
        int node = stack[x];
        if (!visited[node]) {
            cout << "component " << comp_name << "---> ";
            dfs2(graph, node, visited);
            cout << "\n";
            comp_name++;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> graph[N];
    vector<int> rev_graph[N];

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }

    solve(graph, rev_graph, N);
}