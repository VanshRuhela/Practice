#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define re(i, a, n) for (int i = a; i <= n; ++i)
#define repr(i, a, n) for (int i = a; i >= n; --i)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int main() {
    fast_cin();

    int n, m;  // comp , connections
    cin >> n >> m;
    // Uolevi - 1
    // Maija - n

    vector<int> g[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // bfs
    vector<int> vis(n + 1, 0);
    vector<int> dist(n + 1, 0);
    vector<int> p(n + 1, 0);

    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        // cout << "q\n";
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                p[v] = u;
                q.push(v);
            }
        }
    }

    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int u = n;
    int k = dist[n];

    vector<int> ans(k + 1);
    for (int i = k; i >= 0; i--) {
        ans[i] = u;
        u = p[u];
    }

    cout << k + 1 << "\n";
    for (int i = 0; i <= k; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}