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

struct Pair {
    string psf;
    int i;
    int j;
};

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m;j++) {
            cin >> arr[i][j];
        }
    }

    int dp[n][m];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1)
                dp[i][j] = arr[i][j];
            else if (i == n - 1)
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            else if (j == m - 1)
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + arr[i][j];
        }
    }

    queue<Pair> q;
    Pair p = {"", 0, 0};
    q.push(p);

    while (q.size() > 0) {
        Pair rem = q.front();
        q.pop();

        if (rem.i == n - 1 && rem.j == m - 1)  // last cell
            cout << rem.psf << "\n";
        else if (rem.i == n - 1)  // last row
            q.push({rem.psf + "H", rem.i, rem.j + 1});
        else if (rem.j == m - 1)  // last col
            q.push({rem.psf + "V", rem.i + 1, rem.j});
        else {
            if (dp[rem.i][rem.j + 1] < dp[rem.i + 1][rem.j])
                q.push({rem.psf + "H", rem.i, rem.j + 1});
            else if (dp[rem.i][rem.j + 1] > dp[rem.i + 1][rem.j])
                q.push({rem.psf + "V", rem.i + 1, rem.j});
            else {
                q.push({rem.psf + "H", rem.i, rem.j + 1});
                q.push({rem.psf + "V", rem.i + 1, rem.j});
            }
        }
    }

    return 0;
}