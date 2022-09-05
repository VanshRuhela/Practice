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

char s[1005][1005];
char path[1005][1005];
int n, m;

bool isBoundary(int x, int y) {
    return (x == 0 || x == n - 1 || y == 0 || y == m - 1);
}

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.');
}

int main() {
    fast_cin();
    cin >> n >> m;
    int x1 = 0, y1 = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            if (g[i][j] == 'A')
                x1 = i, y1 = j;
            else if (s[i][j] == 'M')
                q.push({i, j});
        }
    }

    if(isBoundary(x1, y1)){
        cout << "YES\n0\n";
        return 0;
    }

    q.push({x1, y1});

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string stepDir = "URDL";

    return 0;
}