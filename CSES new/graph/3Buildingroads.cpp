/*=============================================================================
#  PROBLEM:          Byteland has n cities, and m roads between them.
The goal is to construct new roads so that there is a route between any two
cities. Your task is to find out the minimum number of roads required, and also
determine which roads should be built. Input The first input line has two
llegers n and m: the number of cities and roads. The cities are numbered
1,2,\dots,n. After that, there are m lines describing the roads. Each line has
two llegers a and b: there is a road between those cities. A road always
connects two different cities, and there is at most one road between any two
cities. Output First prll an lleger k: the number of required roads. Then,
prll k lines that describe the new roads. You can prll any valid solution.
Constralls

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define re(i, a, n) for (ll i = a; i <= n; ++i)
#define repr(i, a, n) for (ll i = a; i >= n; --i)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define f first
#define s second

ll n;  // cities
ll m;  // roads
map<ll, vector<ll>> g;
vector<ll> ele;
vector<bool> vis;

void dfs(ll src) {
    if (vis[src] == true) return;

    vis[src] = true;
    for (auto x : g[src]) dfs(x);
}

int main() {
    fast_cin();

    cin >> n >> m;

    rep(i, m) {
        ll a;
        ll b;
        cin >> a >> b;

        // add edge
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis.resize(n + 1, false);

    // cout << " g >> " << g.size() << endl;
    // for (auto x : g) {
    //     cout << x.first << "->";
    //     for (auto y : x.second) cout << y << " ";
    //     cout << "\n";
    // }

    ll numcomp = 0;
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            numcomp++;
            ele.push_back(i);
        }
    }

    cout << numcomp - 1 << "\n";
    for (int i = 1; i < ele.size(); i++) {
        cout << ele[i - 1] << " " << ele[i]<<"\n";
    }

    return 0;
}