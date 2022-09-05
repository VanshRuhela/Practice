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

const int MN = 1e5 + 10;
int N, M, ans, rep[MN];
vector<int> g[MN];
bool visited[MN];

void dfs(int node) {
    visited[node] = true;
    for (int u : g[node])
        if (!visited[u]) dfs(u);
}

int countComp() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            rep[cnt++] = i;
            dfs(i);
        }
    }

    return cnt;
}

int main() {
    fast_cin();
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    int ans = countComp();
    cout << ans - 1 << "\n";
    for (int i = 1; i < ans; i++) {
        cout << rep[i - 1] << " " << rep[i];
        cout << "\n";
    }

    return 0;
}