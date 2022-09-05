// My_Template

#include <bits/stdc++.h>
using namespace std;

#define myfor(n) for (int i = 0; i < n; i++)
#define INFI 9223372036854775807ll
#define pb(a) push_back(a)

typedef long long int ll;

// unweighted-->
vector<int> adj[500005];

bool visited[40005];

ll a, b, c, p, q, r, l, n, m, k, e, t, x, y, z, u, v, w, ans;

ll da[40005], db[40005], dn[40005];

void bfs(int root) {
    int cur = root;
    queue<int> q;
    q.push(cur);

    while (q.size()) {
        cur = q.front(), q.pop();
        visited[cur] = true;

        for (auto next : adj[cur])
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                if (root == 1) da[next] = da[cur] + 1;
                if (root == 2) db[next] = db[cur] + 1;
                if (root == n) dn[next] = dn[cur] + 1;
            }
    }

    memset(visited, 0, sizeof(visited));
}

int main() {
       cin >> b >> e >> p >> n >> m;

    myfor(m) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    bfs(1), bfs(2), bfs(n);

    ans = INFI;

    for (int i = 1; i <= n; i++)
        ans = min(ans, da[i] * b + db[i] * e + dn[i] * p);

    cout << ans;

    return 0;
}