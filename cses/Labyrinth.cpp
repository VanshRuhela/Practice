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
    pair<int, int> begin, end;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A')
                begin = mp(i, j);
            else if (g[i][j] == 'B')
                end = mp(i, j);
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string stepDir = "URDL";
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<pair<int, int>> q;
    vector<vector<char>> prevStep(n, vector<char>(m));
    q.push(begin);
    vis[begin.f][begin.s] = true;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            auto v = mp(u.f + dx[i], u.s + dy[i]);

            if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
            if (g[v.f][v.s] == '#') continue;
            if (vis[v.f][v.s]) continue;

            vis[v.f][v.s] = true;
            prevStep[v.f][v.s] = i;

            q.push(v);
        }
    }

    if (vis[end.f][end.s]) {
        cout << "YES\n";
        vector<int> steps;
        while (end != begin) {
            int p = prevStep[end.f][end.s];
            steps.push_back(p);
            end = mp(end.f - dx[p], end.s - dy[p]);
        }

        reverse(steps.begin(), steps.end());

        cout << steps.size() <<"\n";
        for (char c : steps) cout << stepDir[c];
        cout << "\n";
    } else
        cout << "NO\n";

    return 0;
}