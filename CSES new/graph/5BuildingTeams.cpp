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

int n, m;
vector<int>* g;


int main() {
    fast_cin();
    cin >> n >> m;
    g = new vector<int>[n + 1];
    vector<int> team(n + 1, 0);

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            team[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto u : g[node]) {
                    if (team[u] == 0) {
                        team[u] = 3 - team[node];
                        q.push(u);
                    } else if (team[u] == team[node]) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }

    return 0;
}