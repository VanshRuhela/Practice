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

    int n, m;
    cin >> n >> m;

    vector<int> g[n + 1];
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist(n + 1, 0);
    vector<int> p(n + 1, 0);

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto v : g[x]) {
            if (dist[v] == 0 and v != 1) {
                dist[v] = dist[x] + 1;
                p[v] = x;
                q.push(v);
            }
        }
    }

    if (dist[n] == 0) {
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