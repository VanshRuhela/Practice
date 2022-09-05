// link :
// https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/

/*
Prob :
Suppose there are n towns connected by m bidirectional roads. There are s towns
among them with a police station. We want to find out the distance of each town
from the nearest police station. If the town itself has one the distance is 0.

Example:

Input :
Number of Vertices = 6
Number of Edges = 9
Towns with Police Station : 1, 5
Edges:
1 2
1 6
2 6
2 3
3 6
5 4
6 5
3 4
5 3
*/

#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mp make_pair
#define f first
#define s second

#define N 100000 + 1
#define inf 1000000
int dist[N];
int source[N];
int visited[N];
deque<pair<int, int> > BFSQueue;

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void multisource_bfs(vector<int> graph[], queue<int> q) {
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) { // ek lebel pr kr rha !! Q -> 6 , "7" -> "2 , 4 , 5"
            int k = q.front();
            q.pop();

            for (auto i : graph[k]) {
                if (!visited[i]) {
                    q.push(i);
                    dist[i] = dist[k] + 1;
                    visited[i] = true;
                }
            }
        }
    }
}

// int k = q.front();
// q.pop();

// for (auto i : graph[k]) {
//     if (!visited[i]) {
//         q.push(i);
//         dist[i] = dist[k] + 1;
//         visited[i] = true;
//     }
// }

void nearestTown2(vector<int> graph[], int n, int sources[], int s) {
    queue<int> q;

    for (int i = 0; i < s; i++) {
        q.push(sources[i]);
        visited[sources[i]] = true;
    }

    multisource_bfs(graph, q);

    // printing the distance
    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << endl;
    }
}

void BFS(vector<int> graph[], int start) {
    while (!BFSQueue.empty())
        BFSQueue.pop_back();  // global queue of queue<pair<int, int>>

    BFSQueue.push_back({start, 0});

    while (!BFSQueue.empty()) {
        int s = BFSQueue.front().f;
        int d = BFSQueue.front().s;

        visited[s] = 1;
        BFSQueue.pop_front();

        if (source[s] == 1) {
            dist[start] = d;
            return;
        }

        for (int i = 0; i < graph[s].size(); i++)
            if (visited[graph[s][i]] == 0)
                BFSQueue.push_back({graph[s][i], d + 1});
    }
}

void nearestTown(vector<int> graph[], int n, int sources[], int S) {
    for (int i = 1; i <= n; i++) source[i] = 0;
    for (int i = 0; i <= S - 1; i++) source[sources[i]] = 1;

    for (int i = 1; i <= n; i++) {  //(E.V)
        for (int i = 1; i <= n; i++) visited[i] = 0;
        BFS(graph, i);
    }

    // printing the distances
    for (int i = 1; i <= n; i++) cout << i << " " << dist[i] << endl;
}

int main() {
    fast_cin();
    int n = 6;
    vector<int> graph[n + 1];
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 6);
    addEdge(graph, 5, 4);
    addEdge(graph, 6, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 3);

    // Sources
    int sources[] = {1, 5};
    int S = sizeof(sources) / sizeof(sources[0]);

    // nearestTown(graph, n, sources, S);
    cout << "\nMultisource BFS way >\n";
    nearestTown2(graph, n, sources, S);
    return 0;
}